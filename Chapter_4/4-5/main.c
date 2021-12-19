#include <stdio.h>
#include <stdlib.h>  /* for atof() */
#include <math.h>
#include "calc.h"

#define MAXOP    100 /* max size of operand or operator */

/* Exercise 4-5. Add access to library functions like 'sin', 'exp', and 'pow'.
 * See <math.h> in Appendix B, Section 4 */

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

            case 'i':    /* sin() */
                push(sin(pop()));
                break;

            case 'o':    /* cos() */
                push(cos(pop()));
                break;

            case 'e':    /* exp() */
                push(exp(pop()));
                break;

            case 'w':    /* pow() */
                {
                    double x, y;
                    y = pop();
                    x = pop();
                    if (x == 0 && y < 0 ||
                            x < 0 && y-(int)y != 0)
                        printf("error:  pow(x,y) error\n");
                    push(pow(x, y));
                }
                break;

            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}
