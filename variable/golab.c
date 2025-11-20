#include <stdio.h>
int nn=10;
int twox(int n){
    n=n+n;
    return n;
}
int main(){
    for(int i =1;i<=nn;i++){
        printf("%d ",i);
    }
    nn=twox(nn);
    printf("\n");
    for(int i =1;i<=nn;i++){
        printf("%d ",i);
    }
    return 0;
}