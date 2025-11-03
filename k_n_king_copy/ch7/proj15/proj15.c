#include <stdio.h>

int main(void)
{
    // 1. we ask the user to insert a positive number
    printf("Enter a positive integer: ");
    int n = 0;
    scanf("%d", &n);

    // 2. Loop:
    //  we take n and multiply it by n - i;
    long double factorial = 1.0;
    int i = 1;
    while (i <= n)
    {
        factorial *= i;
        // validate that factorial is positive
        //  if factorial is negative:
        //   -- 1. report to the user that the factorial of "i" went negative with a value of "factorial"
        //  -- 2. quit the program
        if (factorial < 0)
        {
            printf("**ERROR: The Factorial went negative!\n");
            printf("factorial of i:%d is:%Lf\n", i, factorial);
            return 1;
        }

        printf("factorial of i:%d is:%Lf\n", i, factorial);
        i++;
    }

    // 3. Report the factorial to the user
    printf("Factorial of %d is %Lf\n", n, factorial);

    return 0;
}

// Factorial
// Loop:
// 1: factorial = 5 * 4 = 20
// 2: factorial = factorial * 3 = 60
// 3: factorial * 2 = 120
// 4: factorial * 1 = 120

// factorial = 1
// Loop:
// i=1: factorial *= i = 1
// i=2: factorial *= i = 2
// i=3:

// 5! = 5 * 4 * 3 * 2 * 1 = 120
// 6! = 6 * 5! = 6 * 120 = 720
// 15! = a very large number
// n * (n-1) * (n-2) * .... * 1