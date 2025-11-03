#include <stdio.h>

int main(void)
{
    long int n_input = 0;

    do
    {
        printf("Enter a number: ");
        scanf("%ld", &n_input);
        long int n = n_input;
        if (n_input <= 0)
            break;
        printf("You entered: %ld\n", n);
        int digits_seen[10] = {0};

        while (n > 0)
        {
            int digit = n % 10; // 4
            digits_seen[digit]++;
            n /= 10;
            // printf("current value of n: %ld\n", n);
        }

        printf("Digit:\t    ");
        int j = 0;
        while (j < 10)
        {
            printf("%d  ", j);
            j++;
        }
        printf("\n");

        // loop through digit array, looking at each element's value.

        printf("Occurences: ");
        int repeated = 0;
        int i = 0;
        while (i < 10)
        {
            int value = digits_seen[i];
            // if I see a value greater than 1, I will print that value

            printf("%d  ", digits_seen[i]);
            repeated++;
            i++;
        }
        printf("\n\n");
        // printf("\n the value of n_input: %ld\n", n_input);
    } while (n_input > 0);

    printf("\n");

    return 0;
}