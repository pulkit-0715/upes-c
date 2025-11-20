// Sum of all elements in 2D array #include <stdio.h>
#include <stdio.h>

int main(){
    int n,m;
    printf("Enter size of 2D array\n");
    scanf("%d %d",&n,&m);
    int arr[n][m];
    int sum=0;
    printf("Enter elemnts\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&arr[i][j]);
            sum+=arr[i][j];
        }
    }

    printf("Sum: %d",sum);
    return 0;
}