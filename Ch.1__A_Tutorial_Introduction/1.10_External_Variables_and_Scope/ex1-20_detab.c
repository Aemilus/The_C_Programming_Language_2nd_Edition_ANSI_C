/*
Exercise 1-20
Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next
tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?
*/

#include <stdio.h>

#define TAB             '\t'
#define NEWLINE         '\n'
#define NULL            '\0'
#define BLANK           ' '
#define BLANKS_PER_TAB  4
#define MAX_LINELENGTH  200

char line[MAX_LINELENGTH];
char dline[MAX_LINELENGTH*BLANKS_PER_TAB];

int getline(void);
void detab(void);

int main()
{
    int len;
    while ((len=getline()) > 0)
        if (len > 0) {
            detab();
            printf("%s", dline);
        }

    return 0;
}

int getline(void)
{
    int i;
    char c;

    for(i=0; i<MAX_LINELENGTH-1 && (c=getchar())!=EOF && c!=NEWLINE; ++i)
        line[i] = c;
    
    if (c == NEWLINE) {
        line[i] = NEWLINE;
        ++i;
    }

    line[i] = NULL;

    return i;
}

void detab(void)
{
    char c;
    int i;
    int j;
    int k;

    j = 0;
    for (i=0; (c=line[i]) != NULL; ++i) {
        if (c == TAB) {
            for (k=0; k < BLANKS_PER_TAB - j%BLANKS_PER_TAB; ++k)
                dline[j+k] = BLANK;
            j = j + k;
        } else {
            dline[j] = c;
            ++j;
        }
    }

    dline[j] = NULL;
}
