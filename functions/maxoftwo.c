/*. Write a function to find the maximum of two number*/
#include <stdio.h>
int maxi(int a, int b){
    if(a>b)
    return a;
    else if(b>a)
    return b;
    else 
    return -1;
}

int main(){
    int a ,b;
    printf("Enter values");
    scanf("%d %d",&a,&b);
    printf("Maximum is:%d",maxi(a,b));
    return 0;
}