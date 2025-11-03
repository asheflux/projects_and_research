#include <stdio.h>
#include <stdbool.h>

void read_word(int alphabet[26]);
bool equal_array(int alphabet1[26], int alphabet2[26]);

int main(void)
{
	int alphabet[26] = {0};

	printf("Enter first word: ");
	int alphabet1[26] = {0};
	read_word(alphabet1);

	printf("Enter second word: ");
	int alphabet2[26] = {0};
	read_word(alphabet2);

	equal_array(alphabet1, alphabet2);

	return 0;
}

void read_word(int alphabet[26])
{
	char c;
	int index = 0;
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
}

bool equal_array(int alphabet1[26], int alphabet2[26])
{
	int index = 0;
	while (index < 26)
	{
		if (alphabet1[index] != alphabet2[index])
		{
			printf("The words are not anagram\n");
			return false;
		}

		index++;
	}

	printf("The words are anagram\n");

	return true;
}