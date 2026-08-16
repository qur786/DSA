#!/usr/bin/env python3
"""
CSES Problem Set Helper

Usage:
    python cses.py new <problem_no> [--lang <language>]
    python cses.py run <problem_no> [solution_no] [--lang <language>]

Supported languages:
    C++        cpp, c++, cxx, cc, cplusplus
    JavaScript js, javascript, node, nodejs
    Java       java
    Python     py, python, python3

C++ is the default language.

Optional dependency for cross-platform memory-limit enforcement:
    python -m pip install psutil
"""

import html as html_lib
import json
import os
import re
import shutil
import subprocess
import sys
import tempfile
import threading
import time
import urllib.error
import urllib.request
import zipfile
from html.parser import HTMLParser


# -----------------------------------------------------------------------------
# Configuration
# -----------------------------------------------------------------------------

DEFAULT_GPP_PATH = "g++"
GPP_PATH = os.environ.get("CXX", DEFAULT_GPP_PATH)
CSES_BASE = "https://cses.fi/problemset/task"
PROBLEMS_DIR = os.path.dirname(os.path.abspath(__file__))

GPP_FLAGS = ["-std=c++17", "-O2", "-o"]
COMPILER_TIMEOUT_SECONDS = 30
DEFAULT_FALLBACK_TIME_SECONDS = 5.0

LANGUAGES = {
    "cpp": {
        "folder": "C++",
        "extension": ".cpp",
        "display": "C++",
        "aliases": {"cpp", "c++", "cxx", "cc", "cplusplus"},
    },
    "javascript": {
        "folder": "JavaScript",
        "extension": ".js",
        "display": "JavaScript",
        "aliases": {"js", "javascript", "node", "nodejs"},
    },
    "java": {
        "folder": "Java",
        "extension": ".java",
        "display": "Java",
        "aliases": {"java"},
    },
    "python": {
        "folder": "Python",
        "extension": ".py",
        "display": "Python",
        "aliases": {"py", "python", "python3"},
    },
}

LANGUAGE_ALIASES = {
    alias: canonical
    for canonical, config in LANGUAGES.items()
    for alias in config["aliases"]
}
DEFAULT_LANGUAGE = "cpp"

try:
    import psutil  # type: ignore
except ImportError:
    psutil = None


# -----------------------------------------------------------------------------
# ANSI helpers
# -----------------------------------------------------------------------------

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


# -----------------------------------------------------------------------------
# Language helpers
# -----------------------------------------------------------------------------

def normalize_language(language):
    if not language:
        return DEFAULT_LANGUAGE

    value = str(language).strip().lower()
    canonical = LANGUAGE_ALIASES.get(value)
    if not canonical:
        supported = ", ".join(
            f"{config['display']} ({', '.join(sorted(config['aliases']))})"
            for config in LANGUAGES.values()
        )
        raise RuntimeError(
            f"Unsupported language: {language!r}. Supported: {supported}"
        )
    return canonical


def language_config(language):
    return LANGUAGES[normalize_language(language)]


def solution_filename(solution_no, language):
    config = language_config(language)
    return f"solution-{solution_no}{config['extension']}"


def language_folder(problem_folder, language):
    return os.path.join(problem_folder, language_config(language)["folder"])


def solution_path(problem_folder, solution_no, language):
    return os.path.join(
        language_folder(problem_folder, language),
        solution_filename(solution_no, language),
    )


def list_solution_numbers(folder, language):
    if not os.path.isdir(folder):
        return []

    extension = re.escape(language_config(language)["extension"])
    pattern = re.compile(rf"^solution-(\d+){extension}$")
    numbers = []

    for filename in os.listdir(folder):
        match = pattern.match(filename)
        if match:
            numbers.append(int(match.group(1)))

    return sorted(numbers)


def next_solution_number(folder, language):
    numbers = list_solution_numbers(folder, language)
    return numbers[-1] + 1 if numbers else 1


def latest_solution_number(folder, language):
    numbers = list_solution_numbers(folder, language)
    return numbers[-1] if numbers else None


# -----------------------------------------------------------------------------
# HTML / Math parsing
# -----------------------------------------------------------------------------

