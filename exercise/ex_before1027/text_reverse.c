#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char *p[3];
    char tmp[100];

    int i, k, size;

    for (i=0; i<3; i++)
    {
        printf("%dth string : ", i+1);
        gets(tmp);

        size = strlen(tmp);
        p[i] = (char *)malloc(sizeof(char)*size+1);

        strcpy(p[i], tmp);
    }        

    printf("printout reverse\n");

    for(i=2; i>=0; i--)
    {
        size = strlen(p[i]);
        tmp[size]='\0';
        for(k=size-1; k>=0; k--)
        {
            tmp[size-1-k] = p[i][k];
        }
        printf("%d : %s \n", i+1, tmp);
    }

    for(i=0; i<3; i++)
        free(p[i]);
    return 0;
}