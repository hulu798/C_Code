/*
	qsort函数排序
*/
//正常传参int(*)(const void*,const void*)类型函数指针
#include <stdio.h>
#include <stdlib.h>

int compare(const void *x, const void *y)
{
    return *((int *)x) - *((int *)y);
}
int main()
{
    int arr[10] = {423, 55, 54646, 4243, 54654, 4243, 6546, 8567, 3132, 546};
    qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), compare);
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    return 0; 
}  