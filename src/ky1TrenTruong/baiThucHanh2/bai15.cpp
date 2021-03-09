#include <stdio.h>
void enter(int &n, int a[]);
void printResult(int n, int a[]);
void printValue(int n, int a[]);
void printNumber(int n, int a[]);
int checkNumber(int n, int a[]);
int main()
{
    int a[100];
    int n;
    enter(n, a);
    printValue(n, a);
    printResult(n, a);
    printNumber(n, a);
    return 0;
}
void enter(int &n, int a[])
{
    printf("\nenter the number: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("\nenter the number a[%d]: ", i);
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
int checkNumber(int n, int a[])
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if ((a[i] % 3 == 0 || a[i] % 7 == 0) && (a[i] > 0 && a[i] <= 100))
        {
            count++;
        }
    }
    return count;
}
void printResult(int n, int a[])
{
    int count_number = checkNumber(n, a);
    printf("\nyour result is here: %d", count_number);
}
void printNumber(int n, int a[])
{
    printf("\nyour numbers is here: ");
    for (int i = 1; i <= n; i++)
    {
        if ((a[i] % 3 == 0 || a[i] % 7 == 0) && (a[i] > 0 && a[i] <= 100))
        {
            printf("%4d", a[i]);
        }
    }
}