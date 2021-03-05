#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct employee_st{
    char name[30];
    char province[30];
    int year;
};
void enter(employee_st *input);
void enterEmployees(employee_st *input, int numberOfEmployee);
void arrangeEmployees(employee_st *input, int numberOfEmployee);
void print(employee_st *output, int numberOfEmployee);
int main(){
    employee_st *employeetList;
    int numberOfEmployee =3;
    employeetList=(employee_st *)calloc(numberOfEmployee,sizeof(employee_st));
    enterEmployees(employeetList,numberOfEmployee);
    arrangeEmployees(employeetList, numberOfEmployee);
    print(employeetList, numberOfEmployee);
}
void enter(employee_st *input){
    printf("\nNhap ten cua nhan vien: ");
    fflush(stdin);
    gets(input->name);
    printf("Nhap tinh: ");
    gets(input->province);
    printf("Nhap nam sinh: ");
    scanf("%d",&input->year);
}
void enterEmployees(employee_st *input, int numberOfEmployee){
    input = (employee_st *)realloc(input,(numberOfEmployee)*sizeof(employee_st));
    for(int i=0; i < numberOfEmployee; i++){
        printf("\nNhap thong tin nhan vien %d",i+1);
        enter(&*(input+i));
    }
}
void print(employee_st *output, int numberOfEmployee){
    printf("\n|-----------------------|-----------------------|------------|");
    printf("\n|\tName\t\t|\tProvince\t|Year\t     |");
    printf("\n|-----------------------|-----------------------|------------|");
    for(int i=0; i < numberOfEmployee; i++){
        printf("\n|%15s\t|%15s\t|%d\t     |",(output+i)->name,(output+i)->province,(output+i)->year);
        printf("\n|-----------------------|-----------------------|------------|");
    }
}
void arrangeEmployees(employee_st *input, int numberOfEmployee){
    employee_st temp;
    for(int i = 0; i < numberOfEmployee-1; i++){
        for(int j = i+1; j <numberOfEmployee; j++){
            if(strcmp((input+i)->province, (input+j)->province) < 0){
                temp = *(input+i);
                *(input+i)= *(input+j);
                *(input+j) = temp;
            }
        }
    }
}