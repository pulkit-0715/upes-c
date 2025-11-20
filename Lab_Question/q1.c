#include <stdio.h>

void check_type(int aa,int bb, int cc){
    if(aa==bb&& cc==bb)
    printf("equlatral triangle");
    else if(aa==bb||bb==cc||cc==aa)
    printf("Iso-sceles, triangle");
    else if(((aa*aa)+(bb*bb)==cc*cc)||((aa*aa)+(cc*cc)==bb*bb)|| ((cc*cc)+(bb*bb)==aa*aa))
    printf("Right angle triangle");
    else
    printf("Scalene");


}

int main(){
    int a,b,c;
    printf("Enter 3 side\n");
    scanf("%d %d %d",&a,&b,&c);
    if(a+b<=c||b+c<=a||c+a<=b)
        printf("Not valid"); 
    
    else
    {
        printf("Valid Triangle\n");
        check_type(a,b,c);
       
    }
    
    return 0;
}