#include <stdio.h>

int main(void)
{

    // Item number
    printf("Enter item number: ");
    int item_number = 0;
    scanf("%d", &item_number);

    // Unit Price
    printf("Enter unit price: ");
    float unit_price = 0.0f;
    scanf("%f", &unit_price);

    // Purchase date
    printf("Enter purchase date (mm/dd/yyyy): ");
    int month = 0;
    int day = 0;
    int year = 0;
    scanf("%d/%d/%d", &month, &day, &year);

    // Output
    printf("\n");
    printf("Item\t\tUnit\t\tPurchase\n");
    printf("\t\tPrice\t\tDate\n");
    printf("%d\t\t$%7.2f\t%.2d/%.2d/%.4d\t\t\n", item_number, unit_price, month, day, year);

    return 0;
}
