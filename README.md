# 🐚 `mysh` — A Custom Unix Shell in C

`mysh` is a simple custom-built Unix-like shell written in C. It supports basic command execution, piping, input/output redirection, and a couple of built-in commands like `cd` and `exit`. The goal of this project was to get hands-on experience with low-level system programming and understand how shells work under the hood.

---

## ✨ Features

- **Command Execution**
  - Supports basic Unix commands like `ls`, `echo`, `cat`, `pwd`, etc.
  - Example: `echo Hello World`, `ls -l`, `cat file.txt`

- **Pipes (`|`)**
  - Chain commands using pipes
  - Example: `ls | grep .c | wc -l`

- **Input/Output Redirection**
  - Input: `cat < input.txt`
  - Output: `echo Hello > output.txt`
  - Combined: `cat < input.txt | tr a-z A-Z > output.txt`

- **Built-in Commands**
  - `cd <dir>`: Change the current working directory
  - `exit`: Exit the shell

- **Memory Safe**
  - Verified using Valgrind — no memory leaks 🎉

---

## 📁 Project Structure

```
mysh/
├── Makefile           # Build script
├── README.md          # This file
├── mysh               # Compiled shell binary
├── include/
│   ├── parser.h       # Header for parsing logic
│   └── executor.h     # Header for execution logic
├── src/
│   ├── main.c         # Entry point with REPL loop
│   ├── parser.c       # Tokenizer and parser
│   └── executor.c     # Handles execution, piping, redirection
```

---

## 🛠️ How to Build & Run

1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/mysh.git
   cd mysh
   ```

2. Build the project using `make`:
   ```bash
   make
   ```

3. Run the shell:
   ```bash
   ./mysh
   ```

---

## ▶️ Sample Usage

```bash
echo hello
ls | wc -l
echo "data" > test.txt
cat < test.txt | tr a-z A-Z > out.txt
cat out.txt
cd ..
pwd
exit
```

---

## 🧪 Testing & Debugging

To check for memory leaks and runtime errors, use:

```bash
valgrind ./mysh
```

---

## ⚠️ Known Limitations

- Built-in commands like `cd` and `exit` cannot be used in pipes (e.g., `cd | ls` won't work).
- No support for background jobs (`&`) or advanced scripting.
- Lacks signal handling (e.g., `Ctrl+C`) and command history.

---

## 🚀 Possible Future Improvements

- Background process support
- Command history
- Auto-completion
- Environment variable expansion

---

## 👤 Author

**Aman Yadav**
