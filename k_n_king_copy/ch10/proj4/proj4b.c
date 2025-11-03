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
bool straight = true;
bool flush = true;
bool royal = true;
bool four = false;
bool three = false;
int pairs = 0; // can be 0, 1 or 2

// prototypes
void read_cards(int hand[NUM_CARDS][2]);
void analyze_hand(int hand[NUM_CARDS][2]);
void print_result(void);
void print_hand(int hand[NUM_CARDS][2]);
void print_card(int rank_value, int suit_value);
void sort_hand(int hand[NUM_CARDS][2]);

// function definitions

int main(void)
{

    int hand[NUM_CARDS][2];

    // LOOP:
    while (true)
    {
        //   call read_cards()
            read_cards(hand);
            // print_hand(hand);
            //   call analyze_hand()
            //     ** analyze_card is where we can exit the program
            analyze_hand(hand);
            //   call print_result()
            print_result();
    }

    return 0;
}

// function: reads the cards into the external variables num_in_rank[], num_in_suit[].
//           checks for bad cards and duplicate cards
void read_cards(int hand[NUM_CARDS][2])
{
    
    // clear out the hand[NUM_CARDS][2]
    for (int i = 0; i < NUM_CARDS; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            hand[i][j] = 0;
        }
    }

    //  read 5 cards from the user
    //  LOOP:
    int cards_read = 0;
    while (cards_read < NUM_CARDS)
    {
        bool bad_card = false;
        //    ask the user to enter a card
        printf("Enter a card: ");
        //    SWITCH on the first ascii char:
        int rank_value;
        char rank_ch = getchar();
        switch (rank_ch)
        {
             //      convert the ascii that the user inputs into zero based index for the num_in_rank[] array
            case '0':               exit(EXIT_SUCCESS);
            case '2':               rank_value = 0; break;
            case '3':               rank_value = 1; break;
            case '4':               rank_value = 2; break;
            case '5':               rank_value = 3; break;
            case '6':               rank_value = 4; break;
            case '7':               rank_value = 5; break;
            case '8':               rank_value = 6; break;
            case '9':               rank_value = 7; break;
            case 't': case 'T':     rank_value = 8; break;
            case 'j': case 'J':     rank_value = 9; break;
            case 'q': case 'Q':     rank_value = 10; break;
            case 'k': case 'K':     rank_value = 11; break;
            case 'a': case 'A':     rank_value = 12; break;
            default:                bad_card = true;
        }
        //    SWITCH on the second ascii char:
        int suit_value;
        char suit_ch = getchar();
        switch (suit_ch)
        {
            //      convert the ascii that the user inputs into zero based index for the num_in_suit[] array
            case 'c': case 'C':     suit_value = 0; break;
            case 'd': case 'D':     suit_value = 1; break;
            case 'h': case 'H':     suit_value = 2; break;
            case 's': case 'S':     suit_value = 3; break;
            default:                bad_card = true;
        }
        //    any additional ascii results in a bad card except for spaces and newline character to read the card
        //      ** (uses a loop)
        char ch;
        while ((ch = getchar()) != '\n')
        {
            if (ch != ' ')
            {
                bad_card = true;
            }
        }

        /*
        The current card:
            values to insert for the current card: rank_value, and suit_value
             = hand[rank_value][suit_value]


             hand[][0 = rank] = value
             hand[][1 = suit] = value

             hand[0][0] is the FIRST CARD'S RANK
             hand[0][1] is the FIRST CARD'S SUIT

             array[index] = value
             hand[cards_read][0] = rank_value
             hand[cards_read][1] = suit_value

             first card = '2' 'h'
                hand[0][0] = 0
                hand[0][1] = 2
             second card = 'a' 's'
                hand[1][0] = 12
                hand[1][1] = 3
             third card = '4' 'd'
                hand[2][0] = 2
                hand[2][1] = 1

            // hand[][] matrix has a size of 5 cards (10 elements because each element has both a rank value and a suit value)
            // the current number of cards in the hand matrix is 'cards_read'

            current card that has not yet been inserted into the hand:
             current card: 'a' 's'
                rank_value = 12
                suit_value = 3


            hand[][]
            hand[][]
            hand[][]
            
            hand[0]:
                hand[0][0] = rank
                hand[0][1] = suit

            // *** we check each card in hand and see if any of them match the currently read card.  If so, then we mark the currently read card as a duplicate card and it gets ignored.
            // we create a flag for a duplicate card and set it to false by default
            // we check all the cards stored in the hand, one at a time using a loop
            //      describe the loop
            //      for each card in the hand
            //          we compare it with the currently inserted card by the user, its rank value and suit value

            bool duplicate_card = false;
            for (int i; i < cards_read; i++)
            {
                if (hand[i][0] == rank_value && hand[i][1] == suit_value)
                {
                    duplicate_card = true;
                    break;
                }

            }


            cards_read is 2
            // check for a duplicate
            // ** we loop through the hand 2d array and check if the current card read already exists
            //  loop through the 2d array
            //      we check if the value of the card read matches value of the same index

       */

        //    if the card is invalid (a bad card or a duplicate) the card gets ignored and loop again
        if (bad_card)
        // check for a bad card, and igore it if it isbad_card)
        {
            printf("Bad card; ignored.\n");
            continue;
        }

        // check for a duplicate and flag it using duplicate_card
        bool duplicate_card = false;
        for (int i = 0; i < cards_read; i++)
        {
            if (hand[i][0] == rank_value && hand[i][1] == suit_value)
            {
                duplicate_card = true;
                break;
            }

        }
        // ignore the duplicate card
        if (duplicate_card)
        {
            printf("Duplicate card; ignored.\n");
            continue;
        }
        // the card is valid, and we need to store it into the hand[][] matrix
        hand[cards_read][0] = rank_value;
        hand[cards_read][1] = suit_value;
        cards_read++;
    }
}

