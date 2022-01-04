#include <stdio.h>

typedef enum {
    TRUE,
    FALSE
} Boolean;

/* Exercise 4-12. Adapt the ideas of "printd" to write a recursive version of "itoa";
 * that is, convert an integer into a string by calling a recursive routine. */

/* itoa:  convert an integer into a string, recursive version */
static void
itoa(int n, char s[])
{
    static Boolean flag = FALSE;
    static int top = 0;    /* indicate top stack of function call */
    static int i = 0;      /* subscript of s[] */

    if (n < 0) {
        n = -n;
        s[i++] = '-';
    }
    if (n == -n) {    /* largest negative number */
        n += 1;
        n = -n;
        flag = TRUE;
    }
    if (n / 10) {
        ++top;
        itoa(n / 10, s);
    }
    if (top == 0 && flag == TRUE) {
        s[i++] = n%10 + '0' + 1;
        flag = FALSE;
    } else
        s[i++] = n%10 + '0';
    if (top == 0) {
        s[i] = '\0';
        i = 0;
    } else
        --top;
}

int main(void)
{
    int i, n;
    char s[100];

    for (i = 0; i < 10; i++) {
        scanf("%d", &n);
        itoa(n, s);
        printf("%s\n", s);
    }
    return 0;
}
