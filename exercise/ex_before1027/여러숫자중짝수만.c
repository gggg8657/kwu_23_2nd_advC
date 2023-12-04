#define _CRT_SECURE_NO_WARNIGS
#include <stdio.h>
#include <stdlib.h>

int main(){
    int *p;
    int i, sum=0;
    int cnt;

    printf("input number");
    scanf("%d", &cnt);
    p=(int*)malloc(sizeof(int)*cnt);
    for(i=0; i<cnt; i++)
    {
        printf("%d th number", i+1);
        scanf("%d", p+i);
    }
    for(i=0; i<cnt; i++)
    {
        if(p[i]%2==0)
            sum = sum+ p[i];
    }
    printf("summation result ==> %d\n", sum);

    free(p);
    return 0;

}