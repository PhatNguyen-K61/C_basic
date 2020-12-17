#include<stdio.h>
#include<conio.h>
#define Max 100
typedef struct student
{
    int birthday,mark;
    char name[25];
}stud[Max];
void inputStudent(stud[] &input, int &n);
void ouputStudent(stud[] output, int n);
int main(){
    int n;
    stud input, output;
    inputStudent(input, n);
    outputStudent(output, n);
}
void inputStudent(stud[] &input, int &n){
    printf("Enter the no of students\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){   
        fflush(stdin);
        printf("Name of student %d: ", i+1);
        gets(st.name);
        printf("Birthday: ");
        scanf("%d", &input.birthday);
        printf("Medium score: ");
        scanf("%d", &st.mark);
    }
}
void outputStudent(stud[] output, int n){
    for(int i=0;i<n;i++){
        fflush(stdin);
        printf("\nName of student %d: %s", i+1, st.name);
        printf("\nBirthday: %d", st.birthday);
        printf("\nMedium score: %d", st.mark);
    }
}