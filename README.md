# CTaskManager
Terminal-Based C Task Manager: Merging of two University projects showcasing Gantt charts and per-person task assignments using Linked Lists.

# Project Background & Purpose:

This program is a comprehensive refactoring and consolidation of two collaborative projects completed during my first year at University College Dublin (UCD).

While the original projects served as an introduction to team-based C programming, I felt that our knowledge of Git/GitHub was lacking. The goal of revisiting the projects, was mainly to be able to apply more advanced software engineering principles. Including:

* Writing Clean Code: Refactoring messy legacy code into cleaner, more readable and maintainable C code.
* Proper Documentation: Implementing a proper CMake build, clear installation instructions alongside structured ReadMe file
* Better Control Flow for User: Ensured that userInput is correct with more defined and clear functionality.

# Features
**Upon launch, the program will prompt the user if they would like to see a example of a gantt chart.**


After the initial answer, the user will then be prompted with a menu with the following functions:
1. Add a Team Member:
2. Remove a Team Member:
3. Add and Set a task:
4. Show Current Gantt Chart: -> To-Be-Implemented as of 27/03/2026
5. Show Team Member and Tasks:
6. Exit


# Installation Guide

**Ensure that the following is installed:**
* C Compiler: GCC (Linux/Windows via MinGW) or Clang(macOS)
* CMake: Version 3.20 or higher
* Git: To clone the repository

**Step 1: Setup + Compilation**

Open the terminal (Command Prompt / Powershell on Windows), (Bash on Linux/MacOS) and run:

**Clone the Repository:**

* git clone https://github.com/kevinsiu-cs/CTaskManager.git 

**Go to CTaskManager folder (may be type sensitive on Linux):**

* cd CTaskManager

**Build and compile the project:**
* cmake -S . -B build
* cmake --build build 

**Step 2: Run the Program**
Depending on your operating system used and ensuring that you are in the correct folder:

**Linux** 
* ./build/ctaskmanager

**Windows**
* .\build\Debug\ctaskmanager.exe








