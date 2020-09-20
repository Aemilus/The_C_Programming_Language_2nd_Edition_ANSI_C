#include <stdio.h>

/* count characters in input; 2nd version */
main() {
    double nc;

    for(nc = 0; getchar() != EOF; ++nc)
        ;   //the isolated semicolon ";" is a null statement; in C the for loop requires a body
    printf("%.0f\n", nc);
}
