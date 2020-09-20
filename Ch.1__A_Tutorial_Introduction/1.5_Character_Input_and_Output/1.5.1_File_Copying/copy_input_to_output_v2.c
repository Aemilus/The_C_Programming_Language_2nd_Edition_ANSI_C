#include <stdio.h>

/* copy input to output; 2nd version */
/* to generate EOF on Windows just press Ctrl + Z; on Linux typically it's Ctrl + D */
main() {
    int c;

    /* in C, any assignment, such as 'c = getchar()' is an expression and has a value
    which is the value of the left hand side after the assignment */
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
}
