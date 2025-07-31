// name: proj6.c
// purpose: Calculate polynomial using Horner's Rule
// author: embercircuit

#include <stdio.h>

int main(void)
{
    int x = 0;
    printf("Enter the value of x: ");
    scanf("%d", &x);

    int result = ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6;
    printf("The result is: %d\n", result);

    return 0;
}