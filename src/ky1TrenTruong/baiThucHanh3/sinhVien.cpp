#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 100
struct Student
{
    int day, month, year;
    float mark;
    char name[25];
};
void inputStudent(Student &stud);
void inputNStudent(Student a[], int &n);
void outputStudent(Student stud);
void outputNStudent(Student a[], int n);
bool validDay(Student stud);
bool leapYear(Student stud);
void arrangeStudentsByName(Student a[], int n);
int main()
{
    int n;
    char searchName[25];
    Student a[MAX], stud;
    printf("\nEnter the number of Students: ");
    scanf("%d", &n);
    inputNStudent(a, n);
    arrangeStudentsByName(a, n);
    outputNStudent(a, n);
}
void inputStudent(Student &stud)
{
    printf("\nName of Student: ");
    fflush(stdin);
    gets(stud.name);
    do
    {
        printf("\nBirthday: ");
        printf("\nDay: ");
        scanf("%d", &stud.day);
        printf("Month: ");
        scanf("%d", &stud.month);
        printf("Year: ");
        scanf("%d", &stud.year);
        if (!validDay(stud))
        {
            printf("\nEnter again");
        }
    } while (!validDay(stud));
    printf("\nAverage score: "); //Điểm trung bình
    scanf("%f", &stud.mark);
}
void inputNStudent(Student a[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nInformation of Student %d: ", i + 1);
        inputStudent(a[i]);
    }
}
void outputStudent(Student stud)
{
    printf("\nName of Student: %s", stud.name);
    printf("\tBirthday: %d/%d/%d", stud.day, stud.month, stud.year);
    printf("\tAverage score: %.2f", stud.mark);
}
void outputNStudent(Student a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nInformation of Student %d: ", i + 1);
        outputStudent(a[i]);
    }
}
bool validDay(Student stud)
{ //kiểm tra ngày tháng
    bool validDay = true;
    if (stud.month < 0 || stud.month > 12)
    {
        validDay = false;
    }
    else
    {
        switch (stud.month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (stud.day < 1 || stud.day > 31)
            {
                validDay = false;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (stud.day < 1 || stud.day > 30)
            {
                validDay = false;
            }
            break;
        case 2:
            if (leapYear(stud) && (stud.day < 1 || stud.day > 29))
            {
                validDay = false;
            }
            break;
        }
    }
    return validDay;
}
bool leapYear(Student stud)
{
    return stud.year % 4 == 0;
}
void arrangeStudentsByName(Student a[], int n)
{ //sắp xếp SV theo tên
    printf("\n\tArrange students by name: ");
    Student k;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(a[i].name, a[j].name) > 0)
            {
                k = a[i];
                a[i] = a[j];
                a[j] = k;
            }
        }
    }
}