#include <stdio.h>

/*
The parantheses around the assignment within the condition are necessary.

The precedence of != is higher than that of =,
which means that in the absence of parantheses
the relational test != would be done before the assignment =.

So the statement c = getchar() != EOF is equivalent to c = (getchar() != EOF).

This has the undesired effect of setting c to 0 or 1,
depending on whether or not the call of getchar encountered end-of-file.
*/

/* Testing the above observations */
main() {
    int c;
    
    printf("%s\t%d\n", "Expression 'c = getchar() != EOF' gives:", c = getchar() != EOF);
}
