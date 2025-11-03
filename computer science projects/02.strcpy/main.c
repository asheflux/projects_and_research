#include <stdio.h>

char *my_strcpy(char *dest, const char *src);

int main()
{

    const char *source = "Goodbye Humanity";
    char destination[100];

    my_strcpy(destination, source);
    printf("Copied: %s\n", destination);

    return 0;
}