#include <stdio.h>
#include <ctype.h>
#include "calc.h"
#define MAX   100

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c, j;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c;        /* not a number */

    j = 0;
    if (c == '-') {
        if (!isdigit(s[1] = c = getch())) {	/* after minus is not a number */
            ungetch(c);
            s[1] = '\0';
            return s[0];
        }
        else 
            j = 1;	/* negative number, so i begin at 1 */
    }
    i = (j == 1) ? 1 : 0;
    if (isdigit(c))        /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')        /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

/* verify the number whether include a decimal point */
double Isinteger(double d)
{
    int i;
    char s[MAX];
    sprintf(s, "%g", d);
    for (i = 0; s[i] != '.' && s[i] != '\0'; i++)
        ;
    if (s[i] == '\0')
        return d;
    else 
        return -1.1;
}
