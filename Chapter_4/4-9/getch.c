#include <stdio.h>
#include "calc.h"
#define BUFSIZE  100

int buf[BUFSIZE];    /* buffer for ungetch */
int bufp = 0;         /* next free position in buf */

/* getch:  get a (possibly pushed-back) character */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch:  push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* ungets:  push back an entire string onto the input, 
 * just use ungetch() */
void ungets(char s[])
{
    int i;
    for (i = 0; s[i]; i++)
        ;
    for (i -= 1; i >= 0; --i)
        ungetch(s[i]);
}
