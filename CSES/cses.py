#!/usr/bin/env python3
"""
CSES Problem Set Helper Script

Usage:
    python cses.py new <problem_no>         - Create problem folder & files
    python cses.py run <problem_no> <#>     - Compile & test solution-#.cpp

Environment:
    CXX - Optional C++ compiler path/name. Defaults to "g++".
          Example on Windows:
              set CXX=C:\\msys64\\mingw64\\bin\\g++.exe
"""

import html as html_lib
import os
import re
import shutil
import subprocess
import sys
import urllib.error
import urllib.request
import zipfile
from html.parser import HTMLParser
from pathlib import Path


# --- Configuration ---

DEFAULT_GPP_PATH = r"C:\msys64\mingw64\bin\g++.exe"
GPP_PATH = os.environ.get("CXX", DEFAULT_GPP_PATH)
CSES_BASE = "https://cses.fi/problemset/task"
PROBLEMS_DIR = os.path.dirname(os.path.abspath(__file__))

GPP_FLAGS = ["-std=c++17", "-O2", "-o"]
LOCAL_TIMEOUT_SECONDS = 5
COMPILER_TIMEOUT_SECONDS = 30


# --- ANSI Colors ---

GREEN = "\033[92m"
RED = "\033[91m"
YELLOW = "\033[93m"
CYAN = "\033[96m"
BOLD = "\033[1m"
DIM = "\033[2m"
RESET = "\033[0m"


def ok(msg):
    print(f"{GREEN}+{RESET}  {msg}")


def err(msg):
    print(f"{RED}x{RESET}  {msg}")


def info(msg):
    print(f"{CYAN}>{RESET}  {msg}")


def warn(msg):
    print(f"{YELLOW}!{RESET}  {msg}")


def hdr(msg):
    print(f"\n{BOLD}{msg}{RESET}")


# --- HTML Parser ---

class CSESParser(HTMLParser):
    """Parse a CSES problem page into title, constraints, and problem content."""

    def __init__(self):
        super().__init__(convert_charrefs=True)

        self.title = ""
        self.constraints_text = ""
        self.md_content = ""

        self._in_title_block = False
        self._in_h1 = False

        self._in_constraints = False
        self._constraints_depth = 0

        self._in_md = False
        self._md_depth = 0
        self._md_root_seen = False
        self._in_pre = False

        self._title_buf = []
        self._constraints_buf = []
        self._md_buf = []

    @staticmethod
    def _classes(attrs):
        attrs_dict = dict(attrs)
        return set(attrs_dict.get("class", "").split())

    def handle_starttag(self, tag, attrs):
        classes = self._classes(attrs)

        # Problem title
        if "title-block" in classes:
            self._in_title_block = True

        if self._in_title_block and tag == "h1":
            self._in_h1 = True

        # Constraints
        if "task-constraints" in classes and not self._in_constraints:
            self._in_constraints = True
            self._constraints_depth = 0

        if self._in_constraints:
            if tag in {"div", "ul", "ol"}:
                self._constraints_depth += 1

        # Main Markdown/content block
        if "md" in classes and not self._in_md:
            self._in_md = True
            self._md_root_seen = False
            self._md_depth = 0

        if self._in_md:
            if tag == "div":
                if not self._md_root_seen:
                    self._md_root_seen = True
                    self._md_depth = 1
                else:
                    self._md_depth += 1

            self._append_start_markup(tag)

    def _append_start_markup(self, tag):
        if tag == "pre":
            self._in_pre = True
            self._md_buf.append("\n```\n")
        elif tag in {"h1", "h2", "h3"}:
            self._md_buf.append("\n" + "#" * (int(tag[1]) + 1) + " ")
        elif tag == "p":
            self._md_buf.append("\n")
        elif tag == "br":
            self._md_buf.append("\n")
        elif tag == "li":
            self._md_buf.append("\n- ")
        elif tag in {"b", "strong"}:
            self._md_buf.append("**")
        elif tag in {"i", "em"}:
            self._md_buf.append("*")
        elif tag == "code" and not self._in_pre:
            self._md_buf.append("`")
        elif tag == "a":
            self._md_buf.append("[")

    def handle_endtag(self, tag):
        # Title
        if tag == "h1" and self._in_h1:
            self._in_h1 = False
            self._in_title_block = False

        # Constraints
        if self._in_constraints:
            if tag in {"div", "ul", "ol"}:
                self._constraints_depth -= 1

            if self._constraints_depth <= 0:
                self._in_constraints = False
                self.constraints_text = "".join(self._constraints_buf)

        # Main content
        if self._in_md:
            if tag == "pre":
                self._in_pre = False
                self._md_buf.append("\n```\n")
            elif tag in {"h1", "h2", "h3"}:
                self._md_buf.append("\n")
            elif tag == "p":
                self._md_buf.append("\n")
            elif tag in {"b", "strong"}:
                self._md_buf.append("**")
            elif tag in {"i", "em"}:
                self._md_buf.append("*")
            elif tag == "code" and not self._in_pre:
                self._md_buf.append("`")
            elif tag == "a":
                # Close a Markdown link. If the href is unavailable, this still
                # leaves readable Markdown text rather than HTML.
                self._md_buf.append("]")

            if tag == "div" and self._md_root_seen:
                self._md_depth -= 1
                if self._md_depth <= 0:
                    self._in_md = False
                    self.md_content = "".join(self._md_buf)

    def handle_data(self, data):
        if self._in_h1:
            self._title_buf.append(data)
            self.title = "".join(self._title_buf).strip()

        if self._in_constraints:
            self._constraints_buf.append(data)

        if self._in_md:
            self._md_buf.append(data)


