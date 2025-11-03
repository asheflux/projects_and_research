
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    // 1 - Receive the size of the matrix from the user.
    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");

    bool validation = false;
    int size = 0;
    do
    {
        scanf("%d", &size);
        // validating size to make it's odd & between 1 and 99
        int odd_number = size % 2;
        if (odd_number && 1 <= size && size <= 99)
        {
            validation = true;
        }
        else
        {
            printf("Invalid number.\n");
            printf("Please enter an odd number between 1 and 99: ");
        }
    } while (validation == false);

    printf("Size is: %d\n", size);

    // 2 - create an int matrix using the size provided by the user and initialize it to all 0.
    int matrix[size][size];
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            matrix[i][j] = 0;

    // 3 - start by placing '1' in the middle of the first row.
    int number = 1;
    int row = 0;
    int col = size / 2;
    matrix[row][col] = number++;

    // 4 - RULES:
    //  we peek at the position one step right and one step up, and if the position is clear (meaning, it is a 0), then we update row&col to that position, and insert the next number into this new position.
    //  if there are no rows on top we go to the bottom row again and continue
    //  if we end up on the far right column we reset to the first column
    //  if there is already a number in a block, then we instead will go one step down and insert the next number into this position instead.  But we still need to validate that the next position has a 0 in it.

    // //DRAFT SAMPLE
    // 0   0   1   0   0
    // 0   5current   0   0   0
    // 4   0preview   0   0   0
    // 0   0   0   0   3
    // 0   0   0   2   0

    // loop through each position of the matrix until you hit a collision
    bool collision = false;
    do
    {
        // calculate the next position for row/col
        int preview_row = (row - 1 >= 0) ? row - 1 : size - 1;
        int preview_col = (col + 1 < size) ? col + 1 : 0;
        printf("new row:%d, col:%d\n", row, col);
        // check for a collision along the diagonal.
        if (matrix[preview_row][preview_col] > 0)
        {
            printf("Collision detected! at row:%d, col:%d\n", preview_row, preview_col);
            // FIRST, Try going straight down
            // 1. reset the preview coordinate to one row down from row and col
            // go back to the original row and column
            // go down by one row
            preview_row = (row + 1 < size) ? row + 1 : 0;
            preview_col = col;
            // check for collision going down by 1 row
            if (matrix[preview_row][preview_col] > 0)
            {
                printf("A second collision was detected! at row:%d, col:%d\n", preview_row, preview_col);
                collision = true;
            }
            else
            {
                // no collision the second time, so update row and col
                row = preview_row;
                col = preview_col;
                matrix[row][col] = number++;
            }
        }
        else
        {
            // No collision
            row = preview_row;
            col = preview_col;
            matrix[row][col] = number++;
        }

    } while (!collision);

    // And if there is none, then input the next value.

    // Print the matrix
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%2d\t", matrix[i][j]);
        }
        printf("\n\n");
    }

    return 0;
}

// SAMPLE OUTPUT
/*
This program creates a magic square of a specified size.
The size must be an odd number between 1 and 99.
Enter size of magic square: __5__

//we start at this position:
row = 0;
col = size / 2;

//we need to peek at the next position (row-- and col++), and account for the boundaries
row--;  now check if row is negative.
is row-- negative?  If so, set row to the last row (size-1).
col++;  now check if col is out of bounds.
if col is now 'size', then set col to 0.
//continue until you have a collision.

row: 0
col: 2

//calculate the next position
row =  row--;
if (row < 0)
    row = size - 1;
row = (row - 1 >= 0) ? row -1 : size - 1;

//check for out-of-bounds, and correct for it


col = (col + 1 < size) ? col + 1 : 0;

col = col++
//check for out-of-bounds, and correct for it
if (col >= size)
    col = 0;



//DRAFT SAMPLE
0   0   1   0   0
0   5   0   0   0
4   0   0   0   0
0   0   0   0   3
0   0   0   2   0


//DRAFT SAMPLE
0   0   1   0   0
0   0   0   0   0
0   0   0   0   0
0   0   0   0   0
0   0   0   0   0

//FINAL SAMPLE
17  24   1   8  15
23   5   7  14  16
 4   6  13  20  22
10  12  19  21   3
11  18  25   2   9


*/
