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
void detab(char t[], char s[], int n);
int main(int argc, char *argv[])
{
    char line[MAXLINE];
    char no_tab_line[MAXLINE];
    int n;    /* number of blanks */

    if (argc != 2) {
        printf("Usage: %s [number]\n", argv[0]);
        return -1;
    }

    n = (atoi(argv[1]) <= 8) ? atoi(argv[1]) : 8;
    while (mygetline(line, MAXLINE) > 0) {
        detab(no_tab_line, line, n);
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
void detab(char t[], char s[], int n)
{
    char blanks[n];
    int i, j;

    for (i = 0; i < n; i++)
        blanks[i] = ' ';

    for (i=0, j=0; t[j] = s[i]; i++, j++)
        if (t[j] == '\t') {
            t[j] = '\0';
            strcat(t, blanks);
            j = j + n - 1;
        }
}
