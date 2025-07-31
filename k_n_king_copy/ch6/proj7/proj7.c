#include <stdio.h> 

int main (void)
{
	int i, n, odd, square;

	printf ("This program prints a table of squares. \n"); 
	printf ("Enter number of entries in table: ");
	scanf ("%d", &n);

	odd = 3;
	for (i = 0, square = 1; square <= n; odd += 2, i++) 
	{
		int even = square % 2;
		if (even == 0)
			printf ("%d\n", square); 
		square += odd;
	}
	return 0;
}
