#include <stdio.h>


void demo() {
     int regular_var = 1;

    static int static_var = 1;

    printf("Regular variable: %d\n", regular_var);
    printf("Static variable: %d\n", static_var);

    regular_var++;
    static_var++;
}

int main() {
    printf("Calling demo() first\n");
    demo();

    printf("\nCalling demo()second\n");
    demo();

    printf("\nCalling demo()third \n");
    demo(); 

    return 0;
}

