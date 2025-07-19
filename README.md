

## ✅ **Project Summary: Custom Unix Shell (`mysh`)**

built a mini shell in C that mimics basic functionalities of Unix-like shells. This shell supports:

### 🔧 Core Features

* **Command Execution**: Run basic commands like `ls`, `echo`, `cat`, `pwd`, etc.
* **Pipes (`|`)**: Commands can be chained using pipes (`ls | wc -l`).
* **I/O Redirection**:

  * Input redirection with `<` (e.g., `cat < file.txt`)
  * Output redirection with `>` (e.g., `echo "hi" > file.txt`)
* **Built-in Commands**:

  * `cd`: Changes the current working directory.
  * `exit`: Exits the shell.
* **Memory Safe**: Verified using Valgrind to ensure there are no memory leaks.

---

## 📝 `README.md`

```markdown
# mysh – Custom Unix Shell in C

`mysh` is a lightweight, custom-built Unix shell implemented in C. It supports essential shell functionalities like executing commands, piping, input/output redirection, and basic built-in commands like `cd` and `exit`.

---

## Features

- ✅ **Basic command execution**
  - Example: `ls`, `pwd`, `echo hello`

- ✅ **Pipe support**
  - Example: `ls | grep .c | wc -l`

- ✅ **Input/Output Redirection**
  - Input: `cat < file.txt`
  - Output: `echo hello > out.txt`
  - Combined: `cat < file.txt | tr a-z A-Z > out.txt`

- ✅ **Built-in commands**
  - `cd [dir]`: Change directory
  - `exit`: Exit the shell

- ✅ **Memory Safety**
  - Verified with Valgrind for zero memory leaks.

---

## Project Structure

```

mysh/
├── Makefile           # Build script
├── README.md          # Project documentation
├── mysh               # Compiled shell binary
├── include/
│   ├── parser.h       # Header for command parsing
│   └── executor.h     # Header for executing parsed commands
├── src/
│   ├── main.c         # Entry point with REPL loop
│   ├── parser.c       # Tokenizes and parses commands
│   └── executor.c     # Executes commands, handles pipes/redirection

````

---

## Build Instructions

1. Clone or download the project.
2. Compile using the provided Makefile:

```bash
make
````

3. Run the shell:

```bash
./mysh
```

---

## Sample Usage

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

## Testing and Debugging

### Run with Valgrind:

To verify memory safety:

```bash
valgrind ./mysh
```

---

## Limitations

* Built-in commands cannot be piped (`cd | ls` won't work).
* No support for background jobs (`&`) or advanced scripting features.
* No signal handling or command history yet.

---

## Future Improvements

* Support for background processes
* Command history
* Auto-completion
* Environment variable expansion

---

## Author

👤 [Aman Yadav](https://github.com/amany4864)

---


```
