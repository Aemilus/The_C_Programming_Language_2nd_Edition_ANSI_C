/*
Write a program to print a histogram of the lengths of words in its input.
It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
*/
#include <stdio.h>

#define MAX     100 /* max length of array with length of words */
#define IN      1   /* inside word */
#define OUT     0   /* outside word */
#define VBAR    "|"
#define HBAR    "_"
#define BLANK   " "
/* 1 - enable; 0 - disable */
#define HPLOT   0   /* enable/disable horizontal plot */
#define VPLOT   1   /* enable/disable vertical plot */

main()
{
    int c, i, j, state, words_count;
    int array_words_length[MAX];

    for(i = 0; i < MAX; ++i)
        array_words_length[i] = 0;

    /* we start from index -1 because we consider we are out of a word at beginning */
    state = OUT;
    i = -1;
    while((c = getchar()) != EOF) {
        /* if the input has more than MAX words then break from loop */
        if (i == MAX-1)
            break;
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (state == OUT) {
                /*
                if outside a word and current symbol is an alphabetical char
                then moving array index to next position
                because i'm at begining of a new word;
                */
                state = IN;
                ++i;
            }
            /* no matter the state we count the alphabetical char */
            ++array_words_length[i];
        } else
            state = OUT;
    }

    /* how many words have been given as input */
    words_count = ++i;

    /* print histogram with horizaontal bars */
    if (HPLOT == 1)
        for(i = 0; i < words_count; i++) {
            for(j = 0; j < array_words_length[i]; j++)
                printf(HBAR);
            printf("\n");
        }

    /* print histogram with vertical bars */
    if (VPLOT == 1) {
        /* 1. find maximum word length */
        int max_word_length = 0;
        for(i = 0; i < words_count; ++i)
            if (array_words_length[i] > max_word_length)
                max_word_length = array_words_length[i];

    /* 2. plot each vertical bar line starrting from lengest to shortest word */
        for(j = max_word_length; j > 0; --j){
            for(i = 0; i < words_count; ++i)
                if (array_words_length[i] >= j)
                    printf(VBAR);
                else
                    printf(BLANK);
            printf("\n");
        }
    }
}
