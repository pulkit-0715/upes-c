/*
Write a function to check whether a number is palindrome or not.
*/
#include <stdio.h>
int pallen(int a)
{
    int copy =a;
    int pal=0;
    while(copy!=0)
    {
        int d=copy%10;
        pal=pal*10+d;
        copy/=10;
    }
    if(pal==a)
    return 1;
    else
    return 0;
}
int main(){
    int a;
    printf("Enter number\n");
    scanf("%d",&a);

    if(pallen(a)){
        printf("Palindrome");
    }
    else
    printf("Not Palindrome");
    return 0;
}