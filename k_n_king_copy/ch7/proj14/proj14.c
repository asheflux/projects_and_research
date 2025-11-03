#include <stdio.h>
#include <math.h>

int main(void)
{

    // 1. ask the user to provide a positive integer
    printf("Enter a positive number: ");
    int number_input = 0;
    scanf("%d", &number_input);

    // 2: Loop 5 times

    double x = (double)number_input;
    double average = 1.0;
    double y = average;
    int i = 0;
    while (i < 1000)
    {
        // 2a. we start a loop where y has just been set to the previous average (starting at 1)

        // 2b. we divide x by y
        double temp = x / y;

        // 2c. we get the average of y and x/y
        average = (y + temp) / 2;

        // 2d. Validate the absolute difference of "average - y" is greater "0.00001 * y"
        double difference = fabs(average - y);
        double limit = 0.00001 * y;
        if (difference < limit)
            break;
        // 2e. assign the average to y
        y = average;

        i++;
    }

    // 3. return the square root to the user
    printf("Square root: %g\n", y);
    printf("Solved in %d iterations", i);

    return 0;
}