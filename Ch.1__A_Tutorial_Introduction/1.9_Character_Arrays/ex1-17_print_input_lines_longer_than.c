/*
Exercise 1-17. Write a program to print all input lines that are longer than 80 characters.
*/
#include <stdio.h>

#define MAXLENGTH   200
#define LIMITLENGTH 80
#define NULL        '\0'
#define NEWLINE     '\n'
#define TAB         '\t'
#define OVERFLOW_Y  1 /* mark if the input line is longer than the MAXLENGTH allowed */
#define OVERFLOW_N  0

/* getline: returns length of input line; input line will be stored in the char array given as argument */
int getline(char line[], int max, short error[]);  

main()
{
    short overflow[1];
    char line[MAXLENGTH];
    int length;
    /*  get input line
        verify length
        print line if valid */
    overflow[0] = OVERFLOW_N;
    while ((length = getline(line, MAXLENGTH, overflow)) > -1)
        if (length > LIMITLENGTH) {
            printf("Length: %d\n", length);
            printf("Overflow: %d\n", overflow[0]);
            printf("%s\n", line);
        }

}

int getline(char s[], int lim, short overflow[])
{
    char c;
    int i;

    /*  if overflow is set then it means the characters I am reading are still on the same line
        using the while to eat up this characters until I move to new line or hit eof */
    if (overflow[0] == OVERFLOW_Y)
        while ((c=getchar())!=EOF && c!=NEWLINE);
    
    /*  I am at start of new line */
    overflow[0] = OVERFLOW_N;

    /*  while no EOF, no newline or the max length is not crossed then copy each character to the line array */
    for (i = 0; (c=getchar())!= EOF && c!=NEWLINE && i<lim-1 ; ++i)
        s[i] = c;

    /* is the line longer than allowed to? */
    if (c!=NEWLINE && i>lim-2)
        overflow[0] = OVERFLOW_Y;

    if (i > 0) {
        s[i] = NULL;
        ++i;
    }

    if (c == EOF)
        return -1;
    else
        return i;
}
