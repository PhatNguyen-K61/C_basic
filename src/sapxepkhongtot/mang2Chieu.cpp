#include <stdio.h>
#define Max 100
void input(int a[][100], int &n, int &m);
void output(int a[][100], int n, int m);
int findMax(int a[][100], int n, int m);
void max(int a[][100], int n, int m);
int findMin(int a[][100], int n, int m);
void min(int a[][100], int n, int m);
void minPosition(int a[][100], int n, int m);
void maxPosition(int a[][100], int n, int m);
bool checkLowerTriangularMatrix(int a[][100], int n, int m);
void lowerTriangularMatrix(int a[][100], int n, int m);
int main()
{
    int a[Max][100];
    int n, m;
    input(a, n, m);
    output(a, n, m);
    max(a, n, m);
    maxPosition(a, n, m);
    min(a, n, m);
    minPosition(a, n, m);
    lowerTriangularMatrix(a, n, m);
}
void input(int a[][100], int &n, int &m)
{
    printf("Enter row n = ");
    scanf("%d", &n);
    printf("\nEnter colum m = ");
    scanf("%d", &m);
    printf("\nEnter the matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            printf("A[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
}

void output(int a[][100], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
}
int findMax(int a[][100], int n, int m)
{ //tìm phần tử lớn nhất
    int max = a[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (max < a[i][j])
            {
                max = a[i][j];
            }
        }
    }
    return max;
}
void max(int a[][100], int n, int m)
{
    int max = findMax(a, n, m);
    printf("The max number is %d", max);
}
void maxPosition(int a[][100], int n, int m)
{ //vị trí phần tử lớn nhất
    int u = 0, v = 0;
    int max = a[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
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
int findMin(int a[][100], int n, int m)
{ //tìm phần tử nhỏ nhất
    int min = a[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (min > a[i][j])
            {
                min = a[i][j];
            }
        }
    }
    return min;
}
void min(int a[][100], int n, int m)
{
    int min = findMin(a, n, m);
    printf("\nThe min number is %d", min);
}
void minPosition(int a[][100], int n, int m)
{ //vị trí phần tử nhỏ nhất
    int u = 0, v = 0;
    int min = a[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
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
bool checkLowerTriangularMatrix(int a[][100], int n, int m)
{ //kiểm tra ma trận tam giác trên
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i > j && a[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}
void lowerTriangularMatrix(int a[][100], int n, int m)
{
    if (checkLowerTriangularMatrix(a, n, m))
    {
        printf("\nThe matrix is a Lower triangular matrix");
    }
}