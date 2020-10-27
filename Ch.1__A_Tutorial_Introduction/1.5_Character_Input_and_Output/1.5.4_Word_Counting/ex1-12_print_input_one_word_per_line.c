#include <stdio.h>

#define IN  1  /* inside word */
#define OUT 0 /* outside word */

/* write a program that prints it's input one word per line */
main()
{
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')) || ((c >= '0') && (c <= '9'))) {
            state = IN;
            putchar(c);
        } else if (state == IN) {
            state = OUT;
            putchar('\n');
        }
    }
}
