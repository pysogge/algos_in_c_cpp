#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 100 /* maximum array size */

void print_ptr_array(int *arr, int n)
{

    printf("array [%d]: ", n);

    int i;
    int *arrp = arr;

    printf("[");
    for (i = 0; i < n; i++){
        printf("%d,", *arrp);
        arrp++;
    }
    printf("\b]\n");
}

/* return an int from a substr starting at i = 0, to n */
int substr_to_int(char *str, int n)
{

    char *strp = str;
    int ret = 0;
    int i = 0;
    int sign = 1;

    // printf("looking for a (%d) length int in :%s\n",n, strp);

    if (*strp == '-')
    {
        sign = -1;
        strp++;
        i++;
    }
    while(i < n && *strp != '\0')
    {
        ret = (ret * 10) + (*strp - '0');
        strp++, i++;
    }

    return ret * sign;
}

/* return a count of the space separated elements in a str*/
int elems_count(char *cstr){
    char *strp = cstr;
    char *debug;
    int num_elems = 0;

    /* remove leading whitespace */
    while (*strp == ' ' && *strp != '\0')
        strp++;

    /* find all of the substrs in between ' ' */
    while (*strp != '\0')
    {
        /* collect indicies for substrs */
        while (*strp != ' ' && *strp != '\0')
            strp++;

        /* increment element count */
        num_elems++;

        /* remove whitespace */
        while (*strp == ' ' && *strp != '\0')
            strp++;
    }

    return num_elems;
}

int * get_arr_from_cbuffer(char *cstr)
{  
    int numints = 0;
    int i = 0, n = 0, m = 0;
    int tmp;
    /* start and end pointers */
    char *strp = cstr;
    char *subp = cstr;
    int *tmpint;
    tmpint = (int *)malloc(sizeof(int) * elems_count(strp));
    int *ret;
    ret = (int *)malloc(sizeof(int) * elems_count(strp));
    ret = tmpint;

    /* remove leading whitespace */
    while (*strp == ' ' && *strp != '\0')
        i++, strp++, subp++;

    /* find all of the substrs in between ' ' */
    while (*strp != '\0')
    {
        /* collect indicies for substrs */
        while (*strp != ' ' && *strp != '\n'&& *strp != '\0')
            i++, strp++;

        /* add element to int array */
        tmp = substr_to_int(subp, i-m);
        *tmpint = tmp;
        tmpint++;
        subp = strp;
        numints++;
        m = i;
        n++;

        /* remove whitespace */
        while ((*strp == ' ' || *strp == '\n') && *strp != '\0' )
            strp++, subp++, n++, i++, m++;
    }

    return ret;
}

char *getbufline(size_t cbuffsize)
{
    char *cbuffret = (char *)malloc(cbuffsize * sizeof(char));
    getline(&cbuffret, &cbuffsize, stdin);
    return cbuffret;
}

void unit_tests(){

    char *ctestA = "-123";
    char *ctestB = "234";
    int ntestA = substr_to_int(ctestA, 4);
    int ntestB = substr_to_int(ctestB, 3);

    char *stestA = "-123 32 -23 3 12";
    char *stestB = "  234 12 3 1 -10000  ";
    char *stestC = "0";
    char *stestD = "";

    int numelemsA = elems_count(stestA);
    int numelemsB = elems_count(stestB);
    int numelemsC = elems_count(stestC);
    int numelemsD = elems_count(stestD);
    printf("test ints: %d, %d\n", ntestA, ntestB);
    printf("num ints (5,5,1,0): (%d,%d,%d,%d)\n", numelemsA, numelemsB, numelemsC, numelemsD);
}

int main()
{

    size_t cbuffsize = (size_t)MAXLEN;
    char *cbuffer = getbufline(cbuffsize);
    size_t arrlen = elems_count(cbuffer);
    int * arr;
    arr = (int *)malloc(arrlen * sizeof(int));
    arr = get_arr_from_cbuffer(cbuffer);

    // debug output:
    printf("line: %s\n", cbuffer);
    printf("array size: %d\n", elems_count(cbuffer));
    print_ptr_array(arr, arrlen);
    
    // unit tests:
    // unit_tests();

}