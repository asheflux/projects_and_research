#include <stddef.h>
#include <stdio.h>
#include <string.h>

void *my_memcpy(void *dest, const void *src, size_t n);

int main(void)
{
	const char source[] = "Neon vibes!";
	char destination[50];
	
	my_memcpy(destination, source, strlen(source) + 1);

	printf("Destination is now %s too!\n", destination);
	return 0;
}
