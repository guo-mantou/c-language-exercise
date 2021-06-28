#include <stdio.h>
#include <stdlib.h>

/* Exercise 2-6.  Write a function 'setbits(x,p,n,y)' that return x with the n
 * bits that begin at position p set to the rightmost n bits of y, leaving the 
 * other bits unchanged. */

int setbits(int x, int p, int n, int y);
int getbits(int x, int p, int n);

int main(int argc, char *argv[])
{
    int x, p, n, y;

    if (argc != 5) {
        printf("Usage: %s x p n y\n", argv[0]);
        return -1;
    }

    x = (int)strtol(argv[1], NULL, 16);
    p = (int)strtol(argv[2], NULL, 10);
    n = (int)strtol(argv[3], NULL, 10);
    y = (int)strtol(argv[4], NULL, 16);

    printf("0x%x\n", setbits(x, p, n, y));

    return 0;
}

/* setbits:  return x with the n bits that begin at position p set to the rightmost
 * n bits of y, leaving the other bits unchanged */
int setbits(int x, int p, int n, int y)
{
    y = getbits(y, n-1, n);
    y = (y << (p-n+1)) | ~(~0 << (p-n+1));

    x = x | (~(~0 << n) << (p-n+1));
    return x & y;
}

/* getbits:  get n bits from position p */
int getbits(int x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}
