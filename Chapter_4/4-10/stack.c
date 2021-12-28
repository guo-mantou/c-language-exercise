#include <stdio.h>
#include "calc.h"
#define MAXVAL    100   /* maximum depth of val stack */

int sp = 0;             /* next free stack position */
double val[MAXVAL];     /* value stack */

/* push:  push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop:  pop and return top value from stack */
double pop()
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* get_top_element:  get top element of the stack */
double get_top_element()
{
    int tsp = sp;
    if (tsp > 0)
        return val[--tsp];
    else {
        printf("\n\terror: stack empty\n");
        return 0.0;
    }
}

/* clear_stack:  clear the stack */
void clear_stack()
{
    sp = 0;
}

/* duplicate_top_elem:  duplicate the top element of the stack */
int duplicate_top_elem()
{
    if (sp > 0) {
        push(get_top_element());
        return 1;
    } else {
        printf("\n\terror: stack empty\n");
        return 0;
    }
}

/* swap_top_elem:  swap the top two element of the stack */
int swap_top_elem()
{
    int t1, t2;
    double tmp;

    t1 = sp;
    t2 = sp - 1;
    if (t1 > 1) {
        tmp = val[--t1];
        val[t1] = val[--t2];
        val[t2] = tmp;
        return 1;
    } else {
        printf("\n\terror: the stack doesn't have enough elements\n");
        return 0;
    }
}

/* print_stack:  print the stack */
void print_stack()
{
    int i;

    if (sp > 0) {
        printf("\nstack: \n");
        for (i = 0; i < sp; ++i)
            printf("[%d]   %5.8g\n", i, val[sp-1-i]);
        printf("\n");
    } else
        printf("\n\terror: the stack is empty\n");
}
