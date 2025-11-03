#include <stdio.h>

int power(int x, int n);

int main(void) {
    
    printf("Enter an integer: ");
    int x;
    scanf("%d", &x);
    
    printf("Enter a power: ");
    int n;
    scanf("%d", &n);

    long int result = power(x, n);

    printf("%d raised to the power of %d is: %ld\n", x, n, result);

    return 0;
}



int power(int x, int n) {
    if (n == 0) 
        return 1;
    else
        return x * power(x, n - 1);

}