class CSESParser(HTMLParser):
    """Parse CSES title, problem sections, constraints metadata and Markdown."""

    def __init__(self):
        super().__init__(convert_charrefs=True)

        self.title = ""
        self.constraints_text = ""
        self.md_content = ""
        self.sections = {}

        self._in_title_block = False
        self._in_h1 = False
        self._in_md = False
        self._md_depth = 0
        self._md_root_seen = False
        self._in_pre = False

        self._title_buf = []
        self._md_buf = []

        # Direct HTML section extraction. This is intentionally independent
        # from Markdown heading generation.
        self._section_name = None
        self._section_buf = []
        self._section_heading_level = None
        self._section_in_md = False

        # CSES task metadata (time/memory limits).
        self._in_constraints = False
        self._constraints_depth = 0
        self._constraints_buf = []

    @staticmethod
    def _classes(attrs):
        return set(dict(attrs).get("class", "").split())

    @staticmethod
    def _normalize_heading(text):
        return re.sub(r"\s+", " ", text).strip().rstrip(":")

    def _section_start(self, level, text):
        heading = self._normalize_heading(text)
        if not heading:
            return

        if self._section_name is not None:
            self.sections[self._section_name] = "".join(self._section_buf).strip()

        self._section_name = heading
        self._section_buf = []
        self._section_heading_level = level

    def _section_end(self):
        if self._section_name is not None:
            self.sections[self._section_name] = "".join(self._section_buf).strip()
        self._section_name = None
        self._section_buf = []
        self._section_heading_level = None

    def _append_section_markup(self, tag):
        if self._section_name is None:
            return
        if tag == "p":
            self._section_buf.append("\n")
        elif tag == "br":
            self._section_buf.append("\n")
        elif tag == "li":
            self._section_buf.append("\n- ")
        elif tag == "pre":
            self._section_buf.append("\n```\n")
        elif tag in {"b", "strong"}:
            self._section_buf.append("**")
        elif tag in {"i", "em"}:
            self._section_buf.append("*")
        elif tag == "code" and not self._in_pre:
            self._section_buf.append("`")

    def _close_section_markup(self, tag):
        if self._section_name is None:
            return
        if tag == "pre":
            self._section_buf.append("\n```\n")
        elif tag == "p":
            self._section_buf.append("\n")
        elif tag in {"b", "strong"}:
            self._section_buf.append("**")
        elif tag in {"i", "em"}:
            self._section_buf.append("*")
        elif tag == "code" and not self._in_pre:
            self._section_buf.append("`")

    def handle_starttag(self, tag, attrs):
        classes = self._classes(attrs)

        if "title-block" in classes:
            self._in_title_block = True

        if self._in_title_block and tag == "h1":
            self._in_h1 = True

        if "task-constraints" in classes and not self._in_constraints:
            self._in_constraints = True
            self._constraints_depth = 0

        if self._in_constraints and tag in {"div", "ul", "ol"}:
            self._constraints_depth += 1

        # Detect actual problem sections from HTML headings. CSES currently
        # uses these headings inside the problem's content, but we deliberately
        # do not require a particular div/class around them.
        if tag in {"h1", "h2", "h3", "h4"} and self._in_md:
            if self._section_name is not None:
                self._section_end()
            self._section_heading_level = int(tag[1])
            self._section_name = ""
            self._section_buf = []
            return

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

            if tag == "pre":
                self._in_pre = True
                self._md_buf.append("\n```\n")
            elif tag in {"h1", "h2", "h3", "h4"}:
                level = int(tag[1])
                self._md_buf.append("\n" + "#" * level + " ")
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

            # Section heading text and section content are captured separately.
            self._append_section_markup(tag)

    def handle_endtag(self, tag):
        if tag == "h1" and self._in_h1:
            self._in_h1 = False
            self._in_title_block = False

        if self._in_constraints:
            if tag in {"div", "ul", "ol"}:
                self._constraints_depth -= 1
            if self._constraints_depth <= 0:
                self._in_constraints = False
                self.constraints_text = "".join(self._constraints_buf)

        if tag in {"h1", "h2", "h3", "h4"} and self._in_md:
            # The heading's text itself is handled by handle_data(). Once the
            # next non-heading element appears, section content is appended.
            if self._section_name == "":
                # The heading data has already populated _section_name.
                self._section_name = self._normalize_heading("".join(self._section_buf))
                self._section_buf = []
            return

        if self._in_md:
            if tag == "pre":
                self._in_pre = False
                self._md_buf.append("\n```\n")
            elif tag in {"h1", "h2", "h3", "h4", "p"}:
                self._md_buf.append("\n")
            elif tag in {"b", "strong"}:
                self._md_buf.append("**")
            elif tag in {"i", "em"}:
                self._md_buf.append("*")
            elif tag == "code" and not self._in_pre:
                self._md_buf.append("`")

            self._close_section_markup(tag)

            if tag == "div" and self._md_root_seen:
                self._md_depth -= 1
                if self._md_depth <= 0:
                    self._in_md = False
                    self.md_content = "".join(self._md_buf)
                    self._section_end()

    def handle_data(self, data):
        if self._in_h1:
            self._title_buf.append(data)
            self.title = "".join(self._title_buf).strip()

        if self._in_constraints:
            self._constraints_buf.append(data)

        if self._in_md:
            self._md_buf.append(data)

            # Heading text is initially stored here, then promoted to the
            # section name on the corresponding end tag.
            if self._section_name == "":
                self._section_buf.append(data)
            elif self._section_name is not None:
                self._section_buf.append(data)

    def finalize(self):
        if self._section_name:
            self.sections[self._section_name] = "".join(self._section_buf).strip()
        self._section_name = None
        self._section_buf = []


def _unicode_math(text):
    """Convert common CSES LaTeX operators into renderer-independent Unicode."""
    replacements = {
        r"\leq": "≤",
        r"\geq": "≥",
        r"\neq": "≠",
        r"\le": "≤",
        r"\ge": "≥",
        r"\ne": "≠",
        r"\lt": "<",
        r"\gt": ">",
        r"\cdot": "·",
        r"\times": "×",
        r"\pm": "±",
        r"\mp": "∓",
        r"\ldots": "…",
        r"\dots": "…",
        r"\rightarrow": "→",
        r"\to": "→",
        r"\in": "∈",
        r"\notin": "∉",
        r"\subseteq": "⊆",
        r"\supseteq": "⊇",
        r"\subset": "⊂",
        r"\supset": "⊃",
        r"\infty": "∞",
        r"\sqrt": "√",
    }

    for old, new in replacements.items():
        text = text.replace(old, new)

    # Remove braces commonly left by LaTeX after simple exponent/subscript forms.
    text = re.sub(r"\^(?:\{([^{}]+)\})", r"^\1", text)
    text = re.sub(r"_(?:\{([^{}]+)\})", r"_\1", text)

    superscript_map = str.maketrans(
        "0123456789+-=()nmi", "⁰¹²³⁴⁵⁶⁷⁸⁹⁺⁻⁼⁽⁾ⁿₘᵢ"
    )
    subscript_map = str.maketrans(
        "0123456789+-=()aiemnorstuvx", "₀₁₂₃₄₅₆₇₈₉₊₋₌₍₎ₐᵢₑₘₙₒᵣₛₜᵤᵥₓ"
    )

    def superscript(match):
        value = match.group(1)
        converted = value.translate(superscript_map)
        return converted if converted != value else "^" + value

    def subscript(match):
        value = match.group(1)
        converted = value.translate(subscript_map)
        return converted if converted != value else "_" + value

    text = re.sub(r"\^([0-9]+)", superscript, text)
    text = re.sub(r"_([A-Za-z0-9]+)", subscript, text)

    return text


