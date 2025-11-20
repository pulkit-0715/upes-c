/*
 Write a program to check whether a number is even or odd using a function
 */
#include <stdio.h>
int oddeven(int a)
{
    if(a%2==0)
    return 1;
    else 
    return 0;
}
int main(){
    int a;
    printf("Enter number\n");
    scanf("%d",&a);
    if(oddeven(a))
        printf("Even");
    else
    printf("Odd");

    return 0;
}