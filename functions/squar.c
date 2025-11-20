/*. Write a program to calculate the square of a number using a function.*/
#include <stdio.h>
int squar(int a){
return a*a;
}
int main(){
    int a;
    printf("Enter Number\n");
    scanf("%d",&a);
    int sq=squar(a);
    printf("Squar is:%d",sq);
    return 0;
}