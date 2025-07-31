#include <stdio.h>

int main(void)
{

	int usr_hrs = 0, usr_mins = 0;
	printf("Enter a 24-hour time: ");
	scanf("%2d:%2d", &usr_hrs, &usr_mins);

	if (!(usr_hrs <= 23 && usr_hrs >= 0) && (usr_mins >= 0 && usr_mins <= 59))
	{
		printf("Invalid time.\n");
		return 0;
	}

	int user_time_to_mins = (usr_hrs * 60) + usr_mins;
	// variables in mins			// Departure time	Arrival time
	// 8:00 a.m.		10:16 a.m.
	int dep1_to_mins = 480;
	int diff1 = user_time_to_mins - dep1_to_mins;
	diff1 = (diff1 < 0) ? -diff1 : diff1;

	// 9:43 a.m.		11:52 a.m.
	int dep2_to_mins = 583;
	int diff2 = user_time_to_mins - dep2_to_mins;
	diff2 = (diff2 < 0) ? -diff2 : diff2;

	// 11:19 a.m. 		1:31 p.m.
	int dep3_to_mins = 679;
	int diff3 = user_time_to_mins - dep3_to_mins;
	diff3 = (diff3 < 0) ? -diff3 : diff3;

	// 12:47 p.m.		3:00 p.m.
	int dep4_to_mins = 767;
	int diff4 = user_time_to_mins - dep4_to_mins;
	diff4 = (diff4 < 0) ? -diff4 : diff4;

	// 2:00 p.m. 		4:08 p.m.
	int dep5_to_mins = 840;
	int diff5 = user_time_to_mins - dep5_to_mins;
	diff5 = (diff5 < 0) ? -diff5 : diff5;

	// 3:45 p.m.		5:55 p.m.
	int dep6_to_mins = 945;
	int diff6 = user_time_to_mins - dep6_to_mins;
	diff6 = (diff6 < 0) ? -diff6 : diff6;

	// 7:00 p.m. 		9:20 p.m.
	int dep7_to_mins = 1140;
	int diff7 = user_time_to_mins - dep7_to_mins;
	diff7 = (diff7 < 0) ? -diff7 : diff7;

	// 9:45 p.m.		11:58 p.m.
	int dep8_to_mins = 1305;
	int diff8 = user_time_to_mins - dep8_to_mins;
	diff8 = (diff8 < 0) ? -diff8 : diff8;

	//***SAMPLE DATA */
	//** Convert time to minutes_after_midnight */
	// user input: __13:15__ (1:15pm) --> (13*60)+15 = (795 minutes)
	// correct answer: __12:47pm__   (767 minutes)
	// incorrect answer: __2:00pm__  (840 minutes)
	//** Convert negatives to positive */
	// diff_1 = user_input - correct_answer:  795 - 767 =  28 minutes difference
	// diff_2 = user_input - incorrect_answer: 795 - 840 = -45 minutes difference
	// ** If diff_2 is negative, flip the sign
	// if  (diff_2 < 0)
	//		diff_2 = -diff_2
	// diff_2: 45 minute

	int dep = 0;

	// track the lowest difference encountered and store it in a variable called "lowest_diff"
	int lowest_diff = diff1;

	// compare lowest_diff to the next diff.  If the next diff is even lower, then store it as the lowest_diff.
	dep = 1;

	if (diff2 < lowest_diff)
	{
		lowest_diff = diff2;
		dep = 2;
	}

	if (diff3 < lowest_diff)
	{
		lowest_diff = diff3;
		dep = 3;
	}

	if (diff4 < lowest_diff)
	{
		lowest_diff = diff4;
		dep = 4;
	}

	if (diff5 < lowest_diff)
	{
		lowest_diff = diff5;
		dep = 5;
	}

	if (diff6 < lowest_diff)
	{
		lowest_diff = diff6;
		dep = 6;
	}

	if (diff7 < lowest_diff)
	{
		lowest_diff = diff7;
		dep = 7;
	}

	if (diff8 < lowest_diff)
	{
		lowest_diff = diff8;
		dep = 8;
	}

	printf("Departure time     Arrival time\n");
	switch (dep)
	{
	case 1:
		printf("8:00 a.m.          10:16 a.m.\n");
		break;
	case 2:
		printf("9:43 a.m.          11:52 a.m.\n");
		break;
	case 3:
		printf("11:19 a.m.         1:31 p.m.\n");
		break;
	case 4:
		printf("12:47 p.m.         3:00 p.m.\n");
		break;
	case 5:
		printf("2:00 p.m.          4:08 p.m.\n");
		break;
	case 6:
		printf("3:45 p.m.          5:55 p.m.\n");
		break;
	case 7:
		printf("7:00 p.m.          9:20 p.m.\n");
		break;
	case 8:
		printf("9:45 p.m.          11:58 p.m.\n");
		break;
	default:
		printf("No idea if this line is reachable...\n");
	}

	return 0;
}
