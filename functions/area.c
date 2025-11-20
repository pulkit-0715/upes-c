/*
Write a program to calculate the area of circle, rectangle and triangle using separate
functions.
*/
#include <stdio.h>
float triangle(float b, float h)
{
    return (b*h)/2;
}

float circle(float r){
    return 3.14*r*r;

}
float rectangle(float l,float b){
    return l*b;
}
int main(){
    float rr,ll,bb,hh;

    printf("Enter radius of circle\n");
    scanf("%f",&rr);
    printf("Area of circle is %.2f\n",circle(rr));

    printf("Enter length and breath of rectangle\n");
    scanf("%f %f",&ll,&bb);
    printf("Area of rectangle is %.2f\n",rectangle(ll,bb));

    printf("Enter base and heigth of triangle\n");
    scanf("%f %f",&bb,&hh);
    printf("Area of Triangle is: %.2f",triangle(bb,hh));

    return 0;
}