/*
WAP to read a list of integers and store it in a single dimensional array. 
Write a C program to
print the second largest integer in a list of integers
*/

#include <stdio.h>
#include<limits.h>

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

    int first=INT_MIN, second=INT_MIN;
    for (int i = 0; i < n; i++)
    {
       if(arr[i]>first)
       {
        second=first;
        first=arr[i];
       }
       else if(arr[i]>second && arr[i<first])
       second =arr[i];
    }

    printf("Second largest elemnet is %d",second);
    
    
    
    return 0;
}