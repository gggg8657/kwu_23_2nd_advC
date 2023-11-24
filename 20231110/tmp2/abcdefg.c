#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main() {

   FILE* rp;

   char *sb[7];
   int j[7] = { 0 };
   char g[7][2] = { '0', };
   double cj[7] = { 0 };
   int k = 0;
   int hapr = 0;
   int hapj = 0;
   char imsi1[100];
   char imsi2[1000] = { '\0', };
   

   rp = fopen("./grade.txt", "r");

   fgets(imsi1,100,rp);
    printf("*\t*\t%s*\t*\t", imsi1);
   for (int i = 0; ;i++)
   {
      if (feof(rp))
         break;

      fscanf(rp, "%s\t%d\t%s\n", imsi2, &j[i], g[i]);
      int len = strlen(imsi2);

      sb[i] = (char*)malloc((sizeof(char) * len) + 1);

      strcpy(sb[i], imsi2);

      if (strcmp(g, "A+") == 0)
      {
         cj[k] = 4.5 * j[k];
         k++;
      }
      else if (strcmp(g, "A0") == 0)
      {
         cj[k] = 4 * j[k];
         k++;
      }
      else if (strcmp(g, "B+") == 0)
      {
         cj[k] = 3.5 * j[k];
         k++;
      }
      else if (strcmp(g, "B0") == 0)
      {
         cj[k] = 3 * j[k];
         k++;
      }
      else if (strcmp(g, "C+") == 0)
      {
         cj[k] = 2.5 * j[k];
         k++;
      }
      else if (strcmp(g, "C0") == 0)
      {
         cj[k] = 2 * j[k];
         k++;
      }
      else if (strcmp(g, "D+") == 0)
      {
         cj[k] = 1.5 * j[k];
         k++;
      }
      else if (strcmp(g, "D0") == 0)
      {
         cj[k] = 1 * j[k];
         k++;
      }
      else if (strcmp(g, "F") == 0)
      {
         cj[k] = 0 * j[k];
         k++;
      }
   }

   for (int i = 0;i < 7;i++)
   {
      printf("%s의 평점 : %.2f \n",sb[i], cj[i]);
      hapr = hapr + cj[i];
      hapj = hapj + j[i];
   }

   printf("총 평점 : %.2f \n", hapr / hapj);
   
}