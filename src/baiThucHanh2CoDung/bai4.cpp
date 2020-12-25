#include <stdio.h>
void enter(int &n, int a[]);
void printValue(int n, int a[]);
int countNegativeNumbers(int n, int a[]);
void printNegativeNumbers(int n, int a[]);
void printTheNumberOfNegative(int n, int a[]);
int main()
{
    int a[100];
    int n;
    enter(n, a);
    printValue(n, a);
    printTheNumberOfNegative(n, a);
    printNegativeNumbers(n, a);
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
    }
}
int countNegativeNumbers(int n, int a[])
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < 0)
        {
            count++;
        }
    }
    return count;
}
void printTheNumberOfNegative(int n, int a[])
{
    int count_negative_numbers = countNegativeNumbers(n, a);
    printf("\nthe amount of negative numbers in array is %d", count_negative_numbers);
}
void printNegativeNumbers(int n, int a[])
{
    printf("\nthe negative numbers in array is: ");
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < 0)
        {
            printf("%4d", a[i]);
        }
    }
}