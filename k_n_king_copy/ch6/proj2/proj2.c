/* Euclid's Algorithm, 300BC */
// Euclid's Algorithm, 300BC
#include <stdio.h>

int main(void)
{
    int m = 0;
    int n = 0;

    printf("Enter two integers: ");
    scanf("%d %d", &m, &n);

    while (n > 0)
    {
        int remainder = m % n; // 12 / 5 = 2
        m = n;
        n = remainder;
    }

    printf("Greatest common divisor: %d\n", m);

    return 0;
}