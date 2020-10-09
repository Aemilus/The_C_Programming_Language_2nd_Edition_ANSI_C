#include <stdio.h>

#define MAXLINE 1000    /* maximum input line size */
#define NEWLINE '\n'
#define NULL    '\0'    /* null character */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

main()
{
    int len;                /* current line length */
    int max;                /* maximum line length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
        if (len > max) {
            copy(longest, line);
            max = len;
        }

    if (max > 0) {
        printf("Longest Line:\n");
        printf("%s", longest);
    }
}

/* getline: read a line into s and return it's length */
int getline(char s[], int lim)
{
    char c;
    int i;
    
    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!=NEWLINE; ++i)
        s[i] = c;
    if (c == NEWLINE) {
        s[i] = c;
        ++i;
    }

    s[i] = NULL;

    return i;
}

/* copy: copy 'from' into 'to'; assume 'to' is big enough */
void copy(char to[], char from[])
{
    int i;

    for (i=0; (to[i] = from[i]) != NULL; ++i);
}
