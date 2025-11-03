#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

/*
How num_in_rank[] works...
    ** num_in_rank[] is an array with 13 elements, one element for each of the 13 card ranks.
    ** ranks: 2  3  4  5  6  7  8  9  t  j  q  k  a
    ** each element of num_in_rank[] contains a value of '0' by default.
    ** The purpose of the element's value is to maintain a count of how many times that rank was found in the user's input of 5 cards.  So the user inputs 5 cards, and for each card we look at it's rank, and we increment the element of num_in_rank[] that matches this card's rank value.

    num_in_rank[] looks like this:
    rank as an ascii character from the user: '2'  '3'  '4'  '5'  '6'  '7'  '8'  '9'  't'  'j'  'q'  'k'  'a'
        convert to zero-based indexs:          0    1    2    3    4    5    6    7    8    9   10    11   12
          the values are the 'counts' of how many times you saw that rank.

                user inputs 5d, 8h, ts, as, 8s
                the ranks for this hand include: 5, 8, t, a, 8
                use a switch to convert these to zero-based indexes
                // '5'->3, '8'->6, 't'->8, 'a'->12, '8'->6
                // now increment the values at each of these indexes
                // num_in_cards[3] += 1
                // num_in_cards[6] += 1
                // num_in_cards[8] += 1
                // num_in_cards[12] += 1
                // num_in_cards[6] += 1
        num_in_cards[]:
        indexs:   0    1    2    3    4    5    6    7    8    9   10   11   12
        values:   0    0    0    1    1    1    1    1    0    0    0    0    0




*/

// external variables
int num_in_rank[NUM_RANKS];
int num_in_suit[NUM_SUITS];
bool straight, flush, four, three;
int pairs; // can be 0, 1 or 2

// prototypes
void read_cards(void);
void analyze_hand(void);
void print_result(void);

// function definitions

int main(void)
{

    // LOOP:
    while (true)
    {
        //   call read_cards()
            read_cards();
            //   call analyze_hand()
            //     ** analyze_card is where we can exit the program
            analyze_hand();
            //   call print_result()
            print_result();
    }

    return 0;
}

// function: reads the cards into the external variables num_in_rank[], num_in_suit[].
//           checks for bad cards and duplicate cards
void read_cards(void)
{
    bool card_exists[NUM_RANKS][NUM_SUITS];
    char ch, rank_ch, suit_ch;
    int rank_index, suit_index;
    bool bad_card;
    int cards_read = 0;

    //  clear out the arrays: num_in_rank[], num_in_suit[], card_exits[][]
    // clear out num_in_rank[]
    for (rank_index = 0; rank_index < NUM_RANKS; rank_index++)
    {
        num_in_rank[rank_index] = 0;
    }
    // clear out num_in_suit[]
    for (suit_index = 0; suit_index < NUM_SUITS; suit_index++)
    {
        num_in_suit[suit_index] = 0;
    }
    // clear out the card_exists[rank_index][suit_index]
    for (rank_index = 0; rank_index < NUM_RANKS; rank_index++)
    {
        for (suit_index = 0; suit_index < NUM_SUITS; suit_index++)
        {
            card_exists[rank_index][suit_index] = false;
        }
    }

    //  read 5 cards from the user
    //  LOOP:
    while (cards_read < NUM_CARDS)
    {
        bad_card = false;
        //    ask the user to enter a card
        printf("Enter a card: ");
        //    SWITCH on the first ascii char:
        rank_ch = getchar();
        switch (rank_ch)
        {
             //      convert the ascii that the user inputs into zero based index for the num_in_rank[] array
            case '0':               exit(EXIT_SUCCESS);
            case '2':               rank_index = 0; break;
            case '3':               rank_index = 1; break;
            case '4':               rank_index = 2; break;
            case '5':               rank_index = 3; break;
            case '6':               rank_index = 4; break;
            case '7':               rank_index = 5; break;
            case '8':               rank_index = 6; break;
            case '9':               rank_index = 7; break;
            case 't': case 'T':     rank_index = 8; break;
            case 'j': case 'J':     rank_index = 9; break;
            case 'q': case 'Q':     rank_index = 10; break;
            case 'k': case 'K':     rank_index = 11; break;
            case 'a': case 'A':     rank_index = 12; break;
            default:                bad_card = true;
        }
        //    SWITCH on the second ascii char:
        suit_ch = getchar();
        switch (suit_ch)
        {
            //      convert the ascii that the user inputs into zero based index for the num_in_suit[] array
            case 'c': case 'C':     suit_index = 0; break;
            case 'd': case 'D':     suit_index = 1; break;
            case 'h': case 'H':     suit_index = 2; break;
            case 's': case 'S':     suit_index = 3; break;
            default:                bad_card = true;
        }
        //    any additional ascii results in a bad card except for spaces and newline character to read the card
        //      ** (uses a loop)
        while ((ch = getchar()) != '\n')
        {
            if (ch != ' ')
            {
                bad_card = true;
            }
        }
        //    if the card is invalid (a bad card or a duplicate) the card gets ignored and loop again
        if (bad_card)
        {
            printf("Bad card; ignored.\n");
        }
        else if (card_exists[rank_index][suit_index])
        {
            printf("Duplicate card; ignored.\n");
        }
        else  //    else, the card is valid then we count the card and loop back
        {
            num_in_rank[rank_index]++;
            num_in_suit[suit_index]++;
            card_exists[rank_index][suit_index] = true;
            cards_read++;
        }
    }
}

