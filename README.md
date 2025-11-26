# 🎓 COURSE MANAGEMENT SYSTEM (C Programming)

## 📄 ABSTRACT
The **Course Management System** is a terminal-based application written in **C** that allows users to manage academic course records efficiently. It provides core functionalities such as adding courses, viewing all courses, searching by ID or name, updating course details, deleting records, and exporting data to a text file.

All course information is stored persistently in a binary file (`courses.dat`), ensuring data is preserved across program runs.

This project demonstrates essential C programming concepts including **structures, file handling, loops, conditionals, binary storage, modular programming, and menu-driven interfaces**. It is ideal for beginners, academic mini-projects, and learning file handling in C.

---

## ✨ FEATURES

### 🔧 Core Functionalities
➕ **Add New Course**  
(ID, Name, Faculty, Credits, Semester)

📋 **Display All Courses**  
Shown in a clean, formatted table

🔍 **Search Course**  
- Search by **Course ID**  
- Search by **Name (case-insensitive)**

✏️ **Update Course Information**  
Modify selected fields while keeping others unchanged

❌ **Delete Course**  
Uses safe temp-file handling

📤 **Export to Text File**  
Outputs all records to `courses.txt` in CSV format

💾 **Persistent Binary Storage**  
Stored in `courses.dat` for fast and efficient data handling

🖥️ **Menu-driven CLI interface**

⚙️ **Automatic File Creation**

⚠️ **Input Validation & Error Handling**

---

## 🛠️ TECHNICAL REQUIREMENTS

### 🖥️ System Requirements
- Windows / Linux / macOS  
- Terminal or Command Prompt  
- At least 4 MB RAM  
- Minimal disk space for `courses.dat`

### 💻 Software Requirements
- C Compiler: **GCC / Clang / MSVC / MinGW**
- Code Editor / IDE: **VS Code, Dev-C++, Code::Blocks, CLion**, etc.
- Optional: `make` utility

### 🔣 Programming Requirements
Language: **C**  
Standard: **C89 / C99 / C11**  
Required Headers:
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <ctype.h>

 ### 4. File Handling Requirements
- Read/write access to working directory
- Course records stored in binary `.dat` file
- Program auto-creates `courses.dat` when missing

### 5. Compilation Requirements
- Must compile without errors
- Recommended flag: `-Wall`

---

## Functional Requirements

### 1. User Interface
- Fully terminal-based
- Clear menu options
- Validates user input

### 2. Course Record Operations
- **Add Course:** Save new course details
- **Search Course:** By ID or name
- **View Courses:** Display all saved records
- **Update Course:** Modify existing details
- **Delete Course:** Remove course from database
- **Export Courses:** Save readable `.txt` file

### 3. Data Management
- All information stored in `courses.dat`
- Data persists across multiple sessions
- Smooth handling of missing or new files

### 4. Program Flow
- Menu-driven loop until user selects Exit
- Displays confirmations and error messages
- Easy navigation between operations

---

## How to Run the Program

### 1. Compile the Program
Open your terminal in the project directory and run:

```bash
gcc course_management.c -o course_management

2. Run the Executable
On Linux/macOS:
./course_management

On Windows:
course_management.exe

Data File

The program automatically creates courses.dat on first run.

All course records are saved to and loaded from this file.

Exported records will appear in courses.txt when using the export option.

Notes

Ensure the executable has permission to read/write files in the directory.

Running with -Wall is recommended to see potential warnings.
