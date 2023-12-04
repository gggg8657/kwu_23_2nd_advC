#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#pragma warning (disable: 6031)

void sort_Ascending(char** B);
void sort_Descending(char** B);
void write_result_to_file(char** B, FILE* wfp);
void print_arr(char* arr[20]);

void main()
{
   FILE* rfp;
   FILE* wfp;
   FILE* wfp2;
   char imsi[100] = { NULL, };
   char* A[4];
   char* B[20];
   char dan[20] = { NULL, };
   int len, each = 0, tmp = 0;
   rfp = fopen("./data_thu.txt", "r");
   wfp = fopen("./result_A.txt", "w");
   wfp2 = fopen("./result_B.txt", "w");

   for (int i = 0; i < 4; i++)
   {
      fgets(imsi, 100, rfp);
      len = strlen(imsi);
      A[i] = (char*)malloc(sizeof(char) * len + 1);
      strcpy(A[i], imsi);

      for (int j = 0; j < len; j++)
      {
         if (A[i][j] == '\n' && A[i][j-1] == '|')
            break;
         if (A[i][j] == '|' || A[i][j]=='\n')
         {
            B[each] = (char*)malloc(sizeof(char) * tmp + 1);
            strcpy(B[each], dan);
            for (int k = 0; k < tmp; k++)
               dan[k] = '\0';
            each++;
            tmp = 0;
         }
         else
         {
            dan[tmp] = A[i][j];
            tmp++;
         }
      }
   }

   print_arr(B);
   sort_Ascending(B);
   write_result_to_file(B, wfp);
   print_arr(B);
   sort_Descending(B);
   print_arr(B);
   write_result_to_file(B, wfp2);
   
   for (int i = 0; i < 20; i++)
      free(B[i]=NULL);
   for (int i = 0; i < 4; i++)
      free(A[i]=NULL);
   fclose(rfp);
   fclose(wfp);
   fclose(wfp2);
}

void sort_Ascending(char** B)
{
   int k;
   char tmp[20] = { NULL, };
   for (int i = 0; i < 19; i++)
   {
      k = i + 1;
      for (k; k < 19; k++)
      {
         if (strcmp(B[i], B[k]) > 0)
         {
            strcpy(tmp, B[i]);
            strcpy(B[i], B[k]);
            strcpy(B[k], tmp);
         }
      }
   }
}
void sort_Descending(char** B)
{
   int k;
   char tmp[20] = { NULL, };
   for (int i = 0; i < 19; i++)
   {
      k = i + 1;
      for (k; k < 19; k++)
      {
         if (strcmp(B[i], B[k]) < 0)
         {
            strcpy(tmp, B[i]);
            strcpy(B[i], B[k]);
            strcpy(B[k], tmp);
         }
      }
   }
}
void write_result_to_file(char** B,FILE *wfp)
{
   fprintf(wfp,"========sorting Result========\n");
   for (int i = 0; i < 19; i++)
      fprintf(wfp, "[%20s]\n", B[i]);
}


void print_arr(char* arr[20])
{
   printf("========sorting Result========\n");
   for (int i = 0; i < 19; i++)
      printf("[%10s]\n", arr[i]);
}