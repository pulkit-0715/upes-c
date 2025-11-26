/*2.Perform pointer arithmetic (increment and decrement) on pointers of different data types.
Observe how the memory addresses change and the effects on data access. */

#include <stdio.h>

int main() {
    int a[3] = {10, 20, 30};
    float b[3] = {1.1, 2.2, 3.3};
    char c[3] = {'x', 'y', 'z'};

    int *p1 = a;
    float *p2 = b;
    char *p3 = c;

    printf("Initial: int *p1 = %p, value = %d\n", p1, *p1);
    p1++;
    printf("After p1++: %p, value = %d\n", p1, *p1);
    p1--;
    printf("After p1--: %p, value = %d\n\n", p1, *p1);

    printf("Initial: float *p2 = %p, value = %.1f\n", p2, *p2);
    p2++;
    printf("After p2++: %p, value = %.1f\n", p2, *p2);
    p2--;
    printf("After p2--: %p, value = %.1f\n\n", p2, *p2);

    printf("Initial: char *p3 = %p, value = %c\n", p3, *p3);
    p3++;
    printf("After p3++: %p, value = %c\n", p3, *p3);
    p3--;
    printf("After p3--: %p, value = %c\n", p3, *p3);

    return 0;
}
