#include <stdio.h>

int my_atoi(char *str);

int main(void)
{
    char string[] = "2389732";

    printf("Converted number is: %d\n", my_atoi(string));
    return 0;
}