#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main() {
   FILE* rfp = fopen("words.txt", "r");

   char str[200];
   char temp[200] = { '\0', };
   char* dic[200];
   int j = 0;
   int cnt1 = 0;

   while (fgets(str,200,rfp)!=NULL) {
       int i = 0;
       while (str[i] != '\0' && str[i] != '\n') {
           while (str[i] != ',' && str[i] != ';' && str[i] != '\t' && str[i] != '|' && str[i] != '\0' && str[i] != '\n') {
               temp[i] = str[i];
               i++;
           }
           temp[i] = '\0';
           cnt1 = strlen(temp);
           dic[j] = (char*)malloc(sizeof(char) * (cnt1 + 1));
           strcpy(dic[j], temp);
           for (int k =0; k<i; k++) temp[k]='\0';
           printf("%s\n", dic[j]);
           i++;
           j++;
       }

   }


   fclose(rfp);
}
//tlqkf