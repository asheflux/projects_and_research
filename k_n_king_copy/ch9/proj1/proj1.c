#include <stdio.h>

void selection_sort(int size, int series[size]);
void put_largest_at_end(int size, int series[size]);

// THIS WORKS
int main(void)
{

	// 1 - ask user to enter a series of integers
	//   -- request "size" number of integers and store the integers into an array called "values"
	printf("How many numbers would you like to add: ");
	int size;
	scanf("%d", &size);
	int values[size];

	// 2 - Ask the user to enter "size" number of integers, and store them in the "values" array
	printf("Please enter %d integers to be sorted: \n", size);
	for (int i = 0; i < size; i++)
	{
		int integer = 0;
		printf("Enter an integer: ");
		scanf("%d", &values[i]);
	}

	printf("\n");

	// 3 - print the unsorted array to confirm
	printf("You entered: ");
	for (int i = 0; i < size; i++)
		printf("%d ", values[i]);

	printf("\n");

	// 4 - sort the array values using selection sort
	selection_sort(size, values);

	// 5 - print the sorted array
	printf("You entered: ");
	for (int i = 0; i < size; i++)
		printf("%d ", values[i]);

	printf("\n");

	return 0;
}

void selection_sort(int size, int series[size])
{
	// Validate for the endpoint of the recursion
	if (size <= 1)
		return;

	// If it's NOT the endpoint, then you:
	//  Perform "put_largest_at_end" on elements 0 to n.  Put this in its own function called "selection_high"
	put_largest_at_end(size, series);
	//  recursively call the selection_sort function again: performing it on elements 0 to n-1.
	selection_sort(size - 1, series);
}

// THIS WORKS
void put_largest_at_end(int size, int series[size])
{
	//		size = 6 elements
	//         i = 0 1 2 3 4 5 <-- last index is size-1
	// series[i] = 4 5 6 3 2 1
	//	highest = 4, index = 0
	//  		  5, index = 1
	//            6, index = 2
	//            6, index = 2
	//            6, index = 2
	//            6, index = 2
	// the  highest value "6" is at index "2"

	// put the largest element at the end of the array
	// 1. start off counting the first element of the array as the "highest" variable
	int index_of_highest = 0;
	// 2. loop through the array, looking at each elemnet of the array
	for (int i = 1; i < size; i++)
	{
		//   -- compare the current element against the previous "highest" value
		//   -- update the index_of_highest value with the current index
		if (series[i] > series[index_of_highest])
			index_of_highest = i;
	}
	// swap the element of index_of_highest with the element in the last_index
	int temp = series[index_of_highest];
	series[index_of_highest] = series[size - 1];
	series[size - 1] = temp;
}
