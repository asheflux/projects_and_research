#include <stdio.h>

int main(void)
{
    int n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0, n7 = 0, n8 = 0, n9 = 0, n10 = 0, n11 = 0, n12 = 0;

    printf("Enter UPC code: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9, &n10, &n11, &n12);

    int sum1 = (n1 + n3 + n5 + n7 + n9 + n11) * 3;
    int sum2 = (sum1 + n2 + n4 + n6 + n8 + n10) - 1;
    int num_check = 9 - (sum2 % 10);

    if (num_check == n12)
        printf("The UPC code is valid\n");
    else
        printf("The UPC code is not valid\n");

    // UPC: 013800151735 is valid
    // UPC: 013800151732 is not valid
    return 0;
}