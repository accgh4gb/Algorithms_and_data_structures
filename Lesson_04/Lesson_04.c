#include <stdio.h>

void DecToBin(int num)
{
    if (num >= 2)
    {
        DecToBin(num / 2);
    }
    printf("%d", num % 2);
}

int exponentiation(int num, int exp)
{
    int result = 0;
    if((num == 0) || (num == 0 && exp == 0))
    {
        return 0;
    }
    else if(exp == 0)
    {
        return 1;
    }
    else
    {
        result = num * exponentiation(num, exp - 1);
    }
    return result;
            
}

int exponentiation2(int num, int exp)
{
    int result = 0;
    if((num == 0) || (num == 0 && exp == 0))
    {
        return 0;
    }
    if(exp == 0)
    {
        return 1;
    }
    if(exp == 1)
    {
        return num;
    }
    if(exp % 2 == 0)
    {
        result = exponentiation2(num*num, exp/2);
    }
    else
    {
        result = num * exponentiation2(num*num, (exp-1)/2);
    }
    return result;
}

int KingsMove(int x, int y, int move_X, int move_Y)
{
    if((x == 0) && (y == 0))
    {
        return 0;
    }
    else if((x == move_X) && (y == move_Y))
    {
        return 0;
    }
    else if((x == 0) || (y == 0))
    {
        return 1;
    }
    else if((x == move_X - 1) || (y == move_Y - 1))
    {
        return 1;
    }
    else
    {
        return KingsMove(x, y - 1, move_X, move_Y) + KingsMove(x - 1, y, move_X, move_Y);
    }
}

int main()
{
{
    int num;
    scanf("%d", &num);
    DecToBin(num);
    printf("\n");
}

{
    int num = 5;
    int exp = 11;
    printf("The value of the number %d to the power of %d is %d\n", num, exp, exponentiation(num, exp));
}

{
    int num = 5;
    int exp = 11;
    printf("The value of the number %d to the power of %d is %d\n", num, exp, exponentiation2(num, exp));
}

{
    const int size_X = 4;
    const int size_Y = 4;
            
    int move_X = 1;
    int move_Y = 1;
                    
    for(int y = 0; y < size_Y; y++)
    {
        for(int x = 0; x < size_X; x++)
        {
            printf("%4d", KingsMove(x, y, move_X, move_Y));
        }
        printf("\n");
    }
}

    return 0;
}
