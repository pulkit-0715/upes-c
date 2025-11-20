// to perform realtional operations
#include <stdio.h>

int main(){
     int a,b;
    printf("Enter 2 numbers\n");
    scanf("%d %d",&a,&b);
    if(a>b)
    printf("%d is greater",a);
    else if(b>a)
    printf("%d is greater",b);
    else
    printf("no. are same");
    return 0;
}