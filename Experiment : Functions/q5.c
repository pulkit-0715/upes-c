/*
Develop a function REVERSE (str) that accepts a string argument. Write a C program that
invokes this function to find the reverse of a given string.
*/
#include <stdio.h>
#include <string.h>

void REVERSE(char str[],int n) {
    char revstr[1000];
    int i;

    for (i = 0; i < n; i++) {
        revstr[i] = str[n - 1 - i];
    }
    revstr[i] = '\0';

    printf("Reversed String: %s\n", revstr);
}

int main() {
    char str[1000];
    printf("Enter String: ");
    fgets(str, sizeof(str), stdin);
    
     int n = strlen(str);

    if (n > 0 && str[n - 1] == '\n')
        str[--n] = '\0';

    REVERSE(str,n);

    return 0;
}
