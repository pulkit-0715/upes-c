#include <stdio.h>

int main(){
    int n;
    printf("Enter value of n\n");
    scanf("%d",&n);
    
    int ct=0;
    for(int i =1;i<=n/2;i++){
        if(n%i==0)
        ct=ct+1;
    }

    printf("Numbers of factros: %d",ct);
    return 0;
}