// function: determines whether the hand contains a straight, a flush, four-of-a-kind
//           and/or three-of-a-kind; determines the number of pairs;
//           stores the results into the external variables: straight, flush, four, three, and pairs

void analyze_hand(int hand[NUM_CARDS][2])
{
    // reset the external variables
    straight = true;
    flush = true;
    royal = false;
    four = false;
    three = false;
    pairs = 0; // can be 0, 1 or 2


    // SORT THE HAND
    printf("Sorting the hand...\n");
    sort_hand(hand);        
    print_hand(hand);
    printf("\n");

    // check for a flush:
    // look at each card in the hand, and check that it's suit matches the next card's suit.
    // do this until you have compared all consecutive cards.
    // if you find 5 cards with the same suit, then it's a flush.
    for (int i = 0; i < NUM_CARDS - 1; i++)
    {
        if (hand[i][1] != hand[i+1][1])
        {
            flush = false;
        }
    }

    // 4 5 6 7 8
    //----------
    // 7 8 4 6 5
    // 7 8 
    //   4 8
    //     6 8 
    //       5 8
    // 7 4 6 5 8

    // 8 7 6 5 4
    // 1: 8 is at the end
    // 2: 7 8 are the end
    // 3: 6 7 8 are at the end
    // 4: 5 6 7 8 are at the end.
    // so after 4 iterations, the numbers are in order.  4 5 6 7 8

    // CHECK FOR "STRAIGHT" on the sorted hand (uses a loop), returns if straight is true
    // look at each consecutive pair of ordered cards, and check that the rank of the next card is one value greater than the previous.    
    for (int i = 0; i < NUM_CARDS - 1; i++)
    {
        int left_value = hand[i][0];
        int right_value = hand[i+1][0];

        if (left_value + 1 != right_value)
        {
            straight = false;
        }
    }


    // if you get to this line, and straight and flush are both true, then you have a straight flush.  So if they are both true, then check for royal flush.   Remember, the cards are already sorted from lowest to highest rank. 
    
    // a q j t k
    // th jh qh kh ah
    
    if (straight && flush)
    {
        if (hand[0][0] ==  8) // 't' is rank_value 8
        {
            royal = true;
        }
    }


    

    // check for four, three, pair(s) (uses a loop)
    // look at each consecutive pair of cards in the hand
    // count how many matching pairs (by rank) are next to each other.
    // if num_consec was 0, and you encounter your first pair, increase num_consec by 2 
    // for each additional consecutive pair that you see, increase num_consec by 1
    // if you see two cards that don't match, then reset num_consec to 0


    // 5 5 5 7 7

    // 4 comparisons
    // i:0 --> 5 5
    // i:1 --> 5 5
    // i:2 --> 5 7
    // i:3 --> 7 7

    // cards_in_a_row: 3
    // three: false
    // pairs: 0

    // 2 7 7 7 7 + 1 more loop


    int cards_in_a_row = 1;
    
    for (int i = 0; i < NUM_CARDS - 1; i++)
    {
        int left_value = hand[i][0];
        int right_value = hand[i+1][0];
        if (left_value == right_value)
        {
            cards_in_a_row++;
        }
        
        //no match.  record any matching cards, and reset the counter
        if ((left_value != right_value) || (i == NUM_CARDS - 2))
        {
            // check for a 4 of a kind, 3 of a kind, or 2 of a kind 
            if (cards_in_a_row == 4) 
            {
                four = true;
            }
            else if (cards_in_a_row == 3)
            {
                three = true;
            }
            else if (cards_in_a_row == 2)
            {
                pairs++;
            }
            cards_in_a_row = 1;
        }
    }
    
    // do one final check 
    // a streak ended

    // for (int i = 0; i < NUM_RANKS; i++)
    // {
    //     if (cards_in_a_row == 4)
    //     {
    //         four = true;
    //     }
    //     if (cards_in_a_row == 3)
    //     {
    //         three = true;
    //     }
    //     if (cards_in_a_row == 2)
    //     {
    //         pairs++;
    //     }
    // }
}

