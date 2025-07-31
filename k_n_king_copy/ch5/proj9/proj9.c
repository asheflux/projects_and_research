#include <stdio.h>

int main(void)
{

	int y1 = 0, m1 = 0, d1 = 0;
	printf("Enter first date (mm/dd/yy): ");
	scanf("%2d/%2d/%2d", &m1, &d1, &y1);

	int y2 = 0, m2 = 0, d2 = 0;
	printf("Enter second date (mm/dd/yy): ");
	scanf("%2d/%2d/%2d", &m2, &d2, &y2);

	if (y1 < y2)
	{
		printf("%d/%d/%d is earlier than %d/%d/%d\n", m1, d1, y1, m2, d2, y2);
	}
	else if (y1 == y2)
	{
		if (m1 < m2)
		{
			printf("%d/%d/%d is earlier than %d/%d/%d\n", m1, d1, y1, m2, d2, y2);
		}
		else if (m1 == m2)
		{
			if (d1 < d2)
			{
				printf("%d/%d/%d is earlier than %d/%d/%d\n", m1, d1, y1, m2, d2, y2);
			}
			else if (d1 == d2)
			{
				printf("%d/%d/%d is the same as %d/%d/%d.\n", m1, d1, y1, m2, d2, y2);
			}
			else
			{
				printf("%d/%d/%d is earlier than %d/%d/%d\n", m2, d2, y2, m1, d1, y1);
			}
		}
		else
		{
			printf("%d/%d/%d is earlier than %d/%d/%d\n", m2, d2, y2, m1, d1, y1);
		}
	}
	else
	{
		printf("%d/%d/%d is earlier than %d/%d/%d\n", m2, d2, y2, m1, d1, y1);
	}

	return 0;
}
