#include <stdio.h>
#define  MAXLINE  1000

/* Exercise 1-21. Write a program "entab" that replaces strings of blanks
 * by the mininum number of tabs and blanks to achieve the same spacing. 
 * Use the same tab stops as for "detab". When either a tab or a single 
 * blank would suffice to reach a tab stop, which should be given prefer-
 * rence? */

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
    int n, cn, tabn, spacen;    /* 'cn' is the number of characters before consecutive spaces */
    int tflag;    /* tab flag */

    tflag = 0;
    for (i=0, j=0; t[j] = s[i]; i++, j++) {
        if (s[i] == '\t')
            tflag = 1;

        if (s[i] == ' ') {
            cn = i;
            for (n = 0; s[i] == ' '; i++, n++)
                ;
            tabn = n/8;
            spacen = (tflag == 0) ? n%8+cn%8 : n%8;
            while (tabn--)
                t[j++] = '\t';
            while (spacen--)
                t[j++] = ' ';
            i--;
            j--;
        }
    }
}
