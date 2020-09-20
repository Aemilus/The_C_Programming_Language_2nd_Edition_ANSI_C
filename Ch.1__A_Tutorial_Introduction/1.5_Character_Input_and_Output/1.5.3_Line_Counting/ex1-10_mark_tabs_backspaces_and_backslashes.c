/*
Write a program to copy its input to its output, replacing each tab by \t, each backspace by \b, 
and each backslash by \\. This makes tabs and backspaces visible in an unambiguous way.
*/
#include <stdio.h>

#define TAB '\t'
#define BACKSPACE '\b'
#define BACKSLASH '\\'

main() {
    int c;

    for(c = getchar(); c != EOF; c = getchar())
        switch (c) {
            case TAB:
                putchar(BACKSLASH);
                putchar('t');
                break;
            
            case BACKSPACE:
                putchar(BACKSLASH);
                putchar('b');
                break;

            case BACKSLASH:
                putchar(BACKSLASH);
                putchar(BACKSLASH);
                break;

            default:
                putchar(c);
                break;
        }
}
