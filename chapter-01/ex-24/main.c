/* This program checks a C-program for mismatched braces */

/* Implementation:
 * brace matching syntax check:
 *
 * 1. at the end of the program, the amount of the individual opening brace symbols has to match the amount of the individual closing brace symbols
 * 2. at any given point in time, there can never be a higher number of closing brace symbols than opening brace symbols
 * 3. the current closing brace symbol always has to match the last opening brace symbol on the stack
 * 
 * all of the invariants above are covered by the stack data structure
 *
 * we dont want to check for mismatches when we are inside a single line or multiline comment or inside a string
 */

// libraries
#include <stdio.h>

// constants
#define MAXLEN 1000

// global variables
int stack_top;
int mismatch_error;
int single_line_comment;
int multi_line_comment;
int single_quote_str;
int double_quote_str;

// function prototypes
int parse_line(char stack[], char arr[]);
int stack_empty(char stack[]);
void push(char stack[], int c);
int pop(char stack[]);
void print_stack(char stack[]);
void check_mismatch(char stack[], int c);
int check_comment(char arr[], int c);

// program entry
int main(void)
{
    extern int stack_top;
    stack_top = 0;

    extern int mismatch_error;
    mismatch_error = 0;

    extern int single_line_comment;
    single_line_comment = 0;

    extern int multi_line_comment;
    multi_line_comment = 0;

    extern int single_quote_str;
    single_quote_str = 0;

    extern int double_quote_str;
    double_quote_str = 0;

    char stack[MAXLEN];
    char str[MAXLEN];

    while (parse_line(stack, str) != -1) {
        printf("%s", str);
    }

    if (mismatch_error) {
        printf("Syntax Error - mismatched brace symbols\n");
    }

    return 0;
}

int parse_line(char stack[], char arr[])
{
    extern int single_line_comment;
    extern int multi_line_comment;
    extern int single_quote_str;
    extern int double_quote_str;

    int i, c;
    i = 0;

    while (((c = getchar()) != EOF) && (c != '\n') && (i < MAXLEN - 2)) {

        // check if we are moving out of a multline comment
        if (multi_line_comment) {
            if (c == '*') {
                arr[i] = c;
                ++i;

                c = getchar();

                if (c == '/') {
                    multi_line_comment = 0;
                }

                // check for loop conditions again here, since otherwise we would not check this char
                else if ((c == EOF) || (c == '\n') || (i >= MAXLEN - 2)) {
                    break;
                }
            }
        }
        
        // check if we are moving out of a string
        if (single_quote_str || double_quote_str) {
            if (single_quote_str && (c == '\'')) {
                single_quote_str = 0;
            }

            else if (double_quote_str && (c == '"')) {
                double_quote_str = 0;
            }

            if ((single_quote_str == 0) && (double_quote_str == 0)) {

                arr[i] = c;
                ++i;

                c = getchar();

                // check for loop conditions again here, since otherwise we would not check this char
                if ((c == EOF) || (c == '\n') || (i >= MAXLEN - 2)) {
                    break;
                }
            }
        }

        // check if we are inside a comment (only if we are not insde a string)
        if ((!single_quote_str) && (!double_quote_str)) {
            if (c == '/') {
                arr[i] = c;
                ++i;

                c = check_comment(arr, c);
           
                // check for loop conditions again here, since otherwise we would not check this char
                if ((c == EOF) || (c == '\n') || (i >= MAXLEN - 2)) {
                    break;
                }
            }
        }

        // if we are not inside a comment
        if ((!single_line_comment) && (!multi_line_comment) && (!single_quote_str) && (!double_quote_str)) {
        
            // if there is a open brace symbol, place it on the stack
            if ((c == '(') || (c == '[') || (c == '{')) {
                push(stack, c);
            }

            // if there is a closed brace symbol, check for a mismatch by popping the last item off the stack
            else if ((c == ')') || (c == ']') || (c == '}')) {
                check_mismatch(stack, c);
            }

            // check if we are inside a string
            else if ((c == '\'') || (c == '"')) {
                if (c == '\'') {
                    single_quote_str = 1;
                }

                else {
                    double_quote_str = 1;
                }
            }
        }

        arr[i] = c;
        ++i;
    }

    // if we move to a newline we automatically move out of a single line comment
    if (single_line_comment) {
        single_line_comment = 0;
    }

    if (i == MAXLEN - 2) {
        printf("array full - output will be truncated\n");

        // flush I/O buffer
        while (((c = getchar()) != EOF) && (c != '\n')) {
            ;
        }
    }

    arr[i] = '\n';
    ++i;

    arr[i] = '\0';
   
    if (c == EOF) {
        return -1;
    }

    else {
        return i;
    }
}

int stack_empty(char stack[])
{
    extern int stack_top;

    // there is no element on the stack
    if (stack_top == 0) {
        return 1;
    }

    return 0;
}

void push(char stack[], int c)
{
    extern int stack_top;

    // if the stack is full
    if (stack_top == MAXLEN -1) {
        printf("Overflow - Stack full\n");
    }

    else {
        ++stack_top;
        stack[stack_top] = c;
    }
}

int pop(char stack[])
{
    extern int stack_top;

    // if the stack is empty, there were more closed brace symbols than open brace symbols
    if (stack_empty(stack)) {
        return -1;
    }

    --stack_top;

    return stack[stack_top + 1];
}

void print_stack(char stack[])
{
    int i;

    for (i = stack_top; i > 0; --i) {
        printf("%c\n", stack[i]);
    }
}

void check_mismatch(char stack[], int c) 
{
    extern int mismatch_error;

    if (c == ')') {
        if (pop(stack) != '(') {
            mismatch_error = 1;
        }
    }

    else if (c == ']') {
        if (pop(stack) != '[') {
            mismatch_error = 1;
        }
    }

    else {
        if (pop(stack) != '{') {
            mismatch_error = 1;
        }
    }
}

int check_comment(char arr[], int c)
{
    extern int single_line_comment;
    extern int multi_line_comment;

    c = getchar();

    if (c == '/') {
        single_line_comment = 1;
    }

    else if (c == '*') {
        multi_line_comment = 1;
    }

    return c;
}
