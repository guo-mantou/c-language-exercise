#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>      /* for getopt */
#define  MAXSIZE   100
#define  OPTSTRING "nx"  /* for getopt */ 

/* Exercise 7-7. Modify the pattern finding program of Chapter 5 to 
 * take its input from a set of named files or, if no files are named 
 * as arguments, from the standard input. Should the file name be printed
 * when a matching line is found? -Yes 
 *
 * This program is equivalent to 'grep [-n] [-v] pattern [files]' */

int main(int argc, char *argv[])
{
    int c, myargc;
    int number, except;
    char *lineptr;
    size_t lsize;
    int lnum;      /* line's number */
    char pattern[MAXSIZE] = "";
    FILE *fp;

    number = 0;
    except = 0;
    lineptr = NULL;
    lsize = 0;
    lnum = 0;

    /* process options */
    while ((c = getopt(argc, argv, OPTSTRING)) != -1) {
        switch (c) {
            case 'n':
                number = 1;
                break;

            case 'x':
                except = 1;
                break;

            default:  /* '?' */
                fprintf(stderr, "Usage: %s [-n] [-x] pattern [files]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    myargc = argc - optind + 1;
    /* pattern not found */
    if (myargc == 1) {
        fprintf(stderr, "Invalid pattern!\n");
        fprintf(stderr, "Usage: %s [-n] [-x] pattern [files]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strcpy(pattern, argv[optind]);   /* get pattern */

    /* determine stdin or specified file */
    if (myargc == 2) {    /* stdin */
        printf("No specified file, read lines from standard input\n");
        fp = stdin;

        /* process pattern */
        while (getline(&lineptr, &lsize, fp) > 0) {
            lnum++;   /* record lines number */
            if ((strstr(lineptr, pattern) != NULL) != except) {
                if (number == 1)
                    printf("%d:", lnum);
                printf("%s", lineptr);
            }
        }
    }
    else     /* specified file */
        while (myargc-- > 0 && (fp = fopen(argv[++optind], "r")) != NULL) { /* open file */
            lnum = 0;  /* clear line number in next file */

            /* process pattern */
            while (getline(&lineptr, &lsize, fp) > 0) {
                lnum++;   /* record lines number */
                if ((strstr(lineptr, pattern) != NULL) != except) {
                    printf("%s:", argv[optind]);  /* print file name */
                    if (number == 1)
                        printf("line %d: ", lnum);
                    printf("%s", lineptr);
                }
            }
            fclose(fp);   /* close file */
        }

    free(lineptr);   /* free lineptr */

    exit(EXIT_SUCCESS);
}
