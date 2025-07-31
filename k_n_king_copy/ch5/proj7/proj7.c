#include <stdio.h>

int main(void)
{

	int i1 = 0, i2 = 0, i3 = 0, i4 = 0, max_a = 0, min_a = 0, max_b = 0, min_b = 0;
	printf("Enter four integers: ");
	scanf("%d %d %d %d", &i1, &i2, &i3, &i4);

	max_a = i1;
	min_a = i2;
	if (i1 < i2)
	{
		max_a = i2;
		min_a = i1;
	}
	
	max_b = i3;
	min_b = i4;
	if (i3 < i4)
	{
		max_b = i4;
		min_b = i3;
	}

	if (max_a < max_b)
	{
		max_a = max_b;
	}

	if (min_a < min_b)
	{
		min_b = min_a;
	}
	
	printf("Highest number is: %d\n", max_a);
	printf("Lowest number is: %d\n", min_b);

	return 0;
}
