#include <stdio.h>

int main(void)
{
    int x = 0;
    printf("Enter the value of x: ");
    scanf("%d", &x);

    int result = (3 * x * x * x * x * x) + (2 * x * x * x * x) - (5 * x * x * x) - (x * x) + (7 * x) - 6;
    printf("The result is: %d\n", result);

    return 0;
}