# --- Math / Markdown Utilities ---

def convert_cses_math(text):
    """
    Convert CSES mathematical notation into GitHub-compatible Markdown math.

    Handles explicit MathJax delimiters and bare CSES LaTeX such as:
        2 \le n \le 2 \cdot 10^5
        1,2,\ldots,n
    """
    text = text.replace("\u00a0", " ")

    # Temporarily protect explicit math so the bare-LaTeX pass cannot
    # accidentally modify the contents of an already-converted expression.
    protected = []

    def protect(value):
        token = f"@@CSES_MATH_{len(protected)}@@"
        protected.append(value)
        return token

    # Explicit inline MathJax.
    text = re.sub(
        r"\\\((.*?)\\\)",
        lambda m: protect(f"${m.group(1).strip()}$"),
        text,
        flags=re.DOTALL,
    )

    # Explicit display MathJax.
    text = re.sub(
        r"\\\[(.*?)\\\]",
        lambda m: protect(
            f"\n$$\n{m.group(1).strip()}\n$$\n"
        ),
        text,
        flags=re.DOTALL,
    )

    # Bare CSES relation expressions, e.g.
    #   2 \le n \le 2 \cdot 10^5
    atom = r"(?:[0-9]+(?:\^[0-9]+)?|[A-Za-z](?:_[A-Za-z0-9]+)?)"
    operator = r"(?:\\cdot|\\times|\\pm|\\mp)"
    expression = rf"(?:{atom}(?:\s*{operator}\s*{atom})*)"
    relation = (
        r"(?:\\le|\\ge|\\lt|\\gt|\\ne|\\leq|\\geq|\\neq|"
        r"\\in|\\notin|\\subseteq?|\\supseteq?)"
    )

    relation_chain = re.compile(
        rf"(?<![\w$])"
        rf"({expression}\s*{relation}\s*{expression}"
        rf"(?:\s*{relation}\s*{expression})*)"
        rf"(?![\w$])"
    )

    text = relation_chain.sub(
        lambda m: f"${m.group(1).strip()}$",
        text,
    )

    # Bare sequences, e.g. 1,2,\ldots,n or 1,2,\dots,n.
    sequence = re.compile(
        r"(?<![\w$])"
        r"([0-9A-Za-z]+(?:\s*,\s*[0-9A-Za-z]+)*"
        r"\s*,\s*\\(?:ldots|dots)\s*,?\s*[A-Za-z0-9]+)"
        r"(?![\w$])"
    )

    text = sequence.sub(
        lambda m: f"${m.group(1).strip()}$",
        text,
    )

    # Restore explicit MathJax expressions.
    for index, value in enumerate(protected):
        text = text.replace(f"@@CSES_MATH_{index}@@", value)

    return text


# --- Fetch / Parse ---

