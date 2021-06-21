#include <stdio.h>
#define MAXLEN    1000

/* Exercise 2-5. Write the function any(s1, s2), which returns the first location
 * in the string s1 where any character from the string s2 occurs, or -1 if s1 
 * contains no characters from s2. (The standard library function strpbrk does
 * the same job but returns a pointer to the location) */

int mygetline(char s[], int lim);
int any(char s1[], char s2[]);

int main()
{
    char s1[MAXLEN], s2[MAXLEN];

    printf("Input s2:\n");
    if (mygetline(s2, MAXLEN) == 0)
        return -1;

    while (mygetline(s1, MAXLEN) > 0)
        printf("The first location is %d\n", any(s1, s2));

    return 0;
}

/* mygetline: get one line from standard input */
int mygetline(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';

    return i;
}

/* any: return the first location in the string s1 where any character from the
 * string s2 occurs, or -1 if s1 contains no characters from s2 */
int any(char s1[], char s2[])
{
    int i, j;
    int location;

    location = -1;
    for (i = 0; s2[i] != '\0'; ++i)
        for (j = 0; s1[j] != '\0'; ++j)
            if (s1[j]==s2[i] && (location==-1 || location > j))
                location = j;

    return location;
}
