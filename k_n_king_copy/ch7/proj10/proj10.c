#include <stdio.h>
#include <ctype.h>

int main(void)

{

	printf("Enter a sentence: ");
	char c;
	int vowels = 0;

	while ((c = getchar()) != '\n')
	{
		c = toupper(c);
		switch (c)
		{
			case 'A': case 'E': case 'I': case 'O': case 'U':
            //TIP: start using "variable++" instead of "variable = variable + 1" when you're only increasing by 1.  Otherwise, use +=.  Practically every programmer will be using ++ and =+, and you'll look like a noob for not using these.
			vowels = vowels + 1; break;
		
			default:
            //Adding 0 to vowels serves no purpose, so remove this statement.  you only need "default: break;" here.
			vowels = vowels + 0; break;
		}
	}

	printf("Your sentence contains %d vowels.\n", vowels);

	return 0;
}
