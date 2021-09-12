#include <stdio.h>
#include <string.h>
#define MAXLEN    1000
#define BASE_ERROR 1

/* Exercise 3-5. Write the function 'itob(n,s,b)' that converts the integer n 
 * into a base b character representation in the string s. In particular, 
 * 'itob(n,s,16)' formats n as a hexadecimal integer in s. */

enum itob_error_code {
    ITOB_SUCCESS,
    ITOB_BASE_ERROR,
};

int itob(int n, char s[], int b);
void prints(char s[], int b);
void reverse(char s[]);
void itob_show_error_msg(int error_code);

int main()
{
    int n, b, retval;
    char s[MAXLEN];

    printf("Input n, b:\n");
    printf("n << ");
    scanf("%d", &n);
    printf("b << ");
    scanf("%d", &b);

    retval = itob(n, s, b);
    if (retval != ITOB_SUCCESS) {
        itob_show_error_msg(retval);
        return -1;
    }

    prints(s, b);
    return 0;
}

/* itob:  converts the integer n into a base b character representation in the 
 * string s. */
int itob(int n, char s[], int b)
{
    int i, sign;
    int remainder;

    if (!(b==2 || b==8 || b==10 || b==16))
        return ITOB_BASE_ERROR;

    sign = n;
    i = 0;
    do {
        if ((remainder = n%b) >= 0 && remainder <= 9)
            s[i++] = remainder + '0';
        else if (remainder >= 0xa && remainder <= 0xf)
            s[i++] = (remainder-0xa) + 'a';
        else if (remainder >= -9 && remainder < 0)
            s[i++] = -(remainder) + '0';
        else if (remainder >= -0xf && remainder <= -0xa)
            s[i++] = -(remainder+0xa) + 'a';    /* make remainder fall in range of 0 ~ 5, then plus 'a' */
    } while ((n /= b) != 0);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);

    return ITOB_SUCCESS;
}

/* prints:  print string s in b form. */
void prints(char s[], int b)
{
    switch (b) {
        case 2:
        case 10:
            printf("s: %s\n", s);
            break;

        case 8:
            printf("s: 0%s\n", s);
            break;

        case 16:
            printf("s: 0x%s\n", s);
            break;

        default:
            printf("default print.\n");
            printf("s: %s\n", s);
            break;
    }
}

/* reverse:  reverse string s in place */
void reverse(char s[])
{
    int i, j;
    int temp;

    for (i=0, j=strlen(s)-1; i < j; ++i, --j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

/* itob_show_error_msg:  show itob's error message */
void itob_show_error_msg(int error_code)
{
    switch (error_code) {
        case ITOB_BASE_ERROR:
            printf("itob error. Base should be 2, 8, 10 and 16.\n");
            break;

        default:
            break;
    }
}
