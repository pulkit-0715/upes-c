#include <stdio.h>

int main(){
    int n,a=0,b=1,c;
    printf("Enter nth position");
    scanf("%d",&n);
    printf("%d %d ",a,b);
    for (int i = 0; i <n-2; i++)
    {
        c=a+b;
        a=b;b=c;
        printf("%d ",c);
    }
    

    return 0;
}