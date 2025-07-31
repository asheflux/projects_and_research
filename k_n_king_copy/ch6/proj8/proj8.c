#include <stdio.h>

int main(void)
{

	int n = 0;
	int start = 0;

	printf("Enter number of days: ");
	scanf("%d", &n);
	printf("Enter starting day: ");
	scanf("%d", &start);

	int i = 1;
	int week_position = 1;	
	
	while (week_position < start)
	{
		printf("   ");
		week_position++;
	}

	while (i <= n)
	{
		printf("%2d ", i);
    		if (week_position == 7) 
		{
        		printf("\n");
        		week_position = 1;
		} 
		else
    			week_position++;
    	i++;
	}
	printf("\n");
	return 0;
}
