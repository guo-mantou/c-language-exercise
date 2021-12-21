#define NUMBER   '0' /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
double get_top_element();
void clear_stack();
int duplicate_top_elem();
int swap_top_elem();
void ungets(char *s);
void print_stack();
