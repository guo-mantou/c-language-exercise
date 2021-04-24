#include <stdio.h>
#include <stdlib.h>

#define MAX         100
#define MAXLENGTH   50
#define HORIZENTAL  0
#define VERTICAL    1

/* Write a program to print a histogram of the lengths of words in its 
 * input. Vertical version */
/* TODO: 
 * 1 程序有些臃肿, 需要精简   <-- OK
 * 2 当单词长度较大时，无法整齐的打印出来  <-- read printf in <the C programming language>
 * 3 用一个具有多行数据的文件，用重定向输入程序，会出现core dump的问题 */

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
            p = (char *)malloc(MAXLENGTH);
            *(p + words_length) = c;
            words_length++;
            while (((c = getchar()) >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                *(p + words_length) = c;
                words_length++;
            }
        }
        *(wordsptr + words_count) = p;
        length[words_count] = words_length;

        if (words_count++ >= maxwords)
            return -1;
    }

    return words_count;
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
    /* print matrix */
    printf("\nsource matrix:\n");

    /* print symbol */
    printHorizontalSymbol(horizontal_matrix, wordsptr, words_count, max_words_length);

    /* vertical histogram */
    /* print matrix */
    printf("\nDestination matrix:\n");

    /* print symbol */
    printVerticalSymbol(vertical_matrix, wordsptr, max_words_length, words_count);
}

/* printHorizontalSymbol: print horizontal symbol */
void printHorizontalSymbol(char (*matrix)[MAX], char *wordsptr[], int row, int col)
{
    int i, j;

    for (i = 0; i < row; i++) {
        printf("%s\t\t", *(wordsptr + i));
        for (j = 0; j < col; j++)
            printf("%c  ", matrix[i][j]);
        printf("\n");
    }
}

/* printVerticalSymbol: print vertical symbol */
void printVerticalSymbol(char (*matrix)[MAX], char *wordsptr[], int row, int col)
{
    int i, j;

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++)
            if (matrix[i][j] == ' ')
                printf("\t\t");
            else
                printf("%c\t\t", matrix[i][j]);
        printf("\n");
    }

    for (i = 0; i < col; i++)
        printf("%s\t\t", *(wordsptr + i));

    putchar('\n');
}
