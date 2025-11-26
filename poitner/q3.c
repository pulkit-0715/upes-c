
/*3.Write a function that accepts pointers as parameters. Pass variables by reference using
*/
#include <stdio.h>

void updateValues(int *x, float *y, char *z) {
    *x = *x + 5;
    *y = *y * 2;
    *z = *z + 1;
}

int main() {
    int a = 10;
    float b = 3.5;
    char c = 'A';

    printf("Original int: %d\n", a);
    printf("Original float: %.2f\n", b);
    printf("Original char: %c\n", c);
    updateValues(&a, &b, &c);

    printf("\nUpdated int: %d\n", a);
    printf("Updated float: %.2f\n", b);
    printf("Updated char: %c\n", c);

    return 0;
}