def convert_cses_math(text):
    """Make common CSES math render without relying on a MathJax-only Markdown renderer."""
    text = text.replace("\u00a0", " ")

    # Preserve explicit display/inline delimiters for complex expressions.
    protected = []

    def protect(value):
        token = f"@@CSES_MATH_{len(protected)}@@"
        protected.append(value)
        return token

    text = re.sub(
        r"\\\[(.*?)\\\]",
        lambda m: protect(f"\n$$\n{m.group(1).strip()}\n$$\n"),
        text,
        flags=re.DOTALL,
    )
    text = re.sub(
        r"\\\((.*?)\\\)",
        lambda m: protect(f"${m.group(1).strip()}$"),
        text,
        flags=re.DOTALL,
    )

    # First pass is deliberately Unicode-based for common constraints.
    text = _unicode_math(text)

    # Convert simple remaining fractions to readable Unicode/plain math.
    text = re.sub(
        r"\\frac\{([^{}]+)\}\{([^{}]+)\}",
        r"(\1 / \2)",
        text,
    )

    for index, value in enumerate(protected):
        # Apply Unicode cleanup inside explicit math without changing delimiters.
        if value.startswith("$") or value.lstrip().startswith("$$"):
            value = _unicode_math(value)
        text = text.replace(f"@@CSES_MATH_{index}@@", value)

    return text


def clean_text(text):
    text = html_lib.unescape(text or "")
    text = re.sub(r"<script\b[^>]*>.*?</script>", "", text, flags=re.DOTALL | re.I)
    text = re.sub(r"<style\b[^>]*>.*?</style>", "", text, flags=re.DOTALL | re.I)
    text = re.sub(r"<[^>]+>", "", text)
    text = convert_cses_math(text)
    text = re.sub(r"[ \t]+\n", "\n", text)
    text = re.sub(r"\n{3,}", "\n\n", text)
    return text.strip()


def extract_limits_from_html(raw_html):
    """Extract time and memory limits directly from the fetched page HTML/text."""
    plain = clean_text(raw_html)
    time_match = re.search(
        r"Time\\s+limit:\\s*([\\d.]+)\\s*([A-Za-z]+)",
        plain,
        flags=re.I,
    )
    memory_match = re.search(
        r"Memory\\s+limit:\\s*([\\d.]+)\\s*([A-Za-z]+)",
        plain,
        flags=re.I,
    )
    return time_match, memory_match


def extract_standard_sections_from_markdown(markdown):
    """Extract Input/Output/Constraints from rendered problem Markdown."""
    sections = {}
    current = None
    buffer = []

    for line in markdown.splitlines():
        heading = re.match(r"^#{1,4}\\s+(.+?)\\s*$", line)
        if heading:
            name = re.sub(r"\\s+", " ", heading.group(1)).strip().rstrip(":")
            if current is not None:
                sections[current] = "\\n".join(buffer).strip()
            current = name
            buffer = []
        elif current is not None:
            buffer.append(line)

    if current is not None:
        sections[current] = "\\n".join(buffer).strip()

    return sections


def extract_sections(markdown, parser_sections=None):
    """Extract sections directly from CSES HTML when available.

    `parser_sections` is preferred because it is based on actual HTML heading
    boundaries. Markdown heading parsing is retained only as a fallback.
    """
    if parser_sections:
        normalized = {}
        for key, value in parser_sections.items():
            clean_key = re.sub(r"\s+", " ", key).strip().rstrip(":")
            normalized[clean_key] = clean_text(value)
        return normalized

    sections = {}
    current = None
    buffer = []
    for line in markdown.splitlines():
        heading = re.match(r"^#{2,4}\s+(.+?)\s*$", line)
        if heading:
            if current is not None:
                sections[current] = "\n".join(buffer).strip()
            current = heading.group(1).strip()
            buffer = []
        elif current is not None:
            buffer.append(line)

    if current is not None:
        sections[current] = "\n".join(buffer).strip()
    return sections


def parse_limit_value(raw, kind):
    if raw is None:
        return None

    number = float(raw.group(1))
    unit = raw.group(2).lower()

    if kind == "time":
        if unit.startswith("ms"):
            return number / 1000.0
        if unit.startswith("min"):
            return number * 60.0
        return number

    if unit.startswith("kb"):
        return int(round(number / 1024))
    if unit.startswith("gb"):
        return int(round(number * 1024))
    return int(round(number))


