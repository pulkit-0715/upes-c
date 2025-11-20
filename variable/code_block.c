#include <stdio.h>

void evenorodd(int nn)
{
 if(nn%2==0)
 printf("Even");
 else
 printf("Odd");   
}
int main(){
    int n,sum=0;
    printf("Enter number");
    scanf("%d",&n);
    int copy=n,tens=1;;


    while(copy>0)
    {
        int d=copy%10;
        sum+=d;
        copy/=10;
        tens*=10;
    }
    //printf("Last digit extarcted%d",d);
    //error;
    n=n*10;
    printf("Most significant digit: %d\n",n/tens);
    printf("Sum %d\n",sum);

    printf("Most signifiacant digit is ");
    //evenorodd(d)
    //error;

    evenorodd(n/tens);
    
    return 0;
}