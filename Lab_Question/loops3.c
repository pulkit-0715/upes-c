/*Print the multiplication table of a number entered by the user.*/
#include <stdio.h>

int main(){
    int n;
    printf("Enter a number");
    scanf("%d",&n);
    for(int i=1;i<=10;i++)
    {
        printf("%d x %d = %d\n",n,i,n*i);
    }
    return 0;
}