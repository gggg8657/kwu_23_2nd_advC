#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main(){
    FILE *rfp, *wfp;
    char str1[200], str2[200];
    int size, i;

    rfp = fopen("test.txt", "r");
    wfp = fopen("test2.txt", "w");

    while(1)
    {
        fgets(str1,200,rfp);

        if(feof(rfp)) break;

        size = strlen(str1);
        for(i=size-1; i>=0; i--)
            str2[size-1-i] = str1[i-1];

        str2[size-1]='\0';
        fputs(str2, wfp);
        fputs("\n", wfp);
    }

    fclose(rfp);
    fclose(wfp);

    return 0;
}