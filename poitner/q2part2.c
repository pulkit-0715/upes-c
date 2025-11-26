/* Pointer arithmetic on different data types + multi-pointers + arithmetic operations */

#include <stdio.h>

int main() {
    int a = 20, b = 5;
    float x = 12.5, y = 2.5;
    char c1 = 'A', c2 = 2;

    int *pA = &a, *pB = &b;
    float *pX = &x, *pY = &y;
    char *pc1 = &c1, *pc2 = &c2;

    printf("INT arithmetic using pointers:\n");
    printf("Addition: %d + %d = %d\n", *pA, *pB, (*pA + *pB));
    printf("Subtraction: %d - %d = %d\n", *pA, *pB, (*pA - *pB));
    printf("Multiplication: %d * %d = %d\n", *pA, *pB, (*pA * *pB));
    printf("Division: %d / %d = %d\n\n", *pA, *pB, (*pA / *pB));

    printf("FLOAT arithmetic using pointers:\n");
    printf("Addition: %.2f + %.2f = %.2f\n", *pX, *pY, (*pX + *pY));
    printf("Subtraction: %.2f - %.2f = %.2f\n", *pX, *pY, (*pX - *pY));
    printf("Multiplication: %.2f * %.2f = %.2f\n", *pX, *pY, (*pX * *pY));
    printf("Division: %.2f / %.2f = %.2f\n\n", *pX, *pY, (*pX / *pY));

    printf("CHAR arithmetic using pointers (char as numbers):\n");
    printf("%c + %d = %c\n", *pc1, *pc2, (*pc1 + *pc2));
    printf("%c - %d = %c\n\n", *pc1, *pc2, (*pc1 - *pc2));

    int arr[3] = {10, 20, 30};
    int *p = arr;
    int **pp = &p;

    printf("Pointer arithmetic demonstration with int array:\n");
    printf("Initial: address = %p, value = %d\n", p, *p);
    p++;
    printf("After p++: address = %p, value = %d\n", p, *p);
    p--;
    printf("After p--: address = %p, value = %d\n", p, *p);
    printf("Access via pointer-to-pointer (**pp) = %d\n", **pp);

    return 0;
}