def build_constraints(problem_no, title, constraints_raw, md_content, parser_sections=None, raw_html=None):
    time_match = re.search(
        r"Time\s+limit:\s*([\d.]+)\s*([A-Za-z]+)",
        constraints_raw,
        flags=re.I,
    )
    memory_match = re.search(
        r"Memory\s+limit:\s*([\d.]+)\s*([A-Za-z]+)",
        constraints_raw,
        flags=re.I,
    )

    # The current CSES HTML exposes these limits outside the problem Markdown
    # container, so use the whole fetched page as a robust fallback.
    if raw_html:
        html_time, html_memory = extract_limits_from_html(raw_html)
        if time_match is None:
            time_match = html_time
        if memory_match is None:
            memory_match = html_memory

    sections = extract_sections(md_content, parser_sections)

    # CSES currently renders Input/Output/Constraints as h1 headings. If a
    # future HTML layout prevents the parser from seeing those headings, use the
    # already-cleaned Markdown as a final fallback.
    if not any(k.casefold() == "input" for k in sections):
        fallback_sections = extract_standard_sections_from_markdown(md_content)
        sections.update(fallback_sections)

    def section_value(name):
        for key, value in sections.items():
            if key.casefold() == name.casefold():
                return clean_text(value)
        return ""

    constraints_text = section_value("Constraints")
    input_text = section_value("Input")
    output_text = section_value("Output")

    return {
        "schema_version": 1,
        "problem_number": int(problem_no),
        "title": title,
        "source_url": f"{CSES_BASE}/{problem_no}",
        "limits": {
            "time_seconds": parse_limit_value(time_match, "time"),
            "memory_mb": parse_limit_value(memory_match, "memory"),
        },
        "input": input_text,
        "output": output_text,
        "constraints": constraints_text,
        "sections": sections,
    }


def fetch_problem(problem_no):
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
        raise RuntimeError(f"CSES returned HTTP {e.code}.") from e
    except urllib.error.URLError as e:
        raise RuntimeError(f"Network error while fetching CSES: {e.reason}") from e
    except Exception as e:
        raise RuntimeError(f"Failed to fetch problem: {e}") from e

    parser = CSESParser()
    try:
        parser.feed(raw_html)
        parser.close()
        parser.finalize()
    except Exception as e:
        raise RuntimeError(f"Failed to parse CSES HTML: {e}") from e

    if not parser.title:
        raise RuntimeError(
            "Could not extract problem title. Check the problem number "
            "or whether CSES changed its page structure."
        )

    md = clean_text(parser.md_content)
    constraints_raw = clean_text(parser.constraints_text)
    constraints = build_constraints(
        problem_no,
        parser.title,
        constraints_raw,
        md,
        parser.sections,
        raw_html,
    )

    # Keep the JSON fields present even when CSES changes its HTML.
    constraints.setdefault("input", "")
    constraints.setdefault("output", "")
    constraints.setdefault("constraints", "")
    constraints.setdefault("sections", {})

    # Ensure the three standard sections are present whenever the fetched
    # problem statement contains them.
    fallback = extract_standard_sections_from_markdown(md)
    for name in ("Input", "Output", "Constraints"):
        if not constraints.get(name.lower()):
            value = next(
                (v for k, v in fallback.items() if k.casefold() == name.casefold()),
                "",
            )
            constraints[name.lower()] = clean_text(value)
        if not any(k.casefold() == name.casefold() for k in constraints["sections"]):
            value = constraints[name.lower()]
            if value:
                constraints["sections"][name] = value

    return parser.title, constraints, md


# -----------------------------------------------------------------------------
# Folder utilities
# -----------------------------------------------------------------------------

def sanitize_name(name):
    cleaned = re.sub(r'[<>:"/\\|?*\x00-\x1f]', "", name)
    cleaned = re.sub(r"\s+", " ", cleaned).strip().rstrip(".")

    reserved = {
        "CON", "PRN", "AUX", "NUL",
        *(f"COM{i}" for i in range(1, 10)),
        *(f"LPT{i}" for i in range(1, 10)),
    }

    if cleaned.upper() in reserved:
        cleaned = f"_{cleaned}"

    return cleaned or "Untitled Problem"


def find_problem_folder(folder_name):
    """Match the complete problem folder name exactly."""
    path = os.path.join(PROBLEMS_DIR, folder_name)
    return path if os.path.isdir(path) else None


def find_problem_folder_from_readme(problem_no):
    """Find a problem folder by its exact generated README heading."""
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

        if first_line.startswith(prefix) and entry == first_line[2:].strip():
            return folder_path

    return None


# -----------------------------------------------------------------------------
# Solution templates
# -----------------------------------------------------------------------------

SOLUTION_TEMPLATES = {
    "cpp": """#include <bits/stdc++.h>
using namespace std;

int main() {{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // TODO: Solve {title}
    // https://cses.fi/problemset/task/{problem_no}

    return 0;
}}
""",
    "python": """import sys


def main():
    # TODO: Solve {title}
    # https://cses.fi/problemset/task/{problem_no}
    pass


if __name__ == "__main__":
    main()
""",
    "javascript": """'use strict';

function main() {{
    // TODO: Solve {title}
    // https://cses.fi/problemset/task/{problem_no}
}}

main();
""",
    "java": """import java.io.*;
import java.util.*;

class Solution {{
    public static void main(String[] args) throws Exception {{
        // TODO: Solve {title}
        // https://cses.fi/problemset/task/{problem_no}
    }}
}}
""",
}


def solution_template(language):
    return SOLUTION_TEMPLATES[normalize_language(language)]


# -----------------------------------------------------------------------------
# README / constraints.json
# -----------------------------------------------------------------------------

def build_readme(problem_no, title, constraints, md_content):
    lines = [
        f"# {problem_no}. {title}",
        "",
        f"**Link:** https://cses.fi/problemset/task/{problem_no}",
        "",
    ]

    limits = constraints.get("limits", {})
    time_seconds = limits.get("time_seconds")
    memory_mb = limits.get("memory_mb")

    metadata = []
    if time_seconds is not None:
        metadata.append(f"**Time limit:** {time_seconds:g} s")
    if memory_mb is not None:
        metadata.append(f"**Memory limit:** {memory_mb} MB")

    if metadata:
        lines += [" | ".join(metadata), ""]

    lines += ["---", "", md_content, ""]
    return "\n".join(lines)


