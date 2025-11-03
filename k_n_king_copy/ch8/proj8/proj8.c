#include <stdio.h>

int main(void)
{
    int matrix[5][5] = {0};
    int i = 0;

    while (i < 5)
    {
        printf("Enter 5 grades for student number %d: ", i + 1);
        int j = 0;
        while (j < 5)
        {
            scanf("%d", &matrix[i][j]);
            j++;
        }
        i++;
    }

    printf("\n|--------------------------------------------------------------\n");
    printf("| Quiz and students database:\n");
    printf("|--------------------------------------------------------------\n");
    i = 0;
    int j = 0;

    // 3 - Calculate the row "totals"
    int row_sum = 0;
    int row_average = 0;
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
        row_average = row_sum / 5;
        printf("| Student %d's total grade: %3d   ", i + 1, row_sum);
        printf("|  Average grade: %3d  \n", row_average);

        // col_sum = col_sum + matrix[i][j];
        i++;
    }

    printf("|______________________________________________________________\n");

    // 4 - calculate the col "totals"

    int col_sum = 0;
    int col_average = 0;
    int highest = 0;
    int lowest = 0;
    int grade = 0;

    j = 0;
    while (j < 5)
    {
        col_sum = 0;
        highest = matrix[0][j];
        lowest = matrix[0][j];
        i = 0;
        while (i < 5)
        {

            grade = matrix[i][j];

            if (grade > highest)
                highest = grade;
            if (grade < lowest)
                lowest = grade;

            col_sum = col_sum + matrix[i][j];
            i++;
        }
        col_average = col_sum / 5;
        printf("| Average grade for quiz %d: %3d  ", j + 1, col_average);
        printf("|  Highest: %3d - Lowest: %3d\n", highest, lowest);

        j++;
    }

    printf("\n");

    return 0;
}
