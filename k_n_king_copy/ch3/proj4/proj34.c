#include <stdio.h>

int main(void)
{
    printf("Enter phone number [(xxx) xxx-xxxx]: ");

    int first_three_digits = 0;
    int second_three_digits = 0;
    int last_four_digits = 0;

    scanf("(%d) %d-%d", &first_three_digits, &second_three_digits, &last_four_digits);
    printf("%.3d.%.3d.%.4d\n", first_three_digits, second_three_digits, last_four_digits);

    return 0;
}
