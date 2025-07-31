#include <stdio.h>

int main(void)
{
    int num_1 = 0, num_2 = 0, num_3 = 0, num_4 = 0, num_5 = 0, num_6 = 0, num_7 = 0, num_8 = 0, num_9 = 0, num_10 = 0, num_11 = 0;

    printf("Enter the first 11 digits of UPC: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &num_1, &num_2, &num_3, &num_4, &num_5, &num_6, &num_7, &num_8, &num_9, &num_10, &num_11);

    int sum_phase_1 = (num_1 + num_3 + num_5 + num_7 + num_9 + num_11) * 3;
    int sum_phase_2 = (sum_phase_1 + num_2 + num_4 + num_6 + num_8 + num_10) - 1;
    int num_check = 9 - (sum_phase_2 % 10);
    printf("%d\n", num_check);

    return 0;
}
