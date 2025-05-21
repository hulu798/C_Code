/*
    使用回调函数实现选择排序接口函数
*/

#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[20];
    int year;
    int score;
} Stu;

void selectionSort(void *, int, int, int (*)(const void *, const void *));
int cmp_name(const void *, const void *);
int cmp_year(const void *, const void *);
int cmp_score(const void *, const void *);

void print(Stu *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("name:%-20s year:%3d score:%3d\n", (arr + i)->name, (arr + i)->year, (arr + i)->score);
    }
}
int main()
{
    Stu arr[5] = {{"aaafffefa", 32, 67}, {"bbbsfdb", 24, 90}, {"jjaifj", 18, 70}, {"adadfafeweaeawrw", 29, 80}, {"hello", 50, 66}};
    printf("排序前:\n");
    print(arr, 5);

    printf("\n\n");
    printf("按名字排序:\n");
    selectionSort(arr, 5, sizeof(arr[0]), cmp_name);
    print(arr, 5);

    printf("\n\n");
    printf("按年龄排序:\n");
    selectionSort(arr, 5, sizeof(arr[0]), cmp_year);
    print(arr, 5);

    printf("\n\n");
    printf("按成绩排序:\n");
    selectionSort(arr, 5, sizeof(arr[0]), cmp_score);
    print(arr, 5);

    return 0;
}

// 接口函数
void selectionSort(void *base, int len, int size, int (*compare)(const void *, const void *))
{
    for (int i = 0; i < len - 1; i++)
    {
        int maxIdx = i;
        for (int j = i + 1; j < len; j++)
        {
            if (compare((void *)((char *)base + j * size), (void *)((char *)base + maxIdx * size)) < 0)
                maxIdx = j;
        }
        if (maxIdx != i)
        {
            char arr[size];
            for (int k = 0; k < size; k++)
            {
                arr[k] = ((char *)base + maxIdx * size)[k];
                ((char *)base + maxIdx * size)[k] = ((char *)base + i * size)[k];
                ((char *)base + i * size)[k] = arr[k];
            }
        }
    }
}

int cmp_name(const void *x, const void *y)
{
    return strcmp(((Stu *)x)->name, ((Stu *)y)->name);
}

int cmp_year(const void *x, const void *y)
{
    return ((Stu *)x)->year - ((Stu *)y)->year;
}

int cmp_score(const void *x, const void *y)
{
    return ((Stu *)x)->score - ((Stu *)y)->score;
}