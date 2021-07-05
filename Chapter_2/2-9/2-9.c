#include <stdio.h>
#include <stdlib.h>

/* Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the
 * rightmost 1-bit in x. Explain why. Using this observation to write a faster
 * version of 'bitcount' */

int bitcount(unsigned x);
int mybitcount(unsigned x);
int main(int argc, char *argv[])
{
    unsigned x;

    if (argc != 2) {
        printf("Usage: %s [x]\n", argv[0]);
        return -1;
    }

    x = (unsigned)strtol(argv[1], NULL, 16);
    printf("bitcount: %d\n", bitcount(x));
    printf("mybitcount: %d\n", mybitcount(x));

    return 0;
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;

    return b;
}

/* mybitcount:  count 1 bits in x, my faster version */
int mybitcount(unsigned x)
{
    int b;

    b = 0;
    if (x == 0)
        return b;

    do {
        b++;
    } while (x &= x-1);

    return b;
}
