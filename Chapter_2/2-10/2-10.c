#include <stdio.h>
#include <stdlib.h>
#define  MAXLEN   1000

/* Exercise 2-10. Rewrite the function 'lower', which converts upper case letters
 * to lower case, with a conditional expression instead of 'if-else' */

int lower(int c);
void lowerProcess(char *s);

int main()
{
    char *str;
    size_t n;

    str = (char *)malloc(MAXLEN);
    n = MAXLEN;
    while (getline(&str, &n, stdin) > 0) {
        lowerProcess(str);
        printf("lowerProcess: %s", str);
    }

    free(str);
    return 0;
}

/* lowerProcess: convert characters of str to their lower case */
void lowerProcess(char *s)
{
    while (*s) {
        *s = lower(*s);
        ++s;
    }
}

/* lower:  convert c to lower case; conditional expression version */
int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? (c-'A'+'a') : c;
}
