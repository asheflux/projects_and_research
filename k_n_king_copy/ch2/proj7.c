#include <stdio.h>

int main(void)
{
    printf("Enter a dollar amount: ");
    int dollars = 0;
    scanf("%d", &dollars);

    int remaining_dollars = dollars;  //93

    int twenty = remaining_dollars / 20;  //4 * twenty dollar bills
    remaining_dollars = remaining_dollars - twenty * 20;  // 13 = 93 - (4 * 20)

    int ten = remaining_dollars / 10;
    remaining_dollars = remaining_dollars - ten * 10;

    int five = remaining_dollars / 5;
    remaining_dollars = remaining_dollars - five * 5;

    int one = remaining_dollars / 1;
    remaining_dollars = remaining_dollars - one * 1;


    printf("$20 bills: %d\n", twenty);
    printf("$10 bills: %d\n", ten);
    printf("$5 bills: %d\n", five);
    printf("$1 bills: %d\n\n", one);



    printf("Remaining dollars : %d\n", remaining_dollars);

    return 0;
}