def fetch_problem(problem_no):
    """Fetch and parse a CSES problem page."""
    url = f"{CSES_BASE}/{problem_no}"
    info(f"Fetching {url}")

    req = urllib.request.Request(
        url,
        headers={
            "User-Agent": "Mozilla/5.0 (CSES Problem Set Helper)",
            "Accept": "text/html,application/xhtml+xml",
        },
    )

    try:
        with urllib.request.urlopen(req, timeout=15) as resp:
            raw_html = resp.read().decode("utf-8", errors="replace")
    except urllib.error.HTTPError as e:
        raise RuntimeError(
            f"CSES returned HTTP {e.code} while fetching problem {problem_no}."
        ) from e
    except urllib.error.URLError as e:
        raise RuntimeError(
            f"Network error while fetching problem {problem_no}: {e.reason}"
        ) from e
    except TimeoutError as e:
        raise RuntimeError(
            f"Timed out while fetching problem {problem_no}."
        ) from e
    except Exception as e:
        raise RuntimeError(
            f"Failed to fetch problem {problem_no}: {e}"
        ) from e

    parser = CSESParser()

    try:
        parser.feed(raw_html)
        parser.close()
    except Exception as e:
        raise RuntimeError(f"Failed to parse CSES HTML: {e}") from e

    if not parser.title:
        raise RuntimeError(
            "Could not extract problem title. Check the problem number "
            "or whether CSES changed its page structure."
        )

    md = parser.md_content
    md = html_lib.unescape(md)
    md = re.sub(r"<script\b[^>]*>.*?</script>", "", md, flags=re.DOTALL | re.I)
    md = re.sub(r"<style\b[^>]*>.*?</style>", "", md, flags=re.DOTALL | re.I)
    md = re.sub(r"<[^>]+>", "", md)

    # Convert CSES MathJax/LaTeX to GitHub Markdown math.
    md = convert_cses_math(md)

    # Normalize excessive blank lines while preserving code blocks reasonably.
    md = re.sub(r"[ \t]+\n", "\n", md)
    md = re.sub(r"\n{3,}", "\n\n", md).strip()

    constraints_raw = parser.constraints_text
    constraints = extract_constraints(constraints_raw)

    return parser.title, constraints, md


def extract_constraints(constraints_raw):
    """Extract time and memory limits from the constraints text."""
    parts = []

    time_m = re.search(
        r"Time\s+limit:\s*([\d.]+)\s*([A-Za-z]+)",
        constraints_raw,
        flags=re.I,
    )
    mem_m = re.search(
        r"Memory\s+limit:\s*([\d.]+)\s*([A-Za-z]+)",
        constraints_raw,
        flags=re.I,
    )

    if time_m:
        parts.append(
            f"**Time limit:** {time_m.group(1)} {time_m.group(2)}"
        )

    if mem_m:
        parts.append(
            f"**Memory limit:** {mem_m.group(1)} {mem_m.group(2)}"
        )

    # Preserve/render the actual problem constraints, e.g.
    # "2 \\le n \\le 2 \\cdot 10^5".
    constraint_math = convert_cses_math(constraints_raw)

    # Remove the time/memory labels from this block so they aren't duplicated.
    constraint_math = re.sub(
        r"Time\s+limit:\s*[\d.]+\s*[A-Za-z]+",
        "",
        constraint_math,
        flags=re.I,
    )
    constraint_math = re.sub(
        r"Memory\s+limit:\s*[\d.]+\s*[A-Za-z]+",
        "",
        constraint_math,
        flags=re.I,
    )

    constraint_math = re.sub(r"\s+", " ", constraint_math).strip(" |\n")

    if constraint_math:
        parts.append(constraint_math)

    return " | ".join(parts)


# --- Folder Utilities ---

def sanitize_name(name):
    """Make a problem title safer for use as a Windows/Linux folder name."""
    cleaned = re.sub(r'[<>:"/\\|?*\x00-\x1f]', "", name)
    cleaned = re.sub(r"\s+", " ", cleaned).strip().rstrip(".")

    # Windows reserved device names.
    reserved = {
        "CON", "PRN", "AUX", "NUL",
        *(f"COM{i}" for i in range(1, 10)),
        *(f"LPT{i}" for i in range(1, 10)),
    }

    if cleaned.upper() in reserved:
        cleaned = f"_{cleaned}"

    return cleaned or "Untitled Problem"


def find_problem_folder(folder_name):
    """
    Find a problem folder by its exact name.

    This intentionally does NOT use startswith(), so for example:
        1083. Missing Number
    will not accidentally match:
        1083. Missing Number Backup
    """
    folder_path = os.path.join(PROBLEMS_DIR, folder_name)

    if os.path.isdir(folder_path):
        return folder_path

    return None


