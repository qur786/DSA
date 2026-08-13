# CSES Problem Set Helper

A cross-platform command-line helper for organizing and running [CSES Problem Set](https://cses.fi/problemset/) solutions.

The script automates the repetitive parts of working through CSES problems:

- Fetches a CSES problem statement.
- Creates a problem directory using the problem number and title.
- Creates a `README.md` containing the problem statement and metadata.
- Creates a `constraints.json` file containing machine-readable problem limits and statement sections.
- Organizes solutions by programming language.
- Creates numbered `solution-#.<ext>` files from language-specific templates.
- Runs a selected solution or, by default, the latest solution for that language.
- Reads the CSES time and memory limits from `constraints.json`.
- Enforces the time limit and, when `psutil` is installed, the memory limit.
- Runs the downloaded CSES `.in` / `.out` test cases locally.
- Reports PASS, wrong answer, timeout, memory-limit, and runtime failures.

The script is designed to work on **Windows, macOS, and Linux**.

---

## Table of Contents

- [Requirements](#requirements)
- [Platform Setup](#platform-setup)
- [Quick Start](#quick-start)
- [Commands](#commands)
- [Language Support](#language-support)
- [Problem Directory Structure](#problem-directory-structure)
- [constraints.json](#constraintsjson)
- [README.md inside a Problem](#readmemd-inside-a-problem)
- [solution-\#\<ext> Files](#solution-ext-files)
- [Test ZIP](#test-zip)
- [How `run` Applies Constraints](#how-run-applies-constraints)
- [Latest Solution Behavior](#latest-solution-behavior)
- [Examples](#examples)
- [Troubleshooting](#troubleshooting)
- [Cross-Platform Notes](#cross-platform-notes)
- [Making This an Installable Command](#making-this-an-installable-command)
- [Future Improvements](#future-improvements)

---

## Requirements

### Required

You need:

1. **Python 3**
2. A compiler/runtime for the language you want to use.
3. Internet access when using `new`, because the script fetches the CSES problem statement.

### Recommended

Install `psutil`:

```bash
python -m pip install psutil
```

`psutil` is used for cross-platform memory monitoring during solution execution.

Without `psutil`, the script cannot enforce the memory limit stored in `constraints.json`.

---

## Platform Setup

## Windows

### Python

Install Python 3 from:

https://www.python.org/downloads/windows/

Verify:

```powershell
python --version
```

### C++

Install a C++ compiler such as **MinGW-w64 / MSYS2**.

Verify:

```powershell
g++ --version
```

The script uses:

```text
g++
```

by default.

You can override the compiler with the `CXX` environment variable.

Example:

```powershell
$env:CXX="C:\msys64\mingw64\bin\g++.exe"
```

### Python

```powershell
python --version
```

### JavaScript

Install Node.js:

https://nodejs.org/

Verify:

```powershell
node --version
```

### Java

Install a JDK, not just a JRE.

Verify:

```powershell
java --version
javac --version
```

---

## macOS

### Python

macOS may provide Python-related tools, but install a current Python 3 distribution if necessary.

Verify:

```bash
python3 --version
```

Depending on your setup, the command may be `python` instead of `python3`.

### C++

Install Xcode Command Line Tools:

```bash
xcode-select --install
```

Then verify:

```bash
g++ --version
```

You can also use another C++ toolchain and set `CXX` accordingly.

Example:

```bash
export CXX=/path/to/g++
```

### JavaScript

Install Node.js:

https://nodejs.org/

Verify:

```bash
node --version
```

### Java

Install a JDK.

Verify:

```bash
java --version
javac --version
```

---

## Linux

Install Python 3, a C++ compiler, and the runtimes you need using your distribution's package manager.

Typical Ubuntu/Debian setup:

```bash
sudo apt update
sudo apt install python3 python3-pip g++ nodejs openjdk-17-jdk
```

Verify:

```bash
python3 --version
g++ --version
node --version
java --version
javac --version
```

Then install the Python dependency:

```bash
python3 -m pip install psutil
```

---

# Quick Start

Clone or place the script in the directory where you want your CSES problems to live.

For example:

```text
cses/
├── cses.py
├── 1083. Missing Number/
├── 1094. Increasing Array/
└── ...
```

Run:

```bash
python cses.py new 1083
```

C++ is the default language.

The script fetches the CSES statement and creates a structure similar to:

```text
1083. Missing Number/
├── README.md
├── constraints.json
└── C++/
    └── solution-1.cpp
```

Download the CSES test ZIP for the problem and place it in the problem directory:

```text
1083. Missing Number/
├── README.md
├── constraints.json
├── tests.zip
└── C++/
    └── solution-1.cpp
```

Then run:

```bash
python cses.py run 1083
```

The latest C++ solution is executed automatically.

---

# Commands

## `new`

```bash
python cses.py new <problem_no>
```

Creates a new problem and uses **C++ by default**.

Example:

```bash
python cses.py new 1083
```

### `--lang`

Specify the language:

```bash
python cses.py new 1083 --lang cpp
python cses.py new 1083 --lang python
python cses.py new 1083 --lang js
python cses.py new 1083 --lang java
```

Language aliases are also supported.

Examples:

```bash
python cses.py new 1083 --lang c++
python cses.py new 1083 --lang py
python cses.py new 1083 --lang javascript
```

Running `new` again for an existing problem:

- Reuses the exact problem folder.
- Refreshes `constraints.json` from CSES.
- Preserves an existing `README.md`.
- Creates the next numbered solution in the selected language folder.

---

## `run`

```bash
python cses.py run <problem_no>
```

Runs the **latest solution** for the default language, C++.

Example:

```bash
python cses.py run 1083
```

### Run a specific solution

```bash
python cses.py run 1083 2
```

### Select a language

```bash
python cses.py run 1083 --lang python
python cses.py run 1083 --lang javascript
python cses.py run 1083 --lang java
python cses.py run 1083 --lang cpp
```

### Select both solution number and language

```bash
python cses.py run 1083 3 --lang python
```

If the solution number is omitted, the highest numbered solution in that language folder is selected.

---

# Language Support

The current version supports exactly four languages.

| Language | Accepted names | Extension | Folder |
|---|---|---|---|
| C++ | `cpp`, `c++`, `cxx`, `cc`, `cplusplus` | `.cpp` | `C++` |
| JavaScript | `js`, `javascript`, `node`, `nodejs` | `.js` | `JavaScript` |
| Java | `java` | `.java` | `Java` |
| Python | `py`, `python`, `python3` | `.py` | `Python` |

C++ is the default.

---

# Problem Directory Structure

A typical problem looks like:

```text
1083. Missing Number/
├── README.md
├── constraints.json
├── tests.zip
├── C++/
│   ├── solution-1.cpp
│   ├── solution-2.cpp
│   └── solution-3.cpp
├── Python/
│   ├── solution-1.py
│   └── solution-2.py
├── JavaScript/
│   └── solution-1.js
└── Java/
    └── solution-1.java
```

The language folders are deliberately separated so solution numbering is independent for each language.

For example:

```text
C++/
├── solution-1.cpp
└── solution-2.cpp

Python/
├── solution-1.py
└── solution-2.py
```

`run 1083` uses the latest C++ solution.

`run 1083 --lang python` uses the latest Python solution.

---

# `constraints.json`

Every time `new` fetches a problem, the script creates or refreshes:

```text
constraints.json
```

This is the machine-readable metadata file for that particular CSES problem.

A typical file contains:

```json
{
  "schema_version": 1,
  "problem_number": 1083,
  "title": "Missing Number",
  "source_url": "https://cses.fi/problemset/task/1083",
  "limits": {
    "time_seconds": 1.0,
    "memory_mb": 512
  },
  "input": "...",
  "output": "...",
  "constraints": "...",
  "sections": {
    "Input": "...",
    "Output": "...",
    "Constraints": "..."
  }
}
```

## What the fields mean

### `schema_version`

Version of the JSON structure.

This allows the format to evolve in the future.

### `problem_number`

The CSES problem number.

Example:

```json
"problem_number": 1083
```

### `title`

The problem title.

Example:

```json
"title": "Missing Number"
```

### `source_url`

The original CSES problem URL.

### `limits.time_seconds`

The CSES time limit converted to seconds.

Example:

```json
"time_seconds": 1.0
```

### `limits.memory_mb`

The CSES memory limit converted to megabytes.

Example:

```json
"memory_mb": 512
```

### `input`

The cleaned Input section from the problem statement.

### `output`

The cleaned Output section.

### `constraints`

The cleaned Constraints section.

### `sections`

The parsed Markdown sections from the CSES statement.

This preserves sections such as:

```text
Input
Output
Constraints
```

and any other statement sections that are detected.

---

# Why `constraints.json` Exists

The JSON file separates **problem metadata** from the Markdown presentation.

The README is primarily for humans.

The JSON file is primarily for the program.

This allows the runner to do things such as:

```text
constraints.json
        |
        +-- time_seconds = 1
        |
        +-- memory_mb = 512
        |
        v
run solution
        |
        +-- stop if time exceeds limit
        |
        +-- stop if memory exceeds limit
```

The runner does not need to scrape the CSES website every time you run your solution.

---

# `README.md` inside a Problem

Each problem folder has its own `README.md`.

Example:

```text
1083. Missing Number/
└── README.md
```

The generated README contains:

1. Problem number and title.
2. CSES problem link.
3. Time limit.
4. Memory limit.
5. The problem statement.
6. The relevant statement sections.

The heading is:

```markdown
# 1083. Missing Number
```

The README is intended to be human-readable and useful when browsing the repository on GitHub.

## Important behavior

The script does **not overwrite an existing README** when `new` is executed again.

This lets you manually improve the README without losing your edits.

`constraints.json`, however, is refreshed from CSES when `new` is run.

---

# `solution-#.<ext>` Files

Solutions are stored using a numbered naming convention.

Examples:

```text
solution-1.cpp
solution-2.cpp
solution-3.cpp
```

Python:

```text
solution-1.py
solution-2.py
```

JavaScript:

```text
solution-1.js
```

Java:

```text
solution-1.java
```

The number represents the solution revision for that language.

For example:

```text
C++/
├── solution-1.cpp
├── solution-2.cpp
└── solution-3.cpp
```

A common workflow is:

```text
solution-1.cpp   First attempt
solution-2.cpp   Improved approach
solution-3.cpp   Final/refined approach
```

The script does not overwrite an existing solution number.

It calculates the next available number from existing solution files.

---

# Latest Solution Behavior

The `run` command automatically selects the latest solution when no solution number is supplied.

Suppose:

```text
Python/
├── solution-1.py
├── solution-2.py
└── solution-7.py
```

Then:

```bash
python cses.py run 1083 --lang python
```

runs:

```text
Python/solution-7.py
```

Similarly:

```text
C++/
├── solution-1.cpp
├── solution-4.cpp
└── solution-8.cpp
```

means:

```bash
python cses.py run 1083
```

runs:

```text
C++/solution-8.cpp
```

---

# Test ZIP

The script expects the CSES tests ZIP to be placed directly inside the problem directory.

Example:

```text
1083. Missing Number/
├── README.md
├── constraints.json
├── tests.zip
└── C++/
    └── solution-1.cpp
```

The ZIP is expected to contain matching `.in` and `.out` files.

For example:

```text
1.in
1.out
2.in
2.out
3.in
3.out
```

The script pairs each input file with the corresponding output file.

---

# How `run` Applies Constraints

When `run` starts, it loads:

```text
constraints.json
```

and reads:

```json
"limits": {
  "time_seconds": 1.0,
  "memory_mb": 512
}
```

Each test case is executed with those limits.

## Time limit

The process is monitored using the configured `time_seconds`.

If the solution exceeds the limit:

```text
TLE
```

is reported.

## Memory limit

Memory is monitored using the process's RSS and its child processes.

If the process tree exceeds the configured memory limit:

```text
MLE
```

is reported.

This is why the optional `psutil` dependency is important.

Install it with:

```bash
python -m pip install psutil
```

## Runtime errors

A non-zero process exit is reported as:

```text
RUNTIME ERROR
```

instead of being confused with a wrong answer.

## Wrong answer

The test output is compared using whitespace-separated tokens rather than exact byte-for-byte whitespace.

This avoids false failures caused only by different spaces or line breaks.

---

# Platform Compatibility

The script is designed to use OS-neutral Python functionality where possible.

## C++

The C++ executable is created as:

```text
Windows: solution-1.exe
macOS/Linux: solution-1
```

The script detects the operating system when constructing the executable path.

## Python

The script looks for:

```text
python
```

or:

```text
python3
```

## JavaScript

The script uses:

```text
node
```

## Java

The script uses:

```text
javac
```

to compile and:

```text
java
```

to execute.

Temporary Java compilation artifacts are placed in a temporary directory and cleaned up afterward.

---

# Troubleshooting

## `Python runtime not found`

Check:

```bash
python --version
```

or:

```bash
python3 --version
```

Make sure Python is installed and available on your `PATH`.

---

## `C++ compiler not found`

Check:

```bash
g++ --version
```

If the compiler is installed elsewhere, set:

```text
CXX
```

Example on Windows PowerShell:

```powershell
$env:CXX="C:\msys64\mingw64\bin\g++.exe"
```

Example on macOS/Linux:

```bash
export CXX=/path/to/g++
```

---

## `Node.js runtime not found`

Check:

```bash
node --version
```

Install Node.js if necessary.

---

## `Java runtime/compiler not found`

Check both:

```bash
java --version
javac --version
```

You need a JDK for compilation.

---

## `psutil is not installed`

Install it:

```bash
python -m pip install psutil
```

or on systems where Python 3 is invoked as `python3`:

```bash
python3 -m pip install psutil
```

---

## `constraints.json not found`

Run:

```bash
python cses.py new <problem_no>
```

The `new` command fetches the CSES metadata and creates `constraints.json`.

---

## `No test ZIP found`

Download the test ZIP from the relevant CSES problem page and put it directly in the problem directory.

---

## `No solutions found`

Create a solution first:

```bash
python cses.py new 1083 --lang python
```

Then run:

```bash
python cses.py run 1083 --lang python
```

---

# Recommended Workflow

A simple workflow is:

### 1. Create the problem

```bash
python cses.py new 1083
```

### 2. Download the tests

Place `tests.zip` inside:

```text
1083. Missing Number/
```

### 3. Solve the problem

Edit:

```text
C++/solution-1.cpp
```

### 4. Run it

```bash
python cses.py run 1083
```

### 5. Try another approach

Run `new` again with the same problem:

```bash
python cses.py new 1083
```

This creates:

```text
C++/solution-2.cpp
```

### 6. Compare approaches

You can keep multiple implementations and select a specific one:

```bash
python cses.py run 1083 1
```

or run the newest one:

```bash
python cses.py run 1083
```

---
