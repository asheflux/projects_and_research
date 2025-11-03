#include <stddef.h>

void *my_memcpy(void *dest, const void *src, size_t n)
{
	char *d = (char *) dest;
	char *s = (char *) src;
	size_t i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return dest;
}
