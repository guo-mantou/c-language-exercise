#include <stdio.h>
#include <string.h>   /* for strlen() */
#define MAXLEN    1024

/* Exercise 4-13.  Write a recursive version of the function "reverse(s)", which
 * reverses the string s in place. */

/* reverse:  reverses string s in place, recursive version */
static void
reverse(char s[])
{
    static int i = 0;
    static int j;
    int c;

    if (i <= 0) {   /* first time initialize i, j */
        i = 0;
        j = strlen(s) - 1;
    }
    if (i < j) {
        i++;
        j--;
        reverse(s);
    } else {
        i--;
        j++;
        return;
    }
    c = s[i];
    s[i--] = s[j];
    s[j++] = c;
}

/* mygetline:  get oneline from standard input, return length */
static int
mygetline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c=getchar()) != EOF 
            && c != '\n'; i++)
        s[i] = c;
    s[i] = '\0';
    return i;
}

int main(void)
{
    char s[MAXLEN];

    while (mygetline(s, MAXLEN) > 0) {
        reverse(s);
        printf("%s\n", s);
    }
    return 0;
}
