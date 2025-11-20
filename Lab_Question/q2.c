#include <stdio.h>

int main(){
    float wt,ht;
    printf("Enter weigth in kgs\n");
    scanf("%f",&wt);
    printf("Enter height in meters\n");
    scanf("%f",&ht);

    float bmi=(1.0*wt)/(ht*ht);
    printf("BMI: %.2f\n",bmi);

    if(bmi<15)
    printf("Stravation");
    else if (bmi<=17.5)
        printf("Anorexic");
    else if(bmi<=18.5)
        printf("underweigth");
    else if(bmi<=24.9)
        printf("Ideal");
    else if(bmi<=25.9)
        printf("Overweigth");
    else if(bmi<=39.9)
        printf("Obese");
    else
        printf("Morbidity Obese");
    

    return 0;
}