#include <stdio.h>
void enter(int &n, int a[]);
void printValue(int n, int a[]);
int findMaxNumber(int n, int a[]);
void printMaxNumber(int n, int a[]);
int main()
{
    int a[100];
    int n;
    enter(n, a);
    printValue(n, a);
    printMaxNumber(n, a);
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
int findMaxNumber(int n, int a[])
{
    int max_Number = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > max_Number)
        {
            max_Number = a[i];
        }
    }
    return max_Number;
}
void printMaxNumber(int n, int a[])
{
    int max_Number = findMaxNumber(n, a);
    printf("\nthe max number in array is %d", max_Number);
}