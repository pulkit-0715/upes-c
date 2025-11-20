/*Develop a recursive and non-recursive function FACT(num) to find the factorial of a number, n!, defined by FACT(n) = 1, if n = 0. Otherwise, FACT(n) = n * FACT(n-1). Using this function, write a C program to compute the binomial coefficient. Tabulate the results for different values of n and r with suitable messages.*/
#include <stdio.h>

int FACT_recursive(int n) {
    if (n == 0)
        return 1;
    else
        return n * FACT_recursive(n - 1);
}


int FACT_iterative(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

int binomial_coefficient(int n, int r) {
    return FACT_recursive(n) / (FACT_recursive(r) * FACT_recursive(n - r));
}

int main() {
    int n, r;

    printf("Enter value of n: ");
    scanf("%d", &n);

    printf("Enter value of r: ");
    scanf("%d", &r);

    if (r > n || n < 0 || r < 0) {
        printf("Invalid input! r should be <= n and both non-negative.\n");
        return 0;
    }

    printf("\nFactorial (recursive) of %d = %d\n", n, FACT_recursive(n));
    printf("Factorial (non-recursive) of %d = %d\n", n, FACT_iterative(n));

    printf("\nBinomial Coefficient C(%d, %d) = %d\n", n, r, binomial_coefficient(n, r));

    printf("  n | r | nCr (C(n, r))\n");
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            printf(" %2d | %2d |  %6d\n", i, j, binomial_coefficient(i, j));
        }
    }


    return 0;
}
