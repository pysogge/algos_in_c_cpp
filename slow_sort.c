/* Slow Sort - O(n)^2 - Max Input Length */

/* sh build.sh -c -x slow_sort */

#include <stdio.h>

#define MAXLEN 25 /* maximum line size */

int main()
{
    int arr[MAXLEN];
    int n = 0;
    scanf("%d", &n);
    int m = 0;
    while (m < n)
    {
        scanf("%d", &arr[m]);
        m++;
    }

    int l = 0;
    printf("%s\n", "Orig Array:");
    while (l < n-1)
    {
        printf("%d-", arr[l]);
        l++;
    }
    printf("%d", arr[l]);


    int tmp;
    int tmpindex;
    for(int i = 0; i < n; i++){
        tmpindex = i;
        tmp = arr[i];
        for(int k = i+1; k < n; k++){
            if(arr[k] < tmp){
                tmp = arr[k];
                tmpindex = k;
            }
        }
        if(i != tmpindex){
            tmp = arr[i];
            arr[i] = arr[tmpindex];
            arr[tmpindex] = tmp;
        }
    }

    l = 0;
    printf("\n%s\n", "Sorted Array:");
    while (l < n-1)
    {
        printf("%d-", arr[l]);
        l++;
    }
    printf("%d", arr[l]);

    return 0;
}