#include <stdio.h>

main() {
    float celsius, fahrenheit;
    int lower, upper, step;

    lower = -60;
    upper = 260;
    step = 10;

    printf("%s\n", "Celsius to Fahrenheit table:");

    celsius = lower;
    while (celsius <= upper) {
        fahrenheit = (9.0/5.0) * celsius + 32;
        printf("%3.0f %6.1f\n", celsius, fahrenheit);
        celsius += step;
    }
}
