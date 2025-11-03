NOTE: Ch9/Proj5 in the book seems to be an error.  The magic_square matrix contains a matrix of integers.  However, the book's prototypes for create_magic_square and print_magic_square wants you to use an array of chars.  This is not possible since any integer greater than 9 would require more than 1 char to store it.  Thus, a char matrix would only be able to store one digit of the integer.

Solution: use these function prototypes instead:
    void create_magic_square(int n, int magic_square[n][n]);
    void print_magic_square(int n, int magic_square[n][n]);
