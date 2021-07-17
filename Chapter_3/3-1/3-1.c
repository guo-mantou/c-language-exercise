#include <stdio.h>

/* Exercise 3-1. Our binary search makes two tests inside the loop, when one
 * would suffice (at the price of more tests outside). Write a version with only one
 * test inside the loop and measure the difference in run-time */

int mybinsearch(int x, int v[], int n);
int binsearch(int x, int v[], int n);

int main(int argc, char *argv[])
{
    int x;
    int i;
    int a[] = {
        1, 2, 3, 4, 5,
        6, 7, 8, 9, 10,
        11, 12, 13, 14, 15,
        99, 100, 888, 889, 1000
    };

    if (argc == 2) {
        x = atoi(argv[1]);
        //printf("Finding result: %d\n", binsearch(x, a, 20));
        printf("Finding result: %d\n", mybinsearch(x, a, 20));
    }
    else if (argc == 1) {
        printf("Not detect argument, auto test begin.\n");
        /* auto test */
        for (i = 0; i < 20; ++i) {
            printf("Finding result: %d\n", mybinsearch(a[i], a, 20));
        }
    }

    return 0;
}

/* mybinsearch:  find x in v[0] <= v[1] <= ... <= v[n-1], ONE TEST IN LOOP version */
int mybinsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = mid = 0;
    high = n-1;
    while (low<=high && x!=v[mid]) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if (x==v[mid])
        return mid;    /* find match */
    else
        return -1;    /* no match */
}

/* binsearch:  find x in v[0] <= v[1] <= ... v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n-1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;    /* found match */
    }

    return -1;    /* no match */
}

