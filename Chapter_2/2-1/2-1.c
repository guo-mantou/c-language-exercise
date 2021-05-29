#include <stdio.h>
#include <limits.h>
#include <float.h>

#define HEADER_1    "C data type"
#define HEADER_2    "Minimum"
#define HEADER_3    "Maximum"
#define CHAR        "[signed] char"
#define UCHAR       "unsigned char"
#define SHORT       "short"
#define USHORT      "unsigned short"    
#define INT         "int"
#define UINT        "unsigned int"
#define LONG        "long"
#define ULONG       "unsigned long"    
#define FLOAT       "float"
#define DASHLENGTH  117

#define MYSCHAR_MAX     (char)cal2ex_int(7) - 1
#define MYSCHAR_MIN     (char)-cal2ex_int(7)
#define MYUCHAR_MAX     (unsigned char)cal2ex_int(8) - 1
#define MYSHRT_MAX		(short)cal2ex_int(15) - 1
#define MYSHRT_MIN		(short)-cal2ex_int(15)
#define MYUSHRT_MAX		(unsigned short)cal2ex_int(16) - 1
#define MYINT_MAX		(int)cal2ex_int(31) - 1
#define MYINT_MIN		(int)-cal2ex_int(31)
#define MYUINT_MAX		(unsigned int)cal2ex_int(32)
#define MYLONG_MAX		(long)cal2ex_int(63) - 1
#define MYLONG_MIN		(long)-cal2ex_int(63)
#define MYULONG_MAX		cal2ex_int(64) - 1

#define PRINT_VALUE(var1, conver_char, var2, var3)  printf("%-16s%50"#conver_char"%50"#conver_char"\n", var1, var2, var3)
#define PRINT_CHAR(max, min)           PRINT_VALUE(CHAR, hhd, max, min)
#define PRINT_UNSIGNED_CHAR(max, min)  PRINT_VALUE(UCHAR, hhu, max, min)
#define PRINT_SHORT(max, min)          PRINT_VALUE(SHORT, hd, max, min)
#define PRINT_UNSIGNED_SHORT(max, min) PRINT_VALUE(USHORT, hu, max, min)
#define PRINT_INT(max, min)            PRINT_VALUE(INT, d, max, min)
#define PRINT_UNSIGNED_INT(max, min)   PRINT_VALUE(UINT, u, max, min)
#define PRINT_LONG(max, min)           PRINT_VALUE(LONG, ld, max, min)
#define PRINT_UNSIGNED_LONG(max, min)  PRINT_VALUE(ULONG, lu, max, min)
#define PRINT_FLOAT(max, min)          PRINT_VALUE(FLOAT, f, max, min)
#define PRINT_HEADER(header_1, header_2, header_3) PRINT_VALUE(header_1, s, header_2, header_3)
/* TODO: cal float range */

/* Exercise 2-1. Write a program to determine the ranges of char, short, int,
 * and long variables, both signed and unsigned, by printing appropriate 
 * values from standard headers and by direct computation. Harder if you 
 * compute them: determine the ranges of the various floating-point types. */

void print_range_standard_header();
void print_range_direct_compute();
void print_dashes(int len);
void print_header();
unsigned long cal2ex_int(int ex);

enum choice {STDHEADERS=1, DIRCOMPUT, EXIT=0};

int main()
{
    int i;

    i = -1;
    while (i) {
        printf("Functions:\n");
        printf(" 1 print ranges of data type from standard headers\n");
        printf(" 2 print ranges of data type from directing computation\n");
        printf(" 0 exit\n");
        printf("Input: ");
        scanf("%d", &i);

        switch (i) {
            case STDHEADERS:
                print_range_standard_header();
                break;

            case DIRCOMPUT:
                print_range_direct_compute();
                break;

            default:
                break;
        }
    }

    return 0;
}

void print_range_standard_header()
{
    printf("\n");
    print_dashes(DASHLENGTH);
    PRINT_HEADER(HEADER_1, HEADER_2, HEADER_3);
    print_dashes(DASHLENGTH);

    PRINT_CHAR(SCHAR_MAX, SCHAR_MIN);
    PRINT_UNSIGNED_CHAR(UCHAR_MAX, 0);
    printf("\n");

    PRINT_SHORT(SHRT_MAX, SHRT_MIN);
    PRINT_UNSIGNED_SHORT(USHRT_MAX, 0);
    printf("\n");

    PRINT_INT(INT_MAX, INT_MIN);
    PRINT_UNSIGNED_INT(UINT_MAX, 0);
    printf("\n");

    PRINT_LONG(LONG_MAX, LONG_MIN);
    PRINT_UNSIGNED_LONG(ULONG_MAX, (unsigned long)0);
    printf("\n");

    PRINT_FLOAT(FLT_MAX, FLT_MIN);
    print_dashes(DASHLENGTH);
    printf("\n");
}

void print_range_direct_compute()
{
    printf("\n");
    print_dashes(DASHLENGTH);
    PRINT_HEADER(HEADER_1, HEADER_2, HEADER_3);
    print_dashes(DASHLENGTH);

    PRINT_CHAR(MYSCHAR_MAX, MYSCHAR_MIN);
    PRINT_UNSIGNED_CHAR(MYUCHAR_MAX, 0);
    printf("\n");

    PRINT_SHORT(MYSHRT_MAX, MYSHRT_MIN);
    PRINT_UNSIGNED_SHORT(MYUSHRT_MAX, 0);
    printf("\n");

    PRINT_INT(MYINT_MAX, MYINT_MIN);
    PRINT_UNSIGNED_INT(MYUINT_MAX, 0);
    printf("\n");

    PRINT_LONG(MYLONG_MAX, MYLONG_MIN);
    PRINT_UNSIGNED_LONG(MYULONG_MAX, (unsigned long)0);
    printf("\n");

    print_dashes(DASHLENGTH);
    printf("\n");
}

void print_dashes(int len)
{
    int i;

    for (i = 0; i < len; i++)
        printf("-");
    printf("\n");
}

void print_header()
{
    printf("%-16s%50s%50s\n", HEADER_1, HEADER_2, HEADER_3);
}

/* calculate exponet of 2 */
unsigned long cal2ex_int(int ex)
{
    unsigned long i, num;

    for (i=0, num=1; i < ex; i++)
        num = num * 2;

    return num;
}