// function: prints the classification of the hand
//           based on the values of the external variables:
//           ** straight, flush, four, three, and pairs
void print_result(void)
{
    // print the results to the user
    //   straight flush, four for a kind, full house, flush, straight, three of a kind, pair(s), high card
    if (royal)
    {
        printf("Royal flush");
    }
    else if (straight && flush)
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

// TEST INPUT 2s 2d 5h 6c as

// 

void print_hand(int hand[NUM_CARDS][2])
{

    for (int i = 0; i < NUM_CARDS; i++)
    {
        int rank_value = hand[i][0];
        int suit_value = hand[i][1];
        printf("Card[%d]: ", i + 1);
        print_card(rank_value, suit_value);
    }
}

void print_card(int rank_value, int suit_value) 
{

    // NEW CODE HERE
    // switch that will take the rank_value and convert it to the ascii character
    bool bad_card = false;
    char rank_ch;
    switch (rank_value)
    {
        case 0:               rank_ch = '2'; break;
        case 1:               rank_ch = '3'; break;
        case 2:               rank_ch = '4'; break;
        case 3:               rank_ch = '5'; break;
        case 4:               rank_ch = '6'; break;
        case 5:               rank_ch = '7'; break;
        case 6:               rank_ch = '8'; break;
        case 7:               rank_ch = '9'; break;
        case 8:               rank_ch = 't'; break;
        case 9:               rank_ch = 'j'; break;
        case 10:              rank_ch = 'q'; break;
        case 11:              rank_ch = 'k'; break;
        case 12:              rank_ch = 'a'; break;
        default:              bad_card = true;
    }

    // switch that will take the suit_value and convert it to the ascii character
    char suit_ch;
    switch (suit_value)
    {
        case 0:               suit_ch = 'c'; break;
        case 1:               suit_ch = 'd'; break;
        case 2:               suit_ch = 'h'; break;
        case 3:               suit_ch = 's'; break;
        default:              bad_card = true;
    }

    if (bad_card)
    {
        printf("Bad card; ignored.\n");
    } 
    else 
    {
        printf("%c%c\n", rank_ch, suit_ch);
    }
}


// SORT the cards in the hand, by their rank
// look at each consecutive pair of cards 
// if the card on the right is less than the card on the left, swap them.  otherwise do nothing and go to the next pair of cards.
// repeat this for n-1 times
void sort_hand(int hand[NUM_CARDS][2]) 
{
    
    for (int i = 0; i < NUM_CARDS - 1; i++)
    {
        for (int j = 0; j < NUM_CARDS - 1 - i; j++)
        {
            int left_hand_card = hand[j][0];
            int right_hand_card = hand[j + 1][0];
            if (left_hand_card > right_hand_card)
            {
                //swap the values
                int temp = left_hand_card;
                left_hand_card = right_hand_card;
                right_hand_card = temp;
                hand[j][0] = left_hand_card;
                hand[j + 1][0] = right_hand_card;
            }
        }
    }
}

/*
Enter a card: 4d  
Enter a card: 5d
Enter a card: 6d
Enter a card: 7d
Enter a card: 1d
Bad card; ignored.
Enter a card: ad
Four of a kind

*/

    // struct hand_result {
    //     bool straight;
    //     bool flush;
    //     bool royal;
    //     bool four;
    //     bool three;
    //     int pairs;
    //     initializeDefaultValues: {
    //         straight = true;
    //         flush = true;
    //         royal = false;
    //         four = false;
    //         three = false;
    //         pairs = 0; // can be 0, 1 or 2
    //     }
    // }
