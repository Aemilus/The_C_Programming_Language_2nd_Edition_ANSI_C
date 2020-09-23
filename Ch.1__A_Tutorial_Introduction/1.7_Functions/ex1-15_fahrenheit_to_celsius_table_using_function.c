/* Rewrite the temperature conversion program of Section 1.2 to use a function for conversion. */
#include <stdio.h>

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300; floating-point version */

float tocelsius(int fahr);

main() {
    int lower, upper, step, fahr;

    lower = 0;
    upper = 300;
    step = 20;

    printf("fahr celsius\n");
    for(fahr = lower; fahr <= upper; fahr = fahr + step)
        printf("%4d %7.1f\n", fahr, tocelsius(fahr));

    return 0;
}

float tocelsius(int fahr)
{
    return (5.0/9.0) * (fahr-32.0);
}
