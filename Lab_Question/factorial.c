#include <stdio.h>

int main(){
    int n;
    long long fact=1;
    printf("Enter Number\n");
    scanf("%d",&n);
    
    if (n<0)
    {
        printf("Invalid");
        return 0;
    }
    
    for(int i=1;i<=n;i++)
    {
        fact*=i;
    }
    printf("Factorial: %lld",fact);
    return 0;
}