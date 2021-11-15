#include <stdio.h>
#include <stdlib.h>  /* for atof() */
#include "calc.h"

#define MAXOP    100 /* max size of operand or operator */
#define tpush(x)    push(top_elem = (x))  /* make sure top_elem always right */

/* Exercise 4-4. Add commands to print the top element of the stack without pop-
 * ping, to duplicate it, and to swap the top two elements. Add a command to
 * clear the stack */

/* reverse Polish calculator */
int main(void)
{
    int type;
    double op2, top_elem;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                tpush(atof(s));
                break;

            case '+':
                tpush(pop() + pop());
                break;

            case '*':
                tpush(pop() * pop());
                break;

            case '-':
                op2 = pop();
                tpush(pop() - op2);
                break;

            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    tpush(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;

            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    tpush((int)pop() % (int)op2);
                else
                    printf("error: zero divisor\n");
                break;

            case '\n':
                printf("\t%.8g\n", pop());
                break;

                /* FIXME: input 3 4 + 5 6 * p s p -> '\n' -> p Ctrl-d
                 * print still 7, which should be updated to 30! */
            case 'p':    /* print top element of the stack */
                printf("\n\ttop element of the stack: %.8g\n", top_elem);
                break;

            case 'd':    /* duplicate top element */
                tpush(top_elem);
                printf("\n\ttop element has been duplicated\n");
                break;

            case 's':    /* swap the top two elements */
                {
                    double elem1, elem2;
                    elem1 = pop();
                    elem2 = pop();
                    tpush(elem1);
                    tpush(elem2);
                    printf("\n\tthe top two elements have been swapped\n");
                }
                break;

            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}
