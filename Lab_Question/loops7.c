/*
Calculate the sum of digits of a given integer.
*/
#include <stdio.h>

int main(){
    int n;
    printf("Enter a number");
    scanf("%d",&n);


    int temp=n;
    int sum=0;
    while (temp!=0)
    {
        sum+=(temp%10);
        temp/=10;
    }

    /*
    for(int temp=n ;temp>0;temp/=10)
    sum+=(temp%10);
    */
    printf("Sum = %d",sum);
    


    return 0;
}