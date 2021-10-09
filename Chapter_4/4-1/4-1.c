#include <stdio.h>
#define MAXLINE  1000       /* maximum input line length */

/* Exercise 4-1.  Write the function strrindex(s, t), which returns the position
 * of the rightmost occurence of t in s, or -1 if there is none. */

int mygetline(char line[], int max);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";    /* pattern to search for */

int main()
{
    char line[MAXLINE];
    int rightmost;
    
    while (mygetline(line, MAXLINE) > 0)
        if ((rightmost = strrindex(line, pattern)) >= 0)
            printf("rightmost: %d\n", rightmost);

    return 0;
}


/* mygetline: get line into s, return length */
int mygetline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* strrindex:  return rightmost index of t in s, -1 if none */
int strrindex(char s[], char t[])
{
    int i, j, k, rightmost;

    rightmost = -1;
    for (i = 0; s[i] != '\0'; ++i) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; ++j, ++k)
            ;
        if (k > 0 && t[k] == '\0')
            rightmost = i;
    }
    return rightmost;
}
