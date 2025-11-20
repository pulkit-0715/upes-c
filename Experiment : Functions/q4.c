/*
Develop a C function ISPRIME (num) that accepts an integer argument and returns 1 if the
argument is prime, a 0 otherwise. Write a C program that invokes this function to generate prime
numbers between the given ranges
*/
#include <stdio.h>
int ISPRIME(int n){
    if(n==0 || n==1)
    return 0;
    if(n==2)
    return 1;
    if(n%2==0)
    return 0;
    

    for(int i =3;i*i<n;i++)
    if(n%i==0)
    return 0;

    return 1;

}
int main(){
    int n;
    printf("Enter value of n\n");
    scanf("%d",&n);
    printf("%d",ISPRIME(n));
    return 0;
}