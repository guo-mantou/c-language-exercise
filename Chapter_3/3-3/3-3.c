#include <stdio.h>
#include <ctype.h>
#define MAXLEN    1000
#define EXPENDTOS2 do { \
                    s2[j] = c++; \
                } while (s2[j++] < s1[t])

/* Exercise 3-3. Write a function expand(s1, s2) that expands shorthand nota-
 * tions like 'a-z' in the string s1 into the equivalent complete list abc...xyz in
 * s2. Allow for letters of either case and digits, and be prepared to handle cases
 * like 'a-b-c' and 'a-z0-9' and '-a-z'. Arrange that a leading or trailing '-' is
 * taken literally. */

void expand(char *s1, char *s2);

int main(int argc, char *argv[])
{
    char s2[MAXLEN];

    if (argc != 2) {
        printf("Usage: %s [s1]\n", argv[0]);
        return -1;
    }

    expand(argv[1], s2);
    printf("expand string: %s\n", s2);

    return 0;
}

/* expand: expand s1's shorthand notations like 'a-z' into 'abc...xyz' in s2 */
void expand(char s1[], char s2[])
{
    int i, j, c, t;
    int tmp_value;

    for (i=0, j=0; (c=s1[i]) != '\0'; ++i) {
        if (isalpha(c)) {
            t = i;
            if (s1[++t]=='-' && isalpha(s1[++t]) && 
                        (tmp_value=s1[t]-c) >= 0 && tmp_value < 26) {
                EXPENDTOS2;
                i = t;
            }
            else
                s2[j++] = s1[i];
        }
        else if (isdigit(c)) {
            t = i;
            if (s1[++t]=='-' && isdigit(s1[++t]) && c<=s1[t]) {
                EXPENDTOS2;
                i = t;
            }
            else
                s2[j++] = s1[i];
        }
        else
            s2[j++] = s1[i];
    }

    s2[j] = '\0';
}
