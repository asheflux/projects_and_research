#include <stdio.h>
#include <stddef.h>

char *my_strrchr(char *str, char c);

int main(void)
{
	char sentence[] = "my vibe > your vibes";
	char target = 'v';
	char *result = my_strrchr(sentence, target);

	if (result != NULL)
	{
		printf("Snagged: %s Out of %s\n", result, sentence);
	}
	else
	{
		printf("Nothing snagged~");
	}
	return 0;
}
