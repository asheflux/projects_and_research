#include <stdio.h>

void selection_sort(int size, int array[size]);

// MAIN FUNCTION
int main(void)
{

    // ask the user to specify the size of the array
    printf("How many integers would you like to sort: ");

    int size;
    scanf("%d", &size);

    // check if size is less than one then terminate the program
    if (size < 1)
        return 0;

    // ask the user to insert a set of integers
    printf("\n");
    printf("Enter the integers you want to sort seperated by spaces: ");

    // store 'size' number of integers in an array called array
    int array[size];
    int i = 0;
    while (i < size)
    {
        int value;
        scanf(" %d", &value);
        array[i] = value;
        i++;
    }

    printf("Printing the UNSORTED array...\n");
    i = 0;
    while (i < size)
    {
        printf("%d ", array[i]);
        i++;
    }
    printf("\n");

    // call a function called selection sort
    selection_sort(size, array);

    printf("Printing the SORTED array...\n");
    i = 0;
    while (i < size)
    {
        printf("%d ", array[i]);
        i++;
    }
    printf("\n");

    return 0;
}

// SELECTION_SORT FUNCTION
// this function sort the array that we inserted in main
void selection_sort(int size, int array[size])
{

    // check for the recursion endpoint
    if (size <= 1)
        return;

    // find the largest element
    int largest_index = 0;
    int i = 1;
    while (i < size)
    {
        if (array[i] > array[largest_index])
            largest_index = i;
        i++;
    }

    // move the largest element to the last position in the array (book says 'moving' but it's really swapping)
    int last_index = size - 1;
    int temp = array[last_index];
    array[last_index] = array[largest_index];
    array[largest_index] = temp;

    // call the function recursively to sort the first size-1 elements of the array

    selection_sort(size - 1, array);
}
