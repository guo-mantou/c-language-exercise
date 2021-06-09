#include <stdio.h>
#define MAXLEN   1000

/* the for loop: for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i) */
/* Exercise 2-2. Write a loop equivalent to the for loop above without using &&
 * or || */

int mygetline(char s[], int lim);

int main()
{
    char line[MAXLEN];

    while (mygetline(line, MAXLEN) > 0)
        printf("%s", line);

    return 0;
}

int mygetline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1; ++i) {
        if ((c=getchar()) != '\n')
            if (c != EOF)
                s[i] = c;
            else
                break;
        else
            break;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}
