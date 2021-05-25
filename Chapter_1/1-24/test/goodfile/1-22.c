#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE  1000
#define myalloc(i)  tmp[i] = '\n'; \
                             tmp[i+1] = '\0'; \
                             char *p = malloc(n+1);  \
                             strcpy(p, tmp);  \
                             t[k++] = p

/* Exercise 1-22. Write a program to "fold" long input lines into two or more 
 * shorter lines after the last non-blank character that occurs before the 
 * n-th column of input. Make sure your program does sth intelligent with 
 * very long lines, and if there are no blanks and tabs before the specified 
 * column. */

int foldstr(char *t[], char s[], int n);
int mygetline(char s[], int lim);

int main(int argc, char *argv[]) 
{
    int length;    /* foldline length */
    int i, n;
    char line[MAXLINE];
    char *foldline[MAXLINE];

    if (argc != 2) {
        printf("Usage: %s [n]\n", argv[0]);
        return -1;
    }

    n = (atoi(argv[1])) ? atoi(argv[1]) : 6;
    while (mygetline(line, MAXLINE) > 0) {
        length = foldstr(foldline, line, n);
        for (i = 0; i < length; i++) {
            printf("%s", foldline[i]);
            free(foldline[i]);
        }
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

/* foldstr:  fold long input lines into more shorter lines */
int foldstr(char *t[], char s[], int n)
{
    char tmp[n+1];
    int i, j, k;
    int c;
    int lbc;    /* last blank character subscription */

    lbc = -1;
    for (i=0, j=0, k=0; tmp[j] = s[i]; i++) {
        if ((c=tmp[j])==' ' || c=='\t')
            lbc = j;

        if (j == n-1) {
            if (lbc == -1) {    /* there are no blanks and tabs before the specified column */
                myalloc(j);
                i--;
            }
            else {
                myalloc(lbc);
                i = i - (j-lbc);
            }
            j = 0;
            lbc = -1;
        }
        else
            j++;
    }

    if (j > 0 && j <= n-1)
        myalloc(j);

    return k;
}
