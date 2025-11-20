//Search for an element in a 2D array.
//Take an m×n matrix and a key. Search for the key and print its row and column index if found.

#include <stdio.h>

int main(){
    int n,m;
    printf("Enter size of array\n");
    scanf("%d %d",&n,&m);
    int arr[n][m];
    
    printf("Enter elements\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    int target;
    printf("Enter target\n");
    scanf("%d",&target);
       
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
           if(target==arr[i][j])
           {
            printf("Found at %d %d",i,j);
            return 0;
           }
        }
    }
    printf("Not Found -1 -1");

    return 0;
}