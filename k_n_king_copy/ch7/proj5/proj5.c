#include <stdio.h>
#include <ctype.h>

int main(void)
{

	printf("Enter a word: ");
	char c;
	int score = 0;

	while ((c = getchar()) != '\n')
	{
		c = toupper(c);

		switch (c)
		{
			case 'A': case 'E': case 'I': case 'L':
			case 'N': case 'O': case 'R': case 'S':
			case 'T': case 'U':
			score = score + 1; break;
			break;

			case 'D': case 'G':
			score = score + 2; break;

			case 'B': case 'C': case 'M': case 'P':
			score = score + 3; break;

			case 'F': case 'H': case 'V':
			case 'W': case 'Y':
			score = score + 4; break;

			case 'K':
			score = score + 5; break;

			case 'J': case 'X':
			score = score + 8; break;

			case 'Q': case 'Z':
			score = score + 10; break;
			
			default: break;
		}
	
	}
	printf("Scrabble value: %d\n", score);
	return 0;
}
