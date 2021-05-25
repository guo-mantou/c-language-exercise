#include <stdio.h>
#define  MAXLINE   1000

/* Exercise 1-17. Write a program to print all input lines that 
 * is longer than 80 characters */

int mygetline(char s[], int lim);

int main()
{
    int len;    /* current line length */
    char line[MAXLINE];  /* current input line */

    while ((len = mygetline(line, MAXLINE)) > 0)
        if (len > 80)
            printf("%4d  %s", len, line);

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
