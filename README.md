# Course Management System
# Abstract
The Course Management System is a simple, terminal based application developed in C for managing academic course records efficiently. The system provides core functionalities including adding new course details, searching for courses by ID or name, updating existing records, and deleting entries when necessary. All course information is stored persistently in a binary .dat file, ensuring data remains available across multiple sessions. Designed for ease of use, the program offers a menu-driven interface suitable for learning basic C concepts and for managing a small course catalog. The project clearly demonstrates fundamental concepts of file handling, data structures, and control flow in C
# Features of the Program
                 
**Add New Courses:** Record details including unique ID, Name, Faculty, Credits (1-10), and Semester (1-12).

**Unique ID Validation:** Prevents adding a course if its ID already exists.

**View All Courses:** Display all stored course records in a clean, tabular format.

**Search Functionality:** Find records by Course ID or by case-insensitive substring match of the course name.

**Update Records:** Modify name, faculty, credits, or semester of existing courses.

**Delete Entries:** Remove course records from the database.

**Data Export:** Generates a human-readable, comma-separated text file (courses.txt).

**Persistent Data Storage:** Uses a binary .dat file (courses.dat) to save data.

**Fully Terminal-Based (CLI):** Interface operates entirely through the command line.

**Robust File Handling:** Uses temporary files for safe update/delete operations and creates the data file if missing.

**Input Handling:** Includes utilities (read_line, clear_stdin) and input validation for robustness.
