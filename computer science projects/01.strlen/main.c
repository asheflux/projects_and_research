#include <stdio.h>

int my_strlen(const char *str);

int main()
{
    const char *string = "Hello World";

    printf("Length: %d\n", my_strlen(string));

    return 0;
}