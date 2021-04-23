#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP 100

/* reverse Polish calculator */
int main()
{
    int type;
    double op2, op3;
    int iop3, iop4;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                //op2 = pop();
                if ((op2 = pop()) != 0.0) {
                    //op3 = pop();
                    if ((Isinteger(op2) != -1.1) && (Isinteger(op3 = pop()) != -1.1)) {
                        push((int)op3 % (int)op2);
                    }
                    else
                        printf("error: modulus include decimal point\n");
                }
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}
