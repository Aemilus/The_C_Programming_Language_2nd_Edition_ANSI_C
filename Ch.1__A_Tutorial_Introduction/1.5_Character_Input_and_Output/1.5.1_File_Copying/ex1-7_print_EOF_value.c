#include <stdio.h>

main() {
    printf("%s\t%d\n", "EOF value in decimal:", EOF);
    printf("%s\t%x\n", "EOF value in hexa:", EOF);

    /* Test with keyboard strokes */
    int c;
    while ((c = getchar()) == EOF) {
        printf("%s\t%d\t%x\n", "EOF:", c, c);
    }
}