#include <stdio.h>

int main(void)
{

	float number_of_shares = 0.0f;
	printf("Enter number of shares: ");
	scanf("%f", &number_of_shares);

	float price_per_share = 0.0f;
	printf("Enter price per share: ");
	scanf("%f", &price_per_share);

	float value = number_of_shares * price_per_share;

	// Calculate our commission
	float our_commission = 0.0f;
	if (value < 2500.00f)
		our_commission = 30.00f + .017f * value;
	else if (value < 6250.00f)
		our_commission = 56.00f + .0066f * value;
	else if (value < 20000.00f)
		our_commission = 76.00f + .0034f * value;
	else if (value < 50000.00f)
		our_commission = 100.00f + .0022f * value;
	else if (value < 500000.00f)
		our_commission = 155.00f + .0011f * value;
	else
		our_commission = 255.00f + .0009f * value;

	if (our_commission < 39.00f)
		our_commission = 39.00f;
	printf("\n");
	printf("Our commission is $%.2f\n", our_commission);

	// Calculate rival's commission
	float rival_commission = 0.0f;
	if (number_of_shares < 2000)
		rival_commission = 33.0f + (0.03f * number_of_shares);
	else
		rival_commission = 33.0f + (0.02f * number_of_shares);

	printf("Rival's commission is $%.2f\n", rival_commission);

	return 0;
}
