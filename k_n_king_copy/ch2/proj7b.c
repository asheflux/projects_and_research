#include <stdio.h>

int main(void)
{
    printf("Enter a dollar amount: ");
    int dollars_total = 0;
    scanf("%d", &dollars_total);


    int remaining_dollars = dollars_total;
    // 93
    // (4 * 20) = 80
    // 13 = 93 - 80.  remaining = remaining - (twenty * 20)



    // 93 / 20 = 4
    int qty_of_twentys = remaining_dollars / 20; // 4
    remaining_dollars = remaining_dollars - (qty_of_twentys * 20);

    int qty_of_tens = remaining_dollars / 10; // 1
    remaining_dollars = remaining_dollars - (qty_of_tens * 10);

    int qty_of_fives = remaining_dollars / 5; // 0
    remaining_dollars = remaining_dollars - (qty_of_fives * 5);

    int qty_of_ones = remaining_dollars / 1; // 3
    remaining_dollars = remaining_dollars - (qty_of_ones * 1);
    // int remaining_dollars = dollars_total / 

    printf("$20 bills: %d\n", qty_of_twentys);
    printf("$10 bills: %d\n", qty_of_tens);
    printf(" $5 bills: %d\n", qty_of_fives);
    printf(" $1 bills: %d\n\n", qty_of_ones);

    printf("Remaining dollars: %d", remaining_dollars);
    /*
    Enter a dollar amount:  __93__
    $20 bills: 4
    $10 bills: 1
    $5 bills: 0
    $1 bills: 3

    */

    return 0;
}