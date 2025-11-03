#include <stdio.h>
#include <ctype.h>

int main(void)
{

	printf("Enter a word: ");
	char c;
	int score = 0;
	// create an array of 26 locations, and each location will correspond to a letter.
	// alphabet[0] (A), alphabet[1] (B)
	//  alphabet[26] = {1,3,3........,0,0,0,0....}
	//                  A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P,  Q, R, S, T, U, V, W, X, Y, Z
	int alphabet[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

	while ((c = getchar()) != '\n')
	{
		c = toupper(c);

		// convert the user's letter to the matching score value
		//  'A'....alphabet[0]
		//  'B'....alphabet[1]
		//  score = score + (c - 'A')
		int ascii_index = c - 'A';
		score = score + alphabet[ascii_index];
		// c is 'A' is 65: 0
		//  ascii = 'A' - 'A' >> 65 - 65 = 0
		// c is 'B' is 66: 1 >> 66 - 65 = 1
		// c is 'C' is 67: 2
		// c is 'D' is 68: 3
	}
	printf("Scrabble value: %d\n", score);
	return 0;
}
