#include <stdio.h>
#include <math.h>
void enter(int &n, int a[]);
void printValue(int n, int a[]);
bool isPrimeNumber(int x);
int countPrimeNumber(int n, int a[]);
void printTheAmountOfPrimeNumber(int n, int a[]);
void printPrimeNumbers(int n, int a[]);
int main()
{
    int a[100];
    int n;
    enter(n, a);
    printValue(n, a);
    printTheAmountOfPrimeNumber(n, a);
    printPrimeNumbers(n, a);
    return 0;
}
void enter(int &n, int a[])
{
    printf("enter the number: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("enter the number a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}
void printValue(int n, int a[])
{
    for (int i = 1; i <= n; i++)
    {
        printf("%4d", a[i]);
        if (i % 10 == 0)
        {
            printf("\n");
        }
    }
}
bool isPrimeNumber(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}
int countPrimeNumber(int n, int a[])
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (isPrimeNumber(a[i]))
        {
            count++;
        }
    }
    return count;
}
void printTheAmountOfPrimeNumber(int n, int a[])
{
    int count_prime_number = countPrimeNumber(n, a);
    printf("\nthe amount of prime numbers in array is %d", count_prime_number);
}
void printPrimeNumbers(int n, int a[])
{
    printf("\nthe prime numbers in array is: ");
    for (int i = 1; i <= n; i++)
    {
        if (isPrimeNumber(a[i]))
        {
            printf("%4d", a[i]);
        }
    }
}