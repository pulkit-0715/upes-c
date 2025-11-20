//Print the matrix in row-major and column-major order.
//Row-major: print row by row
//Column-major: print column by column

#include <stdio.h>


int main(){
    
    int n,m;
    printf("Enter size of 2D array\n");
    scanf("%d %d",&n,&m);
    int arr[n][m];
    printf("Enter elemnts\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&arr[i][j]);   
        }
    }

    printf("Row wise\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
           printf("%d ",arr[i][j]);   
        }
        printf("\n");
    }

    printf("Column wise\n");
    for(int j=0;j<m;j++)
    {
        for(int i=0;i<m;i++)
        {
            printf("%d ",arr[i][j]);   
        }
        printf("\n");
    }
    return 0;
}