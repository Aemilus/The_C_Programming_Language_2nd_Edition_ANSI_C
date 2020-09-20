#include <stdio.h>

main() {
    int c;
    long nb, nt, nl;

    nb = 0;
    nt = 0;
    nl = 0;

    while ((c = getchar()) != EOF) {
        switch (c) {
            case ' ':
                ++nb;
                break;

            case '\t':
                ++nt;
                break;

            case '\n':
                ++nl;
                break;
            
            default:
                break;
        }
    }

    printf("%10s %ld\n", "Blanks:", nb);
    printf("%10s %ld\n", "Tabs:", nt);
    printf("%10s %ld\n", "Newlines:", nl);
}
