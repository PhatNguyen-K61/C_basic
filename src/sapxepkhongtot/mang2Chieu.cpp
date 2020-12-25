#include <stdio.h>
#define Max 100
void input(int a[][100], int &m, int &n);
void output(int a[][100], int m, int n);
int findMax(int a[][100], int m, int n);
void max(int a[][100], int m, int n);
int findMin(int a[][100], int m, int n);
void min(int a[][100], int m, int n);
void minPosition(int a[][100], int m, int n);
void maxPosition(int a[][100], int m, int n);
int main()
{
    int a[Max][100];
    int m, n;
    input(a, m, n);
    output(a, m, n);
    max(a, m, n);
    maxPosition(a, m, n);
    min(a, m, n);
    minPosition(a, m, n);
}
void input(int a[][100], int &m, int &n)
{
    printf("Enter row n = ");
    scanf("%d", &n);
    printf("\nEnter colum m = ");
    scanf("%d", &m);
    printf("\nEnter the matrix:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            printf("A[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
}

void output(int a[][100], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
}
int findMax(int a[][100], int m, int n)
{//tìm phần tử lớn nhất
    int max = a[0][0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (max < a[i][j])
            {
                max = a[i][j];
            }
        }
    }
    return max;
}
void max(int a[][100], int m, int n)
{
    int max = findMax(a, m, n);
    printf("The max number is %d", max);
}
void maxPosition(int a[][100], int m, int n)
{//vị trí phần tử lớn nhất
    int u = 0, v = 0;
    int max = a[0][0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (max < a[i][j])
            {
                max = a[i][j];
                u = i;
                v = j;
            }
        }
    }
    printf("\nPosition of max number is [%d][%d]", u + 1, v + 1);
}
int findMin(int a[][100], int m, int n)
{//tìm phần tử nhỏ nhất
    int min = a[0][0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (min > a[i][j])
            {
                min = a[i][j];
            }
        }
    }
    return min;
}
void min(int a[][100], int m, int n)
{
    int min = findMin(a, m, n);
    printf("\nThe min number is %d", min);
}
void minPosition(int a[][100], int m, int n)
{//vị trí phần tử nhỏ nhất
    int u = 0, v = 0;
    int min = a[0][0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (min > a[i][j])
            {
                min = a[i][j];
                u = i;
                v = j;
            }
        }
    }
    printf("\nPosition of min number is [%d][%d]", u + 1, v + 1);
}