#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Выделение памяти под двумерный массив
int** allocationMemoryArray(int** array, int sizeX, int sizeY)
{
    array = (int**)calloc(sizeof(int*), sizeX);
    for(int i = 0; i < sizeX; i++)
    {
        *(array + i) = (int*)calloc(sizeof(int), sizeY);
    }
    return array;
}

//Инициализация двумерного массива
void initiozalitionArray(int** array, int sizeX, int sizeY)
{
    for(int i = 0; i < sizeX; i++)
    {
        for(int j = 0; j < sizeY; j++)
        {
            *((*(array + i)) + j) = rand()%10;
        }
    }
}

//Инициализация статического двумерного массива
void initiozalitionArrayStatic(int** array, int sizeX, int sizeY)
{
    int counter = sizeX * sizeY;//счетчик для заполнения массива
    for(int i = 0; i < sizeX; i++)
    {
        for(int j = 0; j < sizeY; j++)
        {
            *((*(array + i)) + j) = counter--;
        }
    }
}

//Вывод двумерного массива
void printArray(int** array, int sizeX, int sizeY)
{
    for(int i = 0; i < sizeX; i++)
    {
        for(int j = 0; j < sizeY; j++)
        {
            printf("[%2d]", *((*(array + i)) + j));
        }
        printf("\n");
    }
}

//Замена значений в массиве
void swapValue(int *arrA, int *arrB)
{
    int temp = *arrA;
    *arrA = *arrB;
    *arrB = temp;
}

//Сортировка массива: Пузырьковая
void sortBubbles(int** array, int sizeX, int sizeY)
{
    int counter = 0;
    for(int k = 0; k < (sizeX*(sizeY-1)); k++)
    {
        for(int i = 0; i < sizeX; i++)
        {
            for(int j = 0; j < sizeY-1; j++)
            {
                if((j <= sizeY - 1) && (array[i][j] > array[i][j + 1]))
                {
                    printf("#EQUALITY! -%d- array[%d][%d] < array[%d][%d]", counter, i, j, i, j+1);
                    swapValue(&array[i][j], &array[i][j+1]);
                    printf("\n");
                }
                if((i != 0) && (j == 0) && (array[i][j] < array[i-1][sizeY-1]))
                {
                    printf("#STROKA!   -%d- array[%d][%d] < array[%d][%d]", counter, i, j, i-1, sizeY-1);
                    swapValue(&array[i][j], &array[i-1][sizeY-1]);
                    printf("\n");
                }
                counter++;
            }
            printArray(array, sizeX, sizeY);
            printf("\n");
        }
        printf("Колличество проходов основного цикла: %d\n", counter);
        printf("\n");
    }
    printf("Колличество проходов основного цикла: %d\n", sizeX*(sizeY-1));
    printf("\n");
}

//Заполнение массива через консоль
void manualInputArray(int *arr, int sizeX)
{
    for(int i = 0; i < sizeX; i++)
    {
        printf("Введите число [%2d из %2d]: ", i, sizeX);
        scanf("%d", &arr[i]);
        printf("\n");
    }
    printf("\n");
}

//инвертация одномерного массива
void inverting(int *arr3, int sizeX)
{
    int elLeft = 0;
    int elRight = sizeX-1;
    while(elLeft != (sizeX / 2))
    {
        swapValue(&arr3[elLeft], &arr3[elRight]);
        elLeft++;
        elRight--;
    }
}

//вычисления в одномерном массиве по алгоритму ТПК
void calculationTPK(int *arr3, int sizeX)
{
    int result = 0;
    for(int i = 0; i < sizeX; i++)
    {
        result = sqrt(fabs(arr3[i])) + 5 * pow(arr3[i], 3);
        if(result > 400)
        {
            printf("Результат расчетов числа [%2d] превышает 400 и равен: %2d\n", arr3[i], result);
        }
        else
        {
            printf("Результат расчетов числа [%2d] равен: %2d\n", arr3[i], result);
        }
    }
}

int main()
{
    // 1. Реализовать пузырьковую сортировку двумерного массива например, массив 1,9,2 5,7,6 4,3,8 должен на выходе стать 1,2,3 4,5,6 7,8,9
    printf("1. Задание - сортировака пузырьковым методом\n\n");
    int sizeX = 3;
    int sizeY = 3;

    int** array = allocationMemoryArray(array, sizeX, sizeY);
    initiozalitionArray(array, sizeX, sizeY);//рандомное заполнение
    initiozalitionArrayStatic(array, sizeX, sizeY);//заполнение по убыванию
    printArray(array, sizeX, sizeY);
    printf("\n");
    sortBubbles(array, sizeX, sizeY);
    printArray(array, sizeX, sizeY);
    printf("\n");

// 3. Реализовать алгоритм Трабба-Прадо-Кнута в коде на языке С
    printf("3. Задание - алгоритм Трабба-Прадо-Кнута\n\n");
    int sizeX3 = 11;
    int arr3[sizeX3];
    manualInputArray(arr3, sizeX3);
    inverting(arr3, sizeX3);
    calculationTPK(arr3, sizeX3);

    return 0;
}

