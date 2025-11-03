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
    //   call read_cards()
    //   call analyze_hand()
    //     ** analyze_card is where we can exit the program
    //   call print_result()

    return 0;
}

// function: reads the cards into the external variables num_in_rank[], num_in_suit[].
//           checks for bad cards and duplicate cards
void read_cards(void)
{
    //  clear out the arrays: num_in_rank[], num_in_suit[], card_exits[][]

    //  read 5 cards from the user
    //  LOOP:
    //    ask the user to enter a card
    //    SWITCH on the first ascii char:
    //      convert the ascii that the user inputs into zero based index for the num_in_rank array
    //    SWITCH on the second ascii char:
    //      convert the ascii that the user inputs into zero based index for the num_in_suit array
    //    any additional ascii results in a bad card except for spaces and newline character to read the card
    //      ** (uses a loop)
    //    if the card is invalid (a bad card or a duplicate) the card gets ignored and loop again
    //    if the card is valid then we count the card and loop back
}

// function: determines whether the hand contains a straight, a flush, four-of-a-kind
//           and/or three-of-a-kind; determines the number of pairs;
//           stores the results into the external variables: straight, flush, four, three, and pairs
void analyze_hand(void)
{
    // reset all the results to false and zeroes: straight, flush, four, three, pair(s)
    // check for a flush (uses a loop)
    // check for a straight (uses a loop), returns if straight is true
    // check for four, three, pair(s) (uses a loop)
}

// function: prints the classification of the hand
//           based on the values of the external variables:
//           ** straight, flush, four, three, and pairs
void print_result(void)
{
    // print the results to the user
    //   straight flush, four for a kind, full house, flush, straight, three of a kind, pair(s), high card
}