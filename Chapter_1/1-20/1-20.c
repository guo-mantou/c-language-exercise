#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define  MAXLINE   1000

/* Exercise 1-20. Write a program "detab" that replaces tabs 
 * in the input with the proper number of blanks to space to
 * the next tab stop. Assume a fixed set of tab stops, say 
 * every "n" columns. Should "n" be a variable or symbolic 
 * parameter? */

int mygetline(char line[], int lim);
void detab(char t[], char s[]);
int main()
{
    char line[MAXLINE];
    char no_tab_line[MAXLINE];

    while (mygetline(line, MAXLINE) > 0) {
        detab(no_tab_line, line);
        printf("%s", no_tab_line);
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

/* detab: replace the tabs in s with n blank spaces */
void detab(char t[], char s[])
{
    int i, j;
    int lts;    /* last tab subscription in s */
    int sn;     /* space number */

    lts = -1;
    sn = 0;
    for (i=0, j=0; t[j] = s[i]; i++, j++)
        if (s[i] == '\t') {
            sn = 8 - (i-lts-1)%8;     /* calculate the number of characters between two consecutive tabs */
            while (sn--)
                t[j++] = ' ';
            j--;
            lts = i;
        }
}
