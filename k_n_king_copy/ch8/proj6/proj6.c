#include <stdio.h>
#include <ctype.h>

int main(void)
{

	// 1 - ask the user to input a sentence.
	char c;
	char sentence[100];
	printf("Enter a message: ");
	int i = 0, size = 0;

	// 2 - store the UPPERCASE version of the message in an array called "sentence" with size 100.
	while ((c = getchar()) != '\n' && i < 100)
	{
		sentence[i] = toupper(c);
		i++;
	}
    size = i;

	// 3 - Go through the array, looking at each value, and converting the letters to B1FF
	i = 0;
	while (i < size)
	{
		c = sentence[i];
		switch (c)
		{
			case 'A': c = '4'; break;
			case 'B': c = '8'; break;
			case 'E': c = '3'; break;
			case 'S': c = '5'; break;
			case 'O': c = '0'; break;
			case 'I': c = '1'; break;
			default: break;
		}
		sentence[i] = c;
		i++;
	}

	// 4 - print the message
	i = 0;
	while (i < size)
	{
		printf("%c", sentence[i]);
		i++;
	}

    //5 - print exclamation marks for the remaining portion of the array!
	i = size;
    while (i < 100)
	{
		printf("!");
		i++;
	}

    printf("\n");
    	
	return 0;
}
