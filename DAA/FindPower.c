#include <stdio.h>

int exponent(int a, int n)
{
    int x;

    if (n == 0)
        return 1;

    x = exponent(a, n / 2);

    if (n % 2 == 0)
        return x * x;
    else
        return a * x * x;
}

int main()
{
    int a, n;

    printf("Enter the base: ");
    scanf("%d", &a);

    printf("Enter the exponent: ");
    scanf("%d", &n);

    printf("Result = %d", exponent(a, n));

    return 0;
}