/*
WAP a progam to print prime factor of a given number
*/

#include <stdio.h>
int prime(int i){
    if(i==2)
    return 1;
    if(i%2==0||i==1||i==0)
    return 0;
    for(int j =3;j*j<=i;j++)
    {
        if(i%j==0)
        return 0;
    }
    return 1;
}
int main(){
    int n;
    printf("Enter value of n\n");
    scanf("%d",&n);
    if(n<0)
    {
        printf("Not valid for negative nnumbers");
        return 1;
    }
    if(n==1||n==0)
    {
    printf("No factor exists, 0");
    return 0;
    }

    if(prime(n)==1)
    {
        printf("%d",n);
        return 0;
    }

    for(int i=2;i<=n;i++)
    {
        if((prime(i)==1)&&(n%i==0))
        printf("%d ",i);
    }

    return 0;
}