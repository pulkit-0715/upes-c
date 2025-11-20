// to perform contional assigment
#include <stdio.h>

int main(){
     int a,b;
    printf("Enter 2 numbers\n");
    scanf("%d %d",&a,&b);
    a-=b;
    printf("Diffrernce is: %d",a);
    return 0;
}