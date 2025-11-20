//Find the transpose of a matrix.
//Given a matrix A of size m×n, print its transpose Aᵀ of size n×m.


#include <stdio.h>

void input(int n, int m ,int arr[n][m])
{   
    printf("Enter elements\n");
    for(int i =0;i<n;i++)
    {   for(int j=0;j<m;j++)
        {
            scanf("%d",&arr[i][j]);
        }

    }
}
int main(){
    
    int n,m;
    printf("Enter size of 2D array\n");
    scanf("%d %d",&n,&m);
    int arr[n][m];
    input(n,m,arr);

    printf("Transpose\n");
    for(int j=0;j<m;j++)
    {
        for(int i=0;i<n;i++)
        {
            printf("%d ",arr[i][j]);   
        }
        printf("\n");
    }
    return 0;
}