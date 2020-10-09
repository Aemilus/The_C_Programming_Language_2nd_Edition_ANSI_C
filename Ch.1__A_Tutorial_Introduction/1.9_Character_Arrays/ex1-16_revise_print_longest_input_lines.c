/*
Exercise 1-16.
Revise the main routine of the longest-line program so it will correctly 
print the length of arbitrary long input
lines, and as much as possible of the text.
*/
#include <stdio.h>

#define NULL            '\0'
#define NEWLINE         '\n'
#define MAXLINELENGTH   100

#define OVERFLOW_Y      1
#define OVERFLOW_N      0

int getline(char line[], short overflow[], int max);
void copy(char to[], char from[]);

main()
{
    int len;
    int max;
    short err;
    short overflow[1];
    char line[MAXLINELENGTH];
    char longest[MAXLINELENGTH];

    while ((len = getline(line, overflow, MAXLINELENGTH)) > 0) {
        if (len > max) {
            copy(longest, line);
            err = overflow[0];
            max = len;
        }
    }

    if (max > 0) {
        printf("Longest line length: %d\n", max);
        printf("Overflow: %d\n", err);
        printf("%s\n", longest);
    }
}

int getline(char line[], short overflow[], int max)
{
    char c;
    int i;
    int len;

    overflow[0] = OVERFLOW_N;
    for (i=0; i<max-1 && (c=getchar())!=EOF && c!=NEWLINE; ++i)
        line[i] = c;
    len = i;

    /* if we reached char array limit but still there are characters on the line then we just continue to count and set overflow flag */
    if (c!=EOF && c!=NEWLINE) {
        overflow[0] = OVERFLOW_Y;
        while ((c=getchar())!=EOF && c!=NEWLINE)
            ++len;
    }

    /* mark end of string */
    if (c==NEWLINE || c==EOF) {
        line[len] = NULL;
        ++len;
    }

    return len;
}

void copy(char to[], char from[])
{
    int i;

    for (i=0; (to[i] = from[i]) != NULL; ++i);
}
