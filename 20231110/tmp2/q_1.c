#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init();
void init_ment();
void admin_init();
void sales();
void admin();
int admin_authentication(char ID[], char PW[]);

int main()
{
    init();
    return 0;
}

void init_ment(){
    printf("for Admin mode press 666 \nfor sales mode press 888\n command : ");
}

void init(){
    init_ment();
    int cmd=0;
    scanf("%d",&cmd);
    if(cmd == 666)
        admin_init();
    else if(cmd == 888)
        sales();
    else
        printf("wrong command ");
}

void admin_init(){
    char ID[20];
    char PW[20];
    printf("ID : ");
    scanf("%s", ID);
    printf("PW : ");
    scanf("%s", PW);
    
    // char *ID_ptr=NULL;
    // ID_ptr = &ID;
    // char *PW_ptr=NULL;
    // PW_ptr = &PW;
    if (admin_authentication(ID,PW)==0)
    {
        printf("authentication success\n");
        admin();
    }
    else {
        printf("authentication failed\n");
        init();
    }
}

int admin_authentication(char *ID, char *PW){
    if (strcmp(ID, "admin") == 0 && strcmp(PW, "000a") == 0){
        return 0;
    }
    else return 1;
}

void admin(){
    int cmd =0;
    while(1){
        printf("press 999 for exit admin mode\n::");
        scanf("%d", &cmd);
        if(cmd == 999){
            init();
            break;
        }
            
    }
}

void sales(){
    printf("entering to sales mode");
}

