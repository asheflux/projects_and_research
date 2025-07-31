#include <stdio.h>

int main(void)
{

    //input from user: loan amount, interest rate, monthly payment
    printf("Enter amount of loan: ");
    float amount_of_loan = 0.0f;
    scanf("%f", &amount_of_loan);  //20000

    printf("Enter annual interest rate: ");
    float annual_interest_rate = 0.0f;
    scanf("%f", &annual_interest_rate);  //6.0

    printf("Enter monthly payment: ");
    float monthly_payment = 0.0f;
    scanf("%f", &monthly_payment); //386.66

    // loan balance and monthly rate
    float loan_balance = amount_of_loan; //20000
    float monthly_interest_rate = (annual_interest_rate / 100) / 12.0f;  //0.005

    //payment calculations
    float loan_balance_with_interest = loan_balance * (1 + monthly_interest_rate);
    loan_balance = loan_balance_with_interest - monthly_payment;
    float first_payment = loan_balance;

    //payment calculations
    loan_balance_with_interest = loan_balance * (1 + monthly_interest_rate);
    loan_balance = loan_balance_with_interest - monthly_payment;
    float second_payment = loan_balance;

    loan_balance_with_interest = loan_balance * (1 + monthly_interest_rate);
    loan_balance = loan_balance_with_interest - monthly_payment;
    float third_payment = loan_balance;

    // output the first payment, second payment, third payment
    printf("\n");
    printf("Balance remaining after the first payment: $%.2f\n", first_payment);
    printf("Balance remaining after the second payment: $%.2f\n", second_payment);
    printf("Balance remaining after the third payment: $%.2f\n", third_payment);
    return 0;
}



/*
    Enter amount of loan: __20000.00__
    Enter annual interest rate: __6.0__
    Enter monthly payment: __386.66__

    /////////////////

    annual interest rate is 6.0
    annual interest rate as a percentage = 6.0 / 100 = 0.06
    monthly rate is .06 / 12 = 0.005

    20000 * 1.005 = 20100
    20100 - 386.66 = 19713.34

    monthly_interest_rate = annual_interest_rate / 12;
    loan_balance_with_interest = loan_balance * (1 + monthly_interest_rate);
    loan_balance = loan_balance_with_interest - monthly_payment


    /////////////////
    Balance remaining after first payment: $19713.34
    Balance remaining after second payment: $19425.25
    Balance remaining after third payment: $19135.71
*/