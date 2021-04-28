#include <stdio.h>
#define MAXLINE  10

/* Exercise 1-16. Revise the main routine of the longest-line program so it will 
 * correctly print the length of arbitrarily long input lines, and as much as 
 * possible of the test */

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;        /* current line length */
    int max;        /* maximum length seen so far */
    char line[MAXLINE];    /* current input line */
    char longest[MAXLINE]; /* longest line saved here */

    max = 0;

    while ((len = mygetline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)
        printf("%d  %s", max, longest);

    return 0;
}

/* mygetline: read a line to s, return length */
int mygetline(char s[], int lim)
{
    int c, i;

    for (i = 0; (c = getchar())!=EOF && c!='\n'; ++i)
        if (i < lim-1)
            s[i] = c;

    if (i >= lim-1) {
        s[lim-1] = '\0';
        return i;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    while ((*to++ = *from++) != '\0')
        ;
}
