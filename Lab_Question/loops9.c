/*Check if a given number is prime or not.*/
#include <stdio.h>

int main(){
    int n;
    printf("Enter a number\n");
    scanf("%d",&n);

    if(n==2)
    {
        printf("Prime");
        return 0;
    }
    if(n%2==0)
    {
        printf("Not prime");
        return 0;
    }
    if(n<=1)
    {
        printf("Not prime");
        return 0;
    }


    for(int i=3;i*i<=n;i++)
    if(n%i==0)
    {
        printf("Not prime");
        return 0;
    }

    printf("Prime");
    
    return 0;
}