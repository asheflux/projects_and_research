#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// function prototypes
int roll_dice(void);
bool play_game(void);

int main(void)
{

    // seed the random number generator srand()timenul
    srand((unsigned)time(NULL));
    // count the number of wins and losses
    int wins = 0;
    int losses = 0;
    // play the game, record wins and losses, and repeat until the user enters anything other Y or y
    char ch = 'Y';
    do
    {
        /* code */
        if (ch != 'Y')
        {
            printf("get out");
            break;
        }
        else
        {
            if (play_game())
            {
                printf("You win!\n");
                wins++;
            }
            else
            {
                printf("You lose!\n");
                losses++;
            }
        }
        printf("\n");

        printf("Play again?\n");
        scanf(" %c", &ch); // need a space before %c to "eat" the whitespace newline character
        ch = toupper(ch);
    } while (ch == 'Y');

    // when done playing, print out the number of wins and losses to the user
    printf("You won %d times and lost %d times.\n", wins, losses);

    return 0;
}

// dummy functions
int roll_dice(void)
{
    // here is a dummy function
    // roll 2 dice.  For each dice, generate a random number between 1 and 6.
    int dice1 = (rand() % 6) + 1;
    int dice2 = (rand() % 6) + 1;
    // add the 2 dice results.  and return the result.

    int sum = dice1 + dice2;

    return sum;
}

bool play_game(void)
{
    int result = roll_dice(); // roll 2 dice
    printf("You rolled: %d\n", result);

    // STAGE 1: check for a win
    //  IF the result was 7 or 11, report a WIN
    if (result == 7 || result == 11)
        return true;
    // ELSE IF the result is 2 or 3 or 12, report a LOSS
    else if (result == 2 || result == 3 || result == 12)
        return false;
    // ELSE....call the result "the point", and enter stage 2 of the game
    else
    {
        int the_point = result;
        printf("The point is: %d\n", the_point);

        do
        {
            // DO THIS....
            // STAGE 2: Roll the dice repeatedly...
            result = roll_dice();
            printf("You rolled: %d\n", result);

            // IF a result is 7, report a loss
            if (result == 7)
                return false;
            // ELSE IF, the result == "the point", report a win
            else if (result == the_point)
                return true;
            // ELSE, ignore the result and roll again (loop again)

            // WHILE ("thepoint" != result)
        } while (the_point != result);
    }

    return 0;
}