/*Develop a recursive function FIBO (num) that accepts an integer argument. Write a C program
that invokes this function to generate the Fibonacci sequence up to num.*/

#include <stdio.h>
void FIBO(int num){
    int a=0,b=1;
    printf("%d %d",a,b);
    int c=0;
    for(int i =1;i<=num;i++)
    {
        c=a+b;
        a=b;
        b=c;
        printf(" %d",c);
    }
}
int main(){
    int n;
    printf("Enter value of n");
    scanf("%d",&n);
    FIBO(n);
    
    return 0;
}