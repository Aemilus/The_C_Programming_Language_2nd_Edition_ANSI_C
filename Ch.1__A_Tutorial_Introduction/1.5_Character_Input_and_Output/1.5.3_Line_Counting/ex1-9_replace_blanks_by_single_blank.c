/*
Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.
*/
#include <stdio.h>

#define BLANK ' '

main() {
    int c;
    short first_blank;

    first_blank = 0;
    while ((c = getchar()) != EOF) {
        if (c == BLANK) {
            if (first_blank == 0) {
                first_blank = 1;
                putchar(c);
            }
        } else {
            first_blank = 0;
            putchar(c);
        }
    }
}
