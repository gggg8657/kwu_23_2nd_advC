

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//파일 입출력 관련 문제
//본 문제는 단순한 파일 입출력에 대한 문법 익히기 및 다양한 파일 읽고 쓰는 함수에 대한 학습을 위해 만들어졌습니다.
int main1() {
	//구구단 문제

    int i =0;
    printf("출력하고 싶은 단을 입력 : ");
    scanf("%d", &i);
    char tmp = (char)i;
    
    FILE* wfp;
    char filename[10]={NULL, };
    switch (i) {
    case 1:
        strcpy(filename ,"1_dan.txt");
        break;
    case 2:
        strcpy(filename ,"2_dan.txt");
        break;
    case 3:
        strcpy(filename ,"3_dan.txt");
        break;
    case 4:
        strcpy(filename ,"4_dan.txt");
        break;
    case 5 :
        strcpy(filename ,"5_dan.txt");
        break;
    case 6:
        strcpy(filename ,"6_dan.txt");
        break;
    case 7:
        strcpy(filename ,"7_dan.txt");
        break;
    case 8:
        strcpy(filename ,"8_dan.txt");
        break;
    case 9:
        strcpy(filename ,"9_dan.txt");
        break;
    default:
        strcpy(filename ,"nodan.txt");
        printf("wrong dan");
        return 0;   
    }
    

    wfp = fopen(filename, "w");
    printf("%s에 결과를 저장\n", filename);
    for(int j=i; j<=i; j++){
        for (int k=1; k<=9; k++){
            if(k<9)
                fprintf(wfp, "%d X %d = %d\n", j, k, j*k);
            else fprintf(wfp, "%d X %d = %d", j, k, j*k);
        }
    }
    

	return 0;
}


void print_menu_borad(char **menu, char **price, int i){
    printf("[%20s : %20s]","MENU", "PRICE");
    for (int iter=0; iter<i; iter++)
        printf("\n[%d] %20s : %20s]\n",iter+1 ,*(menu+iter), *(price+iter));    
}

//본 문제는 파일입출력을 기반으로하며, 이를 통해 구현 할 수 있는, 실생활에 사용되는 포스기에 대한 문제입니다.
int main2() {
	
    char **menu;
    char** price;
    char tmp_arr[100]={NULL, };
    FILE *fp;
    FILE *wfp;
    int c;
    wfp = fopen("receipt.txt","w");
    fp = fopen("menu_tue.txt", "r");

    if(fp == NULL){
      printf("파일열기 실패\n");
    } else {
      printf("파일열기 성공\n");
    }
    
    int i=0;
    int k=0;
    //using fgetc
    int flag_menu =0 ;
    int flag_price = 0;
    menu = (char**)malloc(sizeof(char*)*sizeof(tmp_arr));
    price = (char**)malloc(sizeof(char*)*sizeof(tmp_arr));
    
    while((c=fgetc(fp))!=EOF)
    {

        if(c==':')
        {
            if(flag_menu==0) 
            {
                *(menu+i) = (char*)malloc(sizeof(char)*strlen(tmp_arr)+1);
                flag_menu=1;
            }
            else{
                *(menu+i) = (char*)realloc(*(menu+i) ,sizeof(char)*strlen(tmp_arr)+1);
            }
            strcpy(*(menu+i), tmp_arr);
            for(int j=0; j<100; j++)tmp_arr[j]=NULL;
            k=0;
        }
        else if (c=='\n'){
            if(flag_price==0) 
            {
                *(price+i) = (char*)malloc(sizeof(char)*strlen(tmp_arr)+1);
                flag_price=1;
            }
            else{
                *(price+i) = (char*)realloc(*(price+i) ,sizeof(char)*strlen(tmp_arr)+1);
            }
            strcpy(*(price+i), tmp_arr);
            for(int j=0; j<100; j++)tmp_arr[j]=NULL;
            k=0;
            i++;
        }
        else{
            tmp_arr[k]=c;
            k++;
            printf("%c", tmp_arr[k]);
        }
        
    }
    
    //파싱 된 메뉴판 배열에서 값 찾기
    int order =0;
    int result= 0;
    while(1){
        print_menu_borad(menu, price, i);
        printf("메뉴를 고르세요, 주문완료는 0을 누르세요 : ");
        scanf("%d",&order);
        if(order==0)break;
        else if (order > 0 && order < 10)
            {
            result += atoi(*(price+order-1));
            fprintf(wfp, "%s : %s\n", *(menu+order-1), *(price+order-1));
            printf("%s, 주문 받았습니다.\n", *(menu+order-1));
            }
        else{
            printf("잘못 입력하셨습니다.\n");
        }           
    }
    fprintf(wfp, "\n결제금액 : %d", result);

	//return 0;
    for (int iter2=0; iter2<i; iter2++){
        free(*(menu+iter2));
        free(*(price+iter2));
    }
    return 0;
}


void main() {
	main1();
	main2();
}


