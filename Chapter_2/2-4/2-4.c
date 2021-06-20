#include <stdio.h>
#define MAXLEN    1000

/* Exercise 2-4. Write a alternate version of 'squeeze(s1, s2)' that deletes
 * each character in s1 that matches any character in the string s2 */

int mygetline(char s[], int lim);
void squeeze(char s1[], char s2[]);

int main()
{
    char s1[MAXLEN], s2[MAXLEN];
    printf("Input the delete character set (s2): ");
    if (mygetline(s2, MAXLEN) > 0)
        ;

    while (mygetline(s1, MAXLEN) > 0) {
        squeeze(s1, s2);
        printf("%s", s1);
    }

    return 0;
}

/* mygetline: get one line from standard input */
int mygetline(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';

    return i;
}

/* squeeze:  deletes each character in s1 that matches any character in the string s2 */
void squeeze(char s1[], char s2[])
{
    int i, j, k;

    for (i = 0; s2[i] != '\0'; i++) {
        for (j = k = 0; s1[j] != '\0'; j++)
            if (s1[j] != s2[i])
                s1[k++] = s1[j];

        s1[k] = '\0';    /* update s1's length */
    }
}
