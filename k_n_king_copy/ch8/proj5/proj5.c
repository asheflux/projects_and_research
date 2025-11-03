#include <stdio.h>

#define NUM_RATES ((int)(sizeof(value) / sizeof(value[0])))
#define INITIAL_BALANCE 100.00

int main(void)
{
    int i, low_rate_annual, num_years, year;
    double value[5];

    // Request annual interest rate and number of years from the user
    printf("Enter annual interest rate: ");
    scanf("%d", &low_rate_annual);
    printf("Enter number of years: ");
    scanf("%d", &num_years);

    printf("\nCompounded: Monthly\n");

    // Display the table column-headers
    printf("\nYears");
    for (i = 0; i < NUM_RATES; i++)
    {
        printf("%6d%%", low_rate_annual + i);
        value[i] = INITIAL_BALANCE;
    }
    printf("\n");

    // display the row header + data
    for (year = 1; year <= num_years; year++)
    {
        printf("%3d    ", year);
        for (i = 0; i < NUM_RATES; i++)
        {
            // compound the interest monthly
            float low_rate_monthly = low_rate_annual / 12.0f;
            int j = 0;
            while (j < 12)
            {
                value[i] += (low_rate_monthly + i) / 100.0 * value[i];
                j++;
            }
            printf("%8.2f", value[i]);
        }
        printf("\n");
    }
    return 0;
}
