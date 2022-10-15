#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1 == 1
#define false 1 != 1

typedef int boolean;

char *caesar(char *in, int key, boolean encrypt) /* Реализация функции шифрования-дешифрования Цезаря*/
{
    char *str = (char*)calloc(strlen(in), sizeof(char)); // Выделяем массив под строку, чтоб не портить входные данные
    if(!str)
    {
        printf("Out of memory");
        return str;
    }
    if(encrypt)              //Шифрование
    {
        int i = 0;
        while (in[i] != '\0')
        {
            str[i] = in[i] + key;
            i++;
        }
    }
    else                    //Дешифровка обратная шифрованию
    {
        int i = 0;
        while (in[i] != '\0')
        {
            str[i] = in[i] - key;
            i++;
        }
    }
                        
    return str;
}


char *encryption(char *in, int key) /* Функция шифрования перестановками*/
{
    int length = strlen(in);
    char *out_str = (char *)calloc(length + 1, sizeof(char));
    if (!out_str)
    {
        printf("Out of memory");
        return out_str;
    }
    int i = 0;
    int j = 0;
    for (i = 0; i < length - 1; i++)
    {
        out_str[i] = in[j];
        j = (j + key) % (length - 1);
    }
    out_str[i] = in[i];
    out_str[length] = '\0';
    return out_str;
}

char *decryption(char *in, int key) /* Функция дешифрования перестановками*/
{
    int length = strlen(in);
    char *out_str = (char *)calloc(length + 1, sizeof(char));
    if (!out_str)
    {
        printf("Out of memory");
        return out_str;
    }
    int i = 0;
    int j = 0;
    for (i = 0; i < length - 1; i++)
    {
        out_str[i] = in[j];
        j = (j + length / key) % (length - 1);
    }
    out_str[i] = in[i];
    out_str[length] = '\0';
    return out_str;
}

char *addition(char *in, int mult, char filler) /* Функция дополнения до "прямоугольного массива" */
{
    char *str;
    int length = strlen(in);
    int differ = length % mult;
    length = ((length / mult + 1) * mult) + 1;
    str = (char *)calloc(length, sizeof(char));
    if (!str)
    {
        printf("Out of memory");
        return str;
    }
    else
    {
        int i = 0;
        while (in[i] != '\0')
        {
            str[i] = in[i];
            i++;
        }
        for (i; i < length - 1; i++)
        {
            str[i] = filler;
        }
        str[i + 1] = '\0';
    }
    return str;
}

char *shuffle(char *in, int key, boolean encrypt) /* Функция шифрования-дешифрования перестановками произвольной строки*/
{
    int length = strlen(in);
    if (!length || (key <= 0))
    {
        return in;
    }
    char *str = in;
    if (encrypt)
    {
        int differ = length % key;
        if (differ)
        {
            str = addition(in, key, 'X'); // X произвольный заполнитель
            length = strlen(str);
        }
        return encryption(str, key);
    }
    else
    {
        return decryption(str, key);
    }
}

int main()
{
    const int key = 5;
    char arr[] = {"thetestsentenseforexample"};
    char *str;

    str = caesar(arr, key, true);
    printf("encripted: %s\n", str);    
    printf("decripted: %s\n", caesar(str, key, false));
    free(str);

    str = shuffle(arr, key, true);
    printf("encripted: %s\n", str);
    printf("decripted: %s\n", shuffle(str, key, false));
    free(str);
    return 0;
}
