/*WAP to calculate the population growth for 10 years.*/
#include <stdio.h>
int main() {
 int i;
 double population = 100000;
 for (i = 1; i <= 10; i++) {
 population = population + (population * 0.1);
 printf("Year %d: Population = %.0f\n", i, population);
 }
 return 0;
}