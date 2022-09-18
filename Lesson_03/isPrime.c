#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n)
{
    if (n > 0 && n <= 3)
    {
        return true;
    }
    else
    {
        if (n % 2 == 0)
        {
            return false;
        }
        else
        {
            int d = 3;
            while (d * d <= n)
            {
                if (n % d)
                {
                    d += 2;
                }
                else
                {
                    return false;
                }
            }
            return true;
        }
    }
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    bool result = isPrime(n);
    printf(result ? "true\n" : "false\n");
    return 0;
}
