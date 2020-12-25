#include <stdio.h>
#define Max 100
void input(int &n, float a[]);
void ascending(int n, float a[]);
void output(int n, float a[]);
int main()
{
    int n;
    float a[Max];
    input(n, a);
    ascending(n, a);
    output(n, a);
}
void input(int &n, float a[])
{
    printf("Enter n: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter a[%d]: ", i + 1);
        scanf("%f", &a[i]);
    }
}
void ascending(int n, float a[])
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
void output(int n, float a[])
{
    printf("\nAscending number: 5
    ");
    for(int i=0;i<n;i++){
        printf("\t%.2f", a[i]);
    }
}