def write_constraints_json(folder, constraints):
    path = os.path.join(folder, "constraints.json")
    try:
        with open(path, "w", encoding="utf-8", newline="\n") as f:
            json.dump(constraints, f, indent=2, ensure_ascii=False)
            f.write("\n")
    except OSError as e:
        raise RuntimeError(f"Could not write constraints.json: {e}") from e
    return path


def load_constraints(folder):
    path = os.path.join(folder, "constraints.json")
    if not os.path.isfile(path):
        raise RuntimeError(
            "constraints.json not found. Run the 'new' command for this problem "
            "to generate it before using 'run'."
        )

    try:
        with open(path, "r", encoding="utf-8") as f:
            data = json.load(f)
    except (OSError, json.JSONDecodeError) as e:
        raise RuntimeError(f"Could not read constraints.json: {e}") from e

    return data


# -----------------------------------------------------------------------------
# Commands: new
# -----------------------------------------------------------------------------

def cmd_new(problem_no, language=DEFAULT_LANGUAGE):
    language = normalize_language(language)
    lang_config = language_config(language)

    hdr(f"CSES New Problem -- #{problem_no} ({lang_config['display']})")

    title, constraints, md_content = fetch_problem(problem_no)
    ok(f"Problem: {title}")
    info(f"Language: {lang_config['display']}")

    safe_title = sanitize_name(title)
    folder_name = f"{problem_no}. {safe_title}"
    folder_path = os.path.join(PROBLEMS_DIR, folder_name)

    existing = find_problem_folder(folder_name)

    if existing:
        folder_path = existing
        warn(f"Folder already exists: {os.path.basename(existing)}")
    else:
        try:
            os.makedirs(folder_path)
        except OSError as e:
            raise RuntimeError(f"Could not create problem folder: {e}") from e
        ok(f"Created folder: {folder_name}")

    # Always refresh constraints.json from CSES when running "new".
    constraints_path = write_constraints_json(folder_path, constraints)
    ok(f"Created/updated {os.path.basename(constraints_path)}")

    # README is generated only if it does not already exist, preserving user edits.
    readme_path = os.path.join(folder_path, "README.md")
    if not os.path.exists(readme_path):
        readme = build_readme(problem_no, title, constraints, md_content)
        try:
            with open(readme_path, "w", encoding="utf-8", newline="\n") as f:
                f.write(readme)
        except OSError as e:
            raise RuntimeError(f"Could not create README.md: {e}") from e
        ok("Created README.md")

    lang_folder = language_folder(folder_path, language)
    try:
        os.makedirs(lang_folder, exist_ok=True)
    except OSError as e:
        raise RuntimeError(f"Could not create language folder: {e}") from e

    solution_no = next_solution_number(lang_folder, language)
    solution_file = solution_filename(solution_no, language)
    solution_path_value = os.path.join(lang_folder, solution_file)

    try:
        with open(solution_path_value, "w", encoding="utf-8", newline="\n") as f:
            f.write(
                solution_template(language).format(
                    title=title,
                    problem_no=problem_no,
                )
            )
    except OSError as e:
        raise RuntimeError(f"Could not create {solution_file}: {e}") from e

    ok(f"Created {lang_config['folder']}/{solution_file}")

    limits = constraints.get("limits", {})
    if limits.get("time_seconds") is not None:
        info(f"Time limit: {limits['time_seconds']} s")
    if limits.get("memory_mb") is not None:
        info(f"Memory limit: {limits['memory_mb']} MB")

    print()
    info(f"Problem path: {folder_path}")
    info(f"Language path: {lang_folder}")
    print(f"\n{DIM}Download the test zip from:{RESET}")
    print(f"  https://cses.fi/problemset/task/{problem_no}/")
    print(f"{DIM}Place the .zip file inside the problem folder, then run:{RESET}")
    print(
        f"  python {os.path.basename(__file__)} run {problem_no} "
        f"--lang {lang_config['folder']}\n"
    )


# -----------------------------------------------------------------------------
# Test execution helpers
# -----------------------------------------------------------------------------

def find_zip(folder):
    path = os.path.join(folder, "tests.zip")
    return path if os.path.exists(path) else None


def normalize_output(text):
    return text.split()


def compiler_available(language):
    language = normalize_language(language)

    if language == "cpp":
        return shutil.which(GPP_PATH) is not None or os.path.isfile(GPP_PATH)
    if language == "java":
        return shutil.which("javac") is not None and shutil.which("java") is not None
    if language == "javascript":
        return shutil.which("node") is not None
    if language == "python":
        return shutil.which("python") is not None or shutil.which("python3") is not None
    return False


def runtime_commands(language, source_file, solution_no, folder):
    language = normalize_language(language)

    if language == "cpp":
        executable = os.path.join(
            folder,
            f"solution-{solution_no}{'.exe' if os.name == 'nt' else ''}",
        )
        return {
            "compile": [GPP_PATH] + GPP_FLAGS + [executable, source_file],
            "run": [executable],
            "cleanup": [executable],
        }

    if language == "python":
        python_cmd = shutil.which("python") or shutil.which("python3")
        return {
            "compile": None,
            "run": [python_cmd, source_file],
            "cleanup": [],
        }

    if language == "javascript":
        return {
            "compile": None,
            "run": ["node", source_file],
            "cleanup": [],
        }

    if language == "java":
        class_dir = tempfile.mkdtemp(prefix="cses_java_")
        return {
            "compile": ["javac", "-d", class_dir, source_file],
            "run": ["java", "-cp", class_dir, "Solution"],
            "cleanup": [class_dir],
        }

    raise RuntimeError(f"Unsupported language: {language}")


