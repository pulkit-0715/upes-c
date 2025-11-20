/*
Write a program to find the factorial of a number using a function.
*/
#include <stdio.h>
int fact(int a){
if(a==0)
return 1;
else
return a*fact(a-1);
}
int main(){
    int a;
    printf("Enter number\n");
    scanf("%d",&a);
    int factorial = fact(a);
    printf("Factorial is:%d",factorial);
    return 0;
}