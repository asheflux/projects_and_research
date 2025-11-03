#include <stdio.h>

int main(void)
{

	char letter;
    //TIP: Use integers instead of doubles.  Since you are typecasting the numerator to a double when you calculate the average, you don't have to worry about these counting variables being simple integers.  In programming, make a habit of only using "integer" and "float" unless you really need to use something else, or are told to refactor your code to make the program more effecient.
	double count_letter = 0.0;
	double count_word = 0.0;
	
	printf("Enter a sentence: ");

	while ((letter = getchar()) != '\n')
	{
		if (letter == ' ')
			count_word = count_word + 1;
		else
			count_letter = count_letter + 1;
	}

    //BUG: This is cheating.  You're adding 1 here to force your average to hit the right number.  Instead, you need to be counting the period character as both an increase to the word (because it marks the end of the last word) and an increase to the letter count (because it's counted as a letter for some reason, perhaps a mistake by the author).  This may have been a 
	count_word = count_word + 1;

	double average = (double) count_letter / count_word;
    //TIP: put a newline at the end of your format string.
	printf("Average word length: %.1f", average);

	return 0;
}
