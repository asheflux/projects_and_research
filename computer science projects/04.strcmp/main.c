#include <stdio.h>

int my_strcmp(char *str1, char *str2);

int main(void)
{
    char string1[] = "frogs rock!";
    char string2[] = "frogs cute!";

    printf("Comaparison result is: %d\n", my_strcmp(string1, string2));
    return 0;
}