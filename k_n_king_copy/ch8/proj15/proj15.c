#include <stdio.h>

int main(void)
{
    // 1 - Receive a message from the user and store it into an array.
    printf("Enter message to be encrypted: ");
    char c;
    char message[80];
    int size = 0;
    while ((c = getchar()) != '\n')
        message[size++] = c;

    // 2 - Receive an integer to represent the amount that the letters will be shifted
    printf("Enter shift amount (1-25): ");
    int shift = 0;
    scanf("%d", &shift);

    // 3 - Encrypt the message.  Shift the letters to encrypt the message, then print the 'shifted' message.
    //   - each letter in the message is shifted numerically by the 'shift' amount, and translated to it's corresponding char.
    //   - this shift should work for both lowercase and uppercase letters.
    // if c is uppercase, then use this formula: ((c - 'A') + shift) % 26 + 'A'
    // else, if c is lowercase, then use this formula: ((c - 'a') + shift) % 26 + 'a'
    int i = 0;
    while (i < size)
    {
        c = message[i];
        if (c >= 'A' && c <= 'Z')
            message[i] = ((c - 'A') + shift) % 26 + 'A';
        else if (c >= 'a' && c <= 'z')
            message[i] = ((c - 'a') + shift) % 26 + 'a';
        i++;
    }

    // 4 - print the encrypted message
    printf("Encrypted message: ");
    for (i = 0; i < size; i++)
        printf("%c", message[i]);

    printf("\n");

    return 0;
}

//=======================

// SAMPLE OUTPUT
// Enter message to be encrypted: Go ahead, make my day.
// Enter shift amount (1-25): 3
// Encrypted message: Jr dkhdg, pdnh pb gdb.

// Enter message to be encrypted: Jr dkhdg, pdnh pb gdb.
//  Enter shift amount (1-25): 23
//  Encrypted message: Go ahead, make my day.

// 3 - Encrypt the message.  Shift the letters to encrypt the message, then print the 'shifted' message.
//   - each letter in the message is shifted numerically by the 'shift' amount, and translated to it's corresponding char.
//   - this shift should work for both lowercase and uppercase letters.
// if c is uppercase, then use this formula:
// ((c - 'A') + shift) % 26 + 'A'
// R is 82
// R as 0-indexed is 17
// A is 65
// R - A = 82 - 65 = 17
// else, if c is lowercase, then use this formula:
// ((c - 'a') + shift) % 26 + 'a'
// // A B C D E F G
// // 0 1 2 3 4 5 6
// R is now 17.  Add shift of 15.
// shifted R is 17 + 15 = 32.
// Shifted R wrapped is 32 % 26 = 6.
// Encrypted R with shift 15 is G.