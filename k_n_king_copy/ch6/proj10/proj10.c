#include <stdio.h>

int main(void)
{
	// Write a loop that continuously asks the user for dates: mm/dd/yy
	// Loop until the user enters 0/0/0
	//--store the new_date
	//--compare the new_date to the earliest_date.  If the new_date is even earlier, then store IT as the earliest_date

	// Ask the user for the first date (earliest)
	int m_earliest = 0, d_earliest = 0, y_earliest = 0;
	printf("Enter a date (mm/dd/yy): ");
	scanf("%2d/%2d/%2d", &m_earliest, &d_earliest, &y_earliest);
	// validate that it's not 0/0/0
	if (y_earliest == 0 && m_earliest == 0 && d_earliest == 0)
		return 0;

	// Define "next" date outside the while, because it will be used in the while (conditional)
	int m_next = 0, d_next = 0, y_next = 0;
	// loop, asking the user for a new date, and updating the earliest date if necessary
	do
	{
		// get the next date from the user
		printf("Enter a date (mm/dd/yy): ");
		scanf("%2d/%2d/%2d", &m_next, &d_next, &y_next);
		// break the loop if the next_date was 0/0/0
		if (y_next == 0 && m_next == 0 && d_next == 0)
			break;

		// logic to determine which date is the earliest, and update earliest_date if needed
		if (y_earliest < y_next)
		{
			y_earliest = y_earliest;
			m_earliest = m_earliest;
			d_earliest = d_earliest;
		}
		else if (y_earliest == y_next)
		{
			if (m_earliest < m_next)
			{
				y_earliest = y_earliest;
				m_earliest = m_earliest;
				d_earliest = d_earliest;
			}
			else if (m_earliest == m_next)
			{
				if (d_earliest < d_next)
				{
					y_earliest = y_earliest;
					m_earliest = m_earliest;
					d_earliest = d_earliest;
				}
				else if (d_earliest == d_next)
				{
					y_earliest = y_earliest;
					m_earliest = m_earliest;
					d_earliest = d_earliest;
				}
				else
				{
					y_earliest = y_next;
					m_earliest = m_next;
					d_earliest = d_next;
				}
			}
			else
			{
				y_earliest = y_next;
				m_earliest = m_next;
				d_earliest = d_next;
			}
		}
		else
		{
			y_earliest = y_next;
			m_earliest = m_next;
			d_earliest = d_next;
		}
	} while (y_next != 0 && m_next != 0 && d_next != 0); // continue looping while the next date wasn't 0/0/0

	// report the earliest date to the user
	printf("The earliest date is: %d/%d/%02d\n", m_earliest, d_earliest, y_earliest);

	return 0;
}
