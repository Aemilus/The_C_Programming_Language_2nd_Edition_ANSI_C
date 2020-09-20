#include <stdio.h>

/* count lines in input */
main()
{
    int c, nl;
    
    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;

    printf("%s\t%d\n", "Number of lines:", nl);
}

/*
A character written between single quotes represents an integer value 
equal to the numerical value of the character in the machine's character set.
This is called a character constant, although 
this is just another way to write a small integer.
*/