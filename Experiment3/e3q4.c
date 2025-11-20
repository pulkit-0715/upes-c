/* 
    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1
*/
#include <stdio.h>
int fact(int n) {
 int f = 1, i;
 for (i = 1; i <= n; i++)
 f *= i;
 return f;
}
int main() {
 int n = 5, i, j;
 for (i = 0; i < n; i++) {
 for (j = 0; j < n - i - 1; j++)
 printf(" ");
 for (j = 0; j <= i; j++) {
 printf("%d ", fact(i) / (fact(j) * fact(i - j)));
 }
 printf("\n");
 }
 return 0;
}