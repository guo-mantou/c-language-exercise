#include <stdio.h>
#include "calc.h"
#define BUFSIZE  100

char buf[BUFSIZE];    /* buffer for ungetch */
int bufp = 0;         /* next free position in buf */

/* mygetline:  read an entire input line from standard input, return length */
static int mygetline(char s[], int max)
{
    int c, i;

    for (i = 0; i < max-1 && (c=getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    if (i == 0 && c == EOF)
        s[i++] = EOF;
    s[i] = '\0';
    return i;
}

/* reverse:  reverse string s */
static void reverse(char s[], int len)
{
    int i, c;

    for (i = 0; i < len/2; i++) {
        c = s[i];
        s[i] = s[len-1-i];
        s[len-1-i] = c;
    }
}

/* getch:  get a (possibly pushed-back) character */
int getch(void)
{
    if (bufp <= 0) {
        bufp = mygetline(buf, BUFSIZE);
        reverse(buf, bufp);
    }
    return buf[--bufp];
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
