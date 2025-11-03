#include <stdio.h>
char *my_strncpy(char *dest, const char *src, int n);

int main()
{
    const char *source = "Hello Cat";
    char destination[100];

    my_strncpy(destination, source, 7);

    printf("Copied: %s\n", destination);

    return 0;
}