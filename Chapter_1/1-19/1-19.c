#include <stdio.h>
#define MAXLINE  1000

/* Exercise 1-19. Write a function 'reverse(s)' that reverses the
 * character string 's'. Use it to write a program that reverses its
 * input a line at a time */

int mygetline(char line[], int lim);
void reverse(char s[]);
int main()
{
    char line[MAXLINE];

    while (mygetline(line, MAXLINE) > 0) {
        reverse(line);
        printf("%s", line);
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

/* reverse:  reverse the string s */
void reverse(char s[])
{
    int len, i;
    int nb;    /* newline bias */
    char t[MAXLINE];

    len = 0;
    nb = 0;

    while (t[len] = s[len]) {
        if (t[len] == '\n')
            nb = 1;
        len++;
    }

    for (i = 0; i < len-nb; i++)
        s[i] = t[len-nb-1-i];

    if (nb == 1)
        s[i++] = '\n';

    s[i] = '\0';
}
