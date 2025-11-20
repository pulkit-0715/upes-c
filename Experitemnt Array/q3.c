/*WAP to read a list of integers and store it in a single dimensional array. Write a C program to
find the frequency of a particular number in a list of integers.*/
#include <stdio.h>

int main(){
    
    int n;
    printf("Enter size of array\n");
    scanf("%d",&n);
    int arr[n];

    printf("Enter elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]); 
    }


    int k;
    printf("Enter terget\n");
    scanf("%d",&k);
    int fq=0;

    for(int i=0;i<n;i++)
    {
        if(arr[i]==k)
        fq++;
    }  

    printf("Frequency %d",fq);
    return 0;
}