def terminate_process_tree(process):
    if process.poll() is not None:
        return

    if psutil is not None:
        try:
            parent = psutil.Process(process.pid)
            children = parent.children(recursive=True)
            for child in children:
                try:
                    child.terminate()
                except psutil.Error:
                    pass

            try:
                parent.terminate()
            except psutil.Error:
                pass

            _, alive = psutil.wait_procs(children + [parent], timeout=0.5)
            for item in alive:
                try:
                    item.kill()
                except psutil.Error:
                    pass
            return
        except psutil.Error:
            pass

    try:
        process.kill()
    except OSError:
        pass


def process_tree_rss_bytes(pid):
    if psutil is None:
        return 0

    try:
        root = psutil.Process(pid)
        processes = [root] + root.children(recursive=True)
        total = 0
        for proc in processes:
            try:
                total += proc.memory_info().rss
            except psutil.Error:
                pass
        return total
    except psutil.Error:
        return 0



def classify_execution_result(
    *,
    returncode,
    stdout,
    stderr,
    memory_exceeded,
    timed_out,
    memory_limit_mb,
):
    """Classify a solution process result as OK, TLE, MLE, or RUNTIME ERROR."""
    stdout = stdout or ""
    stderr = stderr or ""

    if memory_exceeded:
        return "MLE"

    combined_error = f"{stderr}\n{stdout}".lower()

    memory_error_patterns = (
        "std::bad_alloc",
        "bad_alloc",
        "std::bad_array_new_length",
        "cannot allocate memory",
        "cannot allocate memory block",
        "failed to allocate memory",
        "memory allocation failed",
        "out of memory",
        "not enough memory",
        "unable to allocate",
        "malloc failed",
    )

    if memory_limit_mb is not None and any(
        pattern in combined_error
        for pattern in memory_error_patterns
    ):
        return "MLE"

    if timed_out:
        return "TLE"

    return "OK" if returncode == 0 else "RUNTIME ERROR"

def execute_with_limits(command, input_data, time_limit, memory_limit_mb):
    """
    Run one test with wall-clock and RSS memory monitoring.

    stdin/stdout/stderr are file-backed to avoid pipe deadlocks while stopping
    timed-out or memory-limited processes.
    """
    if memory_limit_mb is not None and psutil is None:
        raise RuntimeError(
            "Memory-limit enforcement requires the 'psutil' package. "
            "Install it with: python -m pip install psutil"
        )

    input_path = stdout_path = stderr_path = None
    process = None
    monitor = None
    memory_exceeded = threading.Event()
    stop_monitor = threading.Event()
    timed_out = False
    started = time.monotonic()

    try:
        with tempfile.NamedTemporaryFile(
            mode="w",
            encoding="utf-8",
            delete=False,
            suffix=".cses.stdin",
        ) as input_file:
            input_file.write(input_data)
            input_path = input_file.name

        with tempfile.NamedTemporaryFile(
            mode="w",
            encoding="utf-8",
            delete=False,
            suffix=".cses.stdout",
        ) as stdout_file:
            stdout_path = stdout_file.name

        with tempfile.NamedTemporaryFile(
            mode="w",
            encoding="utf-8",
            delete=False,
            suffix=".cses.stderr",
        ) as stderr_file:
            stderr_path = stderr_file.name

        with (
            open(input_path, "r", encoding="utf-8") as stdin_file,
            open(stdout_path, "w", encoding="utf-8") as stdout_file,
            open(stderr_path, "w", encoding="utf-8") as stderr_file,
        ):
            process = subprocess.Popen(
                command,
                stdin=stdin_file,
                stdout=stdout_file,
                stderr=stderr_file,
                text=True,
            )

            def monitor_memory():
                if memory_limit_mb is None:
                    return

                limit_bytes = memory_limit_mb * 1024 * 1024

                while not stop_monitor.wait(0.01):
                    if process.poll() is not None:
                        return

                    if process_tree_rss_bytes(process.pid) > limit_bytes:
                        memory_exceeded.set()
                        terminate_process_tree(process)
                        return

            if memory_limit_mb is not None:
                monitor = threading.Thread(
                    target=monitor_memory,
                    daemon=True,
                )
                monitor.start()

            try:
                process.wait(timeout=time_limit)
            except subprocess.TimeoutExpired:
                if process.poll() is None:
                    timed_out = True
                    terminate_process_tree(process)

                    try:
                        process.wait(timeout=1)
                    except subprocess.TimeoutExpired:
                        try:
                            process.kill()
                        except OSError:
                            pass
                        try:
                            process.wait(timeout=1)
                        except subprocess.TimeoutExpired:
                            pass
                else:
                    process.wait()

            elapsed = time.monotonic() - started

    finally:
        stop_monitor.set()
        if monitor is not None:
            monitor.join(timeout=0.5)

    def read_capture(path):
        if not path:
            return ""

        try:
            with open(
                path,
                "r",
                encoding="utf-8",
                errors="replace",
            ) as f:
                return f.read()
        except OSError:
            return ""

    stdout = read_capture(stdout_path)
    stderr = read_capture(stderr_path)

    for path in (input_path, stdout_path, stderr_path):
        if path:
            try:
                os.remove(path)
            except OSError:
                pass

    if process is None:
        return {
            "status": "RUNTIME ERROR",
            "stdout": stdout,
            "stderr": stderr or "Process could not be started.",
            "elapsed_seconds": time.monotonic() - started,
            "returncode": None,
        }

    status = classify_execution_result(
        returncode=process.returncode,
        stdout=stdout,
        stderr=stderr,
        memory_exceeded=memory_exceeded.is_set(),
        timed_out=timed_out,
        memory_limit_mb=memory_limit_mb,
    )

    if status == "MLE" and not stderr:
        stderr = "Memory Limit Exceeded"
    elif status == "TLE" and not stderr:
        stderr = "Time Limit Exceeded"

    return {
        "status": status,
        "stdout": stdout,
        "stderr": stderr,
        "elapsed_seconds": elapsed,
        "returncode": process.returncode,
    }


