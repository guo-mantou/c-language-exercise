#include <stdio.h>

/* Exercise 1-15. Rewrite the temperature conversion program of Secition 1.2 to
 * use a function for conversion */

void printFCTable(int lower, int upper, int step);

int main()
{
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printFCTable(lower, upper, step);

    return 0;
}

/* printFCTable: print Fahrenheit-Celsius table */
void printFCTable(int lower, int upper, int step)
{
    float fahr, celsius;

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
