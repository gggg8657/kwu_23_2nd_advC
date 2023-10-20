#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort_ascending(char **arr, int height);
void sort_descending(char **arr, int height);
void print_arr(char **arr, int height);
void write_result_to_file(char **arr, int height, char *filename);

int main()
{
    char** arr;
    char tmp_arr[100]={NULL, };
    FILE *fp;
    int c;
    fp = fopen("data_tue.txt", "r");

    if(fp == NULL){
      printf("파일열기 실패\n");
    } else {
      printf("파일열기 성공\n");
    }
    int iter =0;
    int height=1;
    int word_size_counter=0;
    int flag =0;
    int flag2=0;

    //using fgetc
    while((c=fgetc(fp))!=EOF){
        if (flag ==0) {
            arr = (char**)malloc(sizeof(char*)*height);
            flag =1;
        }
        else if (flag ==1) arr = (char**)realloc(arr,sizeof(char*)*height);

        if(c==',' || c=='\n' || c=='_' || c=='&' || c=='('||c==')'||c=='|'){
            if(word_size_counter!=0){
                if(flag2 ==0 ) {
                    *(arr+iter)=(char*)malloc(sizeof(char) * word_size_counter);
                    flag2=1;
                }
                else *(arr+iter)=(char*)realloc(*(arr+iter),sizeof(char) * word_size_counter);
                strcpy(*(arr+iter), tmp_arr);
                printf("length of word [%20s] is : %5d\n", *(arr+iter), word_size_counter);
                height++;
                iter++;

                for (int iter = 0; iter<word_size_counter; iter++){
                    tmp_arr[iter]='\0';
                    }
                word_size_counter=0;
                }
        }
        else {
            tmp_arr[word_size_counter] = c;
            word_size_counter++;
        }
    }
  printf("\n *\t*\t* total number of words [%5d] *\t*\t*\t\n", height);

  fclose(fp);

  sort_ascending(arr, height);
  print_arr(arr,height);
  write_result_to_file(arr,height,"Result_Ascending.txt");
  sort_descending(arr,height);
  print_arr(arr,height);
  write_result_to_file(arr,height,"Result_Descending.txt");

  for (int i=0; i<height; i++)
    free(arr[i]);
  
  //end of using getc
  return 0;
}

void sort_ascending(char **arr, int height){
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
}

void sort_descending(char **arr, int height){
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
}

void print_arr(char **arr, int height){
    printf("========sorting Result========\n");
  for (int i=0; i<height-1; i++){
    printf("[%10s]\n", arr[i]);
    }
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