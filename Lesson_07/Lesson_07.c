#include <stdio.h>
#include <stdlib.h>

//Инициализация одномерного массива
void initiozalitionArrayRandom(int* array, int sizeX)
{
    for(int i = 0; i < sizeX; i++)
    {
        *(array + i) = rand() % 10;
    }
}

//Вывод одномерного массива
void printArray(int* array, int sizeX)
{
    for(int i = 0; i < sizeX; i++)
    {
        printf("%2d ", *(array + i));
    }
    printf("\n");
}

//Замена значений в массиве
void swapValue(int *arrA, int *arrB)
{
    int temp = *arrA;
    *arrA = *arrB;
    *arrB = temp;
}

//Улучшенная сортировка вставками
void sortShells(int *arr,int sizeX)
{
    int i, j, step, temp;

    for(step = sizeX / 2; step > 0; step /= 2)
    {
        for(i = step; i < sizeX; ++i)
        {
            temp = arr[i];
            for(j = i; j >= step; j -=step)
            {
                if(temp < arr[j - step])
                {
                    arr[j] = arr[j - step];
                }
                else
                {
                    break;
                }
            }
            arr[j] = temp;
        }
    }
}

//Сортировка Хоара
void sortHoara(int *arr, int first, int last)
{
    int i = first;
    int j = last;
    int opora = arr[(first+last)/2];

    do {
            while (arr[i] < opora) i++;
            while (arr[j] > opora) j--;

            if(i <= j)
            {
                swapValue(&arr[i], &arr[j]);
                i++;
                j--;
            }
        }
        while (i<=j);

        if(i < last) sortHoara(arr, i, last);
        if(first < j) sortHoara(arr, first, j);
}

//Улучшенная сортировка
void sortImproved(int *arr, int first, int last)
{
    if((last - first) < 10)
    {
        sortShells(arr, last+1);
        printf("\nsortShells:\n");
    }
    else
    {
        int avgValArr = (first + last) / 2;
        if((avgValArr > first) && (avgValArr > last))
        {
            if(first > last)
            {
                swapValue(&arr[avgValArr], &arr[first]);
            }
            else
            {
                swapValue(&arr[avgValArr], &arr[last]);
            }
        }
        if((avgValArr < first) && (avgValArr < last))
        {
            if(first > last)
            {
                swapValue(&arr[avgValArr], &arr[last]);
            }
            else
            {
                swapValue(&arr[avgValArr], &arr[first]);
            }
        }
        sortHoara(arr, first, last);
        printf("\nsortHoara:\n");
    }
}

//Блочная сортировка
void sortBlock(int *arr, int sizeX)
{
    const int max = sizeX;
    const int buck = 10;

    int buckets[buck][max+1];
    for(int i = 0; i < buck; i++)
    {
        buckets[i][max] = 0;
    }

    for(int digit = 1; digit < 1000000000; digit *= 10)
    {
        for(int i = 0; i < max; i++)
        {
            if(arr[i] % 2 == 0)
            {
                int d = (arr[i]/digit) % buck;
                int counter = buckets[d][max];
                buckets[d][counter] = arr[i];
                counter++;
                buckets[d][max] = counter;
                arr[i] = -1;
            }
        }
        int idx = 0;
        for(int i = 0; i < buck; i++)
        {
            for(int j = 0; j < buckets[i][max]; j++)
            {
                while(arr[idx] != -1)
                {
                    idx++;
                }
                arr[idx++] = buckets[i][j];
            }
            buckets[i][max] = 0;
        }
    }
}

int main()
{
    //1. Описать в коде улучшенный алгоритм быстрой сортировки
    printf("1. Задание\n");
    int sizeX = 8;
    int array1[sizeX];

    initiozalitionArrayRandom(array1, sizeX);
    printArray(array1, sizeX);
    sortImproved(array1, 0, sizeX-1);
    printArray(array1, sizeX);

    //2. Сортировать в массиве целых положительных чисел только чётные числа, нечётные оставив на своих местах при помощи алгоритма блочной сортировки, то есть массив вида [0 2 8 3 4 6 5 9 8 2 7 3] превратить в [0 2 2 3 4 4 5 9 8 8 7 3]
    printf("\n2. Задание\n");
    int sizeY = 10;
    int array2[sizeY];
    initiozalitionArrayRandom(array2, sizeY);
    printArray(array2, sizeY);
    sortBlock(array2, sizeY);
    printArray(array2, sizeY);

    return 0;
}
