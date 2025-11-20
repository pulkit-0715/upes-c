#include <stdio.h>

int main(){
    long long n,a=0,b=1,c;
    printf("Enter nth position");
    scanf("%lld",&n);
    if (n<3)
    {
        printf("2 value are minimum");
        return 0;
    }
    
    printf("%lld %lld ",a,b);
    for (int i = 0; i <n-2; i++)
    {
        c=a+b;
        a=b;b=c;
        printf("%lld ",c);
    }
    

    return 0;
}