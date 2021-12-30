#include <stdio.h>
#include <ctype.h>
#include "calc.h"

static int flag = 0;    /* indicate that whether 'c' holds a valid value */

/* getop:  get next character or numeric operand */
int getop(char s[])
{
    int i;
    static int c;
    
    if (flag == 0)
        c = ' ';

    if ((s[0] = c) == ' ' || c == '\t')
        while ((s[0] = c = getch()) == ' ' || c == '\t')
            ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '+'
            && c != '-') {
        flag = 0;
        return c;      /* not a number */
    }
    if (c == '+' || c == '-') {
        if (!isdigit(s[1] = c = getch())) {
            flag = 1;
            //ungetch(c);
            s[1] = '\0';
            return s[0];
        } else
            i = 1;
    } else
        i = 0;
    if (isdigit(c))    /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')      /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    flag = 1;
    //ungetch(c);
    return NUMBER;
}
