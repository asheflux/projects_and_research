#include <stdio.h>
#include <ctype.h>

int main(void)
{
	printf("Enter phone number: ");

	char numeric[20], c;
	int i = 0;

	while ((c = toupper(getchar())) != '\n')
	{
		// validate: do not process Q or Z
		if (c == 'Q' || c == 'Z')
			continue;

		if (c >= 'A' && c <= 'C')
			numeric[i] = '2';
		else if (c >= 'D' && c <= 'F')
			numeric[i] = '3';
		else if (c >= 'G' && c <= 'I')
			numeric[i] = '4';
		else if (c >= 'J' && c <= 'L')
			numeric[i] = '5';
		else if (c >= 'M' && c <= 'O')
			numeric[i] = '6';
		else if (c == 'P' || c == 'R' || c == 'S')
			numeric[i] = '7';
		else if (c >= 'T' && c <= 'V')
			numeric[i] = '8';
		else if (c >= 'W' && c <= 'Y')
			numeric[i] = '9';
		else
			numeric[i] = c;
		i++;
	}
	printf("\n");

	// print "In numeric form: " + the message
	printf("In numeric form: ");
	int j = 0;
	while (j < i)
	{
		printf("%c", numeric[j]);
		j++;
	}

	printf("\n");

	return 0;
}
