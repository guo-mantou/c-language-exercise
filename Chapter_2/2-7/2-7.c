#include <stdio.h>
#include <stdlib.h>

/* Exercise 2-7. Write a function invert(x, p, n) that return x with the n bits
 * that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving
 * the others unchanged. */


unsigned getbits(unsigned x, int p, int n);
unsigned invert(unsigned x, int p, int n);
int main(int argc, char *argv[])
{
    unsigned x;
    int p, n;

    if (argc != 4) {
        printf("Usage: %s x p n\n", argv[0]);
        return -1;
    }

    x = (unsigned)strtol(argv[1], NULL, 16);
    p = (int)strtol(argv[2], NULL, 10);
    n = (int)strtol(argv[3], NULL, 10);

    printf("0x%x\n", invert(x, p, n));

    return 0;
}

/* invert:  return x with the n bits that begin at position p inverted */
unsigned invert(unsigned x, int p, int n)
{
    unsigned y, z;

    y = getbits(x, p, n) ^ ~(~0 << n);    /* XOR with 11...1 to get inverted value */
    y = y << p-n+1 | getbits(x, p-n, p-n+1);    /* get suffix part of x */
    z = (x >> p+1) << p+1;    /* get prefix part of x */

    return y | z;
}

/* getbits:  get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> p-n+1) & ~(~0 << n);
}
