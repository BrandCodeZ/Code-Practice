#include <stdio.h>


long long power(int a, int n)
{
   
    if (n == 0)
        return 1;

    // Divide: calculate a^(n/2)
    long long half = power(a, n / 2);

    // Conquer and combine
    if (n % 2 == 0)
        return half * half;
    else
        return a * half * half;
}

int main()
{
    int a, n;

    printf("Enter the base: ");
    scanf("%d", &a);

    printf("Enter the power: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Please enter a non-negative power.\n");
    }
    else
    {
        printf("%d^%d = %lld\n", a, n, power(a, n));
    }

    return 0;
}