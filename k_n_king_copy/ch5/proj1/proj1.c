#include <stdio.h>

int main(void)
{
	
	printf("Enter a number: ");
	
	int num = 0;
	scanf("%d", &num);

	if (num >= 0 && num <= 9)
		printf("The number %d has 1 digit\n", num);

	else if (num >= 10 && num <= 99)
		printf("The number %d has 2 digits\n", num);

	else if (num >= 100 && num <= 999)
		printf("The number %d has 3 digits\n", num);

	else if (num >= 1000 && num <= 9999)
		printf("The number %d has 4 digits\n", num);

	else
		printf("The number %d has more than 3 digits\n", num);

	return 0;
}
