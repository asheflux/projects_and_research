#include <stdio.h>

int main(void)
{
    printf("Enter an expression: ");
    double digit = 0.0;
    double digit2 = 0.0;
    char operator;

    scanf("%lf%c%lf", &digit, &operator, &digit2);

    switch (operator)
    {
        case '+': digit = digit + digit2; break;
        case '-': digit = digit - digit2; break;
        case '*': digit = digit * digit2; break;
        case '/': digit = digit / digit2; break;
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
