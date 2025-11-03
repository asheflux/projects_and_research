#include <stdio.h>
#include <stddef.h>

char *my_strstr(char *sentence, char *target);

int main(void)
{
	char str1[] = "Cyberpunk vibes";
	char str2[] = "x";

	char *result = my_strstr(str1, str2);

	if (result != NULL)
	{
		printf("Found: %s\n", result);
	}
	else
	{
		printf("No match found~\n");
	}
	return 0;
}
