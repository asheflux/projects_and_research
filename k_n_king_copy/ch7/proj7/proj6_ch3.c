/* Adds two fractions */

#include <stdio.h>

int main(void)
{
    int num1 = 0, denom1 = 0, num2 = 0, denom2 = 0, result_num = 0, result_denom = 0;

    printf("Enter two fractions seperated by a Plus sign: ");
    scanf("%d/%d+%d/%d", &num1, &denom1, &num2, &denom2);
 
    result_num = num1 * denom2 + num2 * denom1;
    result_denom = denom1 * denom2;

    printf("The sum is %d/%d\n", result_num, result_denom);

    return 0;
}
