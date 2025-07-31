#include <stdio.h>

int main(void)
{

    printf("Enter amount of loan: ");
    float loan_balance = 0.0f;
    scanf("%f", &loan_balance);
    // Get user input for: amount of loan_balance, annual interest rate, monthly payment, # of months to print
    //****SCANF */
    //  convert the annual_interest_rate_as_percentage
    printf("Enter interest rate: ");
    float annual_interest_rate = 0.0f;
    scanf("%f", &annual_interest_rate);
    printf("Enter monthly payment: ");
    float monthly_payment = 0.0f;
    scanf("%f", &monthly_payment);

    printf("Enter number of months: ");
    int number_of_months = 0;
    scanf("%d", &number_of_months);

    int i = 1;
    // while (loan_balance > 0)
    while (number_of_months > 0)
    {
        float annual_percent = annual_interest_rate / 100.0f;
        // calculate monthly_interest_rate_as_percentage
        float monthly_interest_rate = annual_percent / 12.0f;
        // (1 + monthly_interest_rate_as_percentage) * loan_balance_amount

        // ALGORITHM //
        // A) Increase the loan_balance by the monthly interest rate (0.005) to find the amount due at the end of the month
        loan_balance = (1 + monthly_interest_rate) * loan_balance;
        // B) Pay down the loan_balance by the constant monthly payment amount (386.66)
        loan_balance = loan_balance - monthly_payment;
        // C) Print the remaining balance to the user
        printf("Balance remaining after month %d: $%.2f\n", i, loan_balance);
        // D) Repeat A & B for i months

        number_of_months--;
        i++;
    }
}
