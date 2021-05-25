#include <stdio.h>

int main()
{
    int c;

    while (c = (getchar() != EOF)) {
        printf("%d\n", c);
        //printf("%c\n", c);
    }

    return 0;
}
