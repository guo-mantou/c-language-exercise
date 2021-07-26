#include <stdio.h>
#define  MAXLEN   1000

/* Exercise 3-2. Write a function escape(s, t) that converts characters like 
 * newline and tab into visible escape sequences like \n and \t as it copies the 
 * string t to s. Use a Switch. Write a function for the other direction as well,
 * converting escape sequences into the real characters. */
void printMenu();
void escape(char *s, char *t);
void odescape(char *s, char *t);

enum menu {ESCAPE = 1, ODESCAPE, QUIT = 0};
int main()
{
    int choose;
    char s[MAXLEN];
    char *t;
    ssize_t len;

    choose = -1;
    t = NULL;
    while (choose && getline(&t, &len, stdin)) {
        printMenu();
        scanf("%d", &choose);
        switch (choose) {
            case ESCAPE:
                escape(s, t);
                printf("%s", s);
                break;

            case ODESCAPE:
                odescape(s, t);
                printf("%s", s);
                break;

            case QUIT:
                break;
        }
    };
}

/* printMenu:  print menu */
void printMenu()
{
    printf("\n");
    printf("Menu:\n");
    printf("  1 ESCAPE\n");
    printf("  2 ODESCAPE\n");
    printf("  0 QUIT\n");
    printf("  Input: ");
}

/* escape:  converts escape characters into visible sequences */
void escape(char *s, char *t)
{
    int c;

    while (c = *t) {
        switch (c) {
            case '\n':
                *s++ = '\\';
                *s++ = 'n';
                break;

            case '\t':
                *s++ = '\\';
                *s++ = 't';
                break;

            default:
                *s++ = c;
                break;
        }
        ++t;
    }

    *s = '\0';
}

/* odescape:  converts escape sequences into real escape characters */
void odescape(char *s, char *t)
{
    int c, n;

    while (c = *t) {
        switch (c) {
            case '\\':
                n = *(++t);
                if (n == 'n')
                    *s++ = '\n';
                else if (n == 't')
                    *s++ = '\t';
                else {
                    *s++ = c;
                    --t;
                }
                break;

            default:
                *s++ = c;
                break;

        }
        ++t;
    }

    *s = '\0';
}
