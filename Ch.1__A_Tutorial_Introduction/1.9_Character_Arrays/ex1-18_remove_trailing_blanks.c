/*
Exercise 1-18
Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.
*/
#include <stdio.h>

#define MAXLINELENGTH   200
#define NEWLINE         '\n'
#define BLANK           ' '
#define TAB             '\t'
#define NULL            '\0'

int getline(char line[], int max);
int remove_trailing_blanks(char output[], int length);
void printinfo(int length);

main()
{
    int length;
    char line[MAXLINELENGTH];

    while ((length=getline(line, MAXLINELENGTH)) > 0) {
        printinfo(length);
        length = remove_trailing_blanks(line, length);
        if (length > 0) {
            printf("%s\n", line);
            printinfo(length);
        }
    }
    
    return 0;
}

int getline(char line[], int max)
{
    char c;
    int i;

    for (i=0; (c=getchar())!=EOF && i<max-1; ++i) {
        line[i] = c;
        if (c==NEWLINE) {
            ++i;
            break; 
        }
    }

    return i;
}

/*  remove_trailing_blanks: returns the length of string after skipping the trailing blanks */
int remove_trailing_blanks(char output[], int length)
{
    int i;
    char c;

    /*  loop starting from end of array and skip any trailing blank */
    for (i=length-1; (c=output[i])==BLANK || c==TAB || c==NEWLINE; --i);

    /*  loop has stopped when we reached first non-blank char;
        we need to add null char to mark end of string  */
    ++i;
    output[i]=NULL;

    return i;
}

/*  printinfo: used to print the length of each string (before printing the string itself) */
void printinfo(int length)
{
    printf("Length of line: %d\n", length);
}
