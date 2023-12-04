#include <stdio.h>

int main(){
    int a, b, c;

    printf("Digite o valor de A: ");
    scanf("%d", &a);

    printf("Digite o valor de B: ");
    scanf("%d", &b);

    printf("Digite o valor de C: ");
    scanf("%d", &c);

    if(a > b && a > c){
        printf("O maior valor é A: %d\n", a);
    }
    else if(b > a && b > c){
        printf("O maior valor é B: %d\n", b);
    }
    else{
        printf("O maior valor é C: %d\n", c);
    }

    return 0;
}