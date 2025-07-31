#include <stdio.h>

int main(void)
{
    int num = 0;
    printf("Enter a three-digit number: ");
    scanf("%3d", &num);

    int last_digit = num % 10;
    int first_digit = (num / 10) / 10;
    int mid_digit = (num / 10) %  10;
    printf("The reversal is: %d%d%d\n", last_digit, mid_digit, first_digit);
    //printf("test: %d%d\n", last_digit, first_digit);
    return 0;
}
