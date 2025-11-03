#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

// external variables
int num_in_rank[NUM_RANKS];
int num_in_suits[NUM_SUITS];
bool straight, flush, four, three;
int pairs; // can be 0, 1 or 2

// prototype
void read_cards(void);
void analyze_hand(void);
void print_result(void);

// Main: classifies a poker hand
int main(void)
{
    // LOOP:
    //  read 5 cards
    //  analyze the hand
    //  print the results of the analysis

    return 0;
}

// reads 5 cards and stores them in external variables.
// validates by checking for bad and duplicate cards in hand, and checks if card exists already in hand.
// exits by inputting 0
void read_cards(void)
{
    // initialize all elements in num_in_rank[] to the value 0
    // initialize all elements in card_exists[][] to the value false
    // initialize all elements in num_in_suit[] to the value 0

    // LOOP:
    //   ask the user to enter a card
    //   SWITCH:
    //     check for 0 to quit the program
    //     convert the rank_ch to zero_index
    //     flag a bad card
    //   SWITCH:
    //     convert the suit_ch to zero_index
    //     flag a bad card
    //   clear the input buffer, flag a 'bad card' if any other non-space character was seen
    //   report bad card to user
    //   report duplicate card to user
    //   else, count the card: num_in_rank[], num_in_suit[], card_exists[][], cards_read
    //   quit loop after reading 5 cards
}

// Determines the classification of the poker hand and stores them in the external variables
void analyze_hand(void)
{
    // look for a flush by looping through num_in_suit[] and looking for 5 cards in any one suit
    // look for a straight:
    //   LOOP: first, loop through num_in_rank[] until you find a card at that rank
    //   LOOP: inspect each of the remaining cards, looking for 5 consecutive cards; return if true
    // look for a 4 of a kind, 3 of a kind, 2 pair, or 1 pair:
    //   LOOP: inspect each element in num_in_rank[] to check how many cards in that rank
}

// prints the classifications of the hand based on the external variables
void print_result(void)
{
    // tell the user the classification of the hand:
    // straight flush, four of a kind, full house, flush, straight, three of a kind, two pairs, one pair, high card
}