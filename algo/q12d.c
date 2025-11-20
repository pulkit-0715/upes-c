//WAP to print 2D array col and rowwise

#include <stdio.h>

int main(){
    int n,m;
    printf("Enter size of row and coloum\n");
    scanf("%d %d",&n,&m);
    int arr[n][m];
    printf("Enter array elements\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    printf("\n Transpose matirx \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
           printf("%d",arr[j][i]);
        }
        printf("\n");
    }

    return 0;
}