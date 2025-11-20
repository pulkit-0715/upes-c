/*WAP to read a list of integers and store it in a single dimensional array. Write a C program to
count and display positive, negative, odd, and even numbers in an array.
*/

#include <stdio.h>
void count(int n,int arr[]){
    int pos=0,neg=0,odd=0,even=0;
    for(int i=0;i<n;i++){
        if(arr[i]>0)
        pos++;
        if(arr[i]<0)
        neg++;

        if(arr[i]%2==0)
        even++;
        else 
        odd++;
    }

    printf("Positive:%d\n",pos);
    printf("Negative:%d\n",neg);
    printf("Even:%d\n",even);
    printf("Odd:%d\n",odd);
}

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

    count(n,arr);
    return 0;
}