/*
Exercise 1-21. 
Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. 
Use the same tab stops as for detab. 
When either a tab or a single blank would suffice to reach a tab stop, which should be given preference? 
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
    int k; /* counts number of blanks */
    int next_tab_stop;
    char c;

    j = 0;
    for (i=0; (c=line[i]) != NULL; ++i) {
        /* k: count successive blanks from current position */
        k = 0;
        while (line[i+k] == BLANK)
            ++k;
        
        /* if there are blanks then try to replace with tabs */
        if (k > 0) {
            /* determine next tab stop index */
            next_tab_stop = i / TAB_SPACES * TAB_SPACES + TAB_SPACES - 1;
            /* while we can replace blanks with tabs then do so */
            while (i+k > next_tab_stop) {
                eline[j] = TAB;
                ++j;
                k = k - TAB_SPACES; /* subtract the number of blank spaces replaced by a tab */
                i = next_tab_stop + 1; /* move right after the last blank space replaced by tab */
                next_tab_stop = next_tab_stop + TAB_SPACES;
            }
            /*  If there are blanks remaining but we can't replace with tabs then copy the blanks;
                Since we are placed after the last blank space replaced by tab we need to move one step back
                => decrement i at start of for loop
             */
            for (--i ; k > 0; --k) {
                eline[j] = BLANK;
                ++j;
                ++i;
            }
        /* else put the current char in the eline array and move to next */
        } else {
            eline[j] = c;
            ++j;
        }
    }
    eline[j] = NULL;
}
