#include <stdio.h>

int main(void) {
    double n, sum = 0.0;

    //BUG: change the messages to "doubles"
    printf("This program sums a series of integers.\n");

    printf("Enter integers (0 to terminate): ");
    scanf("%lf", &n);
    while(n != 0.0) {
        //TIP: use +=
        sum = sum + n;
        scanf("%lf", &n);
    }
    //TIP: don't limit the decimal places.  Instead, use %g which will print only as many decimals as needed for precision.
    printf("The sum is %.2lf\n", sum);

    return 0;
}
