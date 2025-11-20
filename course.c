#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DATAFILE "courses.dat"
#define TXTEXPORT "courses.txt"
#define NAME_LEN 100
#define FAC_LEN 100

typedef struct {
    int id;
    char name[NAME_LEN];
    char faculty[FAC_LEN];
    int credits;
    int semester;
} Course;

/* Utility: read a line from stdin safely (trim newline) */
void read_line(char *buffer, int size) {
    if (!fgets(buffer, size, stdin)) {
        buffer[0] = '\0';
        return;
    }
    size_t ln = strlen(buffer);
    if (ln && buffer[ln-1] == '\n') buffer[ln-1] = '\0';
}

/* Utility: clear remaining stdin */
void clear_stdin(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* Check if a course ID already exists */
int id_exists(int id) {
    FILE *fp = fopen(DATAFILE, "rb");
    if (!fp) return 0;
    Course c;
    while (fread(&c, sizeof(Course), 1, fp) == 1) {
        if (c.id == id) { fclose(fp); return 1; }
    }
    fclose(fp);
    return 0;
}

/* Add course (with uniqueness check) */
void add_course() {
    Course c;
    printf("\n=== Add Course ===\n");

    printf("Enter Course ID (integer): ");
    if (scanf("%d", &c.id) != 1) { printf("Invalid input.\n"); clear_stdin(); return; }
    clear_stdin();

    if (c.id <= 0) { printf("ID must be positive.\n"); return; }

    if (id_exists(c.id)) {
        printf("Course with ID %d already exists.\n", c.id);
        return;
    }

    printf("Enter Course Name: ");
    read_line(c.name, NAME_LEN);
    if (strlen(c.name) == 0) { printf("Name can't be empty.\n"); return; }

    printf("Enter Faculty Name: ");
    read_line(c.faculty, FAC_LEN);
    if (strlen(c.faculty) == 0) { printf("Faculty can't be empty.\n"); return; }

    printf("Enter Credits (1-10): ");
    if (scanf("%d", &c.credits) != 1) { printf("Invalid input.\n"); clear_stdin(); return; }
    clear_stdin();
    if (c.credits < 1 || c.credits > 10) { printf("Credits must be 1-10.\n"); return; }

    printf("Enter Semester (1-12): ");
    if (scanf("%d", &c.semester) != 1) { printf("Invalid input.\n"); clear_stdin(); return; }
    clear_stdin();
    if (c.semester < 1 || c.semester > 12) { printf("Semester must be 1-12.\n"); return; }

    FILE *fp = fopen(DATAFILE, "ab");
    if (!fp) { perror("Unable to open data file"); return; }
    fwrite(&c, sizeof(Course), 1, fp);
    fclose(fp);

    printf("Course added successfully.\n");
}

/* View all courses in tabular form */
void view_courses() {
    FILE *fp = fopen(DATAFILE, "rb");
    if (!fp) { printf("\nNo courses found (file missing).\n"); return; }

    Course c;
    int count = 0;
    printf("\n=== All Courses ===\n");
    printf("%-6s | %-30s | %-20s | %-7s | %-8s\n", "ID", "Name", "Faculty", "Credits", "Semester");
    printf("-------------------------------------------------------------------------------\n");
    while (fread(&c, sizeof(Course), 1, fp) == 1) {
        printf("%-6d | %-30s | %-20s | %-7d | %-8d\n",
               c.id, c.name, c.faculty, c.credits, c.semester);
        count++;
    }
    if (count == 0) printf("No courses saved yet.\n");
    fclose(fp);
}

/* Search by ID */
void search_by_id() {
    printf("\n=== Search Course by ID ===\n");
    int id;
    printf("Enter Course ID: ");
    if (scanf("%d", &id) != 1) { printf("Invalid input.\n"); clear_stdin(); return; }
    clear_stdin();

    FILE *fp = fopen(DATAFILE, "rb");
    if (!fp) { printf("No courses found.\n"); return; }

    Course c; int found = 0;
    while (fread(&c, sizeof(Course), 1, fp) == 1) {
        if (c.id == id) {
            printf("\nFound:\nID: %d\nName: %s\nFaculty: %s\nCredits: %d\nSemester: %d\n",
                   c.id, c.name, c.faculty, c.credits, c.semester);
            found = 1; break;
        }
    }
    if (!found) printf("Course with ID %d not found.\n", id);
    fclose(fp);
}

/* Case-insensitive substring search helper */
int contains_case_insensitive(const char *hay, const char *needle) {
    if (!hay || !needle) return 0;
    size_t hn = strlen(hay), nn = strlen(needle);
    if (nn == 0) return 1;
    for (size_t i = 0; i + nn <= hn; ++i) {
        int match = 1;
        for (size_t j = 0; j < nn; ++j) {
            if (tolower((unsigned char)hay[i+j]) != tolower((unsigned char)needle[j])) { match = 0; break; }
        }
        if (match) return 1;
    }
    return 0;
}

/* Search by name substring */
void search_by_name() {
    printf("\n=== Search Course by Name ===\n");
    char query[NAME_LEN];
    printf("Enter name or part of name: ");
    read_line(query, NAME_LEN);
    if (strlen(query) == 0) { printf("Empty query.\n"); return; }

    FILE *fp = fopen(DATAFILE, "rb");
    if (!fp) { printf("No courses found.\n"); return; }

    Course c; int found = 0;
    printf("\nMatches:\n");
    while (fread(&c, sizeof(Course), 1, fp) == 1) {
        if (contains_case_insensitive(c.name, query)) {
            printf("ID: %d | Name: %s | Faculty: %s | Credits: %d | Sem: %d\n",
                   c.id, c.name, c.faculty, c.credits, c.semester);
            found = 1;
        }
    }
    if (!found) printf("No matches found for \"%s\".\n", query);
    fclose(fp);
}

/* Update course (by ID) */
void update_course() {
    printf("\n=== Update Course ===\n");
    int id;
    printf("Enter Course ID to update: ");
    if (scanf("%d", &id) != 1) { printf("Invalid input.\n"); clear_stdin(); return; }
    clear_stdin();

    FILE *fp = fopen(DATAFILE, "rb");
    if (!fp) { printf("No courses found.\n"); return; }
    FILE *tmp = fopen("tmp.dat", "wb");
    if (!tmp) { perror("Unable to create temp file"); fclose(fp); return; }

    Course c;
    int found = 0;
    while (fread(&c, sizeof(Course), 1, fp) == 1) {
        if (c.id == id) {
            found = 1;
            printf("\nCurrent details:\nID: %d\nName: %s\nFaculty: %s\nCredits: %d\nSemester: %d\n",
                   c.id, c.name, c.faculty, c.credits, c.semester);

            printf("\nEnter new name (leave blank to keep): ");
            char buf[NAME_LEN]; read_line(buf, NAME_LEN);
            if (strlen(buf) > 0) strncpy(c.name, buf, NAME_LEN);

            printf("Enter new faculty (leave blank to keep): ");
            read_line(buf, FAC_LEN);
            if (strlen(buf) > 0) strncpy(c.faculty, buf, FAC_LEN);

            printf("Enter new credits (0 to keep): ");
            int creds;
            if (scanf("%d", &creds) == 1) {
                if (creds >= 1 && creds <= 10) c.credits = creds;
                else if (creds != 0) printf("Credits out of range; keeping old value.\n");
            } else {
                clear_stdin();
            }
            clear_stdin();

            printf("Enter new semester (0 to keep): ");
            int sem;
            if (scanf("%d", &sem) == 1) {
                if (sem >= 1 && sem <= 12) c.semester = sem;
                else if (sem != 0) printf("Semester out of range; keeping old value.\n");
            } else {
                clear_stdin();
            }
            clear_stdin();

            printf("Course updated.\n");
        }
        fwrite(&c, sizeof(Course), 1, tmp);
    }

    fclose(fp); fclose(tmp);
    if (!found) {
        printf("Course with ID %d not found — no changes made.\n", id);
        remove("tmp.dat");
    } else {
        remove(DATAFILE);
        rename("tmp.dat", DATAFILE);
    }
}

/* Delete course (by ID) */
void delete_course() {
    printf("\n=== Delete Course ===\n");
    int id;
    printf("Enter Course ID to delete: ");
    if (scanf("%d", &id) != 1) { printf("Invalid input.\n"); clear_stdin(); return; }
    clear_stdin();

    FILE *fp = fopen(DATAFILE, "rb");
    if (!fp) { printf("No courses found.\n"); return; }
    FILE *tmp = fopen("tmp.dat", "wb");
    if (!tmp) { perror("Unable to create temp file"); fclose(fp); return; }

    Course c;
    int found = 0;
    while (fread(&c, sizeof(Course), 1, fp) == 1) {
        if (c.id == id) {
            found = 1;
            printf("Deleting course ID %d (%s).\n", c.id, c.name);
            continue; /* skip writing this one */
        }
        fwrite(&c, sizeof(Course), 1, tmp);
    }

    fclose(fp); fclose(tmp);
    if (!found) {
        printf("Course with ID %d not found — no deletion.\n", id);
        remove("tmp.dat");
    } else {
        remove(DATAFILE);
        rename("tmp.dat", DATAFILE);
        printf("Course deleted successfully.\n");
    }
}

/* Export data to human-readable text file */
void export_to_text() {
    FILE *fp = fopen(DATAFILE, "rb");
    if (!fp) { printf("No courses to export.\n"); return; }
    FILE *out = fopen(TXTEXPORT, "w");
    if (!out) { perror("Unable to open export file"); fclose(fp); return; }

    Course c;
    fprintf(out, "ID,Name,Faculty,Credits,Semester\n");
    while (fread(&c, sizeof(Course), 1, fp) == 1) {
        fprintf(out, "%d,%s,%s,%d,%d\n", c.id, c.name, c.faculty, c.credits, c.semester);
    }
    fclose(fp); fclose(out);
    printf("Exported courses to %s\n", TXTEXPORT);
}

/* Simple header UI */
void header() {
    printf("\n==============================================\n");
    printf("      Advanced Course Management System\n");
    printf("==============================================\n");
}

/* Menu loop */
void menu() {
    int choice;
    while (1) {
        header();
        printf("1. Add Course\n");
        printf("2. View All Courses\n");
        printf("3. Search by ID\n");
        printf("4. Search by Name\n");
        printf("5. Update Course\n");
        printf("6. Delete Course\n");
        printf("7. Export to text file\n");
        printf("8. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Try again.\n");
            clear_stdin();
            continue;
        }
        clear_stdin();

        switch (choice) {
            case 1: add_course(); break;
            case 2: view_courses(); break;
            case 3: search_by_id(); break;
            case 4: search_by_name(); break;
            case 5: update_course(); break;
            case 6: delete_course(); break;
            case 7: export_to_text(); break;
            case 8: printf("Goodbye.\n"); exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
        printf("\nPress Enter to continue...");
        getchar();
    }
}

int main(void) {
    menu();
    return 0;

}
