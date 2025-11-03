#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

// external variables
bool straight, flush, four, three;
int pairs; // can be 0, 1 or 2

// prototype
void read_cards(int num_in_rank[], int num_in_suit[]);
void analyze_hand(int num_in_rank[], int num_in_suit[]);
void print_result(void);

// Main: classifies a poker hand
int main(void)
{
    int num_in_rank[NUM_RANKS];
    int num_in_suit[NUM_SUITS];
    
    // LOOP:
    for (;;)
    {
        //  read 5 cards
        read_cards(num_in_rank, num_in_suit);

        //  analyze the hand
        analyze_hand(num_in_rank, num_in_suit);

        //  print the results of the analysis
        print_result();
    }

    return 0;
}

// reads 5 cards and stores them in external variables.
// validates by checking for bad and duplicate cards in hand, and checks if card exists already in hand.
// exits by inputting 0
void read_cards(int num_in_rank[], int num_in_suit[])
{
    bool card_exists[NUM_RANKS][NUM_SUITS];
    char ch, rank_ch, suit_ch;
    int rank_idx, suit_idx;
    bool bad_card;
    int cards_read = 0;

    // initialize all elements in num_in_rank[] to the value 0
    for (rank_idx = 0; rank_idx < NUM_RANKS; rank_idx++)
    {
        num_in_rank[rank_idx] = 0;
    }

    // initialize all elements in card_exists[][] to the value false
    for (rank_idx = 0; rank_idx < NUM_RANKS; rank_idx++)
    {
        for (suit_idx = 0; suit_idx < NUM_SUITS; suit_idx++)
        {
            card_exists[rank_idx][suit_idx] = false;
        }
    }

    // initialize all elements in num_in_suit[] to the value 0
    for (suit_idx = 0; suit_idx < NUM_SUITS; suit_idx++)
    {
        num_in_suit[suit_idx] = 0;
    }

    // LOOP:
    while (cards_read < NUM_CARDS) // quit loop after reading 5 cards
    {
        bad_card = false;
        
        //   ask the user to enter a card
        printf("Enter a card: ");
        rank_ch = getchar();
        
        //   SWITCH:
        switch (rank_ch)
        {
            //     check for 0 to quit the program
            case '0':               exit(EXIT_SUCCESS); 
            //     c:nvert the rank_ch to zero_index
            case '2':               rank_idx = 0; break;
            case '3':               rank_idx = 1; break;
            case '4':               rank_idx = 2; break;
            case '5':               rank_idx = 3; break;
            case '6':               rank_idx = 4; break;
            case '7':               rank_idx = 5; break;
            case '8':               rank_idx = 6; break;
            case '9':               rank_idx = 7; break;
            case 't':  case 'T':    rank_idx = 8; break;
            case 'j':  case 'J':    rank_idx = 9; break;
            case 'q':  case 'Q':    rank_idx = 10; break;
            case 'k':  case 'K':    rank_idx = 11; break;
            case 'a':  case 'A':    rank_idx = 12; break;
            //     flag a bad card
            default:                bad_card = true;

        }

        suit_ch = getchar();

        //   SWITCH:
        switch (suit_ch)
        {
            //     convert the suit_ch to zero_index
            case 'c':  case 'C':    suit_idx = 0; break;
            case 'd':  case 'D':    suit_idx = 1; break;
            case 'h':  case 'H':    suit_idx = 2; break;
            case 's':  case 'S':    suit_idx = 3; break;
            //     flag a bad card
            default:                bad_card = true;
        }

        //   clear the input buffer, flag a 'bad card' if any other non-space character was seen
        while ((ch = getchar()) != '\n')
        {
            if (ch != ' ') 
            {
                bad_card = true;
            }
        }

        // validate the card, and store it if it's valid
        if (bad_card)  //   report bad card to user
        {
            printf("Bad card; ignored.\n");
        }
        else if (card_exists[rank_idx][suit_idx]) // report duplicate card to user
        {
            printf("Duplicate card; ignored.\n");
        }
        else // count the card: num_in_rank, num_in_suit, card_exists, cards_read
        {
            num_in_rank[rank_idx]++;
            num_in_suit[suit_idx]++;
            card_exists[rank_idx][suit_idx] = true;
            cards_read++;
        }
    }
}

// Determines the classification of the poker hand and stores them in the external variables
void analyze_hand(int num_in_rank[], int num_in_suit[])
{
    int num_consec = 0;
    int rank_idx, suit_idx;
    straight = false;
    flush = false;
    four = false;
    three = false;
    pairs = 0;
    
    // look for a flush:
    //   LOOP: iterate through num_in_suit[] and looking for 5 cards in any one suit
    for (suit_idx = 0; suit_idx < NUM_SUITS; suit_idx++)
    {
        if (num_in_suit[suit_idx] == NUM_CARDS)
        {
            flush = true;
        }
    }

    // look for a straight:
    //   LOOP: iterate through num_in_rank[] until you find a card at that rank
    rank_idx = 0;
    while (num_in_rank[rank_idx] == 0)
    {
        rank_idx++;
    }
    
    //   LOOP: inspect each of the remaining cards, looking for 5 consecutive cards
    for (; rank_idx < NUM_RANKS && num_in_rank[rank_idx] > 0; rank_idx++)
    {
        num_consec++;
    }
    if (num_consec == NUM_CARDS)
    {
        straight = true;
        return;
    }
    
    // look for a 4 of a kind, 3 of a kind, 2 paid, or 1 pair:
    //   LOOP: inspect each element in num_in_rank to check how many cards in that rank
    for (rank_idx = 0; rank_idx < NUM_RANKS; rank_idx++)
    {
        if (num_in_rank[rank_idx] == 4)
        {
            four = true;
        }
        if (num_in_rank[rank_idx] == 3)
        {
            three = true;
        }
        if (num_in_rank[rank_idx] == 2)
        {
            pairs++;
        }
    }
}

// prints the classifications of the hand based on the external variables
void print_result(void)
{
    // tell the user the classification of the hand:
    // straight flush, four of a kind, full house, flush, straight, three of a kind, two pairs, one pair, high card
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