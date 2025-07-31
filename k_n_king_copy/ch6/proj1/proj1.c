/* Finds the largest positive non-zero number in a series of numbers entered by the user */
// A zero or negative number ends the series

// 60 38.8 4.89 100.62 75.2295 0
//  Enter a number: 60
//  Enter a number: 38.3
//  Enter a number: 4.89
//  Enter a number: 100.62
//  Enter a number: 75.2295
//  Enter a number: 0
//  The largest number entered was 100.62

#include <stdio.h>

int main(void)
{
    float n = 0.0f;
    float largest = n;

    do
    {
        printf("Enter a number: ");
        scanf("%f", &n);
        largest = (n > largest) ? n : largest;
        // if (n > largest)
        //     largest = n;
    } while (n > 0);

    printf("The largest number entered was %g\n", largest);

    return 0;
}