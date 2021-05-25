#include <stdio.h>
#define MAXLINE   1000





int sa = 0;    

int mygetline(char s[], int lim);
void removecomments(char t[], char s[]);
int main() 
{
    char line[MAXLINE];
    char rcline[MAXLINE];    

    while (mygetline(line, MAXLINE) > 0) {
        removecomments(rcline, line);
        printf("%s", rcline);
    }

    return 0;
}


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


void removecomments(char t[], char s[])
{
    int i, j;
    int doubleQuote, singleQuote;

    doubleQuote = singleQuote = 0;
    for (i=0, j=0; t[j] = s[i]; i++, j++) {
        if (t[j] == '"') {
            doubleQuote++;
            if (doubleQuote == 2)
                doubleQuote = sa = 0;
        }

        if (t[j] == '\'') {
            singleQuote++;
            if (singleQuote == 2)
                singleQuote = sa = 0;
        }

        if (doubleQuote!=1 && singleQuote!=1)     
            if (t[j] == '/') {    
                if (s[i+1] == '*') {
                    sa = 1;
                    int k = i;
                    while (s[++k])
                        if (s[k] == '*' && s[k+1] == '/') {
                            sa = 0;
                            i = k+1;
                            j--;
                            break;
                        }
                }

                if (s[i+1] == '/') {
                    t[j] = '\n';
                    t[j+1] = '\0';
                    break;
                }
            }
            else if (sa == 1) {    
                int k = i;
                while (s[++k])
                    if (s[k] == '*' && s[k+1] == '/')
                        sa = 0;
                    t[0] = '\n';
                    t[1] = '\0';
                    break;
            }
    }
}
