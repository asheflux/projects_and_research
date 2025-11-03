#include <stdio.h>

int main(void)
{
    int matrix[5][5] = {0};
    int i = 0;
    //1 - generate the matrix using 5 rows from the user
    while (i < 5)
    {
        printf("Enter row %d: ", i+1);
        int j = 0;
        while (j < 5)
        {
            scanf("%d", &matrix[i][j]);
            j++;
        }
        i++;
    }

    printf("\n\n");

    //2 - print the matrix
    i = 0; 
    int j = 0;
    while (i < 5)
    {
        
        int j = 0;
        while (j < 5)
        {
            printf("%3d ", matrix[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }

    //3 - Calculate the row "totals"
    printf("Row totals: ");
    int row_sum = 0;
    i = 0;
    while (i < 5)
    {
        row_sum = 0;
        j = 0;
        while (j < 5)
        {
            row_sum = row_sum + matrix[i][j];
            j++;
        }
        printf("%d ", row_sum);
        
        //col_sum = col_sum + matrix[i][j];
        i++;
    }
    printf("\n");
    //printf("Row totals = %d", rows_sum);
        
    //4 - calculate the col "totals"
    printf("Col totals: ");
    int col_sum = 0;
    j = 0;
    while (j < 5)
    {
        col_sum = 0;
        i = 0;
        while (i < 5)
        {
            col_sum = col_sum + matrix[i][j];
            i++;
        }
        printf("%d ", col_sum);
        
        //col_sum = col_sum + matrix[i][j];
        j++;
    }

    printf("\n");
    
    return 0;
}


// Enter row 1: 8 3 9 0 10
// Enter row 2: 3 5 17 1 1
// Enter row 3: 2 8 6 23 1
// Enter row 4: 15 7 3 2 9
// Enter row 5: 6 14 2 6 0
//
// Row totals: 30 27 40 36 28
// Column totals: 34 37 37 32 21