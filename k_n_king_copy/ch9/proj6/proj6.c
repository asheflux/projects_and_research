

#include <stdio.h>

int polynomial(int x);

int main(void)
{

    // ask the user for value of x
    printf("Enter the value of x: ");
    int x;
    scanf("%d", &x);

    // call the polynomial function
    int result = polynomial(x);

    // display the result to the user
    printf("The result of the polynomial is: %d \n", result);

    return 0;
}

int polynomial(int x)
{
    // 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6

    // result = 3x^5 + 2x^4 - 5x^3

    // TEST WITH X = 1
    // 3 + 2 - 5 - 1 + 7 - 6 = 0

    // TEST WITH X = 3
    // 3*243 + 2*81 - 5*27 - 9 + 7*3 - 6
    // 729 + 162 - 135 - 9 + 21 - 6
    // 762

    int result = 3 * x * x * x * x * x;
    result += 2 * x * x * x * x;
    result -= 5 * x * x * x;
    result -= x * x;
    result += 7 * x;
    result -= 6;

    return result;
}