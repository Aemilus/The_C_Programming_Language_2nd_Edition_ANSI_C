/* Write a program to print a histogram of the frequencies of different characters in its input. */
#include <stdio.h>

#define MAX 255 /* there are 255 ASCII chars */

main()
{
    int c, i, j;
    int chars_array[MAX];

    for(i = 0; i < MAX; ++i)
        chars_array[i] = 0;

    while ((c = getchar()) != EOF)
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) /* count only alphabetical chars */
            ++chars_array[c];
    
    /* vertical bars histogram */
    /* 1. find maximum vertical bar length; is equivalent with the most used character */
    int max_count = 0;
    for(i = 0; i < MAX; ++i)
        if (chars_array[i] > max_count)
            max_count = chars_array[i];
    
    /*2. plot histogram */
    for(j = max_count; j > 0; --j) {
        for(i = 0; i < MAX; ++i)
            if (chars_array[i] >= j)
                printf("|");
            else if (chars_array[i] > 0) /* characters having 0 count are excluded */
                printf(" ");
        printf("\n");
    }

    /* print characters label; they will show up in alphabetic order */
    for(i = 0; i < MAX; ++i)
        if(chars_array[i] > 0) /* characters having 0 count are excluded */
            putchar(i);
    printf("\n");
}
