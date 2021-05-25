#include <stdio.h>
#include <string.h>
#define MAXLINE       1000
#define BLANKLINE     0
#define NONBLANKLINE  1
#define TRAILING      0
#define NONTRAILING   1


/* Exercise 1-18. Write a program to remove trailing blanks and tabs from 
 * each line of input, and to delete entirely blank lines */

int mygetline(char line[], int lim);
int deleteWhiteSpace(char t[], char s[]);
int trailing(char s[]);

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
    int c;
    int i;      /* count input character */
    int bnf;    /* blank newline flag */

    i = 0;
    bnf = BLANKLINE;

    while (c = *s++) {
        if (i==0 && c=='\n')    /* entirely blank line */
            break;

        if ((c==' ' || c=='\t') && trailing(s) == TRAILING) {
            *t++ = '\n';
            break;
        }

        *t++ = c;
        i++;
        bnf = NONBLANKLINE;
    }

    *t = '\0';
    return bnf;
}

/* trailing: determine whether the space or tab is trailing space or tab */
int trailing(char s[])
{
    int c;
    int flag;

    flag = TRAILING;
    while (c = *s++) {
        if (c==' ' || c=='\t' || c=='\n')
            continue;
        flag = NONTRAILING;
        break;
    }

    return flag;
}
