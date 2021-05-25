#include <stdio.h>  /* for printf and exit */
#include <string.h> /* for strcmp */
#include <stdlib.h> /* for exit */ 

#define MAXSIZE    100
#define DEFFER     1
#define INDENTICAL 0

/* Exercise 7-6. Write a program to compare two files, printing the first line
 * where they differ. */

int main(int argc, char *argv[])
{
    FILE *fpa, *fpb;
    char a[MAXSIZE] = "";
    char b[MAXSIZE] = "";
    char *pa, *pb;
    int i, differ;

    i = 0;
    differ = INDENTICAL;

    /* file 1 open */
    if ((fpa = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "%s: can't open file.\n", argv[1]);
        exit(1);
    }

    /* file 2 open */
    if ((fpb = fopen(argv[2], "r")) == NULL) {
        fprintf(stderr, "%s: can't open file.\n", argv[2]);
        exit(2);
    }


    /* read lines and print differ lines */
    while ((pa = fgets(a, MAXSIZE, fpa)) != NULL && (pb = fgets(b, MAXSIZE, fpb)) != NULL) {
        i++;  /* line number */ 
        if (strcmp(a, b)) {
            printf("Different Lines:\n");
            printf("%-10s line %d: ", argv[1], i);
            printf("%s", a);
            printf("%-10s line %d: ", argv[2], i);
            printf("%s", b);
            differ = DEFFER;

            break;
        }
    }

    /* print title */ 
    printf("\nDiffer Result:\n");

    /* print result */
    if (differ == INDENTICAL)
        printf("'%s' and '%s' are indentical\n", argv[1], argv[2]);
    else if (differ == DEFFER)
        printf("'%s' and '%s' are non-indentical\n", argv[1], argv[2]);
    printf("Differ completely\n");

    /* file 1 & 2 close */
    fclose(fpa);
    fclose(fpb);

    exit(0);
}



