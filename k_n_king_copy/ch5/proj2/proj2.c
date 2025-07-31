#include <stdio.h>

int main(void)
{

	printf("Enter a 24-hour time: ");

	int hours = 0;
	int minutes = 0;
	scanf("%2d:%2d", &hours, &minutes);

	if (hours >= 1 && hours <= 11)
	{
		printf("Equivalent 12-hour time: %2d:%02d AM\n", hours, minutes);
	}
	else if (hours >= 13 && hours <= 23)
	{
		hours = hours - 12;
		printf("Equivalent 12-hour time: %2d:%02d PM\n", hours, minutes);
	}
	else if (hours == 00)
	{
		hours = hours + 12;
		printf("Equivalent 12-hour time: %2d:%02d AM\n", hours, minutes);
	}
	else if (hours == 12)
	{
		printf("Equivalent 12-hour time: %2d:%02d PM\n", hours, minutes);
	}
	else
	{
		printf("Invalid time.\n");
	}

	return 0;
}
