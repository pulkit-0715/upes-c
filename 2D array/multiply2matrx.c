//Multiply two matrices.
//Given matrix A (m×p) and matrix B (p×n), compute their product A×B.

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
    if(m!=p)
    {
        printf("Not multiplicable");
        return 0;
    }
    printf("Enter elemnts\n");

    for(int i=0;i<p;i++)
    {
        for(int j=0;j<q;j++)
        {
            scanf("%d",&brr[i][j]);   
        }
    }

    int c[n][q];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < q; j++) {
            c[i][j] = 0;
            for (int k = 0; k < m; k++)
                c[i][j] += arr[i][k] * brr[k][j];
        }

    printf("After mupltiplication:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < q; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }    
}