def find_problem_folder_from_readme(problem_no):
    """
    Find the exact problem folder for `problem_no` without downloading CSES.

    The generated README starts with:
        # <problem_no>. <problem title>

    We only accept a directory whose README has that exact heading and whose
    directory name exactly matches the heading text.
    """
    prefix = f"# {problem_no}. "

    for entry in os.listdir(PROBLEMS_DIR):
        folder_path = os.path.join(PROBLEMS_DIR, entry)

        if not os.path.isdir(folder_path):
            continue

        readme_path = os.path.join(folder_path, "README.md")

        if not os.path.isfile(readme_path):
            continue

        try:
            with open(readme_path, "r", encoding="utf-8") as f:
                first_line = f.readline().strip()
        except OSError:
            continue

        if not first_line.startswith(prefix):
            continue

        expected_folder_name = first_line[2:].strip()

        if entry == expected_folder_name:
            return folder_path

    return None


def next_solution_number(folder):
    pattern = re.compile(r"solution-(\d+)\.cpp$")
    nums = []
    for f in os.listdir(folder):
        m = pattern.match(f)
        if m:
            nums.append(int(m.group(1)))
    return max(nums) + 1 if nums else 1


# --- Solution Template ---

SOLUTION_TEMPLATE = """#include <bits/stdc++.h>
using namespace std;

int main() {{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // TODO: Solve {title}
    // https://cses.fi/problemset/task/{problem_no}

    return 0;
}}
"""


# --- Command: new ---

def cmd_new(problem_no):
    hdr(f"CSES New Problem -- #{problem_no}")

    title, constraints, md_content = fetch_problem(problem_no)
    ok(f"Problem: {title}")

    safe_title = sanitize_name(title)
    folder_name = f"{problem_no}. {safe_title}"
    folder_path = os.path.join(PROBLEMS_DIR, folder_name)

    # Match the complete expected folder name, not just the problem number.
    existing = find_problem_folder(folder_name)

    if existing:
        folder_path = existing
        sol_num = next_solution_number(existing)
        warn(f"Folder already exists: {os.path.basename(existing)}")
        info(f"Creating solution-{sol_num}.cpp")
    else:
        try:
            os.makedirs(folder_path)
        except OSError as e:
            raise RuntimeError(
                f"Could not create problem folder '{folder_path}': {e}"
            ) from e

        ok(f"Created folder: {folder_name}")
        sol_num = 1
        info("Creating solution-1.cpp and README.md")

    # Write solution file
    sol_file = os.path.join(folder_path, f"solution-{sol_num}.cpp")

    try:
        with open(sol_file, "w", encoding="utf-8", newline="\n") as f:
            f.write(
                SOLUTION_TEMPLATE.format(
                    title=title,
                    problem_no=problem_no,
                )
            )
    except OSError as e:
        raise RuntimeError(
            f"Could not create {os.path.basename(sol_file)}: {e}"
        ) from e

    ok(f"Created {os.path.basename(sol_file)}")

    # Write README only for new folders
    readme_path = os.path.join(folder_path, "README.md")

    if not os.path.exists(readme_path):
        readme = build_readme(
            problem_no,
            title,
            constraints,
            md_content,
        )

        try:
            with open(
                readme_path,
                "w",
                encoding="utf-8",
                newline="\n",
            ) as f:
                f.write(readme)
        except OSError as e:
            raise RuntimeError(
                f"Could not create README.md: {e}"
            ) from e

        ok("Created README.md")

    print()
    info(f"Path: {folder_path}")
    print(f"\n{DIM}Download the test zip from:{RESET}")
    print(f"  https://cses.fi/problemset/task/{problem_no}/")
    print(f"{DIM}Place the .zip file inside the problem folder, then run:{RESET}")
    print(f"  python cses.py run {problem_no} {sol_num}\n")


def build_readme(problem_no, title, constraints, md_content):
    lines = [
        f"# {problem_no}. {title}",
        "",
        f"**Link:** https://cses.fi/problemset/task/{problem_no}",
        "",
    ]

    if constraints:
        lines += [constraints, ""]

    lines += ["---", "", md_content, ""]
    return "\n".join(lines)


# --- Command: run ---

def find_zip(folder):
    if os.path.exists(os.path.join(folder, "tests.zip")):
        return os.path.join(folder, "tests.zip")
    return None


