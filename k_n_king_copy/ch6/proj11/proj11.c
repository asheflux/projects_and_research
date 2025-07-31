// Hello
//
// e = 1 + 1/1! + 1/2! + 1/3!....+1/n!
// 1! = 1
// 2! = 2 * 1
// 3! = 3 * 2 * 1
// 4! = 4 * 3 * 2 * 1
// n! = n * (n-1) * (n-2) * .....* 3 * 2 * 1
// 10! = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1

// loop to calculate a factorial
// need a loop to add every inverted factorial for n numbers

// 5!, the inverted version of 5! is 1/5!

//============
// FIRST DRAFT
// create a loop to print out:
// DRAFT1 Output: 1, 2, 6, 24
// DRAFT2: n = 4; Calculate e = 1 + 1/1 + 1/2 + 1/6 + 1/24 = 2.7082
// DRAFT2 Output: e = 2.7082

// (this is the math: e = 1!, 2!, 3!, 4!)
//============

#include <stdio.h>

int main(void)
{
    printf("Enter n: ");
    int n = 1;
    scanf("%d", &n);

    printf("Enter the limit: ");
    float limit = 1.0f;
    scanf("%f", &limit);

    float e = 1.0f;
    int i = 1;
    while (i <= n)
    {

        int factorial = 1;
        int j = 1;
        while (j <= i)
        {
            factorial = factorial * j;
            j++;
        }

        printf("%d, ", factorial);
        // "1, 2, 6, 24, "
        // (this is the math: e = 1 + 1/1! + 1/2! + 1/3! + 1/4!)
        // (this is the math: e = 1 + 1/1 + 1/2 + 1/6 + 1/24)
        float current_term = 1.0f / factorial;

        if (current_term < limit)
            break;

        e = e + current_term;
        printf("current value of e:%f\n", e);

        // DRAFT3: n=4, limit=0.05
        // DRAFT2: n = 4; Calculate e = 1 + 1/1 + 1/2=0.5 + 1/6=0.16666 + 1/24=0.04166 = 2.7082
        // Limit of e as n approaches infinity
        // DRAFT2 Output: e = 2.7082

        i++;
    }

    printf("e = %f\n", e);

    return 0;
}