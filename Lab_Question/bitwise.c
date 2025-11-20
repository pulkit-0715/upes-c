//to perform bitwize operations
#include <stdio.h>

int main(){
     int a,b;
    printf("Enter 2 numbers\n");
    scanf("%d %d",&a,&b);
    if(a^b)
    printf("Numbers are not same");
    else
    printf("Numbers are same");
}