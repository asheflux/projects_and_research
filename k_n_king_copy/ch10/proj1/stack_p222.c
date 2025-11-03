#include <stdbool.h>
#include <stdio.h>

#define STACK_SIZE 2

int contents[STACK_SIZE];
int top = 0;

void stack_underflow(void)
{
    printf("stack underflow occured!\n");
}

void stack_overflow(void)
{
    printf("stack overflow occured!\n");
}

// reset the top-pointer to the 0 position, making any existing stack values "garbage values"
void make_empty(void)
{
    top = 0;
}

// test if 'top' is on the ground floor, meaning there are no items currently in the stack (except possible garbage values).
bool is_empty(void)
{
    return top == 0;
}

// test whether the 'top' has moved beyond the last index (size-1)
bool is_full(void)
{
    return top == STACK_SIZE;
}

// adds the value of i to an array called 'contents' at index position top and increments top.  If the stack was already full, then report a stack_overflow and do nothing.
void push(int i)
{
    if (is_full())
        stack_overflow();
    else
        contents[top++] = i;
}

// tests whether the array 'contents' is empty and if it is it will report a stack_underflow and return 0 to the caller of this function, otherwise it will pop and return the last element in the array 'contents'.
int pop(void)
{
    if (is_empty())
    {
        stack_underflow();
        return 0;
    }
    else
        return contents[--top];
}

int main(void)
{

    // push 3 numbers to the stack, and report to the console the 3 numbers as you push them.
    // then, pop the top element off of the stack and report it's value to the console.
    printf("We are pushing the value 10 to the stack...\n");
    push(10);
    printf("10 has been pushed.\n");

    printf("We are pushing the value 20 to the stack...\n");
    push(20);
    printf("20 has been pushed.\n");

    printf("We are pushing the value 30 to the stack...\n");
    push(30);
    printf("30 has been pushed.\n");

    printf("\n\n");

    printf("We are POPPING the top value...\n");
    int result = pop();
    printf("The result was: %d\n", result);

    printf("We are POPPING the next value...\n");
    result = pop();
    printf("The result was: %d\n", result);

    printf("We are POPPING the next value...\n");
    result = pop();
    printf("The result was: %d\n", result);

    printf("We are POPPING the next value...\n");
    result = pop();
    printf("The result was: %d\n", result);

    return 0;
}