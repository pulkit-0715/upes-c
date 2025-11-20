/*WAP to check if three points (x1,y1), (x2,y2) and (x3,y3) 
are collinear or not.*/
#include <stdio.h>

int main(){
    int x1,y1,x2,y2,x3,y3;
    printf("Enter x1 y1\n");
    scanf("%d %d",&x1,&y1);
    
    printf("Enter x2 y2\n");
    scanf("%d %d",&x2,&y2);

    printf("Enter x3 y3\n");
    scanf("%d %d",&x3,&y3);

    int area=(x2*y3-y2*x3) -(x1*y3-x3*y1)+(x1*y2-x2*y1);

    if (area ==0)
    printf("\nCollinear");
    else
    printf("\nnot collinear");
    return 0;
}