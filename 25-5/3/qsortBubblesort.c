/*
    冒泡排序排序实现类似qsort函数,排序任意数据类型的接口函数
*/
#include <stdio.h>

void qsortBubblesort(void *, int, int, int (*)(const void *, const void *));
int compare(const void *, const void *);

int main()
{
    int arr[10] = {48, 45465, 4848, 33, 78676, 1376, 4363, 4846, 133, 86};
    qsortBubblesort(arr, 10, sizeof(int), compare);
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    return 0;
}

// 接口函数
void qsortBubblesort(void *base, int len, int size, int (*compare)(const void *, const void *))
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            //把任意类型的数据类型强转为char*类型指针,逐个字节偏移和交换等操作,因为知道每个元素的大小
            if (compare((void *)((char *)base + j * size), (void *)((char *)base + (j + 1) * size)) > 0)
            {
                char arr[size];
                for (int k = 0; k < size; k++)
                {
                    arr[k] = ((char *)base + j * size)[k];
                    ((char *)base + j * size)[k] = ((char *)base + (j + 1) * size)[k];
                }
                for (int k = 0; k < size; k++)
                    ((char *)base + (j + 1) * size)[k] = arr[k];
            }
        }
    }
}

int compare(const void *x, const void *y)
{
    return *(int *)x - *(int *)y;
}