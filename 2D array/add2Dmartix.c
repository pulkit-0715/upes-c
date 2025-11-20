 //Add two matrices.
//Take two m×n matrices A and B and compute C[i][j] = A[i][j] + B[i][j].

#include <stdio.h>


int main(){
    
    int n,m;
    printf("Enter size of  1st 2D array\n");
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


    int p,q;
    printf("Enter size of  2nd 2D array\n");
    scanf("%d %d",&p,&q);
    int brr[p][q];

    if(n!=p || m!=q)
    {
        printf("Can not add\n Size must be same");
        exit(0);
    }
    printf("Enter elemnts\n");

    for(int i=0;i<p;i++)
    {
        for(int j=0;j<q;j++)
        {
            scanf("%d",&brr[p][q]);   
        }
    }

    int c[n][p];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++) {
            c[i][j] = 0;
            for (int k = 0; k < m; k++)
                c[i][j] += arr[i][k] * brr[k][j];
        }

    printf("After mupltiplication:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }    
}