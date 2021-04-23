#include <stdio.h>

/* prints its input one word per line */
int main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t') {
            putchar(c);
            while ((c = getchar()) != ' ' && c != '\n' && c != '\t') 
                putchar(c);
            putchar('\n');
        }
    }

    return 0;
}
