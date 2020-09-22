#include <stdio.h>

#define IN  1   /* inside a word */
#define OUT 0   /* outside a word */

/* count lines, words and characters in input */
main()
{
    int c, nl, nw, nc, state;

    state = OUT;

    /* an assignment is an expression with a value
    and assignments associate from right to left */
    nl = nw = nc = 0;   /* it's as if we had written: nl = (nw = (nc = 0)); */

    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t') /* check comments at end */
            state = OUT;
        else if (state == OUT) {
            ++nw;
            state = IN;
        }
    }

    printf("%s %d\n", "Lines:", nl);
    printf("%s %d\n", "Words:", nw);
    printf("%s %d\n", "Chars:", nc);
}

/*
Expressions connected by && or || are evaluated from left to right,
and it is guaranteed that evaluation will stop as soon as the truth or falsehood is known.
*/