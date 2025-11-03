#include <stdio.h>
#include <ctype.h>

int main(void)
{

	int usr_hrs = 0, usr_mins = 0;
	char time_of_day;
	printf("Enter a 12-hour time: ");
	scanf("%2d:%2d %c", &usr_hrs, &usr_mins, &time_of_day);

	time_of_day = toupper(time_of_day);

	if(time_of_day == 'P' && usr_hrs != 12)
		usr_hrs = usr_hrs + 12;
	if(time_of_day == 'A' && usr_hrs == 12)
		usr_hrs = 0;

    //BUG: This program is outputting "1:0" for 1:00am; it should output "01:00" instead.  You need to display 2 digits with leading zeroes,  using 02d
	printf("The equivalent time is: %d:%d\n", usr_hrs, usr_mins);

	return 0;
}
