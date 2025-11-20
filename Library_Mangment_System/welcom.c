#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOOKS_FILE "library_book.txt"
#define USERS_FILE "users.txt"
#define ISSUES_FILE "issues.txt"
#define TEMP_FILE  "temp.txt"

struct Book { 
    int id; char title[100]; char author[100]; 
    int totalCopies; int issuedCopies; 
};

struct IssueRecord { char username[50]; int bookid; 
    int count; };
struct User { char username[50]; char password[50]; 
    char role[10]; };

void trim_newline(char *s) { s[strcspn(s, "\n")] = 0; }
void spaces_to_underscores(char *s) { for (int i = 0; s[i]!='\0'; ++i) if (s[i] == ' ') s[i] = '_'; }
void underscores_to_spaces(char *s) { for (int i = 0; s[i]!='\0'; ++i) if (s[i] == '_') s[i] = ' '; }

int find_user(const char *username, struct User *out) {
    FILE *fp = fopen(USERS_FILE, "r");
    if (!fp) return 0;
    struct User u;
    while (fscanf(fp, "%49s %49s %9s", u.username, u.password, u.role) == 3) {
        if (strcmp(u.username, username) == 0) {
            if (out) *out = u;
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

int authenticate(const char *username, const char *password, char *outRole) {
    struct User u;
   if (find_user(username, &u) && strcmp(u.password, password) == 0) 
   {    if (outRole) {strcpy(outRole, u.role);}
        return 1;}
    return 0;
}

int change_password_flow(const char *currentUser, int isAdmin) {
    char targetUser[50];
    if (isAdmin) {
        printf("Enter username whose password to change: ");
        if (!fgets(targetUser, sizeof(targetUser), stdin)) return 0;
        trim_newline(targetUser);
    } else {
        strcpy(targetUser, currentUser);
    }

    struct User u;
    if (!find_user(targetUser, &u)) {
        printf("User not found.\n");
        return 0;
    }

    char oldpass[50], newpass[50], confirm[50];
    if (!isAdmin) {
        printf("Enter current password: ");
        if (!fgets(oldpass, sizeof(oldpass), stdin)) return 0;
        trim_newline(oldpass);
        if (strcmp(oldpass, u.password) != 0) {
            printf("Current password incorrect.\n");
            return 0;
        }
    }

    printf("Enter new password: ");
    if (!fgets(newpass, sizeof(newpass), stdin)) return 0;
    trim_newline(newpass);

    printf("Confirm new password: ");
    if (!fgets(confirm, sizeof(confirm), stdin)) return 0;
    trim_newline(confirm);

    if (strcmp(newpass, confirm) != 0) {
        printf("Passwords do not match.\n");
        return 0;
    }

    FILE *fp = fopen(USERS_FILE, "r");
    FILE *temp = fopen(TEMP_FILE, "w");
    if (!fp || !temp) {
        if (fp) fclose(fp);
        if (temp) fclose(temp);
        printf("Error opening user files.\n");
        return 0;
    }

    struct User uu;
    int changed = 0;

    while (fscanf(fp, "%49s %49s %9s", uu.username, uu.password, uu.role) == 3) {
        if (strcmp(uu.username, targetUser) == 0) {
            fprintf(temp, "%s %s %s\n", uu.username, newpass, uu.role);
            changed = 1;
        } else {
            fprintf(temp, "%s %s %s\n", uu.username, uu.password, uu.role);
        }
    }

    fclose(fp);
    fclose(temp);

    remove(USERS_FILE);
    rename(TEMP_FILE, USERS_FILE);

    if (changed) {
        printf("Password changed successfully for user '%s'.\n", targetUser);
        return 1;
    }

    printf("Failed to change password.\n");
    return 0;
}

int append_book_to_file(struct Book *b) {
    FILE *fp = fopen(BOOKS_FILE, "a");
    if (!fp) return 0;
    fprintf(fp, "%d %s %s %d %d\n", b->id, b->title, b->author, b->totalCopies, b->issuedCopies);
    fclose(fp);
    return 1;
}

int read_all_books(struct Book **outArr, int *outCount) {
    FILE *fp = fopen(BOOKS_FILE, "r");
    if (!fp) { *outArr = NULL; *outCount = 0; return 0; }

    struct Book *arr = NULL;
    int cap = 0, n = 0;
    struct Book b;

    while (fscanf(fp, "%d %99s %99s %d %d",
                  &b.id, b.title, b.author, &b.totalCopies, &b.issuedCopies) == 5) {
        if (n >= cap) {
            int newcap = cap == 0 ? 8 : cap * 2;
            struct Book *tmp = realloc(arr, newcap * sizeof(struct Book));
            if (!tmp) { free(arr); fclose(fp); return 0; }
            arr = tmp;
            cap = newcap;
        }
        arr[n++] = b;
    }

    fclose(fp);
    *outArr = arr;
    *outCount = n;
    return n;
}

int write_all_books(struct Book *arr, int count) {
    FILE *fp = fopen(BOOKS_FILE, "w");
    if (!fp) return 0;

    for (int i = 0; i < count; ++i)
        fprintf(fp, "%d %s %s %d %d\n",
                arr[i].id, arr[i].title, arr[i].author,
                arr[i].totalCopies, arr[i].issuedCopies);

    fclose(fp);
    return 1;
}

int find_book_by_id(int id, struct Book *outBook) {
    FILE *fp = fopen(BOOKS_FILE, "r");
    if (!fp) return 0;

    struct Book b;

    while (fscanf(fp, "%d %99s %99s %d %d",
                  &b.id, b.title, b.author, &b.totalCopies, &b.issuedCopies) == 5) {
        if (b.id == id) {
            if (outBook) *outBook = b;
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

int find_book_by_name_author(const char *name, const char *author, struct Book *outBook) {
    FILE *fp = fopen(BOOKS_FILE, "r");
    if (!fp) return 0;

    struct Book b;

    while (fscanf(fp, "%d %99s %99s %d %d",
                  &b.id, b.title, b.author, &b.totalCopies, &b.issuedCopies) == 5) {
        if (strcmp(b.title, name) == 0 &&
            strcmp(b.author, author) == 0) {
            if (outBook) *outBook = b;
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

int update_book_by_id(int id, struct Book *newBook) {
    struct Book *arr = NULL;
    int n = 0;

    if (!read_all_books(&arr, &n)) return 0;

    int found = 0;
    for (int i = 0; i < n; ++i)
        if (arr[i].id == id) {
            arr[i] = *newBook;
            found = 1;
            break;
        }

    if (found) write_all_books(arr, n);

    free(arr);
    return found;
}

int delete_book_by_id_if_allowed(int id) {
    struct Book *arr = NULL;
    int n = 0;

    if (!read_all_books(&arr, &n)) return 0;

    int found = 0;
    int newn = 0;

    for (int i = 0; i < n; ++i) {
        if (arr[i].id == id) {
            found = 1;
            if (arr[i].issuedCopies > 0) {
                free(arr);
                return -1;
            }
            continue;
        }
        arr[newn++] = arr[i];
    }

    if (!found) { free(arr); return 0; }

    write_all_books(arr, newn);
    free(arr);
    return 1;
}

int delete_book_by_name_author_if_allowed(const char *name, const char *author) {
    struct Book *arr = NULL;
    int n = 0;

    if (!read_all_books(&arr, &n)) return 0;

    int found = 0;
    int newn = 0;

    for (int i = 0; i < n; ++i) {
        if (strcmp(arr[i].title, name) == 0 &&
            strcmp(arr[i].author, author) == 0) {
            found = 1;
            if (arr[i].issuedCopies > 0) {
                free(arr);
                return -1;
            }
            continue;
        }
        arr[newn++] = arr[i];
    }

    if (!found) { free(arr); return 0; }

    write_all_books(arr, newn);
    free(arr);
    return 1;
}

int read_all_issues(struct IssueRecord **outArr, int *outCount) {
    FILE *fp = fopen(ISSUES_FILE, "r");
    if (!fp) { *outArr = NULL; *outCount = 0; return 0; }

    struct IssueRecord *arr = NULL;
    int n = 0, cap = 0;

    struct IssueRecord ir;

    while (fscanf(fp, "%49s %d %d",
                  ir.username, &ir.bookid, &ir.count) == 3) {
        if (n >= cap) {
            int newcap = cap == 0 ? 8 : cap * 2;
            struct IssueRecord *tmp =
                realloc(arr, newcap * sizeof(struct IssueRecord));
            if (!tmp) { free(arr); fclose(fp); return 0; }
            arr = tmp;
            cap = newcap;
        }
        arr[n++] = ir;
    }

    fclose(fp);

    *outArr = arr;
    *outCount = n;
    return n;
}

int write_all_issues(struct IssueRecord *arr, int count) {
    FILE *fp = fopen(ISSUES_FILE, "w");
    if (!fp) return 0;

    for (int i = 0; i < count; ++i)
        fprintf(fp, "%s %d %d\n",
                arr[i].username, arr[i].bookid, arr[i].count);

    fclose(fp);
    return 1;
}

int get_user_issue_count(const char *username, int bookid) {
    struct IssueRecord *arr = NULL;
    int n = 0;

    read_all_issues(&arr, &n);

    int found = 0;
    for (int i = 0; i < n; ++i)
        if (strcmp(arr[i].username, username) == 0 &&
            arr[i].bookid == bookid) {
            found = arr[i].count;
            break;
        }

    free(arr);
    return found;
}

int update_user_issue_record(const char *username, int bookid, int delta) {
    struct IssueRecord *arr = NULL;
    int n = 0;

    read_all_issues(&arr, &n);

    int idx = -1;

    for (int i = 0; i < n; ++i)
        if (strcmp(arr[i].username, username) == 0 &&
            arr[i].bookid == bookid) {
            idx = i;
            break;
        }

    if (idx == -1) {
        if (delta > 0) {
            struct IssueRecord *tmp =
                realloc(arr, (n + 1) * sizeof(struct IssueRecord));
            if (!tmp) {
                free(arr);
                return 0;
            }
            arr = tmp;
            strcpy(arr[n].username, username);
            arr[n].bookid = bookid;
            arr[n].count = delta;
            n++;
            int ok = write_all_issues(arr, n);
            free(arr);
            return ok;
        }
        free(arr);
        return 0;
    }

    int newcount = arr[idx].count + delta;

    if (newcount < 0) {
        free(arr);
        return 0;
    }

    if (newcount == 0) {
        for (int i = idx; i < n - 1; ++i)
            arr[i] = arr[i + 1];
        n--;
        if (n == 0) {
            free(arr);
            remove(ISSUES_FILE);
            return 1;
        }
        int ok = write_all_issues(arr, n);
        free(arr);
        return ok;
    }

    arr[idx].count = newcount;
    int ok = write_all_issues(arr, n);
    free(arr);
    return ok;
}

void addBook_flow() {
    struct Book b;

    printf("\nEnter Book ID: ");
    if (scanf("%d", &b.id) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    while (getchar() != '\n')
        ;

    printf("Enter Book Title: ");
    if (!fgets(b.title, sizeof(b.title), stdin)) return;
    trim_newline(b.title);

    printf("Enter Author Name: ");
    if (!fgets(b.author, sizeof(b.author), stdin)) return;
    trim_newline(b.author);

    printf("Enter total number of copies: ");
    if (scanf("%d", &b.totalCopies) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    while (getchar() != '\n')
        ;

    b.issuedCopies = 0;

    spaces_to_underscores(b.title);
    spaces_to_underscores(b.author);

    struct Book existing;
    if (find_book_by_id(b.id, &existing)) {
        printf("Book ID already exists.\n");
        return;
    }

    if (append_book_to_file(&b))
        printf("Book added successfully.\n");
    else
        printf("Error adding book.\n");
}

void displayBooks_flow() {
    struct Book *arr = NULL;
    int n = 0;

    if (!read_all_books(&arr, &n) || n == 0) {
        printf("\nNo records to display.\n");
        free(arr);
        return;
    }

    printf("\n--- ALL BOOK RECORDS ---\n");

    for (int i = 0; i < n; ++i) {
        struct Book b = arr[i];

        underscores_to_spaces(b.title);
        underscores_to_spaces(b.author);

        int available = b.totalCopies - b.issuedCopies;

        printf(
            "\nID: %d\nTitle: %s\nAuthor: %s\nTotal Copies: %d\nIssued Copies: %d\nAvailable: %d\n",
            b.id, b.title, b.author, b.totalCopies, b.issuedCopies, available);
    }

    free(arr);
}

void searchBook_flow() {
    int choice;
    struct Book b;
    int found = 0;
    char name[100], auth[100];

    printf("\nSearch by:\n1. Name and Author\n2. Book ID\nEnter choice: ");

    if (scanf("%d", &choice) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    while (getchar() != '\n')
        ;

    if (choice == 1) {
        printf("Enter Book Name: ");
        if (!fgets(name, sizeof(name), stdin)) return;
        trim_newline(name);

        printf("Enter Author Name: ");
        if (!fgets(auth, sizeof(auth), stdin)) return;
        trim_newline(auth);

        spaces_to_underscores(name);
        spaces_to_underscores(auth);

        if (find_book_by_name_author(name, auth, &b)) {
            underscores_to_spaces(b.title);
            underscores_to_spaces(b.author);

            int available = b.totalCopies - b.issuedCopies;

            printf(
                "\nBook Found!\nID: %d\nTitle: %s\nAuthor: %s\nTotal: %d\nIssued: %d\nAvailable: %d\n",
                b.id, b.title, b.author, b.totalCopies, b.issuedCopies, available);

            found = 1;
        }
    } else if (choice == 2) {
        int id;

        printf("Enter Book ID: ");
        if (scanf("%d", &id) != 1) {
            printf("Invalid input.\n");
            while (getchar() != '\n')
                ;
            return;
        }

        if (find_book_by_id(id, &b)) {
            underscores_to_spaces(b.title);
            underscores_to_spaces(b.author);

            int available = b.totalCopies - b.issuedCopies;

            printf(
                "\nBook Found!\nID: %d\nTitle: %s\nAuthor: %s\nTotal: %d\nIssued: %d\nAvailable: %d\n",
                b.id, b.title, b.author, b.totalCopies, b.issuedCopies, available);

            found = 1;
        }
    } else {
        printf("Invalid choice.\n");
        return;
    }

    if (!found) printf("Book not found.\n");
}

int find_id_by_name_author(const char *name, const char *author, int *outId) {
    struct Book b;
    if (find_book_by_name_author(name, author, &b)) {
        if (outId) *outId = b.id;
        return 1;
    }
    return 0;
}

void issueBook_flow(const char *currentUser) {
    int choice;
    printf("\nIssue by:\n1. Name + Author\n2. Book ID\nEnter choice: ");

    if (scanf("%d", &choice) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    while (getchar() != '\n')
        ;

    int bookid = -1;
    char name[100], auth[100];

    if (choice == 1) {
        printf("Enter Book Name: ");
        if (!fgets(name, sizeof(name), stdin)) return;
        trim_newline(name);

        printf("Enter Author Name: ");
        if (!fgets(auth, sizeof(auth), stdin)) return;
        trim_newline(auth);

        spaces_to_underscores(name);
        spaces_to_underscores(auth);

        if (!find_id_by_name_author(name, auth, &bookid)) {
            printf("Book not found.\n");
            return;
        }
    } else if (choice == 2) {
        printf("Enter Book ID: ");
        if (scanf("%d", &bookid) != 1) {
            printf("Invalid input.\n");
            while (getchar() != '\n')
                ;
            return;
        }
        while (getchar() != '\n')
            ;

        struct Book tmp;
        if (!find_book_by_id(bookid, &tmp)) {
            printf("Book not found.\n");
            return;
        }
    } else {
        printf("Invalid choice.\n");
        return;
    }

    struct Book *arr = NULL;
    int n = 0;

    if (!read_all_books(&arr, &n)) {
        printf("No books available.\n");
        return;
    }

    int idx = -1;

    for (int i = 0; i < n; ++i)
        if (arr[i].id == bookid) {
            idx = i;
            break;
        }

    if (idx == -1) {
        printf("Book not found.\n");
        free(arr);
        return;
    }

    int available = arr[idx].totalCopies - arr[idx].issuedCopies;

    if (available <= 0) {
        printf("No copies available.\n");
        free(arr);
        return;
    }

    arr[idx].issuedCopies++;

    write_all_books(arr, n);
    free(arr);

    if (!update_user_issue_record(currentUser, bookid, 1)) {
        struct Book tmp;
        if (find_book_by_id(bookid, &tmp)) {
            tmp.issuedCopies--;
            if (tmp.issuedCopies < 0)
                tmp.issuedCopies = 0;
            update_book_by_id(bookid, &tmp);
        }
        printf("Failed to record issue.\n");
        return;
    }

    printf("Book issued successfully.\n");
}

void returnBook_flow(const char *currentUser) {
    int choice;
    printf("\nReturn by:\n1. Name + Author\n2. Book ID\nEnter choice: ");

    if (scanf("%d", &choice) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    while (getchar() != '\n')
        ;

    int bookid = -1;
    char name[100], auth[100];

    if (choice == 1) {
        printf("Enter Book Name: ");
        if (!fgets(name, sizeof(name), stdin)) return;
        trim_newline(name);

        printf("Enter Author Name: ");
        if (!fgets(auth, sizeof(auth), stdin)) return;
        trim_newline(auth);

        spaces_to_underscores(name);
        spaces_to_underscores(auth);

        if (!find_id_by_name_author(name, auth, &bookid)) {
            printf("Book not found.\n");
            return;
        }
    } else if (choice == 2) {
        printf("Enter Book ID: ");
        if (scanf("%d", &bookid) != 1) {
            printf("Invalid input.\n");
            while (getchar() != '\n')
                ;
            return;
        }
        while (getchar() != '\n')
            ;

        struct Book tmp;
        if (!find_book_by_id(bookid, &tmp)) {
            printf("Book not found.\n");
            return;
        }
    } else {
        printf("Invalid choice.\n");
        return;
    }

    int count = get_user_issue_count(currentUser, bookid);

    if (count <= 0) {
        printf("You have not issued this book.\n");
        return;
    }

    if (!update_user_issue_record(currentUser, bookid, -1)) {
        printf("Failed to update issue record.\n");
        return;
    }

    struct Book b;
    if (!find_book_by_id(bookid, &b)) {
        printf("Error reading book data.\n");
        return;
    }

    b.issuedCopies--;
    if (b.issuedCopies < 0) b.issuedCopies = 0;

    update_book_by_id(bookid, &b);

    printf("Book returned successfully.\n");
}

void deleteBook_flow() {
    int choice;
    printf("\nDelete by:\n1. Name + Author\n2. Book ID\nEnter choice: ");

    if (scanf("%d", &choice) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    while (getchar() != '\n')
        ;

    if (choice == 1) {
        char name[100], auth[100];

        printf("Enter Book Name: ");
        if (!fgets(name, sizeof(name), stdin)) return;
        trim_newline(name);

        printf("Enter Author Name: ");
        if (!fgets(auth, sizeof(auth), stdin)) return;
        trim_newline(auth);

        spaces_to_underscores(name);
        spaces_to_underscores(auth);

        int res = delete_book_by_name_author_if_allowed(name, auth);

        if (res == 1)
            printf("Book deleted.\n");
        else if (res == -1)
            printf("Cannot delete: copies issued.\n");
        else
            printf("Book not found.\n");

    } else if (choice == 2) {
        int id;
        printf("Enter Book ID: ");

        if (scanf("%d", &id) != 1) {
            printf("Invalid input.\n");
            while (getchar() != '\n')
                ;
            return;
        }

        int res = delete_book_by_id_if_allowed(id);

        if (res == 1)
            printf("Book deleted.\n");
        else if (res == -1)
            printf("Cannot delete: copies issued.\n");
        else
            printf("Book not found.\n");

    } else {
        printf("Invalid choice.\n");
    }
}

void updateBook_flow() {
    int choice;
    printf("\nUpdate by:\n1. Name + Author\n2. Book ID\nEnter choice: ");

    if (scanf("%d", &choice) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    while (getchar() != '\n')
        ;

    int bookid = -1;
    char name[100], auth[100];
    struct Book b;

    if (choice == 1) {
        printf("Enter Book Name: ");
        if (!fgets(name, sizeof(name), stdin)) return;
        trim_newline(name);

        printf("Enter Author Name: ");
        if (!fgets(auth, sizeof(auth), stdin)) return;
        trim_newline(auth);

        spaces_to_underscores(name);
        spaces_to_underscores(auth);

        if (!find_book_by_name_author(name, auth, &b)) {
            printf("Book not found.\n");
            return;
        }

        bookid = b.id;
    } else if (choice == 2) {
        printf("Enter Book ID: ");

        if (scanf("%d", &bookid) != 1) {
            printf("Invalid input.\n");
            while (getchar() != '\n')
                ;
            return;
        }
        while (getchar() != '\n')
            ;

        if (!find_book_by_id(bookid, &b)) {
            printf("Book not found.\n");
            return;
        }

    } else {
        printf("Invalid choice.\n");
        return;
    }

    underscores_to_spaces(b.title);
    underscores_to_spaces(b.author);

    printf("\nCurrent Details:\nID: %d\nTitle: %s\nAuthor: %s\nTotal: %d\nIssued: %d\n",
           b.id, b.title, b.author, b.totalCopies, b.issuedCopies);

    printf("\nEnter new title (leave empty to keep): ");
    char t[100];
    if (!fgets(t, sizeof(t), stdin)) return;
    trim_newline(t);
    if (strlen(t) > 0) strcpy(b.title, t);

    printf("Enter new author (leave empty to keep): ");
    char a[100];
    if (!fgets(a, sizeof(a), stdin)) return;
    trim_newline(a);
    if (strlen(a) > 0) strcpy(b.author, a);

    printf("Enter new total copies (enter -1 to keep): ");
    int tc;

    if (scanf("%d", &tc) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    while (getchar() != '\n')
        ;

    if (tc != -1) {
        if (tc < b.issuedCopies) {
            printf("Cannot set total copies below issued copies.\n");
            return;
        }
        b.totalCopies = tc;
    }

    spaces_to_underscores(b.title);
    spaces_to_underscores(b.author);

    if (update_book_by_id(bookid, &b))
        printf("Book updated.\n");
    else
        printf("Update failed.\n");
}

int cmp_id(const void *p1, const void *p2) {
    const struct Book *a = p1, *b = p2;
    return a->id - b->id;
}

int cmp_title(const void *p1, const void *p2) {
    const struct Book *a = p1, *b = p2;
    return strcmp(a->title, b->title);
}

int cmp_author(const void *p1, const void *p2) {
    const struct Book *a = p1, *b = p2;
    return strcmp(a->author, b->author);
}

void sortBooks_flow() {
    struct Book *arr = NULL;
    int n = 0;

    if (!read_all_books(&arr, &n) || n == 0) {
        printf("No books.\n");
        free(arr);
        return;
    }

    int choice;

    printf("\nSort by:\n1. ID\n2. Title\n3. Author\n4. Back\nEnter choice: ");

    if (scanf("%d", &choice) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n')
            ;
        free(arr);
        return;
    }
    while (getchar() != '\n')
        ;

    switch (choice) {
        case 1:
            qsort(arr, n, sizeof(struct Book), cmp_id);
            break;
        case 2:
            qsort(arr, n, sizeof(struct Book), cmp_title);
            break;
        case 3:
            qsort(arr, n, sizeof(struct Book), cmp_author);
            break;
        case 4:
            free(arr);
            return;
        default:
            printf("Invalid.\n");
            free(arr);
            return;
    }

    printf("\n--- SORTED BOOK LIST ---\n");

    for (int i = 0; i < n; ++i) {
        struct Book b = arr[i];

        underscores_to_spaces(b.title);
        underscores_to_spaces(b.author);

        int available = b.totalCopies - b.issuedCopies;

        printf(
            "\nID: %d\nTitle: %s\nAuthor: %s\nTotal: %d\nIssued: %d\nAvailable: %d\n",
            b.id, b.title, b.author, b.totalCopies, b.issuedCopies, available);
    }

    free(arr);
}

void admin_menu(const char *username) {
    while (1) {
        printf("\n--- Admin Menu (%s) ---\n", username);
        printf(
            "1. Add Book\n2. Display All Books\n3. Search Book\n4. Issue Book\n"
            "5. Return Book\n6. Delete Book\n7. Update Book\n8. Sort Books\n"
            "9. Change Password\n10. Change Other User Password\n11. Logout\nEnter: ");

        int ch;

        if (scanf("%d", &ch) != 1) {
            printf("Invalid.\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        while (getchar() != '\n')
            ;

        if (ch == 1) addBook_flow();
        else if (ch == 2) displayBooks_flow();
        else if (ch == 3) searchBook_flow();
        else if (ch == 4) issueBook_flow(username);
        else if (ch == 5) returnBook_flow(username);
        else if (ch == 6) deleteBook_flow();
        else if (ch == 7) updateBook_flow();
        else if (ch == 8) sortBooks_flow();
        else if (ch == 9) change_password_flow(username, 0);
        else if (ch == 10) change_password_flow(username, 1);
        else if (ch == 11) {
            printf("Logging out.\n");
            return;
        } else printf("Invalid.\n");
    }
}

void user_menu(const char *username) {
    while (1) {
        printf("\n--- User Menu (%s) ---\n", username);
        printf(
            "1. Display All Books\n2. Search Book\n3. Issue Book\n"
            "4. Return Book\n5. Sort Books\n6. Change Password\n7. Logout\nEnter: ");

        int ch;

        if (scanf("%d", &ch) != 1) {
            printf("Invalid.\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        while (getchar() != '\n')
            ;

        if (ch == 1) displayBooks_flow();
        else if (ch == 2) searchBook_flow();
        else if (ch == 3) issueBook_flow(username);
        else if (ch == 4) returnBook_flow(username);
        else if (ch == 5) sortBooks_flow();
        else if (ch == 6) change_password_flow(username, 0);
        else if (ch == 7) {
            printf("Logging out.\n");
            return;
        } else printf("Invalid.\n");
    }
}

void ensure_default_admin() {
    struct User u;

    if (!find_user("admin", &u)) {
        FILE *fp = fopen(USERS_FILE, "a");
        if (!fp) return;

        fprintf(fp, "admin admin admin\n");
        fclose(fp);

        printf("Default admin created.\n");
    }
}

void ensure_issues_file() {
    FILE *fp = fopen(ISSUES_FILE, "a");
    if (fp) fclose(fp);
}

int main() {
    ensure_default_admin();
    ensure_issues_file();

    while (1) {
        printf("\n====== LIBRARY MANAGEMENT SYSTEM ======\n");
        printf("1. Login\n2. Exit\nEnter choice: ");

        int ch;

        if (scanf("%d", &ch) != 1) {
            printf("Invalid.\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        while (getchar() != '\n')
            ;

        if (ch == 1) {
            char username[50], password[50], role[10];

            printf("Username: ");
            if (!fgets(username, sizeof(username), stdin)) continue;
            trim_newline(username);

            printf("Password: ");
            if (!fgets(password, sizeof(password), stdin)) continue;
            trim_newline(password);

            if (authenticate(username, password, role)) {
                printf("Login successful. Role: %s\n", role);

                if (strcmp(role, "admin") == 0)
                    admin_menu(username);
                else
                    user_menu(username);

            } else printf("Invalid credentials.\n");

        } else if (ch == 2) {
            printf("Exiting...\n");
            exit(0);
        } else printf("Invalid.\n");
    }

    return 0;
}
