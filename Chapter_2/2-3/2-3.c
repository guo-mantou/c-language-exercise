#include <stdio.h>
#define  MAXLEN    1000

/* Exercise 2-3. Write the function htoi(s), which converts a string of hexa-
 * decimal digits (including an optional 0x or 0X) into its equivalent integer value.
 * The allowable digits are 0 through 9, a through f, A through F. */

int mygetline(char s[], int len);
int htoi(char s[]);

int main()
{
    char s[MAXLEN];

    while (mygetline(s, MAXLEN) > 0) {
        printf("%-15s%-15s\n", "STRING", "INTEGER");
        printf("%-15s0x%-15x\n", s, htoi(s));
        printf("\n");
    }

    return 0;
}


/* mygetline: get a line from standard input */
int mygetline(char s[], int len)
{
    int c, i;

    for (i = 0; i<len-1 && (c=getchar())!=EOF && c!='\n'; i++)
        s[i] = c;

    s[i] = '\0';

    return i;
}

/* htoi: converts string of hexadicimal digits to its equivalent integer value */
int htoi(char s[])
{
    int i, n;

    i = 0;
    n = 0;
    if (s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X'))
        i = 2;
    for (; s[i] != '\0'; ++i)
        if (s[i] >= '0' && s[i] <= '9')
            n = (s[i] - '0') + 16 * n;
        else if (s[i] >= 'a' && s[i] <= 'f')    // 'a' (97), 'W' (87)
            n = (s[i] - 'W') + 16 * n;
        else if (s[i] >= 'A' && s[i] <= 'F')    // 'A' (65), '7' (55)
            n = (s[i] - '7') + 16 * n;

    return n;
}
