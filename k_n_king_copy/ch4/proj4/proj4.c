#include <stdio.h>

int main(void)
{

    printf("Enter a number between 0 and 32767: ");

    int number = 0;
    scanf("%5d", &number);

    printf("In octal, your number is: ");
    int dig_1 = number % 8;
    int dig_2 = (number / 8) % 8;
    number = number / 8;
    int dig_3 = (number / 8) % 8;
    number = number / 8;
    int dig_4 = (number / 8) % 8;
    number = number / 8;
    int dig_5 = (number / 8) % 8;
    printf("%d%d%d%d%d\n", dig_5, dig_4, dig_3, dig_2, dig_1);
    
    return 0;
}
