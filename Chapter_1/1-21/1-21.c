#include <stdio.h>
#define  MAXLINE  1000

/* Exercise 1-21. Write a program "entab" that replaces strings of blanks
 * by the mininum number of tabs and blanks to achieve the same spacing. 
 * Use the same tab stops as for "detab". When either a tab or a single 
 * blank would suffice to reach a tab stop, which should be given prefer-
 * rence? */

/* In this version, tab is given preferrence. */

int mygetline(char s[], int lim);
void entab(char t[], char s[]);
int main()
{
    char line[MAXLINE];
    char entabLine[MAXLINE];

    while (mygetline(line, MAXLINE) > 0) {
        entab(entabLine, line);
        printf("%s", entabLine);
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

/* entab: replace spaces in s with mininum tabs and spaces */
void entab(char t[], char s[])
{
    int i, j;
    int n, tn;    
    int ts;    /* last subscription of tab before consecutive spaces in s */

    tn = 0;
    ts = -1;

    for (i=0, j=0; t[j] = s[i]; i++, j++) {
        if (s[i] == '\t')
            ts = i;

        if (s[i] == ' ') {
            for (n = 0; s[i] == ' '; i++)
                if ((i-ts)%8 == 0) {
                    tn++;
                    n = 0;
                }
                else
                    n++;

            printf("tn: %d\tn: %d\n", tn, n);    /* for debug */
            while (tn) {
                t[j++] = '\t';
                --tn;
            }
            while (n) {
                t[j++] = ' ';
                --n;
            }
            i--;
            j--;
        }
    }
}
