#include <stdio.h>
#include <ctype.h>
#include "calc.h"
#define BUFSIZE  100

char buf[BUFSIZE];    /* buffer for ungetch */
int bufp = 0;         /* next free position in buf */

/* mygetline:  read an entire input line from standard input, return length */
int mygetline(char s[], int max)
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
void reverse(char s[], int len)
{
    int i, c;

    for (i = 0; i < len/2; i++) {
        c = s[i];
        s[i] = s[len-1-i];
        s[len-1-i] = c;
    }
}

/* getop:  get next character or numeric operand */
int getop(char s[])
{
    int i, c;

    /* get another line when buffer is empty */
    if (bufp <= 0) {
        bufp = mygetline(buf, BUFSIZE);
        reverse(buf, bufp);
    }

    while ((s[0] = c = buf[--bufp]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '+'
            && c != '-')
        return c;      /* not a number */
    if (c == '+' || c == '-') {
        if (!isdigit(s[1] = c = buf[--bufp])) {
            ++bufp;
            s[1] = '\0';
            return s[0];
        } else
            i = 1;
    } else
        i = 0;
    if (isdigit(c))    /* collect integer part */
        while (isdigit(s[++i] = c = buf[--bufp]))
            ;
    if (c == '.')      /* collect fraction part */
        while (isdigit(s[++i] = c = buf[--bufp]))
            ;
    s[i] = '\0';
    ++bufp;
    return NUMBER;
}
