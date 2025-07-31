#include <stdio.h>

int main(void)
{
    printf("Enter a date (mm/dd/yyyy) : ");

    int month = 0;
    int day = 0;
    int year = 0;
    scanf("%d/%d/%d", &month, &day, &year);

    printf("You entered the date %.4d%.2d%.2d\n", year, month, day);
    return 0;
}
