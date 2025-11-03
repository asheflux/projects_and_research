int my_atoi(char *str)
{
    int result = 0;
    int i = 0;

    while (str[i] >= '0' && str[i] <= '9')
    {
        int digit = str[i] - '0';
        result = result * 10 + digit;
        i++;
    }
    return result;
}