#include <stdio.h>
#define swap(t, x, y) {\
    t c;\
    c = x;\
    x = y;\
    y = c;\
}

int main(void)
{
    int x, y;

    x = 1;
    y = 2;
    swap(int, x, y);
    printf("%d  %d\n", x, y);
    return 0;
}
