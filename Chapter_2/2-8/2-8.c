#include <stdio.h>
#include <stdlib.h>

/* Exercise 2-8. Write a function rightrot(x, n) that returns the value of the
 * integer x rotated to the right by n bit positions. */


unsigned getbits(unsigned x, int p, int n);
unsigned rightrot(unsigned x, int n);
unsigned count_bit_len(unsigned x);

int main(int argc, char *argv[])
{
    unsigned x, invert_x;
    int p, n;

    if (argc != 3) {
        printf("Usage: %s x n\n", argv[0]);
        return -1;
    }

    x = (unsigned)strtol(argv[1], NULL, 16);
    n = (int)strtol(argv[2], NULL, 10);

    if ((invert_x=rightrot(x, n)) != -1)
        printf("0x%x\n", rightrot(x, n));

    return 0;
}

/* rightrot:  return the value of the integer x rotated 
 * to the right by n bit positions */
unsigned rightrot(unsigned x, int n)
{
    unsigned y, len;

    if ((len=count_bit_len(x)) < n) {
        printf("Bad x and n\n");
        return -1;
    }

    y = getbits(x, n-1, n) << len-n;

    return x >> n | y;
}

/* getbits:  get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> p-n+1) & ~(~0 << n);
}

/* count_bit_len: return the bit length of x */
unsigned count_bit_len(unsigned x)
{
    unsigned i;

    for (i = 0; x != 0; x >>= 1)
        i++;

    return i;
}
