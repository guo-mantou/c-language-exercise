
#include <stdio.h>

#define swap(t, x, y)        {t temp; temp = x; x = y; y = temp;}

//declare functions
int ex4_14();

int main()
{
    ex4_14();
    return 0;
}

int ex4_14()
{
    int x, y;

    x = 99;
    y = 88;

    printf("t = int, x = %d, y = %d\n", x, y);
    swap(int, x, y)
    printf("after swap, x = %d, y = %d\n", x, y);

    return 0;
}
