# Course Management System
# Abstract
The Course Management System is a simple, terminal based application developed in C for managing academic course records efficiently. The system provides core functionalities including adding new course details, searching for courses by ID or name, updating existing records, and deleting entries when necessary. All course information is stored persistently in a binary .dat file, ensuring data remains available across multiple sessions. Designed for ease of use, the program offers a menu-driven interface suitable for learning basic C concepts and for managing a small course catalog. The project clearly demonstrates fundamental concepts of file handling, data structures, and control flow in C
📌 Features
✔ Add Course

Validates unique course IDs

Ensures valid numeric ranges for credits and semesters

✔ View All Courses

Displays data in a clean table format

Reads from the persistent binary data file

✔ Search

Search by ID

Search by Name (case-insensitive substring)

✔ Update Course

Update selected fields while keeping others unchanged

Safe modification using a temporary file

✔ Delete Course

Remove a course by ID

Rewrites file excluding the deleted record

✔ Export to Text

Outputs all courses as a CSV-compatible courses.txt
