#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define MAXLENGTH 50

/* Write a program to print a histogram of the lengths of words in its 
 * input. Vertical version */
/* TODO:
 * 1 input_word_list 每个元素只有一个字母, 而非期待的一个单词;  <--OK
 * 2 转置矩阵函数完成
 * */
int getMaxElem(int a[], int length);
//void transposeMatrix(int **at, int **a, int row, int colum);
void transposeMatrix(int *at[MAX], int *a[MAX], int row, int colum);
int main()
{
    int length[MAX] = {0};    // words' length
    int c, i, j;
    int words_length, words_count, max_words_length;
    int print_matrix[MAX][MAX] = {0};
    int print_matrix_transpose[MAX][MAX] = {0};
    char symbol = '|';
    char *input_word;    
    char *input_word_list[MAX];

    words_count = 0;

    /* store input words and get words count and get every word's length */
    while ((c = getchar()) != EOF) {
        words_length = 0;
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            input_word = (char *)malloc(MAXLENGTH);
            *(input_word + words_length) = c;
            words_length++;
            while (((c = getchar()) >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                *(input_word + words_length) = c;
                words_length++;
            }
        }
        //*(input_word + words_length) = '\0';
        *(input_word_list + words_count) = input_word;
        length[words_count++] = words_length;
    }

    /* TODO: print histogram */
    //words_count--;
    max_words_length = getMaxElem(length, words_count);
    for (i = 0; i < words_count; i++)
        for (j = 0; j < max_words_length; j++)
            if (j < length[i])
                print_matrix[i][j] = 1;
            else 
                print_matrix[i][j] = 0;

    printf("source matrix:\n");
    for (i = 0; i < words_count; i++) {
        //printf("%s\t\t", *(input_word_list + i));
        for (j = 0; j < max_words_length; j++)
            //if (print_matrix[i][j] == 1)
                //printf("%c  ", symbol);
            printf("%d  ", print_matrix[i][j]);
        printf("\n");
    }

    printf("Transposing ... ...");
    transposeMatrix(print_matrix_transpose, print_matrix, words_count, max_words_length);

    printf("Destination matrix:\n");
    for (i = 0; i < max_words_length; i++) {
        //printf("%s\t\t", *(input_word_list + i));
        for (j = 0; j < words_count; j++)
            //if (print_matrix[i][j] == 1)
                //printf("%c  ", symbol);
            printf("%d  ", print_matrix_transpose[i][j]);
        printf("\n");
    }


    /* free */
    for (i = 0; i <= words_count; i++)
        free(*(input_word_list + i));

    putchar('\n');
    return 0;
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

/* TODO: transposeMatrix: Transpose of a matrix */
//void transposeMatrix(int **at, int **a, int row, int colum)
void transposeMatrix(int *at[MAX], int *a[MAX], int row, int colum)
{
    int i, j;

    for (i = 0; i < row; i++)
        for (j = 0; j < colum; j++)
            at[j][i] = a[i][j];
}