def normalize_output(text):
    """
    Normalize CSES output for comparison.

    CSES output is whitespace-insensitive, so comparing tokens avoids
    false failures caused by different spacing/newlines.
    """
    return text.split()


def run_tests(exe_path, test_cases, timeout_seconds=LOCAL_TIMEOUT_SECONDS):
    passed = failed = 0
    results = []

    for idx, (inp, expected) in enumerate(test_cases, 1):
        try:
            proc = subprocess.run(
                [exe_path],
                input=inp,
                capture_output=True,
                text=True,
                timeout=timeout_seconds,
            )

            actual = proc.stdout.strip()
            exp = expected.strip()

            if proc.returncode != 0:
                failed += 1
                error_message = proc.stderr.strip()

                if not error_message:
                    error_message = (
                        f"Process exited with code {proc.returncode}"
                    )

                results.append(
                    (
                        idx,
                        False,
                        inp,
                        exp,
                        "RUNTIME ERROR",
                        error_message,
                    )
                )
            elif normalize_output(actual) == normalize_output(exp):
                passed += 1
                results.append(
                    (idx, True, inp, exp, actual, "")
                )
            else:
                failed += 1
                results.append(
                    (idx, False, inp, exp, actual, proc.stderr)
                )

        except subprocess.TimeoutExpired:
            failed += 1
            results.append(
                (
                    idx,
                    False,
                    inp,
                    expected.strip(),
                    "TLE",
                    "Time Limit Exceeded",
                )
            )

        except OSError as e:
            failed += 1
            results.append(
                (
                    idx,
                    False,
                    inp,
                    expected.strip(),
                    "ERR",
                    str(e),
                )
            )

        except Exception as e:
            failed += 1
            results.append(
                (
                    idx,
                    False,
                    inp,
                    expected.strip(),
                    "ERR",
                    str(e),
                )
            )

    return results, passed, failed


def compiler_available():
    """Return whether the configured compiler can be located."""
    return shutil.which(GPP_PATH) is not None or os.path.isfile(GPP_PATH)


