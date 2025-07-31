#include <stdio.h>

int main(void)
{

	int grade = 0;
	printf("Enter numerical grade: ");
	scanf("%d", &grade);
	
	

	if (grade > 100 || grade < 0)
		printf("Error.\n");
	else 
	{
		grade = (grade / 10) * 10;
		switch (grade)
		{
			case 100:
			printf("Letter grade: A\n"); break;
			case 90:
			printf("Letter grade: A\n"); break;
			case 80:
			printf("Letter grade: B\n"); break;
			case 70:
			printf("Letter grade: C\n"); break;
			case 60:
			printf("Letter grade: D\n"); break;
			default:
			printf("Letter grade: F\n");
		}

	}

	return 0;
}
