#include <stdio.h>
#include <stdlib.h>  /* for atof() */
#include <stdbool.h>
#include <math.h>
#include "calc.h"

#define MAXOP    100 /* max size of operand or operator */

/* Exercise 4-9. Our getch and ungetch do not handle a pushed-back EOF
 * correctly. Decide what their properties ought to be if an EOF is pushed back,
 * then implement your design. */

void helpinfo();

/* reverse Polish calculator */
int main(void)
{
    int type;
    double op2;
    double x, y, z;    /* declare variables x, y, z */
    double r;    /* most recently printed value */
    char s[MAXOP];
    bool assign, arithmetic;

    assign = arithmetic = false;
    x = y = z = 0.0;
    r = 0.0;
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                printf("push: %s\n", s);
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
                r = pop();
                printf("\t%.8g\n", r);
                break;

            case 'h':    /* show help info */
                helpinfo();
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

            case 'a':    /* print the stack */
                print_stack();
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
                            x < 0 && y-(int)y != 0)    /* verify if y is an integer */
                        printf("error:  pow(x,y) error\n");
                    push(pow(x, y));
                }
                break;

            case 'v':    /* show variables */
                printf("\n\nnormal variables:\n");
                printf("\tx:  %g\n", x);
                printf("\ty:  %g\n", y);
                printf("\tz:  %g\n", z);
                printf("\nmost recently printed variables:\n");
                printf("\tr:  %g\n", r);
                break;

            case '=':    /* for assignment of variables */
                assign = true;
                break;

            case '&':    /* for arithmetic operation of variables */
                arithmetic = true;
                break;

            case 'x':    /* variable x */
                if (assign) {
                    x = pop();
                    printf("\n\tx:  %g\n", x);
                    assign = false;
                } else if (arithmetic) {
                    push(x);
                    arithmetic = false;
                }
                break;

            case 'y':    /* variable y */
                if (assign) {
                    y = pop();
                    printf("\n\ty:  %g\n", y);
                    assign = false;
                } else if (arithmetic) {
                    push(y);
                    arithmetic = false;
                }
                break;

            case 'z':    /* variable z */
                if (assign) {
                    z = pop();
                    printf("\n\tz:  %g\n", z);
                    assign = false;
                } else if (arithmetic) {
                    push(z);
                    arithmetic = false;
                }
                break;

            case 'r':    /* for most recently printed variables */
                if (assign)
                    printf("error: can't not assign the most recently printed variables\n");
                else if (arithmetic) {
                    push(r);
                    arithmetic = false;
                }
                break;

            case 't':    /* test ungets() */
                {
                    char *str = "1 2 45";
                    printf("\npush back str \"1 2 45\" onto input\n");
                    ungets(str);
                }
                break;

            case 'b':    /* show all elements of buf[] */
                show_buf();
                break;

            default:
                printf("main:  default got %d\n", type);
                printf("\n\terror: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

/* helpinfo:  print help information */
void helpinfo()
{
    printf("\n\n<============== Reverse Polish Calculator ============>\n\n");
    printf("h:  print help infomation\n");
    printf("p:  print top element of the stack\n");
    printf("d:  duplicate top element\n");
    printf("s:  swap the top two elements\n");
    printf("c:  clear stack\n");
    printf("a:  print stack\n");
    printf("i:  sin()\n");
    printf("o:  cos()\n");
    printf("e:  exp()\n");
    printf("w:  pow()\n");
    printf("v:  show all variables\n");
    printf("x:  normal variable\n");
    printf("y:  normal variable\n");
    printf("z:  normal variable\n");
    printf("r:  most recently printed variable\n");
    printf("=:  assign variables, e.g. 2 3 + = x <=> x = 5\n");
    printf("&:  reference to variables' value, e.g. &x &y + <=> x + y\n");
    printf("t:  test ungets()\n");
    printf("b:  show all elements of buf[]\n");
    printf("\n");
}
