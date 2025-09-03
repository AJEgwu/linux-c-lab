#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_NAME "contacts.txt"

struct Person {
    char name[50];
    int age;
    char phone[20];
};

static void trim_newline(char *s) {
    if (!s) return;
    size_t n = strlen(s);
    while (n > 0 && (s[n-1] == '\n' || s[n-1] == '\r')) {
        s[--n] = '\0';
    }
}

static void add_contact(void) {
    struct Person p;
    char buf[64];

    printf("Name: ");
    if (!fgets(p.name, sizeof(p.name), stdin)) return;
    trim_newline(p.name);

    printf("Age: ");
    if (!fgets(buf, sizeof(buf), stdin)) return;
    p.age = atoi(buf); // simple parse

    printf("Phone: ");
    if (!fgets(p.phone, sizeof(p.phone), stdin)) return;
    trim_newline(p.phone);

    FILE *f = fopen(FILE_NAME, "a");
    if (!f) {
        perror("fopen");
        return;
    }
    // store one contact per line: name|age|phone
    fprintf(f, "%s|%d|%s\n", p.name, p.age, p.phone);
    fclose(f);

    printf("Saved.\n");
}

static void view_contacts(void) {
    FILE *f = fopen(FILE_NAME, "r");
    if (!f) {
        printf("No contacts yet (file not found).\n");
        return;
    }

    char line[128];
    int i = 1;

    while (fgets(line, sizeof(line), f)) {
        char name[50], phone[20];
        int age = 0;
        trim_newline(line);

        // read back the line we wrote earlier
        if (sscanf(line, "%49[^|]|%d|%19[^\n]", name, &age, phone) == 3) {
            printf("%d) %s, %d, %s\n", i++, name, age, phone);
        }
    }
    fclose(f);

    if (i == 1) {
        printf("(no contacts to show)\n");
    }
}

int main(void) {
    for (;;) {
        printf("\nContacts\n");
        printf("1) Add\n");
        printf("2) View\n");
        printf("3) Quit\n");
        printf("Choice: ");

        char buf[16];
        if (!fgets(buf, sizeof(buf), stdin)) break;
        int choice = atoi(buf);

        if (choice == 1) {
            add_contact();
        } else if (choice == 2) {
            view_contacts();
        } else if (choice == 3) {
            break;
        } else {
            printf("Try 1/2/3.\n");
        }
    }
    return 0;
}
