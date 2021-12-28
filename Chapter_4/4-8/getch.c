#include <stdio.h>
#include "calc.h"
#define BUFSIZE  100

char buf = 0;    /* buffer for one character pushed-back */

/* getch:  get a (possibly pushed-back) character */
int getch(void)
{
    int ret;

    if (buf != 0) {
        ret = buf;
        buf = 0;
        return ret;
    } else
        return getchar();
}

/* ungetch:  push character back on input */
void ungetch(int c)
{
    if (buf != 0)
        printf("ungetch: too many characters\n");
    else
        buf = c;
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
