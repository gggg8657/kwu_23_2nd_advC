#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <crtdbg.h>

void write_result_to_file(char* b[],char*f)
{
   FILE* wp;

   wp = fopen(f, "w");

   for (int i = 0;i < 20;i++) {
      fprintf(wp, "[%20s] \n", b[i]);
   }

   fclose(wp);
}

void sort_Ascending(char** b) {
   
   char *ims;

   for (int i = 0;i < 21;i++)
   {
      for (int k = i+1;k<20;k++)
      {
         if (strcmp(b[i], b[k]) > 0)
         {
            ims = b[i];
            b[i] = b[k];
            b[k] = ims;
         }
      }
   }

   write_result_to_file(b,"./results_vxxx.txt");
}

void sort_Descending(char** b) {

   char *ims;

   for (int i = 0;i < 20;i++)
   {
      for (int k = i + 1;k < 19;k++)
      {
         if (strcmp(b[i], b[k]) < 0)
         {
            ims = b[i];
            b[i] = b[k];
            b[k] = ims;
         }
      }
   }

   write_result_to_file(b, "./results_vxxxs.txt");
}

void main() {
    _CrtDumpMemoryLeaks();
   char* a[5];
   char* b[20];

   char imsi[100];
   int len;
   int q = 0;
   int p = 0;

   FILE* rp;

   rp = fopen("./data (1).txt", "r");

   b[0] = (char*)malloc((sizeof(char) * 1) + 1);

   for (int i = 0; ;i++)
   {
      if (feof(rp))
         break;

      fgets(imsi, 200, rp);
      len = strlen(imsi);

      a[i] = (char*)malloc((sizeof(char) * len) + 1);

      strcpy(a[i], imsi);

      for (int k = 0;k < len;k++)
      {

         if ((a[i][k] == '|') && (a[i][k] != '\n'))
         {
            b[q][p] = '\0';
            q++;
            b[q] = (char*)malloc((sizeof(char) * 1) + 1);
            p = 0;
            continue;
         }
         else if ((a[i][k] == '\n')&& (a[i][k] == '|'))
         {
            break;
         }
         else if((a[i][k] != '|') && (a[i][k] != '\n'))
         {
            b[q][p] = a[i][k];
            p++;
            b[q] = (char*)realloc(b[q], (sizeof(char) * (p + 1)) + 1);
         }
      }
   }

   sort_Ascending(b);
   sort_Descending(b);

   fclose(rp);

   for (int i = 0;i < 20;i++)
   {
      free(b[i]);
   }
}