/*
Exercise 1-21. 
Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve
the same spacing. Use the same tab stops as for detab. When either a tab or a single blank would suffice to reach a tab stop,
which should be given preference? 
*/
#include <stdio.h>

#define TAB                 '\t'
#define NEWLINE             '\n'
#define NULL                '\0'
#define BLANK               ' '
#define MAX_LINELENGTH      200
#define TAB_SPACES          8

char line[MAX_LINELENGTH];
char eline[MAX_LINELENGTH];

int getline(void);
void entab(void);

int main()
{
    int len;

    while ((len=getline()) > 0) {
        getline();
        entab();
        printf("%s", eline);
    }
}

int getline(void)
{
    char c;
    int i;

    for (i=0; i<MAX_LINELENGTH-1 && (c=getchar())!=EOF && c!=NEWLINE; ++i)
        line[i] = c;
    
    if (c == NEWLINE) {
        line[i] = NEWLINE;
        ++i;
    }

    line[i] = NULL;

    return i;
}

void entab(void)
{
    int i;
    int j;
    int k;
    int next_tab_stop;
    char c;

    j = 0;
    for (i=0; (c=line[i]) != NULL; i=++i+k) {
        k = 0;
        /* k: count successive blanks from current position */
        while (line[i+k] == BLANK)
            ++k;
        
        /* if there are blanks then verify if we can replace by tabs */
        if (k > 0) {
            next_tab_stop = i / TAB_SPACES * TAB_SPACES + TAB_SPACES;
            while (k > 0)
        } else
            eline[j] = c;
        ++j;
    }
}