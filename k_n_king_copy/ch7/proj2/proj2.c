#include <stdio.h>

int main(void)
{

    int n = 0;
    long int i = 1;
    int limit = 24;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);
    getchar();

    while (i < n)
    {
        //moved print ABOVE the limit test, because instructions say to show the message AFTER 24 results are printed.
        printf("%10ld\t%10ld\n", i, i * i);
        if (i == limit)
        {
            printf("Press Enter to continue...\n");
            //BUG: if user inputs something other than enter, and then presses enter, the limit is no longer checked.
            if (getchar() == '\n'){
                limit = limit + 24;
                printf("limit: %d", limit);
            }
        }
        i++;

    }

    return 0;
}
