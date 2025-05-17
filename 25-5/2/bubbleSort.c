/*
    回调函数bubbleSort
*/

#include <stdio.h>
#include <stdbool.h>

// typedef给函数指针命名
typedef bool (*callBackFunction)(int, int);

void bubbleSort(int *ptr, int size, callBackFunction fp);
bool lowToMax(int x, int y);
bool maxToLow(int x, int y);

int main()
{
    int arr[10] = {1545, 454, 153, 486, 1231, 45, 13, 484, 13, 46};
    bubbleSort(arr, 10, maxToLow);
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    return 0;
}

void bubbleSort(int *ptr, int size, callBackFunction fp)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (fp(ptr[j], ptr[j + 1]))
            {
                int temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;
            }
        }
    }
}

bool lowToMax(int x, int y)
{
    return x > y ? true : false;
}

bool maxToLow(int x, int y)
{
    return x > y ? false : true;
}