def run_tests(command, test_cases, constraints):
    limits = constraints.get("limits", {})
    time_limit = limits.get("time_seconds")
    memory_limit = limits.get("memory_mb")

    if time_limit is None:
        time_limit = DEFAULT_FALLBACK_TIME_SECONDS
        warn(
            f"No time limit in constraints.json; using fallback "
            f"{time_limit:g} seconds."
        )

    passed = failed = 0
    results = []

    for idx, (inp, expected) in enumerate(test_cases, 1):
        try:
            result = execute_with_limits(
                command,
                inp,
                time_limit,
                memory_limit,
            )

            actual = result["stdout"].strip()
            exp = expected.strip()

            if result["status"] == "TLE":
                failed += 1
                results.append(
                    (idx, False, inp, exp, "TLE", result["stderr"])
                )
            elif result["status"] == "MLE":
                failed += 1
                results.append(
                    (idx, False, inp, exp, "MLE", result["stderr"])
                )
            elif result["status"] != "OK":
                failed += 1
                error = result["stderr"].strip() or (
                    f"Process exited with code {result['returncode']}"
                )
                results.append(
                    (idx, False, inp, exp, "RUNTIME ERROR", error)
                )
            elif normalize_output(actual) == normalize_output(exp):
                passed += 1
                results.append((idx, True, inp, exp, actual, ""))
            else:
                failed += 1
                results.append(
                    (idx, False, inp, exp, actual, result["stderr"])
                )

        except Exception as e:
            failed += 1
            results.append(
                (idx, False, inp, expected.strip(), "ERR", str(e))
            )

    return results, passed, failed


# -----------------------------------------------------------------------------
# Commands: run
# -----------------------------------------------------------------------------

def cmd_run(problem_no, solution_no=None, language=DEFAULT_LANGUAGE):
    language = normalize_language(language)
    config = language_config(language)

    folder = find_problem_folder_from_readme(problem_no)
    if not folder:
        raise RuntimeError(
            f"No exact problem folder found for problem #{problem_no}. "
            f"Run: python {os.path.basename(__file__)} new {problem_no}"
        )

    constraints = load_constraints(folder)

    lang_folder = language_folder(folder, language)
    if not os.path.isdir(lang_folder):
        raise RuntimeError(
            f"Language folder not found: {os.path.relpath(lang_folder, folder)}"
        )

    if solution_no is None:
        solution_no = latest_solution_number(lang_folder, language)
        if solution_no is None:
            raise RuntimeError(
                f"No {config['display']} solutions found in "
                f"{os.path.relpath(lang_folder, folder)}"
            )
        info(f"No solution number supplied; using latest solution-{solution_no}")

    source_file = solution_path(folder, solution_no, language)
    if not os.path.isfile(source_file):
        raise RuntimeError(
            f"Solution not found: {os.path.relpath(source_file, folder)}"
        )

    hdr(
        f"CSES Run -- Problem #{problem_no}  "
        f"solution-{solution_no}{config['extension']} ({config['display']})"
    )
    info(f"Problem folder: {os.path.basename(folder)}")
    info(f"Solution: {os.path.relpath(source_file, folder)}")

    limits = constraints.get("limits", {})
    if limits.get("time_seconds") is not None:
        info(f"Time limit: {limits['time_seconds']} s")
    if limits.get("memory_mb") is not None:
        info(f"Memory limit: {limits['memory_mb']} MB")

    if limits.get("memory_mb") is not None and psutil is None:
        raise RuntimeError(
            "Memory-limit enforcement is enabled by constraints.json, but "
            "psutil is not installed. Install it with: "
            "python -m pip install psutil"
        )

    zip_path = find_zip(folder)
    if not zip_path:
        print("No test ZIP found in the problem folder.")
        print(f"\n{DIM}Download the tests zip from:{RESET}")
        print(f"  {CSES_BASE}/{problem_no}/")
        print(f"{DIM}Place it here:{RESET} {folder}")
        raise RuntimeError("Test ZIP file not found.")

    if not compiler_available(language):
        commands = {
            "cpp": f"C++ compiler not found: {GPP_PATH!r}",
            "python": "Python runtime not found (python/python3).",
            "javascript": "Node.js runtime not found (node).",
            "java": "Java runtime/compiler not found (java/javac).",
        }
        raise RuntimeError(commands[language])

    runtime = runtime_commands(
        language,
        source_file,
        solution_no,
        lang_folder,
    )

    try:
        if runtime["compile"]:
            info("Compiling...")
            try:
                result = subprocess.run(
                    runtime["compile"],
                    capture_output=True,
                    text=True,
                    timeout=COMPILER_TIMEOUT_SECONDS,
                )
            except subprocess.TimeoutExpired as e:
                raise RuntimeError(
                    f"Compilation timed out after {COMPILER_TIMEOUT_SECONDS} seconds."
                ) from e
            except OSError as e:
                raise RuntimeError(f"Could not start compiler: {e}") from e

            if result.returncode != 0:
                err("Compilation failed:")
                print(result.stderr)
                raise RuntimeError("Compilation failed.")

            ok("Compiled successfully")
        else:
            info(f"Running with {config['display']} runtime...")

        test_cases = []
        with zipfile.ZipFile(zip_path, "r") as zf:
            bad_file = zf.testzip()
            if bad_file is not None:
                raise RuntimeError(f"Test ZIP contains a corrupt file: {bad_file}")

            names = zf.namelist()
            in_files = [name for name in names if name.endswith(".in")]

            for in_name in sorted(
                in_files,
                key=lambda x: (
                    int(m.group(1))
                    if (m := re.search(r"(\d+)\.in$", x))
                    else 0
                ),
            ):
                out_name = in_name[:-3] + ".out"
                if out_name in names:
                    test_cases.append(
                        (
                            zf.read(in_name).decode("utf-8", errors="replace"),
                            zf.read(out_name).decode("utf-8", errors="replace"),
                        )
                    )

        if not test_cases:
            raise RuntimeError(
                "No test cases found in ZIP (expected matching *.in / *.out files)."
            )

        info(f"Running {len(test_cases)} test case(s)...\n")

        results, passed, failed = run_tests(
            runtime["run"],
            test_cases,
            constraints,
        )

        for idx, success, inp, exp, actual, stderr in results:
            status = f"{GREEN}PASS{RESET}" if success else f"{RED}FAIL{RESET}"
            print(f"  Test {idx:>3}: [{status}]", end="")

            inp_preview = (
                    inp.strip().replace("\n", " | ").replace("\r", "")[:60]
                )
            print(f"\n          Input:    {DIM}{inp_preview}{RESET}")
            print(f"          Expected: {GREEN}{exp[:80]}{RESET}")
            print(f"          Got:      {GREEN if success else RED}{actual[:80]}{RESET}")
            if stderr:
                    print(f"          Error:    {YELLOW}{stderr[:120]}{RESET}")

        total = passed + failed
        bar_pass = "#" * passed
        bar_fail = "-" * failed
        color = GREEN if failed == 0 else RED
        print(
            f"\n  {GREEN}{bar_pass}{color}{bar_fail}{RESET} "
            f" {passed}/{total} passed"
        )

        if failed == 0:
            print(f"\n  {GREEN}{BOLD}All tests passed!{RESET}\n")
        else:
            print(f"\n  {RED}{BOLD}{failed} test(s) failed.{RESET}\n")

    finally:
        # Remove temporary compiled artifacts.
        for path in runtime.get("cleanup", []):
            try:
                if os.path.isdir(path):
                    shutil.rmtree(path, ignore_errors=True)
                elif os.path.exists(path):
                    os.remove(path)
            except OSError as e:
                warn(f"Could not remove temporary artifact {path}: {e}")


