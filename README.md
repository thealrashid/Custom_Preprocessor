# Custom Preprocessor
The Custom C Preprocessor is a tool designed to preprocess C source files by including header files, removing comments, and replacing macros. This program replaces the preprocessing stage in the compilation process and creates a .i file from the .c file.
## Features
* **Header File Inclusion:** Includes the specified built-in and user defined header files.
* **Comment Removal:** Removes single line and multi line comments.
* **Macro Replacement:** Replaces macro definitions with their corresponding values.
* **Parsing Ignored Text:** Ignores any directives or macros specified within double quotes.
## Usage
To use the Custom C Preprocessor, follow these steps:
1. **Compilation:** Use the provided Makefile to compile the preprocessor source code:

   ```bash
   make
2. **Execution:** Run the compiled executable, providing the path to the C source file as a command-line argument:

   ```bash
   ./exe p.c
3. **Compilation Stages:** Compile the .i file through the rest of the compilation stages:

   ```bash
   cc -S p.i -o p.s
   cc -c p.s -o p.o
   cc p.o
4. **Run Executable File:** Run the executable file to get the desired output of the C program.

   ```bash
   ./a.out
