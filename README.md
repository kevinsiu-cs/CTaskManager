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

**Potential Features:**

1. Including an removeTask / editTask function for the gantt chart.
2. Saving / Loading Team + Task info from a file and then creating a gantt chart from that.
3. writing a script to launch the program.

# Installation Guide

**Ensure that the following is installed:**
* C Compiler: **GCC** (Linux/Windows via MinGW) or **Clang** (macOS)
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

# Usage Notes:

* The intitial lines for the formatting of the taskName is Hardcoded and will break if recieving a taskName larger than I believe 24 characters, give or take +- 2
* Right now, the member name is limited to 50 characters as it's defined with a space of 50



# Reflections & Growth:

This refactor allowed me to look back at my early programming habits and apply the lessions I've learnt since my first year. Although the code I've written for this project isn't exactly the cleanest code, but it's a massive improvement from what I've written in first year.

* While the original project worked, looking back I noticed we had a lot of constants being re-declared in different places instead of being defined once and shared. For this refactor, I made sure to clean that up by reusing constants across the files properly. I also spent time clearing up our original confusion around header and source file conventions, I've now organized the imports and includes to follow standard C practices, making the whole project feel much more professional and structured.
  
* Looking back at this project alongside my current Software Engineering module, I’ve realized just how much "future-proofing" matters. It's not only about making code that is functional, but ensuring that the code is readable, especially for future teamates and even myself. I was actually quite shook with what I thought was good work around this time last year.
  
* I’ve focused on breaking the logic into proper sections and clear function calls so the structure actually makes sense at a glance. I’ve also changed how I handle Git, instead of just dumping implementation details into a commit, I now try to keep my messages standardized so they clearly explain what changed and why, making the project history a lot easier to follow.

* I've also noticed a massive flaw alongside the original gantt chart assigment, where the program starts the same way, with asking the user if they want to see an example of a gantt chart. Once given an input, the program will immediately jump into asking, how many tasks? and then running a loop gathering the info needed, until we reach the amount of tasks given by the user.

* I found that this program was quite infuriating to use as it was quite linear with how inputs were handled. You wouldn't be able to exit after entering 3 tasks and then continue adding tasks. This is why I actually decided to modify the tasks into a linked-list based storage as now we are able to store as many tasks as we want, along with Team Members (I've limited it to 10 team Members for simplicity). However I am still not quite sure on what a good limit would be, and I don't think it would be a good idea to leave that up to the user, Which is why I decided on the cap of 10.

* Working on this has also given me a much deeper appreciation for both C and Java. Writing in a low-level language like C has definitely sharpened my understanding of how things work under the hood, but it also made me realize how much I value the standardization of Java. Seeing the contrast between managing everything manually in C versus having those robust, built-in tools and imports in Java has really improved my overall perspective as a programmer.



