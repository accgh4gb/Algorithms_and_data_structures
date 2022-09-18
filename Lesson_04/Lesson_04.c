#include <stdio.h>

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

int main()
{
    int num = 5;
    int exp = 11;
    printf("The value of the number %d to the power of %d is %d\n", num, exp, exponentiation(num,exp));
    return 0;
}
