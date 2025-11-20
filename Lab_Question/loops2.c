/*Calculate the sum of the first 50 natural numbers using for loop.*/
#include <stdio.h>

int main(){
    int sum=0;
    for(int i =1;i<=50;i++)
        sum+=i;

    printf("%d ",sum);
    return 0;
}