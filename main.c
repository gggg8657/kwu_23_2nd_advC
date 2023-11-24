

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct book{
//    char book_name[100][100];
//    int book_storge;
//};
int admin_check(char **book_list,int *book_total,char **auth_IDPW,int *storagebook_total);
int print_booklist(char **book_list,int *book_total);
int manage_booklist(char **book_list,int *book_total,int *storagebook_total);
int initial_booklist(char **book_list,int *book_total);
int k = 0, l = 0,n = 0,m = 0;

int main(int argc, const char * argv[]) {
    char **book_list = (char**)malloc(sizeof(char*) * 100);
    for (int i = 0; i < 100; i++) {
        book_list[i] = (char*)malloc(sizeof(char) * 100);
    }
    //책 갯수 3으로 초기화
    int *book_total = malloc(sizeof(int)*100);
    char **auth_IDPW = (char**)malloc(sizeof(char*)*10);
    for (int i=0; i<10; i++) {
        auth_IDPW[i]=(char*)malloc(sizeof(char)*10);
    }
    int *storagebook_total = malloc(sizeof(int)*100);
    
    for (int i=0; i<100; i++) {
        book_total[i]=3;
        storagebook_total[i]=100;
    }
    
    FILE *fp = fopen("books_utf_8.txt", "r");
    int book_select;

    char auth_check[10];
    while (1) {
        int ch = fgetc(fp);
        if (ch == EOF || ch == '\n') {
            book_list[k][l] = '\0'; // 문자열의 끝에 NULL 문자 추가
            k++;
            l = 0;
            
            if (ch == EOF) {
                break;
            }
        }
        else {
            book_list[k][l] = ch;
            l++;
        }
        
    }
    fclose(fp);
    

    
    FILE *auth_file = fopen("admin_auth.txt", "r");
    while (1) {
        int ch = fgetc(auth_file);
        if (ch == EOF) {
            break;
        }
        else if (ch == ' ' || ch == '\n') {
            auth_IDPW[n][m]='\0';
            n++;
            m=0;
        }
        else {
            auth_IDPW[n][m] = ch;
            m++;
        }
    }
    fclose(auth_file);
    
    while (1) {
        printf("admin or user : ");
        scanf("%s",auth_check);
        if (strcmp(auth_check, "admin")==0) {
            admin_check(book_list, book_total, auth_IDPW,storagebook_total);
            printf("continue service(cs) or end(end) : ");
            scanf("%s",auth_check);
            if (strcmp(auth_check, "end")==0) {
                break;
            }
        }
        
        while (1) {
            printf("===========Book List===========\n");
            for (int i = 0; i < k-1; i++) {
                printf("%d : %s(%d)\n", i+1, book_list[i],book_total[i]);
            }
            printf("===============================\n\n");
            
            printf("Type the book id to borrow(0 to end) : ");
            scanf("%d",&book_select);
            if (book_select==0) {
                printf("End the program\n");
                break;
            }
            if (book_select>k-1) {
                printf("error\n");
                continue;
            }
            if (book_total[book_select-1]==0) {
                printf("No book\n");
                continue;
            }
            
            book_total[book_select-1]--;
            printf("\n===========Borrowed Book List===========\n");
            printf("%d : %s\n",book_select,book_list[book_select-1]);
            printf("===============================\n\n");
        }
    
    }
    
    


    return 0;
}
int admin_check(char **book_list, int *book_total,char **auth_IDPW,int *storagebook_total){//ID : 2, PW : 5
    char IDPW[10];
    printf("ID : ");
    scanf("%s",IDPW);
    if (strcmp(IDPW, auth_IDPW[2])!=0) {
        printf("ID error\n");
        return 0;
    }
    if (strcmp(IDPW, auth_IDPW[2])==0) {
        printf("PW : ");
        scanf("%s",IDPW);

        if (strcmp(IDPW, auth_IDPW[5])==0) {
            printf("author Login succes\n");
        }
        else{
            return 0;
        }
    }

    for (int i=0; i<100; i++) {
        if (book_total[i]==0) {
            book_total[i]+=3;
            storagebook_total[i]-=3;
        }
    }
    print_booklist(book_list, book_total);
    printf("===========Storage Book List===========\n");
    for (int i = 0; i < k-1; i++) {
        printf("%d : %s(%d)\n", i+1, book_list[i],storagebook_total[i]);
    }
    printf("===============================\n\n");
    return 0;
}
int print_booklist(char **book_list, int *book_total){
    printf("===========Book List===========\n");
    for (int i = 0; i < k-1; i++) {
        printf("%d : %s(%d)\n", i+1, book_list[i],book_total[i]);
    }
    printf("===============================\n\n");
    return 0;
}
int manage_booklist(char **book_list, int *book_total,int *storagebook_total){
    FILE *storage = fopen("storage2.txt", "w");
    fprintf(storage, "book_name count\n");
    for (int i=0; i<100; i++) {
        fprintf(storage, "%s %d\n",book_list[i],storagebook_total[i]);
    }
    return 0;
}
int initial_booklist(char **book_list, int *book_total){
    
    return 0;
}

