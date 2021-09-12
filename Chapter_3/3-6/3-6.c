#include <stdio.h>
#include <string.h>

#define MAXLEN    1000

/* Exercise 3-6. Write a version of itoa that accepts three arguments instead of 
 * two. The third argument is a minimum filed width; the converted number must 
 * be padded with blanks on the left if necessary to make it wide enough. */

void reverse(char s[]);
void itoa(int n, char s[], int width);

int main()
{
    int n, width;
    char s[MAXLEN];

    printf("Please input n: \n");
    printf("n << ");
    scanf("%d", &n);

    printf("Please input width: \n");
    printf("width << ");
    scanf("%d", &width);

    itoa(n, s, width);
    printf("It's character form is:\n");
    printf("s:%s\n", s);

    return 0;
}

/* itoa:  convert n to characters in s with a minimum filed width */
void itoa(int n, char s[], int width)
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

    while (i < width)
        s[i++] = ' ';
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
