#include <stdio.h>
#include <stdlib.h>

char *my_strchr(char *str, char c);

int main(void)
{
	char sentence[] = "Cyberpunk vibes";
	char target = 'p';

	char *result = my_strchr(sentence, target);

	if (result != NULL)
	{
		printf("Sentence: %s\nTarget: %s\n", sentence, result);
	}
	else
	{
	printf("Target not found!");
	}
	return 0;
}
