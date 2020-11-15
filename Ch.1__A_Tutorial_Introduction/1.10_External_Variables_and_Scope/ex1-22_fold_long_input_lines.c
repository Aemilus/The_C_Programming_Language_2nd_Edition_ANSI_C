/*
Exercise 1-22. 
Write a program to "fold" long input lines into two or more shorter lines 
after the last non-blank character that occurs before the n-th column of input. 
Make sure your program does something intelligent with very long lines, and 
if there are no blanks or tabs before the specified column. 
*/
#include <stdio.h>

#define MAX_LINE_LENGTH     10
#define NULL                '\0'
#define NEWLINE             '\n'
#define TAB                 '\t'
#define BLANK               ' '
#define COLUMN_FOLD         5

char line[MAX_LINE_LENGTH];
int linelen;

int getline(void);
void foldline(int column);

int main()
{
    while ((linelen=getline()) > 0) {
        foldline(COLUMN_FOLD);
    }

    return 0;
}

int getline(void)
{
    char c;
    int i;

    for (i=0; i<MAX_LINE_LENGTH-1 && (c=getchar())!=EOF && c!=NEWLINE; ++i)
        line[i] = c;
    
    if (c == NEWLINE) {
        line[i] = NEWLINE;
        ++i;
    }

    line[i] = NULL;

    return i;
}

void foldline(int column)
{
    int i;
    char c;

    for (i=0; i<linelen; ++i) {
        putchar(line[i]);
    }
    if (line[i] != NEWLINE)
        putchar(NEWLINE);
}