// function: determines whether the hand contains a straight, a flush, four-of-a-kind
//           and/or three-of-a-kind; determines the number of pairs;
//           stores the results into the external variables: straight, flush, four, three, and pairs
void analyze_hand(void)
{

    // reset all the results to false and zeroes: straight, flush, four, three, pair(s)
    int num_consec = 0;
    int rank_index, suit_index;
    straight = false;
    flush = false;
    four = false;
    three = false;
    pairs = 0;
    

    // num_in_suit: 
    //     index: 0    1     2     3
    //     value: 0    0     0     0
    //
    //  flush: d d d d d
    //  num_in_suit[1] += 1
    //  num_in_suit[1] += 1
    //  num_in_suit[1] += 1
    //  num_in_suit[1] += 1
    //  num_in_suit[1] += 1
    // num_in_suit: 
    //     index: 0    1     2     3
    //     value: 0    5     0     0

    // check for a flush (uses a loop)
    for (suit_index = 0; suit_index < NUM_SUITS; suit_index++)
    {
        if (num_in_suit[suit_index] == NUM_CARDS)
        {
            flush = true;
            break;
        }
    }

    // check for a straight (uses a loop), returns if straight is true
    //   loop through each rank in the num_in_rank[] array
    //   stop when we encounter a rank who's value is not zero
    //   when the loop ends, the rank_index will be pointing at the earliest rank_index that was incremented by a user's card
    // num_in_cards[]:
    // indexs:   0    1    2    3    4    5    6    7    8    9   10   11   12
    // values:   0    0    0    1    1    1    1    1    0    0    0    0    0
    rank_index = 0;
    while (num_in_rank[rank_index] == 0)
    {
        rank_index++;
    }
    for (; rank_index < NUM_RANKS && num_in_rank[rank_index] > 0; rank_index++)
    {
        num_consec++;
    }
    if (num_consec == NUM_CARDS)
    {
        straight = true;
        return;
    }

    // check for four, three, pair(s) (uses a loop)
    for (rank_index = 0; rank_index < NUM_RANKS; rank_index++)
    {
        if (num_in_rank[rank_index] == 4)
        {
            four = true;
        }
        if (num_in_rank[rank_index] == 3)
        {
            three = true;
        }
        if (num_in_rank[rank_index] == 2)
        {
            pairs++;
        }
    }
}

// function: prints the classification of the hand
//           based on the values of the external variables:
//           ** straight, flush, four, three, and pairs
void print_result(void)
{
    // print the results to the user
    //   straight flush, four for a kind, full house, flush, straight, three of a kind, pair(s), high card
    if (straight && flush)
    {
        printf("Straight flush");
    }
    else if (four)
    {
        printf("Four of a kind");
    }
    else if (three && pairs == 1)
    {
        printf("Full house");
    }
    else if (flush)
    {
        printf("Flush");
    }
    else if (straight)
    {
        printf("Straight");
    }
    else if (three)
    {
        printf("Three of a kind");
    }
    else if (pairs == 2)
    {
        printf("Two pairs");
    }
    else if (pairs == 1)
    {
        printf("Pair");
    }
    else
    {
        printf("High card");
    }

    printf("\n\n");
}

// 2s 2d 5h 6c as