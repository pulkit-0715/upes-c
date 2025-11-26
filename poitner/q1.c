/*
Declare different types of pointers (int, float, char) and initialize them with the addresses of
variables. Print the values of both the pointers and the variables they point to.
*/

#include <stdio.h>

int main(){
    int a = 5;
    float b = 10.1;
    char ch = 'a';

    int* pa = &a;
    float* pb = &b;
    char* pch = &ch;

    printf("value of int 'a' is %d and address is %p "
        "and value to pointer is %d\n", a, pa, *pa);
    printf("value of float 'b' is %f and address is %p "
        "and value to pointer is %f\n", b, pb, *pb);
    printf("value of char 'ch' is %c and address is %p "
        "and value to pointer is %c\n", ch, pch, *pch);

    return 0;
}
