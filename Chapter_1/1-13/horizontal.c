#include <stdio.h>

/* print a histogram of the lengths of words in its input 
 * horizontal version */
int main()
{
    int c, i, j;
    char symbol = '-';

    while ((c = getchar()) != EOF) 
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            putchar(c);
            i = 1;
            while (((c = getchar ()) >= 'a' && c <= 'z') || 
                    (c >= 'A' && c <= 'Z')) {
                putchar(c);
                ++i;
            }
            printf("\t\t");
            for (j = 0; j < i; ++j)
                printf("%c", symbol);
            putchar('\n');
        }
    
    return 0;
}
