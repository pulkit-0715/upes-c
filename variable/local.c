#include <stdio.h>
int sumofdigits(int nn){
    int sum=0;
    while(nn>0)
    {
        sum+=(nn%10);
        nn/=10;
    }
    return sum;
}
int main(){
    int n;
    printf("Enter Number\n");
    scanf("%d",&n);
    int ss=sumofdigits(n);
   // printf("Sum %d",sum); 
   //error trying to ecxess 
   //"sum"(local variale of fun. sumofdigits)outside the function
   printf("Sum: %d",ss);

    return 0;
}