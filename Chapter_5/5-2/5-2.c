#include <stdio.h>
#include <ctype.h>

/* Exercise 5-2. Write getfloat, the floating-point analog of getint. What 
 * type does getfloat return as its function value */

#define BUFFSIZE 100

char buf[BUFFSIZE];  /* buffer for ungetch */
int bufp = 0;        /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* getfloat:  get next float value from input into *pn */
int getfloat(double *pn)
{
    int c, s, sign;
    double power;

    while (isspace(c = getch()))  /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    if (c == '.') {
        power = 1.0;
        for (c = getch(); isdigit(c); c = getch()) {
            *pn = 10 * *pn + (c - '0');
            power *= 10.0;
        }
        *pn /= power;
    }
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int main(void)
{
    int c;
    double num;

    while ((c = getfloat(&num)) != EOF && c != 0)
        printf("return: %d, num: %lf\n", c, num);
    return 0;
}
