#include <stdio.h>     /* for printf */
#include <stdlib.h>    /* for exit */
#define  MAXSIZE  100

/* Exercise 7-8. Write a program to print a set of files, starting
 * each new one on a new page, with a new page, with a title and 
 * a running page count for each file */

void filecopy(FILE *ifp, FILE *ofp);
void decoration_filecopy(FILE *ifp, FILE *ofp, char *ifname, int plines);

int main(int argc, char *argv[])
{
    /* 1 print file
     * 2 add Decoration: title && pages 
     * 1 page = 5 lines */
    FILE *fp;
    char *prog;
    int plines;

    prog = argv[0];   /* get program name */
    plines = 10;      /* one page 10 lines */

    /* Usage: ./a.out file1 file2 ... */
    if (argc == 1)
        filecopy(stdin, stdout);
    else
        while (--argc > 0)
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "%s: can't open %s", prog, *argv);
                exit(EXIT_FAILURE);
            }
            else {
                decoration_filecopy(fp, stdout, *argv, plines);
                pclose(fp);
            }

    exit(EXIT_SUCCESS);
}

/* filecopy:  copy file ifp to file ofp */
void filecopy(FILE *ifp, FILE *ofp)
{
    int c;

    while ((c = getc(ifp)) != EOF)
        putc(c, ofp);
}

/* decoration_filecopy: print 'ifname' lines from file ifp in decoration like:
 *
 * ifname                                     pages
 * file content ...
 *
 * para:
 * ifname: input file's name
 * plines: number of lines of one page */
void decoration_filecopy(FILE *ifp, FILE *ofp, char *ifname, int plines)
{
    int i, pages, tmp;
    char buf[MAXSIZE] = "";

    pages = 1;

    while (1) {
        tmp = plines;
        printf("%-80s", ifname);    /* header: file name */
        printf("Pages  %d\n\n", pages++);  /* header: pages */

        /* print 'plines' lines of input file ifp */
        while (tmp-- > 0) {
            if (fgets(buf, MAXSIZE, ifp) == NULL) {   /* EOF */
                printf("-----%s end----- \n\n", ifname);     /* footer */
                return;
            }
            else 
                fputs(buf, ofp);
        }
        printf("\n");
    }
}
