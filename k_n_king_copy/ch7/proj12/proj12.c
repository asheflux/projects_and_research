#include <stdio.h>

int main(void)
{
    printf("Enter an expression: ");
    double digit = 0.0;
    double temp = 0.0;
    double digit2 = 0.0;
    char operator;
    
    //TIP: temp is not needed.  Use "digit2" in place of temp.
    //TIP: Congratulations.  Your code is for this project is superior to mine for this project.  It's both easier to understand and looks cleaner.  Nice work.

    scanf("%lf%c%lf", &digit, &operator, &temp);

    switch (operator)
    {
        case '+': digit = digit + temp; break;
        case '-': digit = digit - temp; break;
        case '*': digit = digit * temp; break;
        case '/': digit = digit / temp; break;
        default: break;
    }

    while ((operator = getchar()) != '\n')
    {
        if (operator == ' ') continue;  // Skip spaces

        if (operator == '+')
        {
            scanf("%lf", &digit2);
            digit = digit + digit2;
        }
        else if (operator == '-')
        {
            scanf("%lf", &digit2);
            digit = digit - digit2;
        }
        else if (operator == '/')
        {
            scanf("%lf", &digit2);
            digit = digit / digit2;
        }
        else if (operator == '*')
        {
            scanf("%lf", &digit2);
            digit = digit * digit2;
        }
        else
        {
            printf("Invalid");
        }
    }

    printf("Result: %.1f\n", digit);

    return 0;
}
