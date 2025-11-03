#include <stdio.h>

int power(int x, int n);

int main(void)
{

    // ask the user to insert the value of x and n
    printf("Enter the value of x: ");
    int x;
    scanf("%d", &x);

    printf("Enter the value of n: ");
    int n;
    scanf("%d", &n);

    // call a function named power to calculate x ^ n
    int result = power(x, n);

    // display the result from the function
    printf("The result: %d\n", result);

    return 0;
}

// the function named power
// 3^3
// 3 * 3 * 3 = 27
// GOING THROUGH RECURSION
// power(3,3) = 27
// power(3,2) = 9
// power(3,1) = 3
// power(3,0) = 1

// 3 * (3 * (3 * (1))

// WHEN N IS AN EVEN NUMBER
// x^2 == x * x
// (x*5.83736)^2 ==
// x = (x * 5.somethingsomething)^2
// 3.14^2 == 3.14 * 3.14
// (x + 1.14)^2 == (x+1.14) * (x+1.14)

// something * something = something_squared
// x^n == x^(n/2)^2 == x^(n/2) * x^(n/2)
// 3^20 = 81
// 3^(20/2)^2
// (3^10)^2
// 9^2 = 81

// WHEN N IS AN ODD NUMBER
// x^n == x * x^(n-1)

int power(int x, int n)
{
    // x = 3, n = 3
    if (n == 0)
        return 1;

    // when n is odd, then n % 2 == 1
    int is_odd = n % 2;

    int result = 0;
    if (is_odd)
        result = x * power(x, n - 1);
    else
        result = power(x, n / 2) * power(x, n / 2);

    return result;
}