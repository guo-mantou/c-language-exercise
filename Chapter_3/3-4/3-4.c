#include <stdio.h>
#include <string.h>

#define MAXLEN    1000

/* Exercise 3-4. In a two's complement number representation, our version of 
 * itoa does not handle the largest negative number, that is, the value of n equal 
 * to -(2)^(wordsize-1). Explain why not. Modify it to print that value corrently, 
 * regardless of the machine on which it runs. */


/* Answer: The reason why itoa can't handle the two's complement largest negative number 
 * is that, if n equal to -(2)^(wordsize-1), then the statement 'n = -n' will result n to 
 * 1 rather than (2)^(wordsize-1). */

void reverse(char s[]);
void itoa(int n, char s[]);

int main()
{
    int n;
    char s[MAXLEN];

    printf("Please input a integer: \n");
    printf("n << ");
    scanf("%d", &n);

    itoa(n, s);
    printf("It's character form is:\n");
    printf("s: %s\n", s);

    return 0;
}

/* itoa:  convert n to characters in s, robust version */
void itoa(int n, char s[])
{
    int i, sign;
    int remainder;

    sign = n;
    i = 0;
    do {
        if ((remainder = n%10) >= 0 && remainder <= 9)
            s[i++] = remainder + '0';
        else if (remainder >= -9 && remainder < 0)
            s[i++] = -remainder + '0';
    } while ((n /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/* reverse:  reverse string s in place */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; ++i, --j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
