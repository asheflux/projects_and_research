#include <stdio.h>
#include <ctype.h>

int main(void)
{

	printf("Enter a first and last name: ");
	char first_name;
	char last_name;
	char first_letter;

    //TIP: since we are capturing individual characters, we should use getchar() instead of scanf.  Everything can be done with just two whiles using getchar.  see my proj11x.c.  While your code effectively works, it's somewhat hacking to get it work with your scanf's, which is unnecesary since you don't even need to use scanf.
	scanf("%c", &first_name);
	first_name = toupper(first_name);

	while ((last_name = getchar()) != ' ')
	{

	}
	scanf("%c", &last_name);
	last_name = toupper(last_name);
	printf("%c", last_name);

	while ((last_name = getchar()) != '\n')
	{
		printf("%c", last_name);
	}
    //BUG: Add the "." after the first initial.  "Lloyd Fosdick" should display "Fosdick, L." with the dot to indicate that the first name was abbreviated.
	printf(", %c\n", first_name); 

	
	return 0;
}
