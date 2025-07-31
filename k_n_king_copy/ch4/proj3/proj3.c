#include <stdio.h>

int main(void)
{

    printf("Enter a three-digit number: ");

    int num_1 = 0;
    int num_2 = 0;
    int num_3 = 0;

    scanf("%1d%1d%1d", &num_1, &num_2, &num_3);
    printf("The reversal is: %d%d%d\n", num_3, num_2, num_1);

    return 0 ;
}
