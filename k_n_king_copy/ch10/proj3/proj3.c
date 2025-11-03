#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5
#define RANK 0
#define SUIT 1

/*
num_in_rank: [0: 0], [1: 0], ....[12: 0]
num_in_suit: [0: 0], [1: 0], ....[3: 0]

hand_of_5_cards: [0,0: rank_value], [0,1: suit_value]

Card1: 5 of hearts is stored as:
[0,0]: 5
[0,1]: 2 (2 = hearts)

Card2: 3 of spades
[1,0]: 3
[1,1]: 3 (3 = spades)

...

Card5: 4 of diamonds
[4,0]: 4
[4,1]: 1 (1 = diamonds)

5 rows, 2 columns

Card#   Rank#   Suit#
0       5       2
1       3       3
..
..
5       4       1  

*/



// external variables
bool straight, flush, four, three;
int pairs; // can be 0, 1 or 2

// prototype
void read_cards(int hand[NUM_CARDS][2]);
void analyze_hand(int hand[NUM_CARDS][2]);
void print_result(void);

// Main: classifies a poker hand
int main(void)
{
    int hand[NUM_CARDS][2];
    
    // LOOP:
    for (;;)
    {
        //  read 5 cards
        read_cards(hand);

        //  analyze the hand
        analyze_hand(hand);

        //  print the results of the analysis
        print_result();
    }

    return 0;
}

// reads 5 cards and stores them in external variables.
// validates by checking for bad and duplicate cards in hand, and checks if card exists already in hand.
// exits by inputting 0
void read_cards(int hand[NUM_CARDS][2])
{
    char ch, rank_ch, suit_ch;
    int rank_idx, suit_idx;
    bool bad_card;
    int cards_read = 0;

    // initialize all elements in hand[][] to the value false
    for (int i = 0; i < NUM_CARDS; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            hand[i][j] = 0;
        }
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
            continue;
        }
        

        /*
        Card0 = 3 of hearts
        hand[0][0] = 3
        hand[0][1] = 2
        hand[ROW = CARD#][COL = 0:RANK, 1:SUIT]
        
        */


        // validate for a duplicate
        // hand matrix: hand[CARD_IDX][COL]
        // check the rank: if hand[cards_read][0] == rank_idx && hand[cards_read][1] == suit_idx
        for (int i = 0; i < cards_read; i++)
        {
            if (hand[i][RANK] == rank_idx && hand[i][SUIT] == suit_idx) // report duplicate card to user
            {
                printf("Duplicate card; ignored.\n");
                continue;
            }
        }

        // count the card: save the card's rank and suit into the hand
            hand[cards_read][RANK] = rank_idx;
            hand[cards_read][SUIT] = suit_idx;
            cards_read++;
        
    }
}

