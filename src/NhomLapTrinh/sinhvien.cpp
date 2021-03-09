#include <stdio.h>
#include <stdlib.h>
struct Mark{
    float math;
    float physical;
    float chemistry;
};
struct Student{
    char name[30];
    char gender[30];
    Mark *mark;
};
void enter(Mark *input);
void enter(Student *input);
float caculateGPA(Mark *input);
void print(Mark *output);
void print(Student *output);
int main(){
    Student *student;
    student = (Student *)malloc(sizeof(Student));
    enter(student);
    print(student);
}
void enter(Mark *input){
    do{
    printf("\nEnter mark of math: ");
    scanf("%f",&input->math);
    }while(input->math<0 || input->math>10.0);
    do{
    printf("Enter mark of physical: ");
    scanf("%f",&input->physical);
    }while(input->physical<0 || input->physical>10.0);
    do{
    printf("Enter mark of chemistry: ");
    scanf("%f",&input->chemistry);
    }while(input->chemistry<0 || input->chemistry>10.0);
}
void enter(Student *input){
    fflush(stdin);
    printf("\nEnter name: ");
    gets(input->name);
    printf("Enter gender: ");
    gets(input->gender);
    printf("Enter mark: ");
    input->mark = (Mark *)malloc(sizeof(Mark));
    enter(input->mark);
}
float caculateGPA(Mark *input){
    return (input->math + input->physical + input->chemistry)/3.0;
}
void print(Mark *output){
    float gpa = caculateGPA(output);
    printf("Mark {Math: %.1f, Physical: %.1f, Chemistry: %.1f, gpa: %.2f}", output->math, output->physical, output->chemistry, gpa);
}
void print(Student *output){
    printf("{name: %s, gender: %s }", output->name, output->gender);
    print(output->mark);
}