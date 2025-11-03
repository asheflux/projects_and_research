#include <stdio.h>

int main(void)
{
	printf("Enter phone number: ");

	char c = getchar();
	while (c != '\n')
	{
		if (c == 'Q' || c == 'Z')
		{
			c = getchar();	
			continue;
		}
		if (c >= 'A' && c <= 'C')
			printf("2");
		else if (c >= 'D' && c <= 'F')
			printf("3");
		else if (c >= 'G' && c <= 'I')
			printf("4");
		else if (c >= 'J' && c <= 'L')
			printf("5");
		else if (c >= 'M' && c <= 'O')
			printf("6");
		else if (c == 'P' || c == 'R' || c == 'S')
			printf("7");
		else if (c >= 'T' && c <= 'V')
			printf("8");
		else if (c >= 'W' && c <= 'Y')
			printf("9");
		else
			printf("%c", c);
		c = getchar(); //TIP: remove this and line 7, and instead put your "c = getchar()" into the while's condition.  
	}
	printf("\n");

	return 0;
}
