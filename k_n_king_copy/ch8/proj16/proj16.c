#include <stdio.h>

int main(void)
{
	int alphabet[26] = {0};	
	char c;
	int index = 0;

	printf("Enter first word: ");
	while ((c = getchar()) != '\n')
	{
		if (c >= 'A' && c <= 'Z')
			index = c - 'A';
		else if (c >= 'a' && c <= 'z')
			index = c - 'a';
		else
			continue;

		alphabet[index]++;
	}

	printf("Enter second word: ");
	index = 0;
	while ((c = getchar()) != '\n')
	{
		if (c >= 'A' && c <= 'Z')
			index = c - 'A';
		else if (c >= 'a' && c <= 'z')
			index = c - 'a';
		else
			continue;

		alphabet[index]--;
	}

	index = 0;
	int anagram = 0;
	while (index < 26)	
	{
		if (alphabet[index] != 0)
		{
			anagram = 1;
			break;
		}
		
		index++;
	}

	if (anagram == 0)
		printf("The words are anagram\n");
	else
		printf("The words are not anagram\n");

	return 0;
}
