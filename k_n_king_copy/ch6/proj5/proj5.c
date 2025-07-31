#include <stdio.h>

int main(void)
{

	int num = 0;
	int rev_num = 0;

	printf("Enter a number: ");
	scanf("%d", &num);	
	
	printf("The reversed number is: ");

	if (num < 0)
	{
		printf("-");
		num = num * -1;
	}

	do
	{
		int digit = num % 10;
		printf("%d", digit);
		rev_num = rev_num * 10 + digit;
		num = num / 10;
	}
	while (num != 0);

	return 0;
}
