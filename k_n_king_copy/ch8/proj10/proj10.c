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

	// Declare the arrays
	int d[8] = {0};
	int a[8] = {0};
	int diff[8] = {0};

	int user_time_to_mins = (usr_hrs * 60) + usr_mins;
	// variables in mins			// Departure time	Arrival time
	// 0 - dep = 8:00 a.m.		arr = 10:16 a.m.
	d[0] = 8 * 60 + 0;
	a[0] = 10 * 60 + 16;
	diff[0] = user_time_to_mins - d[0];
	diff[0] = (diff[0] < 0) ? -diff[0] : diff[0];

	// 9:43 a.m.		11:52 a.m.
	d[1] = 9 * 60 + 43;
	a[1] = 11 * 60 + 52;
	diff[1] = user_time_to_mins - d[1];
	diff[1] = (diff[1] < 0) ? -diff[1] : diff[1];

	// 11:19 a.m. 		1:31 p.m.
	d[2] = 11 * 60 + 19;
	a[2] = 13 * 60 + 31;
	diff[2] = user_time_to_mins - d[2];
	diff[2] = (diff[2] < 0) ? -diff[2] : diff[2];

	// 12:47 p.m.		3:00 p.m.
	d[3] = 12 * 60 + 47;
	a[3] = 15 * 60 + 0;
	diff[3] = user_time_to_mins - d[3];
	diff[3] = (diff[3] < 0) ? -diff[3] : diff[3];

	// 2:00 p.m. 		4:08 p.m.
	d[4] = 14 * 60 + 0;
	a[4] = 16 * 60 + 8;
	diff[4] = user_time_to_mins - d[4];
	diff[4] = (diff[4] < 0) ? -diff[4] : diff[4];

	// 3:45 p.m.		5:55 p.m.
	d[5] = 15 * 60 + 45;
	a[5] = 17 * 60 + 55;
	diff[5] = user_time_to_mins - d[5];
	diff[5] = (diff[5] < 0) ? -diff[5] : diff[5];

	// 7:00 p.m. 		9:20 p.m.
	d[6] = 19 * 60 + 0;
	a[6] = 21 * 60 + 20;
	diff[6] = user_time_to_mins - d[6];
	diff[6] = (diff[6] < 0) ? -diff[6] : diff[6];

	// 9:45 p.m.		11:58 p.m.
	d[7] = 21 * 60 + 45;
	a[7] = 23 * 60 + 58;
	diff[7] = user_time_to_mins - d[7];
	diff[7] = (diff[7] < 0) ? -diff[7] : diff[7];

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
	int lowest_diff = diff[0];
	int lowest_departure = d[0];
	int lowest_arrival = a[0];
	int lowest_index = 0;

	// use a while loop to find the lowest diff[] value and it's corresponding departure and arrival times
	int i = 0;
	while (i < 8)
	{
		if (diff[i] < lowest_diff)
		{
			lowest_diff = diff[i];
			lowest_departure = d[i];
			lowest_arrival = a[i];
			lowest_index = i;
		}
		i++;
	}

	printf("Departure time     Arrival time\n");
	switch (lowest_index)
	{
	case 0:
		printf("8:00 a.m.          10:16 a.m.\n");
		break;
	case 1:
		printf("9:43 a.m.          11:52 a.m.\n");
		break;
	case 2:
		printf("11:19 a.m.         1:31 p.m.\n");
		break;
	case 3:
		printf("12:47 p.m.         3:00 p.m.\n");
		break;
	case 4:
		printf("2:00 p.m.          4:08 p.m.\n");
		break;
	case 5:
		printf("3:45 p.m.          5:55 p.m.\n");
		break;
	case 6:
		printf("7:00 p.m.          9:20 p.m.\n");
		break;
	case 7:
		printf("9:45 p.m.          11:58 p.m.\n");
		break;
	default:
		printf("No idea if this line is reachable...\n");
	}

	return 0;
}
