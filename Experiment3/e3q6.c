/*WAP to print Ramanujan Numbers (up to a limit).*/
#include <stdio.h>
int main() {
 int a, b, c, d, limit, n1, n2;
 printf("Enter limit: ");
 scanf("%d", &limit);
 for (a = 1; a <= limit; a++) 
 {
    for (b = a; b <= limit; b++) 
    {
        n1 = a*a*a + b*b*b;
        for (c = 1; c <= limit; c++) 
        {
            for (d = c; d <= limit; d++) 
            {
                n2 = c*c*c + d*d*d;
                if (n1 == n2 && (a != c && b != d))
                {
                printf("%d = %d^3 + %d^3 = %d^3 + %d^3\n", n1, a, b, c, d);
                }
            }
         }
    }
 }
 return 0;
}