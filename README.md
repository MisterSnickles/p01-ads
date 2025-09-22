**Project Description**

In this project, we work with a record object that includes a first name, last name, and an ID. We import these records from input files and manage them using a linked list. By implementing operations such as searching, inserting, and validating records, we gain practical experience in handling dynamic data structures and organizing complex information efficiently. This approach helps us understand how to structure and manipulate linked lists to support real-world data management tasks.

**Operating System**

This project is designed for a Linux terminal, but the code is portable to other operating systems with a compatible C++ compiler.

**Compilation**

Please ensure that you are using a Linux shell terminal (you can install on windows VSCode), the make command uses the **rm** command instead of **del**.

Open a terminal in the Code directory and run: **make**

This will compile the program using the provided makefile. Alternatively, you can compile manually with: **g++ main.cpp utility.cpp -o p01.exe**

**Execute Program**
After compiling, run the executable from the Code directory: **./p01.exe**

or on Windows: **p01.exe**

**Usage Instructions**

When project is running, there will be a menu containing 4 options:'

1: Import List from File

When selecting this option, please import included files data.txt or people.txt for manual testing.

2: Display List

This option simply displays the imported list. In this program, it displays person record objects appearing as:

---

  Last Name

  First Name

  ID

---

3: Search List

This option allows the user to search the list of people by entering a first and last name or by ID. Make sure to display the list first so you can test the search functionality properly. The search functionality supports fuzzy and case-insensitive searching, meaning if you type an incomplete first or last name (e.g Jonath MaBeRY --> Found 1 Match: (Jonathan Mabery ID: 123)) it will auto-correct your search. It isn't full proof, but will protect against minor spelling and capitalization errors.

x. Exit

This option exits the program

*Alternatively, if you want to simulate the input for automatic testing, please input this command into the terminal: **./p01.exe > input_simulate.txt***


**Code Comments for Clarity**

The source code (main.cpp, utility.cpp, List.h, utility.h) contains comments explaining the logic, data structures, and functions. Review these comments for a better understanding of how the linked list and record management are implemented.
