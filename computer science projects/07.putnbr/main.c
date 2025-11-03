#include <unistd.h>

void my_putnbr(int n);

int main(void)
{
	my_putnbr(3242352);
	write(1, "\n", 1);
	return 0;
}
