#include <stdio.h>

int main(void)
{

    printf("Enter a number: ");
    long long int n = 0;
    scanf("%lld", &n);
    printf("You entered: %lld\n", n);
    int digits_seen[10] = {0};

    while (n > 0)
    {
        int digit = n % 10; // 4
        digits_seen[digit]++;
        n /= 10;
        printf("current value of n: %lld\n", n);
    }

    // digit
    // print "Repeated digit(s): "
    printf("Repeated digit(s): ");

    // loop through digit array, looking at each element's value.

    // 939577 -> 7 9

    // itoa
    //  use mod to chop off the right-most digit, then store it as a character in a char array
    //  int number = 939577 % 10 = 7
    //  reversed_digit[0]: '7' = '0' + 7
    //  reversed_digit[1]: '7'
    //  reversed_digit[2]: '5'
    //  reversed_digit[3]: '9'
    //  reversed_digit[4]: '3'
    //  reversed_digit[5]: '9'
    //  reversed_digit[6]: '\0'

    // while loop, swap positions i with size-i

    // digits_seen[0] = 0
    // digits_seen[1] = 0
    // digits_seen[2] = 0
    // digits_seen[3] = 1
    // digits_seen[4] = 0
    // digits_seen[5] = 1
    // digits_seen[6] = 0
    // digits_seen[7] = 2
    // digits_seen[8] = 0
    // digits_seen[9] = 2

    int repeated = 0;
    int i = 0;
    while (i < 10)
    {
        int value = digits_seen[i];
        // if I see a value greater than 1, I will print that value
        if (value > 1)
        {
            printf("%d ", i);
            repeated++;
        }
        i++;
    }
    if (repeated == 0)
        printf("None!");

    printf("\n");

    // However, if I make it through the entire array without seeing a value greater than 1, then, I'm instead going to add to the print message "none".

    // user inputs 69454
    // digits_seen[0] = 0
    // digits_seen[1] = 0
    // digits_seen[2] = 0
    // digits_seen[3] = 0
    // digits_seen[4] = 2
    // digits_seen[5] = 1
    // digits_seen[6] = 1
    // digits_seen[7] = 0
    // digits_seen[8] = 0
    // digits_seen[9] = 1

    // Loop
    //  1: 69454 % 10 = 4
    //  array[4] = true
    //  chop off the last digit: 6945
    //  2: 6945 % 10 = 5
    //  array[5] = true
    //  chop off the last digit: 694
    //  3: 694 % 10 = 4
    //  array[4] = true !! error, because array[4] is already true.  So quit the program and report to the user that we have repeated digits in the number.

    return 0;
}