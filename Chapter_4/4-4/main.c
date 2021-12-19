#include <stdio.h>
#include <stdlib.h>  /* for atof() */
#include "calc.h"

#define MAXOP    100 /* max size of operand or operator */

/* Exercise 4-4. Add commands to print the top element of the stack without pop-
 * ping, to duplicate it, and to swap the top two elements. Add a command to
 * clear the stack */

/* reverse Polish calculator */
int main(void)
{
    int type;
    double op2;
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
                op2 = pop();
                if (op2 != 0.0)
                    push((int)pop() % (int)op2);
                else
                    printf("error: zero divisor\n");
                break;

            case '\n':
                printf("\t%.8g\n", pop());
                break;

            case 'p':    /* print top element of the stack */
                if (get_top_element())
                    printf("\n\ttop element of the stack: %.8g\n", get_top_element());
                break;

            case 'd':    /* duplicate top element */
                if (duplicate_top_elem())
                    printf("\n\ttop element has been duplicated\n");
                break;

            case 's':    /* swap the top two elements */
                if (swap_top_elem())
                    printf("\n\tthe top two elements have been swapped\n");
                break;

            case 'c':    /* clear the stack */
                clear_stack();
                printf("\n\tthe stack is clear\n");
                break;

            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}
