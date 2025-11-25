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

