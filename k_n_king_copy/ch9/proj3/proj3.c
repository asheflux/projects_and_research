#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_walk(char board[10][10]);
void print_array(char board[10][10]);

int main(void)
{
	// layout for the board
	char board[10][10];
	char alphabet = 'a';
	int i, j;

	// loop through the dots to have 10x10 matrix
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
			board[i][j] = '.';
	}

	// produce different sequence each run
	srand(time(NULL));

	generate_random_walk(board);

	print_array(board);

	return 0;
}

void generate_random_walk(char board[10][10])
{
	// loop through the letters
	int i = 0, j = 0;
	char c = 'A';
	board[i][j] = c;

	while (c < 'Z')
	{
		// deviding any number by 4 will always get us a remainder 0, 1, 2 or 3
		int move = rand() % 4;

		// break out of the loop if no movement is possible
		if (board[i - 1][j] != '.' && board[i + 1][j] != '.' && board[i][j - 1] != '.' && board[i][j + 1] != '.')
			break;

		// move left
		else if (move == 0 && i > 0 && board[i - 1][j] == '.')
		{
			i--;
			c++;
			board[i][j] = c;
		}

		// move down
		else if (move == 1 && j < 9 && board[i][j + 1] == '.')
		{
			j++;
			c++;
			board[i][j] = c;
		}

		// move right
		else if (move == 2 && i < 9 && board[i + 1][j] == '.')
		{
			i++;
			c++;
			board[i][j] = c;
		}

		// move up
		else if (move == 3 && j > 0 && board[i][j - 1] == '.')
		{
			j--;
			c++;
			board[i][j] = c;
		}
	}
	// store the positions of i and j to x and y
	int x = i;
	int y = j;
}

void print_array(char board[10][10])
{
	int i = 0;
	int j = 0;
	char c;
	// print the letters on the board
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			printf("%c  ", board[i][j]);
		}
		printf("\n");
	}
	// print the game results
	if (c == 'Z')
		printf("\nYou win!\n");
	else
		printf("\nYou've reached the letter %c at position (%d, %d).\nGame Over!\n", c, i, j);
	printf("\n");
}