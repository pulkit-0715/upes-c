#include <stdio.h>
int main(){
       float a, b;
       printf("Enter two numbers\n");
    scanf("%f %f", &a, &b);

    printf("Sum = %.2f\n", a + b);
    printf("Diff= %.2f\n", a - b);
    printf("Product = %.2f\n", a * b);
    if(b==0)
    {
        printf("Error , divisor can not be zero");
        return 0;
    }
    else 
    printf("Quotient = %.2f\n", a /b);

    return 0;
}