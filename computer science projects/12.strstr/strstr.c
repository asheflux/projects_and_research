#include <stddef.h>

char *my_strstr(char *sentence, char *target)
{
	int i = 0;
	if (target[i] == '\0')
	{
		return sentence;
	}
	while (sentence[i] != '\0')
	{
		int j = 0;
		while (sentence[i + j] == target[j] && target[j] != '\0')
		{
			j++;
		}
	if (target[j] == '\0')
	{
		return &sentence[i];
	}
	i++;
	}
	return NULL;
}
