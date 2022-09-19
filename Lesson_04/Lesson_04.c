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

    return 0;
}
