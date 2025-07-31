#include <stdio.h>

int main(void)
{
	int m = 0;
	int n = 0;
	int nominator = 0;
	int denominator = 0;

	printf("Enter a fraction: ");
	scanf("%d/%d", &m, &n);

	nominator = m;
	denominator = n;

	while (n > 0)
	{
		int temp = n;
		n = m % n;
		m = temp;
	}
	
	nominator = nominator / m;
	denominator = denominator / m;

	// Normalize negative signs: push minus to numerator
	// if (denominator < 0) {
    	//	nominator *= -1;
    	//	denominator *= -1;
	// }

	if (denominator == 0)
		printf("Error..\n");
	else if (denominator == 0)
		printf("In lowest terms: 0\n");
	else
		printf("In lowest terms: %d/%d\n", nominator, denominator);

	return 0;
}
