#include <stdio.h> 

int main (void)
{
	int i, n, odd, square;

	printf ("This program prints a table of squares. \n"); 
	printf ("Enter number of entries in table: ");
	scanf ("%d", &n);

	i = 0;
	odd = 3;
	for (square = 1; square <= n; odd += 2) 
	{
		int even = square % 2;
		if (even == 0)
			printf ("%d\n", square); 
		square += odd;
		++i;
	}
	return 0;
}
