#include <stdio.h>

int main(void)
{
	
	printf("Size of int is:\t\t%zu bytes\n", sizeof(int));
	printf("Size of short is:\t%zu bytes\n", sizeof(short));	
	printf("Size of long is:\t%zu bytes\n", sizeof(long));
	printf("Size of float is:\t%zu bytes\n", sizeof(float));
    //BUG: misspelled "double"
    printf("Size of doubel is:\t%zu bytes\n", sizeof(double));	
	printf("Size of long double is:\t%zu bytes\n", sizeof(long double));

	return 0;
}