# -----------------------------------------------------------------------------
# CLI
# -----------------------------------------------------------------------------

def parse_language_and_args(args):
    language = DEFAULT_LANGUAGE
    remaining = []
    i = 0

    while i < len(args):
        arg = args[i]

        if arg in {"--lang", "--language", "-l"}:
            if i + 1 >= len(args):
                raise RuntimeError(f"{arg} requires a language name.")
            language = args[i + 1]
            i += 2
            continue

        if arg.startswith("--lang="):
            language = arg.split("=", 1)[1]
            i += 1
            continue

        if arg.startswith("--language="):
            language = arg.split("=", 1)[1]
            i += 1
            continue

        remaining.append(arg)
        i += 1

    return normalize_language(language), remaining


def usage():
    print(f"""
{BOLD}CSES Problem Set Helper{RESET}

{CYAN}Commands:{RESET}
  {BOLD}python cses.py new <problem_no> [--lang <language>]{RESET}
      Fetch the problem, create constraints.json, README.md and a solution.
      C++ is the default.

  {BOLD}python cses.py run <problem_no> [solution_no] [--lang <language>]{RESET}
      Run a specific solution, or the latest solution if the number is omitted.
      Time and memory limits are read from constraints.json.

{CYAN}Examples:{RESET}
  python cses.py new 1083
  python cses.py new 1083 --lang python
  python cses.py new 1083 --lang js
  python cses.py new 1083 --lang java

  python cses.py run 1083
  python cses.py run 1083 --lang py
  python cses.py run 1083 2 --lang cpp
  python cses.py run 1083 --lang javascript

{CYAN}Language aliases:{RESET}
  C++        cpp, c++, cxx, cc, cplusplus
  JavaScript js, javascript, node, nodejs
  Java       java
  Python     py, python, python3

{CYAN}Runtime/compiler:{RESET}
  C++        {GPP_PATH}
  Java       java / javac
  JavaScript node
  Python     python / python3

{CYAN}Memory enforcement:{RESET}
  Cross-platform RSS monitoring uses psutil.
  Install: python -m pip install psutil

{CYAN}Problems dir:{RESET}
  {PROBLEMS_DIR}
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
        language, args = parse_language_and_args(sys.argv[3:])

        if command == "new":
            if args:
                raise RuntimeError(
                    "Unexpected argument(s): " + " ".join(repr(x) for x in args)
                )
            cmd_new(problem_no, language)

        elif command == "run":
            if len(args) > 1:
                raise RuntimeError(
                    "Usage: python cses.py run <problem_no> "
                    "[solution_no] [--lang <language>]"
                )

            solution_no = None
            if args:
                if not args[0].isdigit():
                    raise RuntimeError(
                        f"Solution number must be numeric, got: {args[0]!r}"
                    )
                solution_no = int(args[0])

            cmd_run(problem_no, solution_no, language)

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