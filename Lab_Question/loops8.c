/*
Compute a^b (a raised to the power b).
*/
#include <stdio.h>

int main(){
    int a;
    printf("Enter a number\n");
    scanf("%d",&a);

    int b;
    printf("Enter a power\n");
    scanf("%d",&b);
    float power=1.0;

    if(b>=0)
    for(int i=b;i>0;i--)
    power*=a;
   else
   {
    for(int i=(-1)*b;i>0;i--)
    power*=a;
    power=1.0/power;
   }
    printf("a^b = %.3f",power);
    

    return 0;
}