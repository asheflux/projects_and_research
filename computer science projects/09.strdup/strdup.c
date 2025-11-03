char *my_strdup(char *src)
{
    int length = 0;
    while (src[length] != '\0')
    {
        length++;
    }

    char *dest = malloc(length + 1) * (sizeof(char));

    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';

    return dest;
}