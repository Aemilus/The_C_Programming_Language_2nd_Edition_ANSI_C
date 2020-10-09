/*
Exercise 1-19
Write a function reverse(s) that reverses the character string s.
Use it to write a program that reverses its input a line at a time.
*/

#include <stdio.h>

#define MAXLINELENGTH   200
#define NEWLINE         '\n'
#define NULL            '\0'

int getline(char line[], int max);
void reverse(char output[], char input[], int length);

main()
{
    int length;
    char line[MAXLINELENGTH];
    char backwards[MAXLINELENGTH];

    while ((length=getline(line, MAXLINELENGTH)) > 0) {
        reverse(backwards, line, length);
        printf("%s\n", backwards);
    }
}

int getline(char line[], int max)
{
    int i;
    char c;

    for (i=0; (c=getchar())!=EOF && c!=NEWLINE && i<max-1; ++i)
        line[i] = c;

    return i;
}

/*  reverse: output char array will hold the reversed input string  */
void reverse(char output[], char input[], int length)
{
    int i;
    char c;

    for (i=0; i<length; ++i)
        output[i] = input[length-1-i];

    output[i] = NULL;
}
