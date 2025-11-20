/*Develop a recursive function GCD (num1, num2) that accepts two integer arguments. Write a C
program that invokes this function to find the greatest common divisor of two given integers.*/
#include <stdio.h>
    int gcd(int a,int b){
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;

    }
int main(){
    int x, y;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);
    printf("GCD of %d and %d is %d\n", x, y, gcd(x, y));
    return 0;
}