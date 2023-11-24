#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main() 
{
   char* p[100];
   char imsi[100];
   int len;
   int cnt;
   int ko[100];

   printf("사용자로부터 입력할 문자열 개수를 입력하시오 : ");
   scanf("%d",&cnt);

   for (int i = 0;i < cnt;i++)
   {
      printf("%d 번째 문자열 입력 : ", i + 1);
      gets(imsi);
      len = strlen(imsi);

      p[i] = (char*)malloc((sizeof(char) * len) + 1);
      strcpy(p[i], imsi);

      ko[i] = len;
   }

   int cmp=0;

   for (int w = 0;w < cnt-1;w++)
   {
      for (int e = w+1;e < cnt;e++)
      {
         if (ko[w] < ko[e])
         {
            cmp = ko[w];
            ko[w] = ko[e];
            ko[e] = cmp;
         }
      }
   }

   for (int j = 0;j < ko[0];j++)
   {
      for (int k = 0;k < cnt;k++)
      {
         if (p[k][j] == ' ')
            continue;
         else
            printf("%c", p[k][j]);
      }
   }

   for (int q = 0;q < cnt;q++)
   {
      free(p[q] = NULL);
   }
}