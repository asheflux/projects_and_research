#include <stdio.h>

int main(void)
{

    // Tell the user to enter a sentence
    printf("Enter a sentence: ");

    // read in the sentence from the user
    int size = 0;
    char c;
    char sentence[50];
    char terminating_character = '\0';
    while ((c = getchar()) != '\n')
    {
        // first, check for the 'terminating' character, and if found, then put it inside it's own variable instead of in the array.
        if (c == '.' || c == '?' || c == '!')
            terminating_character = c;
        else
        {
            // save that sentence into an array of characters
            sentence[size] = c;
            size++;
        }
    }

    // print the original sentence, just to make sure it was input correctly.
    printf("original sentence: ");
    int i = 0;
    while (i < size)
    {
        printf("%c", sentence[i]);
        i++;
    }
    printf("%c\n", terminating_character);

    // The part where we reverse the sentence...(to be continued)
    // print this: "Reversal of sentence: " + the sentence + the terminating character

    // We need to go backwards through the array.
    //  Start with the last element at index "size - 1"
    //  End with the first element at index "0"

    printf("Reversed sentence: ");
    i = size - 1;
    int letter_count = 0;
    while (i >= 0)
    {
        // while you search each character going backwards...
        //  1. check if it's a character, and if so, keep "letter_count" of how many characters you have read for this current word.
        //  2. check if it's a 'space' character, and if so, print out "letter_count" number of characters from the sentence starting at the position just after the current position where the space was encountered (i+1)
        c = sentence[i];
        if ((c >= 'a' && c <= 'z') || c == '\'')
        {
            letter_count++;
            // printf("letter_count: %d", letter_count);
        }
        else if (c == ' ')
        {
            // print the word
            int j = i + 1;
            while (letter_count > 0)
            {
                printf("%c", sentence[j]);
                j++;
                letter_count--;
            }
            printf(" ");
        }
        // when i is 0, print the first word.
        if (i == 0)
        {
            // print the word
            int j = i;
            while (letter_count > 0)
            {
                printf("%c", sentence[j]);
                j++;
                letter_count--;
            }
        }
        i--;
    }
    printf("%c\n", terminating_character);

    return 0;
}

// SAMPLE OUTPUT
// Enter a sentence: you can cage a swallow can't you?
// Reversal of sentence: you can't swallow a cage can you?

// //Enter a sentence: you can cage a swallow can't you?
// original[50];
// {'y','o','u',' ','c','a','n',' ', 'c','a','g','e'}
// //= size 12, then original[size - 1 = 11] is the last character
// terminating_character = '.'

// reversed[50];
//  reversed = {'c','a','g','e',' ', 'c','a','n', ' ', 'y','o','u'}
//  print "reversed" for size charcters, and also print the terminating_character '.'.
//  output: "cage can you.";
// start at reversed[size-1], and go backwards.
// int i = size - 1;
// while(i > 0) {
//     //look at each character and check for a ' ' space.  If you see a space, move forward to copy the word into the reversed array
//     int j = i+1;
//     while()
// i--;
// }

// Reversal of sentence: you can't swallow a cage can you?