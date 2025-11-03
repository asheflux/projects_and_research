#include <stdio.h>
#include <ctype.h>

int main(void)
{

	printf("Enter a first and last name: ");
	char last_name[20];
	char first_letter = 0;
	char c;

	// grab the first letter of the first name, then skip over the remaining letters until you get to the 'space' character that separates first and last name.
	while ((c = getchar()) != ' ')
	{
		// check if first_letter is 0, and if it is, store 'c' into first_letter
		if (first_letter == 0)
			first_letter = c;
	}

	// get all of the last name characters and store them into the last_name array, ending at newline.  Also, keep track of the 'size' of the last_name array by counting the number of letters the user input for the last name.
	int size = 0;
	while ((c = getchar()) != '\n')
	{
		last_name[size] = c;
		size++;
	}

	printf("You entered the name: ");

	// print each letter of the last name
	int i = 0;
	while (i < size)
	{
		printf("%c", last_name[i]);
		i++;
	}

	printf(", %c.\n", first_letter);

	return 0;
}