def cmd_run(problem_no, sol_num):
    hdr(f"CSES Run -- Problem #{problem_no}  solution-{sol_num}.cpp")

    folder = find_problem_folder_from_readme(problem_no)
    if not folder:
        raise RuntimeError(
            f"No exact problem folder found for problem #{problem_no}. "
            f"Run: python cses.py new {problem_no}"
        )

    info(f"Folder: {os.path.basename(folder)}")

    sol_file = os.path.join(folder, f"solution-{sol_num}.cpp")
    if not os.path.exists(sol_file):
        raise RuntimeError(
            f"solution-{sol_num}.cpp not found in "
            f"{os.path.basename(folder)}"
        )

    zip_path = find_zip(folder)
    if not zip_path:
        print("No .zip test file found in the problem folder.")
        print(f"\n{DIM}Download the tests zip from:{RESET}")
        print(f"  https://cses.fi/problemset/task/{problem_no}/")
        print(f"{DIM}Place the .zip file inside:{RESET}")
        print(f"  {folder}\n")
        raise RuntimeError("Test ZIP file not found.")

    info(f"Test zip: {os.path.basename(zip_path)}")

    if not compiler_available():
        raise RuntimeError(
            f"C++ compiler not found: {GPP_PATH!r}. "
            f"Set the CXX environment variable to your compiler path."
        )

    # Compile
    exe_path = os.path.join(folder, f"solution-{sol_num}.exe")
    info("Compiling...")

    compile_cmd = [GPP_PATH] + GPP_FLAGS + [exe_path, sol_file]

    try:
        result = subprocess.run(
            compile_cmd,
            capture_output=True,
            text=True,
            timeout=COMPILER_TIMEOUT_SECONDS,
        )
    except subprocess.TimeoutExpired as e:
        raise RuntimeError(
            f"Compilation timed out after "
            f"{COMPILER_TIMEOUT_SECONDS} seconds."
        ) from e
    except OSError as e:
        raise RuntimeError(
            f"Could not start compiler '{GPP_PATH}': {e}"
        ) from e

    if result.returncode != 0:
        err("Compilation failed:")
        print(result.stderr)
        raise RuntimeError("Compilation failed.")

    ok("Compiled successfully")

    try:
        # Extract test cases from zip
        test_cases = []

        with zipfile.ZipFile(zip_path, "r") as zf:
            if zf.testzip() is not None:
                raise RuntimeError("Test ZIP contains a corrupt file.")

            names = zf.namelist()

            in_files = [n for n in names if n.endswith(".in")]

            # Kept intentionally consistent with the original ZIP pairing
            # behavior: matching .in/.out names are expected.
            for in_name in sorted(
                in_files,
                key=lambda x: (
                    int(m.group(1))
                    if (m := re.search(r"(\d+)\.in$", x))
                    else 0
                ),
            ):
                out_name = in_name.replace(".in", ".out")

                if out_name in names:
                    inp_data = zf.read(in_name).decode(
                        "utf-8",
                        errors="replace",
                    )
                    out_data = zf.read(out_name).decode(
                        "utf-8",
                        errors="replace",
                    )
                    test_cases.append((inp_data, out_data))

        if not test_cases:
            raise RuntimeError(
                "No test cases found in zip "
                "(expected *.in / *.out files)."
            )

        info(f"Running {len(test_cases)} test case(s)...\n")

        results, passed, failed = run_tests(
            exe_path,
            test_cases,
            timeout_seconds=LOCAL_TIMEOUT_SECONDS,
        )

        # Print results
        for idx, success, inp, exp, actual, stderr in results:
            status = (
                f"{GREEN}PASS{RESET}"
                if success
                else f"{RED}FAIL{RESET}"
            )

            print(f"  Test {idx:>3}: [{status}]", end="")

            if not success:
                inp_preview = (
                    inp.strip()
                    .replace("\n", " | ")
                    .replace("\r", "")[:60]
                )

                print(f"\n          Input:    {DIM}{inp_preview}{RESET}")
                print(f"          Expected: {GREEN}{exp[:80]}{RESET}")
                print(f"          Got:      {RED}{actual[:80]}{RESET}")

                if stderr:
                    print(
                        f"          Stderr:   "
                        f"{YELLOW}{stderr[:100]}{RESET}"
                    )
            else:
                print()

        # Summary
        total = passed + failed
        bar_pass = "#" * passed
        bar_fail = "-" * failed
        color = GREEN if failed == 0 else RED

        print(
            f"\n  {GREEN}{bar_pass}{color}{bar_fail}"
            f"{RESET}  {passed}/{total} passed"
        )

        if failed == 0:
            print(
                f"\n  {GREEN}{BOLD}All tests passed!{RESET}\n"
            )
        else:
            print(
                f"\n  {RED}{BOLD}{failed} test(s) failed.{RESET}\n"
            )

    finally:
        # Always clean up the local executable, including when a test,
        # ZIP read, or unexpected exception fails.
        try:
            if os.path.exists(exe_path):
                os.remove(exe_path)
        except OSError as e:
            warn(f"Could not remove temporary executable: {e}")


# --- Entry Point ---

def usage():
    print(f"""
{BOLD}CSES Problem Set Helper{RESET}

{CYAN}Commands:{RESET}
  {BOLD}python cses.py new <problem_no>{RESET}
      Fetch problem from CSES, create folder & solution file.
      Example: python cses.py new 1083

  {BOLD}python cses.py run <problem_no> <solution_no>{RESET}
      Compile solution-#.cpp and test against zip test cases.
      Example: python cses.py run 1083 1

{CYAN}Setup:{RESET}
  g++ compiler: {GPP_PATH}
  Problems dir: {PROBLEMS_DIR}
""")


def main():
    if len(sys.argv) < 3:
        usage()
        return 0

    command = sys.argv[1].lower()
    problem_no = sys.argv[2]

    if not problem_no.isdigit():
        err(f"Problem number must be numeric, got: {problem_no!r}")
        return 1

    try:
        if command == "new":
            cmd_new(problem_no)

        elif command == "run":
            if len(sys.argv) < 4:
                err(
                    "Usage: python cses.py run "
                    "<problem_no> <solution_no>"
                )
                return 1

            sol_num = sys.argv[3]

            if not sol_num.isdigit():
                err(
                    f"Solution number must be numeric, "
                    f"got: {sol_num!r}"
                )
                return 1

            cmd_run(problem_no, int(sol_num))

        else:
            err(f"Unknown command: {command!r}")
            usage()
            return 1

    except KeyboardInterrupt:
        print()
        warn("Interrupted by user.")
        return 130

    except RuntimeError as e:
        err(str(e))
        return 1

    return 0


if __name__ == "__main__":
    sys.exit(main())