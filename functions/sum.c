/*2. Write a function int add(int a, int b) that returns the sum of two numbers.*/
#include <stdio.h>
int add(int a,int b)
{
    return a+b;
}
int main(){
    int a,b;
    printf("Enter values of a,b\n");
    scanf("%d %d",&a,&b);
    int sum = add(a,b);
    printf("Sum is:%d",sum);
    return 0;
}