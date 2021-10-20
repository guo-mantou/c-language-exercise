#include <stdio.h>
#include <ctype.h>

#define MAXLINE  100

/* Exercise 4-2. Extend *atof* to handle scientific notation of the form
 *      123.45e-6
 * where a floating-point number may be followed by *e* or *E* and an optionally signed exponent. */

/* rudimentary calculator */
int main()
{
    double sum, ex_atof(char []);
    char line[MAXLINE];
    int mygetline(char line[], int max);

    sum = 0;
    while (mygetline(line, MAXLINE) > 0)
        printf("\t%f\n", sum += ex_atof(line));
    return 0;
}

/* ex_atof:  extended atof, which could handle scientific notation like *123.45e-6* */
double ex_atof(char s[])
{
    double val, power;
    int i, sign;
    int ex_val, j, ex_sign;

    for (i = 0; isspace(s[i]); ++i)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        ++i;
    for (val = 0.0; isdigit(s[i]); ++i)
        val = val * 10 + (s[i] - '0');
    if (s[i] == '.')
        ++i;
    for (power = 1.0; isdigit(s[i]); ++i) {
        val = val * 10 + (s[i] - '0');
        power *= 10;
    }

    /* handle scientific notation */
    if (s[i] == 'e' || s[i] == 'E')
        ++i;
    ex_sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        ++i;
    for (ex_val = 0; isdigit(s[i]); ++i)
        ex_val = ex_val * 10 + (s[i] - '0');
    for (j = 0; j < ex_val; ++j)
        power = (ex_sign == -1) ? power*10 : power/10;

    return sign * val / power;
}

/* mygetline: get line into s, return length */
int mygetline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
