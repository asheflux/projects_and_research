int my_atoi(char *str)
{
	int i = 0;
	int sign = 1;
	int result = 0;

	while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
	{
		i++;
	}

	if(str[i] == '+' || str[i] == '-')
	{
		if(str[i] == '-')
		{
			sign = -1;
		}
		i++;
	}

	while(str[i] >= '0' && str[i] <= '9')
	{
		int digit = str[i] - '0';
		result = result * 10 + digit;
		i++;
	}

	return result * sign;
}
