#include <stdio.h>

/* copy input to output, replacing each string
 * of one or more blanks by a single blank */
int main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            putchar(c); /* print blank */
            while ((c = getchar()) == ' ')
                ;
            putchar(c); /* print first non-blank character */
            continue;
        }
        putchar(c);
    }

    return 0;
}
