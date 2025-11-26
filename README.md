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
```
### 2. Run 

** Linux / macOS**

 ```bash
./course_management
```

**Windows**

```bash
course_management.exe
```

### 3 Data Files

* The program automatically creates 'courses.dat' on first run.
* All course records are saved to and loaded from this file.
* Exported records will appear in courses.txt when using the export option.

  ---

  ## ** Screenshots**
  *Add course

  *<img width="578" height="448" alt="Screenshot 2025-11-26 103314" src="https://github.com/user-attachments/assets/2b9e48c8-358b-4f03-a602-eb49d92edfd0" />

  *View all courses

  *<img width="801" height="390" alt="Screenshot 2025-11-26 103336" src="https://github.com/user-attachments/assets/a75cf8ad-ce85-48a1-a9e8-ad828cdc455b" />

  *Search by ID

  *<img width="455" height="498" alt="Screenshot 2025-11-26 103402" src="https://github.com/user-attachments/assets/339ef601-689e-4d9f-a15d-87ffda432ba9" />

  *Search by name

  *<img width="573" height="413" alt="Screenshot 2025-11-26 103427" src="https://github.com/user-attachments/assets/f80c45ae-9c97-4277-b503-efb4f2475e27" />

  *Update Course

  *<img width="474" height="632" alt="Screenshot 2025-11-26 103517" src="https://github.com/user-attachments/assets/22d229c4-fbec-4982-8f5e-323dac7374c9" />

  *Delete Course

  *<img width="540" height="387" alt="Screenshot 2025-11-26 103536" src="https://github.com/user-attachments/assets/f0e03b8f-85a4-4a2d-aa34-f4b8a0ddbec5" />

  *Export to text file

  *<img width="443" height="311" alt="Screenshot 2025-11-26 103552" src="https://github.com/user-attachments/assets/887e0f38-8a41-4614-99d3-3925e8ac64f9" />

  *Exit

  *<img width="530" height="291" alt="Screenshot 2025-11-26 103620" src="https://github.com/user-attachments/assets/c7ea4988-a995-492a-b434-95e66edd0810" />

  ## Author ##
  Mahesh Kumar





  



  



  
  
