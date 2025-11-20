/*Find the factorial of a given number*/
#include <stdio.h>

int main(){
    int n;
    printf("Enter a number");
    scanf("%d",&n);
    int fact=1;

    if(n<0){
        printf("number cant be negative");
        return 0;
    }

    for(int i=n;i>1;i--)
    fact*=i;
    printf("Factorial is %d",fact);
    return 0;
}