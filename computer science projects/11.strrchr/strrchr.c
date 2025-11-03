#include <stddef.h>

char *my_strrchr(char *str, char c)
{
	int i = 0;
	char *last = NULL;

	while(str[i] != '\0')
	{
		if(str[i] == c)
		{
			last = &str[i];
		}
	i++;
	}
	return last;
}
