#include <stdio.h>
#include <stdlib.h>

#define MAX         100

/* Write a program to print a histogram of the lengths of words in its 
 * input, horizontally and vertically */

int readwords(char *wordsptr[], int *length, int maxwords);
int getMaxElem(int a[], int length);
void matrixMagic(char (*at)[MAX], char (*a)[MAX], int row, int col);
void printHorizontalSymbol(char (*matrix)[MAX], char *wordsptr[], int row, int col);
void printVerticalSymbol(char (*matrix)[MAX], char *wordsptr[], int row, int col);
void printHistogram(char *wordsptr[], int *length, int words_count);

int main()
{
    int i;
    int words_count, max_words_length;
    int length[MAX] = {0};    // words' length
    char *input_word_list[MAX];

    words_count = 0;

    if ((words_count = readwords(input_word_list, length, MAX)) == -1) {
        printf("Beyond max count of words!!\n");
        return -1;
    }

    printHistogram(input_word_list, length, words_count);

    /* free */
    for (i = 0; i < words_count; i++)
        free(*(input_word_list + i));

    return 0;
}

/* readwords: store input words and get words count and get every word's length */
int readwords(char *wordsptr[], int *length, int maxwords)
{
    int c, words_length;
    int words_count;
    char *p;

    words_count = 0;

    while ((c = getchar()) != EOF) {
        words_length = 0;
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            p = (char *)malloc(MAX);
            *(p + words_length) = c;
            words_length++;
            while (((c = getchar()) >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                *(p + words_length) = c;
                words_length++;
            }
        }
        else
            continue;

        *(wordsptr + words_count) = p;
        length[words_count] = words_length;

        if (words_count++ >= maxwords)
            return -1;
    }

    return words_count;
}

/* printHistogram: print horizontal and vertical histogram */
void printHistogram(char *wordsptr[], int *length, int words_count)
{
    int i, j, max_words_length;
    char horizontal_matrix[MAX][MAX] = {0};
    char vertical_matrix[MAX][MAX] = {0};
    char symbol;

    symbol = '|';

    max_words_length = getMaxElem(length, words_count);

    for (i = 0; i < words_count; i++)
        for (j = 0; j < max_words_length; j++)
            if (j < length[i])
                horizontal_matrix[i][j] = '|';
            else 
                horizontal_matrix[i][j] = ' ';

    matrixMagic(vertical_matrix, horizontal_matrix, words_count, max_words_length);

    /* horizontal histogram */
    printf("\nsource matrix:\n");
    printHorizontalSymbol(horizontal_matrix, wordsptr, words_count, max_words_length);

    /* vertical histogram */
    printf("\nDestination matrix:\n");
    printVerticalSymbol(vertical_matrix, wordsptr, max_words_length, words_count);
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
void printHorizontalSymbol(char (*matrix)[MAX], char *wordsptr[], int row, int col)
{
    int i, j;

    for (i = 0; i < row; i++) {
        printf("%12s:  ", *(wordsptr + i));
        for (j = 0; j < col; j++)
            printf("%-2c", matrix[i][j]);
        printf("\n");
    }
}

/* printVerticalSymbol: print vertical symbol */
void printVerticalSymbol(char (*matrix)[MAX], char *wordsptr[], int row, int col)
{
    int i, j;

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++)
            printf("%-12c", matrix[i][j]);
        printf("\n");
    }

    for (i = 0; i < col; i++)
        printf("%-12s", *(wordsptr + i));

    putchar('\n');
}
