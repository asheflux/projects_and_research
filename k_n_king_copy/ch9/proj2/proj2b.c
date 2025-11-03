#include <stdio.h>

float calc_tax(float income);

int main(void)
{

    float income = 0.0f;
    printf("Enter the taxable income: ");
    scanf("%f", &income);

    float tax = calc_tax(income);
    printf("Tax due: %.2f\n", tax);

    return 0;
}

float calc_tax(float income)
{
    // Calculate the tax
    float tax = 0.0f;
    if (income < 0)
        printf("Invalid income: must be 0 or higher");
    else if (income <= 750.00)
        tax = 0.01 * income;
    else if (income <= 2250)
        tax = 7.50 + (0.02 * (income - 750));
    else if (income <= 3750)
        tax = 37.50 + (0.03 * (income - 2250));
    else if (income <= 5250)
        tax = 82.5 + (0.04 * (income - 3750));
    else if (income <= 7000)
        tax = 142.5 + (0.05 * (income - 5250));
    else
        tax = 230 + (0.06 * (income - 7000));

    return tax;
}
