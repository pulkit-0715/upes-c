#include <stdio.h>

int main(){
    int a,b;
    printf("Enter 2 no.");
    scanf("%d %d",&a ,&b);
    int s=a+b;
    int d=a-b;
    int p=a*b;
    float q=a/(1.0*b);
    printf("Sum is %d\n",s);
    printf("Diff is %d\n",d);
    printf("product is %d\n",p);
    printf("quotient is %.1f\n",q);
    return 0;
}