int my_words_count(const char *str, char sep)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0')
    {
        if (str[i] != sep)
        {
            count++;
            while (str[i] != '\0' && str[i] != sep)
            {
                i++;
            }
        }
        else
        {
            i++;
        }
    }
    return count;
}
