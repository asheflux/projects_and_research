#include <unistd.h>

void my_putnbr(int n)
{
	char digit;
	if (n > 9)
	{
		my_putnbr(n / 10);
	}

	digit = '0' + (n % 10);
	write(1, &digit, 1);
}
