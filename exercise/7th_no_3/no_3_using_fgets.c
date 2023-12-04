#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort_Ascending(char** arr, int height);
void sort_Descending(char** arr, int height);
void write_result_to_file(char **arr, int height, char *filename);

void main()
{
    char* ss[5];
    char* cc[20];
    char imsi[100] = { 0, };
    int cnt=0;
    int i = 0;
    int q= 0;
    int p = 0;

    FILE* rfp;
    rfp = fopen("./data_thu.txt", "r");

    for (int i = 0;;i++)
    {
        fgets(imsi, 100, rfp);
        
        cnt = strlen(imsi);
        ss[i] = (char*)malloc(sizeof(char) * (cnt)+ 1);

        strcpy(ss[i], imsi);
        for(int iter = 0; iter<100; iter++)imsi[iter]= '\0';//임시 배열에 뭐 넣을지 임시로 쓸거 넣을거라 싹 비워버림
        if (feof(rfp))
            break;
        for (int k = 0;k<cnt;k++)
        {  
            if(ss[i][k] != '|' && ss[i][k] != '\0' && ss[i][k] != '\n')
            {
                //임시 배열에 어떤거 넣을지 만들어두기
                imsi[q] = ss[i][k];
                //printf("\n%2d 번째 줄에서 반복문 %3d 바퀴 <%16s>",i,k,imsi);
                q++;
            }
            else if (ss[i][k] == '|' || ss[i][k] == '\n')
            {
                q=0;
                cc[p]= (char*)malloc(sizeof(char) * (strlen(imsi) + 1));
                if(strcmp(imsi,"")==0) continue;
                strcpy(cc[p],imsi); //| 만났으니, cc 배열에 넣기
                //printf("\n[디버깅용 at time seq %5d \t ** imsi is :: %15s]", p, cc[p]);
                for(int iter = 0; iter<100; iter++) imsi[iter]= '\0';//어떤거 넣을지 저장해뒀던거 비워버리기
                p++; //cc 배열 몇번째단어인지 카운팅 할거임
                continue; //| 건너뛰기
            }
            else if (ss[i][k]=='\0')
            {
                break; //한줄 끝이니까 다음줄 읽으러 반복문 탈출
            }
        }
    }

    sort_Ascending(cc, 19);
    sort_Descending(cc, 19);
    fclose(rfp);
    for(int iter=0; iter<5; iter++)
      free(ss[iter]);
    for (int iter=0; iter<19; iter++)
      free(cc[iter]);
}











































































void sort_Ascending(char** arr, int height)
{
    for (int i=0; i<height; i++){
    for (int j=i+1; j<height-1; j++){
      if (strcmp(arr[i], arr[j]) > 0)
      {
        char *temp;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;     
      }
    }
  }
  write_result_to_file(arr, height, "Result_Ascending_v2.txt");
}

void sort_Descending(char** arr, int height)
{
    for (int i=0; i<height; i++){
    for (int j=i+1; j<height-1; j++){
      if (strcmp(arr[i], arr[j]) < 0)
      {
        char *temp;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;     
      }
    }
  }
  write_result_to_file(arr, height, "Result_Descending_v2.txt");
}

void write_result_to_file(char **arr, int height, char *filename){
  FILE *fp;
  fp = fopen(filename, "w");
  if (fp == NULL)
  {
    printf("Error opening file!\n");
    exit(1);
  }
  fprintf(fp,"========sorting Result========\n");
  for (int i=0; i<height-1; i++){
    fprintf(fp, "[%20s]\n", arr[i]);
    }
  fclose(fp);
}
