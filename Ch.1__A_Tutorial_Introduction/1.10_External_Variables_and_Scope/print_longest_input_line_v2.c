#include<stdio.h>

#define MAX     100
#define NEWLINE '\n'
#define NULL    '\0'

char line[MAX];
char longest[MAX];
int max;

int getline(void);
void copy(void);

int main()
{
    extern char line[];
    extern int max;
    int len;

    while ((len = getline()) > 0)
        if (len > max) {
            copy();
            max = len;
        }

    if (max > 0)
        printf("Longest line:\n%s", longest);

    return 0;
}

int getline(void)
{
    char c;
    int i;
    extern char line[];

    for (i=0; i<MAX-1 && (c=getchar())!=EOF && c!=NEWLINE; ++i)
        line[i] = c;
    
    if (c == NEWLINE) {
        line[i] = NEWLINE;
        ++i;
    }

    line[i] = NULL;

    return i;
}

void copy(void)
{
    extern char line[], longest[];
    int i;

    i = 0;
    while ((longest[i] = line[i]) != NULL)
        ++i;
}
