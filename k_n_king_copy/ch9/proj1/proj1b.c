#include <stdio.h>

void selection_sort(int size, int array[size]);

// MAIN function
int main(void)
{
    // ask the user how many integers they want to input
    printf("How many integers would you like to insert? ");
    int size;
    scanf("%d", &size);
    if (size <= 0)
        return 0;

    // ask the user to enter a series of integers
    printf("Enter %d integers separated by space: ", size);
    // store the integers in an array called array
    int value;
    int i = 0;
    int array[size];
    while (i < size)
    {
        scanf(" %d", &value);
        array[i] = value;
        i++;
    }

    // debug function
    // print the array
    printf("\n");
    printf("Printing array...\n");
    i = 0;
    while (i < size)
    {
        printf("array[%d]: %d\n", i, array[i]);
        i++;
    }

    // call a function selection_sort that uses recursion
    // -- pass in the size of the array, and the array itself with the size specified
    printf("\n");
    printf("Sorting the array...\n");
    selection_sort(size, array);

    printf("\n");
    printf("Printing array...\n");
    i = 0;
    while (i < size)
    {
        printf("array[%d]: %d\n", i, array[i]);
        i++;
    }

    return 0;
}

// SELECTION_SORT function
void selection_sort(int size, int array[size])
{
    // -- selection_sort function will do 3 things:
    // -- 0. ENDPOINT of the recursion is: if the size of the array is 1 or less
    if (size <= 1)
        return;

    // -- 1. search the array to find the largest element
    int largest_index = 0;
    int i = 1;
    while (i < size)
    {
        /*
        largest = 12, largest_index = 0


        array[1]: 43 > array[0]:12
        largest_index = 1

        array[2]: 52 > array[1]: 43 ? YES
        largest_index = 2

        array[3]: 21 > array[2]: 52 ? NO
        don't update largest index

        largest_index = 2;

        LAST_INDEX = size - 1;
        swap the values at largest_index with last_index
        swap array[largest_index] with array[last_index]

        */

        if (array[i] > array[largest_index])
            largest_index = i;
        i++;
    }
    printf("The value of the largest element %d is at index %d\n", array[largest_index], largest_index);

    // -- 2. swap the element in the 'largest' position with the element in the 'last' position
    // temp, largest_index, last_index
    int last_index = size - 1;
    int temp = array[largest_index];
    array[largest_index] = array[last_index];
    array[last_index] = temp;

    // -- 3. recursively call selection_sort to sort the first n - 1 elements of the array
    selection_sort(size - 1, array);
}
