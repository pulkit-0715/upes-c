#include <stdio.h>


int main(){
    int l1,b1,l2,b2,l3,b3;
    printf("Enter length breath for 1st\n");
    scanf("%d %d",&l1,&b1);
    
    printf("Enter length breath for 2nd\n");
    scanf("%d %d",&l2,&b2);


    printf("Enter length breath for 3rd\n");
    scanf("%d %d",&l3,&b3);
    
    int p1=2*(l1+b1);
    int p2=2*(l2+b2);
    int p3=2*(l3+b3);

    (p1 >= p2 && p1 >= p3) ? printf("Perimeter 1 is the greatest: %d\n", p1) :
    (p2 >= p3) ? printf("Perimeter 2 is the greatest: %d\n", p2) :
    printf("Perimeter 3 is the greatest: %d\n", p3);    

    
    return 0;
}