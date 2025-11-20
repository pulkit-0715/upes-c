/* WAP to enter numbers till the user wants. At the end, display
the count of positive, negative, and zeroes entered.
Logic: Use a loop (`while` or `do-while`) to continuously accept numbers. Use counters for positive,
negative, and zero. Stop when user chooses not to continue.*/

#include <stdio.h>
#include <stdbool.h>
int main() {

 int num, pos = 0, neg = 0, zero = 0;
 bool ct=true;
 printf("Enter a number: ");
 while (ct)
 {
   scanf("%d", &num);
    if (num > 0)
    pos++;
   else if (num < 0)
   neg++;
   else
   zero++;
    printf("Do you want to continue (y/n)? ");
   char ch;
   scanf(" %c", &ch);
   if(ch=='n' || ch=='N')
    ct=false;
   else if(ch=='Y' || ch =='y')
    ct=true;
   else
      {
      printf("Invalid choice \n terminating program");
      break;
      }
   }

 printf("\nCount of Positive numbers = %d", pos);
 printf("\nCount of Negative numbers = %d", neg);
 printf("\nCount of Zeroes = %d\n", zero);
 return 0;
}