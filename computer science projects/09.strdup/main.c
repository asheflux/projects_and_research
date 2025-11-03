#include <stdio.h>
#include <stdlib.h>

char *my_stddup(char *src);

int main(void)
{
    char original[] = "Cyber vibes";
    char *copy = my_strdup(original);

    printf("Copied %s\n", copy);
    free(copy);
    return 0;
}