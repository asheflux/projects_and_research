#include <stdio.h>

int main(void)
{

    // Get the income from the user
    float income = 0.00f;
    printf("Enter the income value: ");
    scanf("%f", &income);

    // Calculate the tax due
    float tax = 0.00f;
    if (income < 750.00f) //  0 to 750, 1% of income
        tax = 0.01f * income;
    else if (income <= 2250.00f) // $750-$2,250,  $7.50 plus 2% of amount over $750
        tax = 7.50f + (0.02f * (income - 750.00f));
    else if (income <= 3750.00f) // $2,250-$3,750, $37.50 plus %3 of amount over $2,250
        tax = 37.50f + (0.03f * (income - 2250.00f));
    else if (income <= 5250) // $3,750-$5,250, $82.50 plus 4% of amount over $3,750
        tax = 82.50f + (0.04f * (income - 3750.00f));
    else if (income <= 7000) // $5,250-$7.000, $142.50 plus %5 of amount over $5,250
        tax = 142.50f + (0.05f * (income - 5250.00f));
    else // Over $7,000, $230.00 plus 6% of amount over $7,000
        tax = 230.00f + (0.06f * (income - 7000.00f));

    printf("Tax due is %.2f", tax);

    return 0;
}