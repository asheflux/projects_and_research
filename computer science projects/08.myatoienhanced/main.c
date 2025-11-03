#include <stdio.h>

int my_atoie(char *str);
int main(void)
{
	printf("%d\n", my_atoie("42"));           // → 4
	printf("%d\n", my_atoie("   -42"));       // → -42
	printf("%d\n", my_atoie("+73"));          // → 73
	printf("%d\n", my_atoie("   +0045abc"));  // → 45
	printf("%d\n", my_atoie("--32"));         // → 0 (invalid)
	printf("%d\n", my_atoie("99bottles"));    // → 99
	printf("%d\n", my_atoie("   "));          // → 0

	return 0;
}