// Determines the classification of the poker hand and stores them in the external variables
void analyze_hand(int hand[NUM_CARDS][2])
{
    int num_consec = 0;
    int rank_idx, suit_idx;
    straight = true;
    flush = true;  //   set flush to true by default;
    four = false;
    three = false;
    pairs = 0;


    // sort the cards by their rank (using bubble sort)
    // you will need size-1 passes through the array
    // for each passthrough, and each time the current value is greater than the next value, swap them.
    //  8 5 7 2 1
    //* 5 7 2 1 8
    //  5 2 1 7 8
    //  2 1 5 7 8
    //  1 2 5 7 8
    // worst case: we need to iterate 4 times for a set of 5 numbers 
    // size-1
    //  * *
    //    * * 
    //      * *
    //        * *
    for (int i = 0; i < NUM_CARDS - 1; i++)
    {
        for (int j = 0; j < NUM_CARDS - 1 - i; j++)
        {
            if (hand[j][RANK] > hand[j+1][RANK])
            {
                // swap card j and card j+1
                // store the first card's suit and rank into temp variables
                rank_idx = hand[j][RANK];
                suit_idx = hand[j][SUIT];
                // store the second card into the first card's position
                hand[j][RANK] = hand[j+1][RANK];
                hand[j][SUIT] = hand[j+1][SUIT];
                // store the first card into the second card's position using the temp variables
                hand[j+1][RANK] = rank_idx;
                hand[j+1][SUIT] = suit_idx;
            }
        }
    }
    


    // validate for a flush:
    //   look at the first card (at index 0), and store it's suit value in a variable 'suit_idx'
    suit_idx = hand[0][SUIT];
    //   LOOP: iterate through the remaining 4 cards
    for (int i = 1; i < NUM_CARDS; i++)
    {
        //           look at the card's suit, and if it DOESN'T match the first card's suit, then set flush to FALSE and 'break' out of the for loop.
        if (hand[i][SUIT] != suit_idx)
        {
            flush = false;
            break;
        }
    }


    // validate for a straight
    // start off with 'straight' variable is true
    // start at the first card, and compare it with the second card and make sure that the second card EXACTLY equals the rank of the first card + 1
    // 3 4 5 7 9
    // verify that the rank of the second card == rank of the first card + 1
    // find the rank of the current card and add 1.  then compare that to the rank of the second card to make sure it matches.
    for (int i = 0; i < NUM_CARDS - 1; i++)
    {
        if (hand[i][RANK] + 1 != hand[i+1][RANK])
        {
            straight = false;
            break;
        }
        
    }

    // look for a 4 of a kind, 3 of a kind, 2 pair, or 1 pair:
    for (int i = 0; i < NUM_CARDS - 1; i++)
    {
        int match = 0;
        for (int j = i; j < NUM_CARDS - 1; j++)
        {
            if (hand[i][RANK] == hand[j+1][RANK])
            {
                match++;
            }
            
        }
        if (match == 3)
        {
            four = true;
            break;  // so that we don't double-count the remaining matches
        }
        else if (match == 2)
        {
            three = true;  // so that we don't double-count the remaining matches
            break;
        }
        else if (match == 1) {
            pairs++;
        }
    }



    // 4 of a kind
    // a  a  a  5  5
    

    
    // 1 pair = 2 cards have the same rank

    //ranks: 2 3 4 5 6 7 8 9 t j q k a
    // hand contains cards with these ranks: 
    //   3h 3d 5s 8h td 
    //   3  3  5  8  t
    //  only 1 match with the first card
    //  3  5  8  t  t
    //  only 1 match found
    
    // 4 of a KIND
    // 7  a  a  a  a
    // 3 matches in one pass == 4 of a kind

    // 3 OF A KIND
    // 4  7  t  t  t
    // 2 matches in one pass == 3 of a kind

    // TWO PAIR
    //  3  3  8  t  t
    //  pairs++ for the 3
    //  pairs++ for the t


    


    // for (suit_idx = 0; suit_idx < NUM_SUITS; suit_idx++)
    // {
    //     if (hand[0][suit_idx] == )
    //     {
    //         flush = true;
    //     }
    // }

    // // look for a straight:
    // //   LOOP: iterate through num_in_rank[] until you find a card at that rank
    // rank_idx = 0;
    // while (num_in_rank[rank_idx] == 0)
    // {
    //     rank_idx++;
    // }
    
    // //   LOOP: inspect each of the remaining cards, looking for 5 consecutive cards
    // for (; rank_idx < NUM_RANKS && num_in_rank[rank_idx] > 0; rank_idx++)
    // {
    //     num_consec++;
    // }
    // if (num_consec == NUM_CARDS)
    // {
    //     straight = true;
    //     return;
    // }
    
    // // look for a 4 of a kind, 3 of a kind, 2 pair, or 1 pair:
    // //   LOOP: inspect each element in num_in_rank to check how many cards in that rank
    // for (rank_idx = 0; rank_idx < NUM_RANKS; rank_idx++)
    // {
    //     if (num_in_rank[rank_idx] == 4)
    //     {
    //         four = true;
    //     }
    //     if (num_in_rank[rank_idx] == 3)
    //     {
    //         three = true;
    //     }
    //     if (num_in_rank[rank_idx] == 2)
    //     {
    //         pairs++;
    //     }
    // }



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