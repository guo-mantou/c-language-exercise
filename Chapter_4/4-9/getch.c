#include <stdio.h>
#include "calc.h"
#define BUFSIZE  100

int buf[BUFSIZE];    /* buffer for ungetch */
int bufp = 0;         /* next free position in buf */

/* getch:  get a (possibly pushed-back) character */
int getch(void)
{
    int c;
    if (bufp > 0) {
        c = buf[--bufp];
        if (c == EOF)
            printf("getch:  got EOF\n");
        return c;
    } else {
        c = getchar();
        printf("%c\n", c);
        if (c == EOF)
            printf("getchar:  got EOF\n");
        return c;
    }
    //return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch:  push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else {
        if (c == EOF)
            printf("ungetch:  Got EOF\n");
        buf[bufp++] = c;
        printf("ungetch:  %d\n", buf[0]);
    }
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

/* show_buf:  show all elements of buf[] */
void show_buf()
{
    int i, p;

    if (bufp <= 0)
        printf("\n\tError: the buf[] is empty\n");
    else {
        printf("\nbuf:\n");
        for (i = 0, p = bufp; i < bufp; ++i)
            printf("[%d] \'%c\'\n", i, buf[p-1-i]);
    }
}
