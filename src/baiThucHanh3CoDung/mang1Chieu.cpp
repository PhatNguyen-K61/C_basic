#include <stdio.h>
#include <math.h>
#define Max 100
void input(int a[], int &x, int &n);
void square(int a[], int n);
void max(int a[], int n);
void min(int a[], int n);
void minPositive(int a[], int n);
void sum(int a[], int n);
int averageNumbers(int a[], int n);
void printAverage(int a[], int n);
float averageMultiplication(int a[], int n);
void printAverageMultiplication(int a[], int n);
int findX(int a[], int x, int n);
void X(int a[], int x, int n);
void ascending(int a[], int n);
void decreasing(int a[], int n);
void reverseNumbers(int a[], int n);
void insert(int a[], int n);
void deleteK(int a[], int n);
void positiveNumbers(int a[], int n);
bool checkSymmetricalArray(int a[], int n);
void symmetricalArray(int a[], int n);
bool isGrow(int a[], int n);
void grow(int a[], int n);
bool isPrime(int n);
void primeCount(int a[], int n);
bool isNumberInFibo(int n);
void outputFibonacci(int a[], int n);
void pairOfNumber(int a[], int n);
void menu(int a[], int n, int x);
int main()
{
    int a[Max], x, n;
    input(a, x, n);
    square(a, n);
    menu(a, x, n);
}
void input(int a[], int &x, int &n)
{
    printf("Enter n: ");
    scanf("%d", &n);
    printf("\nEnter x: ");
    scanf("%d", &x);
    for (int i = 0; i < n; i++)
    {
        printf("\nenter a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}
void square(int a[], int n)
{
    //xuất ra dòng gồm 10 phần tử
    for (int i = 0; i < n; i++)
    {
        if (i % 10 == 0)
        {
            printf("\n");
        }
        printf("%4d", a[i]);
    }
}
void max(int a[], int n)
{
    //tìm max
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    printf("\nThe max number is: %d", max);
}
void min(int a[], int n)
{
    //tìm min
    int min = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    printf("\nThe min number is: %d", min);
}
void minPositive(int a[], int n)
{
    //tìm số dương nhỏ nhất
    int min = a[0];
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if ((a[i] > 0) && (a[i] < min))
        {
            min = a[i];
            count++;
        }
    }
    printf("\nThe min positive number is: %d", min);
    printf("\nThe position of min positive number is: a[%d]", count);
}
void sum(int a[], int n)
{
    //tính tổng mảng
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    printf("\nThe summation of array is %d", sum);
}
int averageNumbers(int a[], int n)
{ //tính trung bình cộng của mảng
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    return sum / n;
}
void printAverage(int a[], int n)
{
    int result = averageNumbers(a, n);
    printf("\nthe average of number is: %d", result);
}
float averageMultiplication(int a[], int n)
{ //tính trung bình nhân của mảng
    float sum = 1;
    for (int i = 0; i < n; i++)
    {
        sum *= a[i];
    }
    return pow(sum, 1.0 / n);
}
void printAverageMultiplication(int a[], int n)
{
    float result = averageMultiplication(a, n);
    printf("\nthe average multiplication of number is %.2f", result);
}
int findX(int a[], int x, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            return i + 1;
        }
    }
    return -1;
}
void X(int a[], int x, int n)
{
    printf("\nPosition of x is: %d", findX(a, x, n));
}
void ascending(int a[], int n)
{ //dãy tăng dần
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("\nAscending number: ");
    square(a, n);
}
void decreasing(int a[], int n)
{
    //dãy giảm dần
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
    printf("\nDecresing number: ");
    square(a, n);
}
void reverseNumbers(int a[], int n)
{ //Xuất dãy đảo ngược
    printf("\n The reverse numbers is: ");
    for (int i = n - 1; i >= 0; i--)
    {
        printf("\t%d", a[i]);
    }
}
void insert(int a[], int n)
{ //Thêm một phần tử x vào vị trí k
    int x;
    int k;
    printf("\nEnter the number need to insert: ");
    scanf("%d", &x);
    printf("\nEnter the position need to insert: ");
    scanf("%d", &k);
    for (int i = n; i >= k; i--)
    {
        a[i] = a[i - 1];
    }
    a[k] = x;
    n++;
    square(a, n);
}
void deleteK(int a[], int n)
{ //Xóa một phần tử ở vị trí thứ k
    int k;
    printf("\nEnter the position need to delete: ");
    scanf("%d", &k);
    for (int i = 0; i < n; i++)
    {
        a[k] = a[k + 1];
        n = n - 1;
    }
    square(a, n);
}
void positiveNumbers(int a[], int n)
{
    //Đếm số phần tử dương và in ra tổng các phần tử dương của mảng
    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            count++;
            sum += a[i];
        }
    }
    printf("\nPositive numbers have in array is: %d", count);
    printf("\nSummation of positive number is: %d", sum);
}
bool checkSymmetricalArray(int a[], int n)
{ //kiểm tra mảng đối xứng
    bool symmetricalArray = true;
    for (int i = 0; i < n / 2; i++)
    {
        if (a[i] != a[n - i - 1])
        {
            symmetricalArray = false;
        }
    }
    return symmetricalArray;
}
void symmetricalArray(int a[], int n)
{
    if (checkSymmetricalArray(a, n))
    {
        printf("\nThis is a symmetrical array !");
    }
    else
    {
        printf("\nThis is NOT a symmetrical array !");
    }
}
bool isGrow(int a[], int n)
{
    //Kiểm tra mảng có sắp thứ tự tăng hay không
    bool grow = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
            grow = false;
    }
    return grow;
}
void grow(int a[], int n)
{
    if (isGrow(a, n))
    {
        printf("\nYour array is a array ascending !");
    }
    else
    {
        printf("\nYour array is NOT a array ascending !");
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
void primeCount(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (isPrime(a[i]))
        {
            count++;
        }
    }
    printf("\nPrime numbers in array is: %d", count);
}
bool isNumberInFibo(int n)
{
    //kiểm tra số fibonacci
    int numberinfibo = false;
    int letter[100];
    letter[0] = 1, letter[1] = 1;
    if (n == letter[0] || n == letter[1])
    {
        numberinfibo = true;
    }
    else
    {
        for (int i = 2; i < n; i++)
        {
            letter[i] = letter[i - 2] + letter[i - 1];
            if (n == letter[i])
            {
                numberinfibo = true;
                break;
            }
        }
    }
    return numberinfibo;
}
void outputFibonacci(int a[], int n)
{
    printf("\nnumbers in fibonacci: \n");
    for (int i = 0; i < n; i++)
    {
        if (isNumberInFibo(a[i]))
        {
            printf("\n%d", a[i]);
        }
    }
}
void pairOfNumber(int a[], int n)
{
    //Kiểm tra trong dãy số có bao nhiêu cặp ai+aj (i#j) là số nguyên tố.
    printf("\nPair of number is prime number: ");
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((a[i] != a[j]) && isPrime(a[i] + a[j]))
            {
                printf("\ta[%d] & a[%d]", a[i], a[j]);
            }
        }
    }
}
void menu(int a[], int x, int n)
{
    int choise;
    do
    {
        printf("\n----------\tMenu\t----------\n");
        printf("1. Find Max (Tim phan tu lon nhat)\n");
        printf("2. Find Min (Tim phan tu nho nhat)\n");
        printf("3. Find and print the Min positive number (Tim va in ra vi tri phan tu duong nho nhat)\n");
        printf("4. Sum of array (Tinh tong cua mang)\n");
        printf("5. Average of array (Tinh Trung binh cong cua mang)\n");
        printf("6. Average multiplication of array (Tinh Trung binh nhan cua mang)\n");
        printf("7. Find X (Tim phan tu x da cho truoc)\n");
        printf("8. Ascending array (Sap xep mang theo thu tu tang dan)\n");
        printf("9. Decresing array (Sap xep mang theo thu tu giam dan)\n");
        printf("10. Print the reverse numbers (Xuat ra day dao nguoc)\n");
        printf("11. Insert x into place k (Them x vao vi tri k)\n");
        printf("12. Delete a number in place k (Xoa 1 phan tu o vi tri k)\n");
        printf("13. Count positive numbers in array and find sum (Đem so phan tu duong va in ra tong cac phan tu duong do)\n");
        printf("14. Check symmetrical array (Kiem tra mang co doi xung khong)\n");
        printf("15. Check Ascending array (Kiem tra mang co sap thu tu tang khong)\n");
        printf("16. Count Prime numbers in array (Dem so nguyen to trong day)\n");
        printf("17. Find fibonacci numbers (Kiem tra day co bao nhieu cap so ma so sau bang tong 2 so truoc)\n");
        printf("18. Check prime number of pair numbers (Kiem tra cap so la so nguyen to)\n");
        printf("----------------------------------");
        printf("\nYour choise: ");
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
            max(a, n);
            break;
        case 2:
            min(a, n);
            break;
        case 3:
            minPositive(a, n);
            break;
        case 4:
            sum(a, n);
            break;
        case 5:
            printAverage(a, n);
            break;
        case 6:
            printAverageMultiplication(a, n);
            break;
        case 7:
            X(a, x, n);
            break;
        case 8:
            ascending(a, n);
            break;
        case 9:
            decreasing(a, n);
            break;
        case 10:
            reverseNumbers(a, n);
            break;
        case 11:
            insert(a, n);
            break;
        case 12:
            deleteK(a, n);
            break;
        case 13:
            positiveNumbers(a, n);
            break;
        case 14:
            symmetricalArray(a, n);
            break;
        case 15:
            grow(a, n);
            break;
        case 16:
            primeCount(a, n);
            break;
        case 17:
            outputFibonacci(a, n);
            break;
        case 18:
            pairOfNumber(a, n);
            break;
        default:
            printf("\nChoose again!");
            break;
        }
        printf("\nDo you want to exit? (press 0)");
    } while (choise);
}