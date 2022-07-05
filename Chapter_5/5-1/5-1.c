#include <stdio.h>
#include <ctype.h>

/* Exercise 5-1. As written, getint treats a + or - not followed by a digit as a 
 * valid representation of zero. Fix it to push such a character back on the input. */

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

/* getint:  get next integer from input into *pn */
int getint(int *pn)
{
    int c, s, sign;

    while (isspace(c = getch()))  /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        s = c;
        if (!isdigit(c = getch())) {
            //ungetch(c);
            ungetch(s);
            return s;
        }
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int main(void)
{
    int num, c;

    while ((c = getint(&num)) != EOF && c != 0)
        printf("return: %d, num: %d\n", c, num);
    return 0;
}
