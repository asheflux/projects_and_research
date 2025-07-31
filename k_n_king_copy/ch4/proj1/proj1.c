#include <stdio.h>

int main(void)
{

    int num = 0;

    printf("Enter a two-digit number: ");
    scanf("%2d", &num);
    int right_digit = num % 10;
    int left_digit = num / 10;
    printf("The reversal is: %d%d\n", right_digit, left_digit);
    
    return 0;
}
