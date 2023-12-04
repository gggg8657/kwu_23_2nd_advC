#include <stdio.h>

int main2(){
    char str[] = "13";
    int a = str - '0';
    printf("%d\n", a);
    return 0;
}



int main() {
    char three_char = '3';
    int three_int = three_char - '0';
    int result = three_int + 1;

    printf("%d + 1 is %d\n", three_int, result);
    main2();
}
