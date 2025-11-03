
#include <stdio.h>
#include <stdbool.h>

void create_magic_square(int n, int matrix[n][n]);
void print_magic_square(int n, int matrix[n][n]);

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

    int matrix[size][size];
    // And if there is none, then input the next value.
    create_magic_square(size, matrix);

    print_magic_square(size, matrix);

    return 0;
}

void create_magic_square(int size, int matrix[size][size])
{

    // 2 - create an int matrix using the size provided by the user and initialize it to all 0.
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            matrix[i][j] = 0;

    // 3 - start by placing '1' in the middle of the first row.
    int number = 1;
    int row = 0;
    int col = size / 2;
    matrix[row][col] = number++;
    bool collision = false;

    do
    {
        // calculate the next position for row/col
        int preview_row = (row - 1 >= 0) ? row - 1 : size - 1;
        int preview_col = (col + 1 < size) ? col + 1 : 0;
        // check for a collision along the diagonal.
        if (matrix[preview_row][preview_col] > 0)
        {

            preview_row = (row + 1 < size) ? row + 1 : 0;
            preview_col = col;
            // check for collision going down by 1 row
            if (matrix[preview_row][preview_col] > 0)
            {
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
}

void print_magic_square(int size, int matrix[size][size])
{
    printf("\n");
    // Print the matrix
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%2d\t", matrix[i][j]);
        }
        printf("\n\n");
    }
}