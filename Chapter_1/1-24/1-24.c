#include <stdio.h>
#define MAXLINE       1000
#define PARENTHESES   0
#define BRACKETS      1
#define BRACES        2
#define SINGLEQUOTE   3
#define DOUBLEQUOTE   4

#define check(s)    if (count[i] != 0) \
                                    printf("unbalanced %s\n", s)

/* Exercise 1-24. Write a program to check a C program for 
 * rudimentary syntax error like unbalanced parentheses, 
 * brackets and braces. Don't forget about quotes, both 
 * single and double, escape sequences and comments. (
 * This program is hard if you do it in full generality)*/ 

int mygetline(char s[], int lim);
void countSymbol(int a[], char s[]);
int main()
{
    char line[MAXLINE];
    int i;
    int count[10] = { 0 };    // 0 parentheses 1 brackets 2 braces 3 single quote 
    // 4 double quote
    while (mygetline(line, MAXLINE) > 0)
        countSymbol(count, line);

    for (i = 0; i < 5; i++)
        switch (i) {
            case PARENTHESES:
                {
                    char *s = "parentheses";
                    check(s);
                }
                break;

            case BRACKETS:
                {
                    char *s = "brackets";
                    check(s);
                }
                break;

            case BRACES:
                {
                    char *s = "braces";
                    check(s);
                }
                break;

            case SINGLEQUOTE:
                {
                    char *s = "single quote";
                    check(s);
                }
                break;

            case DOUBLEQUOTE:
                {
                    char *s = "double quote";
                    check(s);
                }
                break;

            default:
                break;

        }

    return 0;
}

/* mygetline:  read a line to s, return length */
int mygetline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;

    if (c == '\n') {
        s[i] = '\n';
        i++;
    }

    s[i] = '\0';

    return i;
}

/* countSymbol: count the number of parentheses, brackets, braces, single
 * and double quotes */
void countSymbol(int a[], char s[])
{
    int i, c;

    for (i = 0; c = s[i]; i++)
        switch (c) {
            case '(':
                if (a[SINGLEQUOTE]!=1 && a[DOUBLEQUOTE]!=1)
                    a[PARENTHESES]++;
                break;

            case ')':
                if (a[SINGLEQUOTE]!=1 && a[DOUBLEQUOTE]!=1)
                    a[PARENTHESES]--;
                break;

            case '[':
                if (a[SINGLEQUOTE]!=1 && a[DOUBLEQUOTE]!=1)
                    a[BRACKETS]++;
                break;

            case ']':
                if (a[SINGLEQUOTE]!=1 && a[DOUBLEQUOTE]!=1)
                    a[BRACKETS]--;
                break;

            case '{':
                if (a[SINGLEQUOTE]!=1 && a[DOUBLEQUOTE]!=1)
                    a[BRACES]++;
                break;

            case '}':
                if (a[SINGLEQUOTE]!=1 && a[DOUBLEQUOTE]!=1)
                    a[BRACES]--;
                break;

            case '\'':
                if (a[DOUBLEQUOTE] != 1)
                    a[SINGLEQUOTE]++;
                if (a[SINGLEQUOTE] == 2)
                    a[SINGLEQUOTE] = 0;
                break;

            case '"':
                if (a[SINGLEQUOTE] != 1)
                    a[DOUBLEQUOTE]++;
                if (a[DOUBLEQUOTE] == 2)
                    a[DOUBLEQUOTE] = 0;
                break;
        }
}
