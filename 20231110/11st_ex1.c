#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char name[50];
    int id;
    int cnt;
};

struct library {
    struct Book* Booklist;
    int book_cnt;
    struct Book* rent;
    int rent_cnt;
};

char* parser(char* input) {
    char tmp[100] = { '\0' };
    int i = 0;
    for (i ; input[i] != '\n' && input[i] != 26; i++) {
        tmp[i] = input[i];
    }
    tmp[i] = '\0';
    return tmp;
}

void printBookList(struct Book* input, int cnt) {
    for (int i = 0; i < cnt; i++) {
        printf("%d : %s\n", input[i].id, input[i].name);
    }
}

struct library* initial_booklist() {
    struct library* lib = (struct library*)malloc(sizeof(struct library));
    lib->Booklist = malloc(lib->Booklist, sizeof(struct Book));
    lib->rent = malloc(lib->rent, sizeof(struct Book));
    lib->book_cnt = 0;
    lib->rent_cnt = 0;

    struct Book book_info;

    FILE* fin = fopen("./books_ansi.txt", "r"); //change the txt file name

    char tmp[100] = { 0, };
    printf("========== Book List (ID : Book Name) ==========\n");
    //fgets(tmp, 100, fin);
    int T = 0, F = 0;

    for (int i = 0; !feof(fin); i++) {

        char input[100] = { 0, };
        fgets(input, 100, fin);
        if ((int)input[0] == 0)
            break;

        char* parsed = parser(input);
        strcpy(book_info.name, parsed);
        book_info.id = i + 1;
        book_info.cnt = 3;
        lib->Booklist = realloc(lib->Booklist, sizeof(struct Book) * (i + 1));
        lib->Booklist[i] = book_info;
        lib->book_cnt++;

    }

    return lib;
}

int manage_booklist(struct library* lib, int id) {

    if (id == 0)
        return 0;

    if (id > lib->book_cnt || id < 0) {
        printf("Error : Not a valid id\n");
        return 1;
    }
    else {
        if (lib->Booklist[id-1].cnt == 0) {
            printf("The book is out of stock.\n");
            return 2;
        }
        else {
            lib->Booklist[id - 1].cnt--;
            lib->rent = realloc(lib->rent, sizeof(struct Book) * (lib->rent_cnt + 1));
            lib->rent[lib->rent_cnt] = lib->Booklist[id - 1];
            lib->rent_cnt++;
            printf("Rent a book\n");
            return 3;
        }
    }
}

int main(void) {

    struct library * lib = initial_booklist();
    
    int book_id = 999;
    while (1) {
        printf("\n========= Available to Borrow ==========\n");
        printBookList(lib->Booklist, lib->book_cnt);

        printf("\nEnter the Book ID (type 0 to end) : ");
        scanf("%d", &book_id);
        int res = manage_booklist(lib, book_id);
        if (res == 0)
            break;

        printf("\n========= Borrowed Book ==========\n");
        printBookList(lib->rent, lib->rent_cnt);
    }
    
    free(lib);

    return 0;
}