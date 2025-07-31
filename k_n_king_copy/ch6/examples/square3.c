/* Prints a table of squares using an odd method */
#include <stdio.h> 

int main(void)
{
    int i, n, odd, square;
    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table : ");
    scanf("%d", &n);

    i = 1;
    odd = 3;
    for (square = 1; i <= n; odd += 2) // i=3, n=5, odd=7, square=9
    {
        printf("%10d%10d%10d\n", i, square, odd); // 3 9
        ++i; //i=4
        square += odd; //square=16
    }

    return 0;
}