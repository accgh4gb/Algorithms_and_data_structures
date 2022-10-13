#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000
#define COUNT 5
#define true 1 == 1
#define false 1 != 1

int HashFunc(char *ch)
{
    char *p = ch;
    int sum = 0;
    while( *p != '\0' )
    {  
        sum += (int)*p;
        p++;        
    }        
    return sum;    
}

int SummOfCoins(int sum, int *coins)
{
    int result = 0;
    for (int i = 0; i < COUNT; ++i)
    {
        while (sum >= coins[i])
        {
            printf("%d ", coins[i]);
            sum -=coins[i];
            result++;            
        }
    }
    return result;
}


int main()
{
    char str[] = "This is the simple cifer";
    int coins[COUNT] = {50, 10, 5, 2, 1};
    const int sum = 98;

    printf("%d\n",HashFunc(str)); 
    
    printf(" Count of coins %d\n", SummOfCoins(sum, coins));
    
    return 0;
}

