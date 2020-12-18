#include <stdio.h>
#include <conio.h>
#define Max 100
struct student
{
    int day, month, year;
    float mark;
    char name[25];
};
typedef student STUDENT;
void inputStudent(STUDENT &stud);
void inputNStudent(STUDENT a[], int &n);
void outputStudent(STUDENT stud);
void outputNStudent(STUDENT a[], int n);
bool validDay(STUDENT stud);
bool leapYear(STUDENT stud);
int main()
{
    int n;
    STUDENT a[Max], stud;
    printf("\nEnter the number of students: ");
    scanf("%d", &n);
    inputNStudent(a, n);
    outputNStudent(a, n);
}
void inputStudent(STUDENT &stud){
        printf("\nName of student: ");
        fflush(stdin);
        gets(stud.name);
        do{
        printf("\nBirthday: ");
        scanf("%d%d%d", &stud.day, &stud.month, &stud.year);
        }while(!validDay(STUDENT stud));
        printf("\nMedium score: ");//Điểm trung bình
        scanf("%f", &stud.mark);
}
void inputNStudent(STUDENT a[], int &n){
    for(int i=0;i<n;i++){
        printf("\nNhap thong tin sinh vien thu %d: ", i+1);
        inputStudent(a[i]);
    }
}
void outputStudent(STUDENT stud){
        printf("\nName of student: %s", stud.name);
        printf("\nBirthday: %d/%d/%d", stud.day, stud.month, stud.year);
        printf("\nMedium score: %.2f", stud.mark);
}
void outputNStudent(STUDENT a[], int n){
    for(int i=0;i<n;i++){
        printf("\nThong tin sinh vien thu %d: ", i+1);
        outputStudent(a[i]);
    }
}
bool validDay(STUDENT stud){
    bool validDay = true;
    if(stud.month<0 || stud.month>12){
        validDay = false;
    }
    else{
        switch(stud.month){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                if(stud.day<1 || stud.day>31){
                    validDay = false;
                }
            break;
            case 4: case 6: case 9: case 11:
                if(stud.day<1 || stud.day>30){
                    validDay = false;
                }
            break;
            case 2:
                if(leapYear(stud) && (stud.day<1 || stud.day>29)){
                    validDay = false;  
                }
            break;
        }
    }
    return validDay;
}
bool leapYear(STUDENT stud){
    return stud.year%4 == 0;
}