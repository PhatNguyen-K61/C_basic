#include <stdio.h>
void enter(int &n, int a[]);
void printValue(int n, int a[]);
void printAverage(int n, int a[]);
int averageEvenNumbers(int n, int a[]);
int main()
{
    int a[100];
    int n;
    enter(n, a);
    printValue(n, a);
    printAverage(n, a);
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
int averageEvenNumbers(int n, int a[])
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] % 2 == 0)
        {
            sum += a[i];
        }
    }
    return sum / n;
}
void printAverage(int n, int a[])
{
    int result = averageEvenNumbers(n, a);
    printf("\nthe average of even number is: %d", result);
}