#include <stdio.h>

#define MAX   100

/* Write a program to print a histogram of the frequencies of different
 * characters in its input */

int ifRedundant(char *ic, int c);
int readchars(char *ic, int *freq, int max);
void printFreq(char *ic, int *freq, int count);
void matrixMagic(char (*at)[MAX], char (*a)[MAX], int row, int col);
void printHorizontalSymbol(char (*matrix)[MAX], char ic[], int row, int col);
void printVerticalSymbol(char (*matrix)[MAX], char ic[], int row, int col);
int getMaxElem(int a[], int length);

int main()
{
    char ic[MAX] = "";    /* store input characters */
    int freq[MAX];        /* store the frequencies of input characters */
    int maxFreq;          /* store the max of the frequencies */
    int count;            /* store the count of input characters */

    if ((count = readchars(ic, freq, MAX)) == -1) {
        printf("Too many characters!!\n");
        return -1;
    }

    printFreq(ic, freq, count);

    return 0;
}

/* readchars: store input characters and get frequencies of them */
int readchars(char *ic, int *freq, int max)
{
    int c, i, j;    /* j for count of input characters */
    int index;

    i = 0;
    j = 0;

    for (i = 0, j = 0; (c = getchar()) != EOF && j < max; j++) {
        if ((index = ifRedundant(ic, c)) == -1) {
            ic[i] = c;
            freq[i] = 1;
            i++;
        }
        else 
            freq[index]++;
    }

    if (j == max)
        return -1;

    return i;
}

/* printFreq: print the frequencies's horizontal and vertical histogram */
void printFreq(char *ic, int *freq, int count)
{
    int i, j, max_frequency;
    char horizontal_matrix[MAX][MAX] = {0};
    char vertical_matrix[MAX][MAX] = {0};

    max_frequency = getMaxElem(freq, count);

    for (i = 0; i < count; i++)
        for (j = 0; j < max_frequency; j++)
            if (j < freq[i])
                horizontal_matrix[i][j] = '|';
            else 
                horizontal_matrix[i][j] = ' ';

    matrixMagic(vertical_matrix, horizontal_matrix, count, max_frequency);

    /* horizontal histogram */
    printf("\nhorizontal histogram:\n");
    printHorizontalSymbol(horizontal_matrix, ic, count, max_frequency);

    /* vertical histogram */
    printf("\nvertical histogram:\n");
    printVerticalSymbol(vertical_matrix, ic, max_frequency, count);
}

/* getMaxElem: find max element in array a */
int getMaxElem(int a[], int length)
{
    int temp, i;

    temp = a[0];

    for (i = 1; i < length; i++)
        if (temp < a[i])
            temp = a[i];

    return temp;
}

/* matrixMagic: Transpose a matrix, then fold up and down(上下对折) */
void matrixMagic(char (*at)[MAX], char (*a)[MAX], int row, int col)
{
    int i, j;

    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            at[col-j-1][i] = a[i][j];
}

/* printHorizontalSymbol: print horizontal symbol */
void printHorizontalSymbol(char (*matrix)[MAX], char ic[], int row, int col)
{
    int i, j;

    for (i = 0; i < row; i++) {
        if (ic[i] == '\n')
            printf("\\n:  ");
        else if (ic[i] == '\t')
            printf("\\t:  ");
        else
            printf("%2c:  ", ic[i]);

        for (j = 0; j < col; j++)
            printf("%-2c", matrix[i][j]);
        printf("\n");
    }
}

/* printVerticalSymbol: print vertical symbol */
void printVerticalSymbol(char (*matrix)[MAX], char ic[], int row, int col)
{
    int i, j;

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++)
            printf("%-3c", matrix[i][j]);
        printf("\n");
    }

    for (i = 0; i < col; i++) {
        if (ic[i] == '\n')
            printf("\\n ");
        else if (ic[i] == '\t')
            printf("\\t ");
        else
            printf("%-3c", ic[i]);
    }

    putchar('\n');
}

/* ifRedundant: determine if the character c is redundant */
int ifRedundant(char *ic, int c)
{
    int i;

    for (i = 0; ic[i] != '\0' && ic[i] != c; i++)
        ;

    if (ic[i] == c)
        return i;

    return -1;
}
