/*
xWrite a function that takes a number and returns 1 if prime, otherwise 0
*/
#include <stdio.h>
int prime(int a){
    if(a==2)
    return 1;
    if(a%2==0)
    return 0;
    if(a==0 || a==1)
    return 0;

    for(int i =3;i*i<a;i++)
    if(a%i==0)
    return 0;

    return 1;
}
int main(){
    int a;
    printf("Enter number\n");
    scanf("%d",&a);
    if(prime(a))
    {
        printf("Is prime \n1");
    }
    else
    printf("Not Prime \n0");
    return 0;
}