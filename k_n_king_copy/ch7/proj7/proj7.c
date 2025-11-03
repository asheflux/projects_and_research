#include <stdio.h>

int main(void)
{
	int num1 = 0, denom1 = 0, num2 = 0, denom2 = 0, result_num = 0, result_denom = 0;
	char operator;

	printf("Enter two fractions seperated by an operator: ");
	scanf("%d/%d%c%d/%d", &num1, &denom1, &operator, &num2, &denom2); //TIP: allow the user to enter spaces between the fractions and the operator, eg "1/2 * 1/3"
 
	switch (operator)
	{
		case '+':
			result_num = num1 * denom2 + num2 * denom1;
			result_denom = denom1 * denom2;
			break;
		case '-':
			result_num = num1 * denom2 - num2 * denom1;
			result_denom = denom1 * denom2;
			break;
		case '/':
			result_num = num1 * num2;
			result_denom = denom1 * denom2;
			break;
		case '*':
            //BUG: This is not the correct formula for calculating division
            result_num = num1 * num2;
			result_denom = denom1 * denom2;
			break;
		default:
			printf("Invalid input...");
			return 0;			
	}

	printf("The result is %d/%d\n", result_num, result_denom);

	return 0;
}

