#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5


bool straight, flush, four, three;
int pairs; 
void read_cards(int hand[NUM_CARDS][2]);
void analyze_hand(int hand[NUM_CARDS][2]);
void print_result(void);


int main(void)
{

    int hand[NUM_CARDS][2];

    while (true)
    {
            read_cards(hand);

            analyze_hand(hand);
            print_result();
    }

    return 0;
}

void read_cards(int hand[NUM_CARDS][2])
{
    
    for (int i = 0; i < NUM_CARDS; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            hand[i][j] = 0;
        }
    }

    int cards_read = 0;
    while (cards_read < NUM_CARDS)
    {
        bool bad_card = false;
        printf("Enter a card: ");
        int rank_value;
        char rank_ch = getchar();
        switch (rank_ch)
        {
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
        int suit_value;
        char suit_ch = getchar();
        switch (suit_ch)
        {
            case 'c': case 'C':     suit_value = 0; break;
            case 'd': case 'D':     suit_value = 1; break;
            case 'h': case 'H':     suit_value = 2; break;
            case 's': case 'S':     suit_value = 3; break;
            default:                bad_card = true;
        }

        char ch;
        while ((ch = getchar()) != '\n')
        {
            if (ch != ' ')
            {
                bad_card = true;
            }
        }

        if (bad_card)
        {
            printf("Bad card; ignored.\n");
            continue;
        }

        bool duplicate_card = false;
        for (int i; i < cards_read; i++)
        {
            if (hand[i][0] == rank_value && hand[i][1] == suit_value)
            {
                duplicate_card = true;
                break;
            }

        }
        if (duplicate_card)
        {
            printf("Duplicate card; ignored.\n");
            continue;
        }
        hand[cards_read][0] = rank_value;
        hand[cards_read][1] = suit_value;
        cards_read++;
    }
}

void analyze_hand(int hand[NUM_CARDS][2])
{
    int flush = true;
    for (int i = 0; i < NUM_CARDS - 1; i++)
    {
        if (hand[i][1] != hand[i+1][1])
        {
            flush = false;
        }
    }
    
    for (int i = 0; i < NUM_CARDS - 1; i++)
    {
        for (int j = 0; j < NUM_CARDS - 1 - i; j++)
        {
            int left_hand_card = hand[j][0];
            int right_hand_card = hand[j + 1][0];
            if (left_hand_card > right_hand_card)
            {
                int temp = left_hand_card;
                left_hand_card = right_hand_card;
                right_hand_card = temp;
            }
        }
    }
    
    int straight = true;
    for (int i = 0; i < NUM_CARDS - 1; i++)
    {
        int left_value = hand[i][0];
        int right_value = hand[i+1][0];

        if (left_value + 1 != right_value)
        {
            straight = false;
        }
    }

    int cards_in_a_row = 0;
    int four = false;
    int three = false;
    int pairs = 0;
    for (int i = 0; i < NUM_CARDS - 1; i++)
    {
        int left_value = hand[i][0];
        int right_value = hand[i+1][0];
        if (left_value == right_value)
        {
            if (cards_in_a_row == 0)
              cards_in_a_row = 2;
            else
                cards_in_a_row += 1;
        } 
        
        if (left_value != right_value || if you've already looped 4 times and you're on the 5th loop now)
        {
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

            cards_in_a_row = 0;
        }
    }
    
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


        int num_consec = 0;
    
    int match_counter = 0;
    for (int i = 0; i < NUM_CARDS - 1; i++)
    {
        int left_value = hand[i][0];
        int right_value = hand[i+1][0];

        if (left_value == right_value)
        {
            match_counter++;
        }
    }

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

void print_result(void)
{
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
