#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void input(int *array, int &n);
void output(int *array, int n);
int sum(int *array, int n);
void sort(int *array, int n);
void printMin2(int *array, int n);
void reverseNumbers(int *array, int n);
bool isPrime(int n);
void primeCount(int *array, int n);
void insert(int *array, int &n);
void deleteK(int *array, int &n);
int main()
{
    int *array, n;
    array = (int *)malloc(sizeof(int));
    input(array, n);
    output(array, n);
    reverseNumbers(array, n);
    printf("\nSum off array is: %d\n", sum(array, n));
    sort(array, n);
    output(array, n);
    printf("\nSecond min is: ");
    printMin2(array, n);
    primeCount(array, n);
    insert(array, n);
    output(array, n);
    deleteK(array, n);
    output(array, n);
    return 0;
}
void input(int *array, int &n)
{
    int count = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", (array + i));
    }
}
void output(int *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", *(array + i));
    }
}
int sum(int *array, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += *(array + i);
    }
    return sum;
}
void sort(int *array, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (*(array + i) > *(array + j))
            {
                temp = *(array + i);
                *(array + i) = *(array + j);
                *(array + j) = temp;
            }
        }
    }
}
void printMin2(int *array, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        if (*(array + i) < 0 && *(array + i) > *(array + i - 1))
        {
            printf("%d", *(array + i - 1));
            break;
        }
    }
}
void reverseNumbers(int *array, int n)
{ //Xuất dãy đảo ngược
    printf("\nThe reverse numbers is: ");
    for (int i = n - 1; i >= 0; i--)
    {
        printf("\t%d", *(array + i));
    }
}
bool isPrime(int n)
{ //kiểm tra số nguyên tố trong mảng
    bool prime = true;
    if (n < 2)
        prime = false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            prime = false;
        }
    }
    return prime;
}
void primeCount(int *array, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (isPrime(*(array + i)) && *(array + i) > 0)
        {
            count++;
        }
    }
    printf("\nPrime numbers in array is: %d", count);
}
void insert(int *array, int &n)
{ //Thêm một phần tử x vào vị trí k
    int x;
    int k;
    printf("\nEnter the number need to insert: ");
    scanf("%d", &x);
    printf("\nEnter the position need to insert: ");
    scanf("%d", &k);
    for (int i = n; i >= k; i--)
    {
        *(array + i) = *(array + i - 1);
    }
    *(array + k) = x;
    n++;
}
void deleteK(int *array, int &n)
{ //Xóa một phần tử ở vị trí thứ k
    int k;
    printf("\nEnter the position need to delete: ");
    scanf("%d", &k);
    for (int i = 0; i < n; i++)
    {
        *(array + k) = *(array + k + 1);
        --n;
    }
}