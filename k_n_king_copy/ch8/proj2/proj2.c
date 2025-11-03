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
    if (repeated == 0)
        printf("None!");

    printf("\n");

    return 0;
}