#include <stdio.h>

#define N 10
#define SIZE ((int)(sizeof(a) / sizeof(a[0])))

int main(void)
{
    // Ask user to provide 10 numbers
    int a[N], i;
    printf("Enter %d numbers: ", SIZE);

    // Receive the numbers and store them in array "a"
    for (i = 0; i < SIZE; i++)
        scanf("%d", &a[i]);

    // Print the array's numbers in reverse order
    printf("In reverse order: ");
    for (i = SIZE - 1; i >= 0; i--)
        printf(" %d", a[i]);
    printf("\n");

    return 0;
}