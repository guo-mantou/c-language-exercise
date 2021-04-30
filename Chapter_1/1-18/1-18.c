#include <stdio.h>
#define MAXLINE       1000
#define BLANKLINE     1
#define NONBLANKLINE  0

/* Exercise 1-18. Write a program to remove trailing blanks and tabs from 
 * each line of input, and to delete entirely blank lines */

int mygetline(char line[], int lim);
int deleteWhiteSpace(char t[], char s[]);

int main() 
{
    char line[MAXLINE];    /* the input line */
    char realline[MAXLINE];    /* without white space line */

    while (mygetline(line, MAXLINE) > 0) {
        if (deleteWhiteSpace(realline, line) != BLANKLINE)
            printf("%s", realline);
    }

    return 0;
}

/* mygetline:  read a line to s, return length */
int mygetline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;

    if (c == '\n') {
        s[i] = '\n';
        i++;
    }

    s[i] = '\0';

    return i;
}

/* deleteWhiteSpace: remove s[]'s trailing blanks and tab and entirely 
 * blank lines, store in t[] */
int deleteWhiteSpace(char t[], char s[])
{
    int c, i;

    i = 0;

    while (c = *s++) {
        if (i==0 && c=='\n' || c=='\t')
            continue;
        *t++ = c;
        i++;
    }

    *t = '\0';

    i = (i == 0) ? BLANKLINE : NONBLANKLINE;

    return i;
}
