// Find the largest element in a 2D array.
//Traverse the matrix and return the maximum value present in it.
#include <stdio.h>
#include <limits.h>
int main(){
    int n,m;
    printf("Enter size of 2D array\n");
    scanf("%d %d",&n,&m);
    int arr[n][m];
    int largest=INT_MIN;
    printf("Enter elemnts\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&arr[i][j]);
            if(arr[i][j]>largest)
            largest=arr[i][j];
        }
    }
    printf("Largets: %d",largest);
    return 0;
}