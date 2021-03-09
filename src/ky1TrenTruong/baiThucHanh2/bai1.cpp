#include <stdio.h>
void input(int &n, int a[]);
void output(int n, int a[]);
int main()
{
    int a[100];
    int n;
    input(n, a);
    output(n, a);
    return 0;
}
void input(int &n, int a[])
{
    printf("enter n: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("enter the number a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}
void output(int n, int a[])
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