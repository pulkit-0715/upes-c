#include <stdio.h>
#include <limits.h>
int main(){
    int n;
    printf("Enter size of array");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements of array");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int max = INT_MIN;
    int secmaax=INT_MIN;

    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            secmaax=max;
            max=arr[i];
        }

        else if(arr[i]<max && arr[i]>secmaax)
        {
            secmaax=arr[i];
        }
    }

    if(secmaax==INT_MIN)
    {
        printf("All elemnts are same");
        return 0;
    }

    else 
    printf("Max:%d Secondmax:%d ",max,secmaax);
    return 0;
}