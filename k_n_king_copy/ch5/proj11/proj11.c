#include <stdio.h>

int main(void)
{

	int tens = 0, ones = 0;
	printf("Enter a two-digit number: ");
	scanf("%1d%1d", &tens, &ones);

	if (tens > 1)
	{
		switch (tens)
		{
			case 2:
			printf("You entered Twenty"); break;
			case 3:
			printf("You entered Thirty"); break;

			case 4:
			printf("You entered Fourty"); break;

			case 5:
			printf("You entered Fifty"); break;

			case 6:
			printf("You entered Sixty"); break;

			case 7:
			printf("You entered Seventy"); break;

			case 8:
			printf("You entered Eighty"); break;

			case 9:
			printf("You entered Ninety"); break;
		}
		switch (ones)
		{
			case 3:
			printf("-three"); break;

			case 4:
			printf("-four"); break;

			case 5:
			printf("-five"); break;

			case 6:
			printf("-six"); break;

			case 7:
			printf("-seven"); break;

			case 8:
			printf("-eight"); break;

			case 9:
			printf("-nine"); break;
			
			case 0:
			printf("");
		}
	}
	else if (tens == 1)
	{
		if (ones == 1)
			printf("You entered Eleven");
		else if (ones == 2)
			printf("You entered Twelve");
		else
		{
			switch (ones)
			{
				case 3:
				printf("You entered Thirteen"); break;
				case 4:
				printf("You entered Fourteen"); break;
				case 5:
				printf("You entered Fifteen"); break;
				case 6:
				printf("You entered Sixteen"); break;
				case 7:
				printf("You entered Seventeen"); break;
				case 8:
				printf("You entered Eighteen"); break;
				case 9:
				printf("You entered Nineteen"); break;
			}
		}
	}
	printf(".\n");

	return 0;
}
