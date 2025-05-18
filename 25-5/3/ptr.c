/*
    selectionSort && bubbleSort by pointer
*/

#include <stdio.h>
#include <assert.h>

void bubbleSort(int *, int);
void selectionSort(int *, int);

int main()
{
    int arr[] = {24, 434, 24, 7563, 35436, 7, 56767, 4234, 65756};
    int len = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, len);
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    return 0;
}

void bubbleSort(int *arr, int len)
{
    // 检查是否传入空指针
    assert(arr != NULL);
    for (int *i = arr; i < arr + len - 1; i++)
    {
        int isSwap = 0;
        for (int *j = arr + 1; j < arr + len - (i - arr); j++)
        {
            if (*j > *(j - 1))
            {
                int temp = *(j - 1);
                *(j - 1) = *j, *j = temp;
                isSwap = 1;
            }
        }
        if (!isSwap)
            break;
    }
}

void selectionSort(int *arr, int len)
{
    // 检查是否传入空指针
    assert(arr != NULL);
    for (int *i = arr; i < arr + len - 1; i++)
    {
        int *maxPtr = i;
        for (int *j = i + 1; j < arr + len; j++)
        {
            if (*maxPtr < *j)
                maxPtr = j;
        }
        if (maxPtr != i)
        {
            int temp = *maxPtr;
            *maxPtr = *i;
            *i = temp;
        }
    }
}