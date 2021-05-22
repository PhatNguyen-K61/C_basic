#include<stdio.h>
#include <stdlib.h>
struct NHANSU{
    char name[30];
    float salary;
    char position[30];
};
void enter(NHANSU *input);
void enter(NHANSU *&input, int &n);
void exportNhanSu(FILE *file, char *path, NHANSU *output, int n);
int main(){
    FILE *file;
    char *output_path = "./src/ky2TrenTruong/nhansu.txt";
    NHANSU *nhansu;
    int n;
    nhansu =(NHANSU*)malloc(sizeof(NHANSU));
    enter(nhansu, n);
    exportNhanSu(file, output_path, nhansu, n);
    free(nhansu);
}
void enter(NHANSU *input){
    fflush (stdin);
    printf("\nNhap ten: ");
    gets(input->name);
    printf("Nhap he so luong: ");
    scanf("%f", &input->salary);
    fflush (stdin);
    printf("Nhap Chuc vu: ");
    gets(input->position);
}
void enter(NHANSU *&input, int &n){
    printf("Nhap so luong: ");
    scanf("%d", &n);
    input=(NHANSU *)realloc(input,n* sizeof(NHANSU));
    for(int i=0; i<n; i++){
        printf("Nhap nhan vien thu %d", i+1);
        enter(&*(input+i));
    }
}
void exportNhanSu(FILE *file, char *path, NHANSU *output, int n){
    char *mode = "w";
    file = fopen(path, mode);
    fprintf(file, "%d", n);
    for(int i=0; i < n; i++){
        fprintf(file,"\nNhan vien thu %d", i+1);
        fprintf(file, "\nTen: %s, he so luong: %.2f, Chuc vu: %s", (output+i)->name, (output+i)->salary, (output+i)->position);
    }
    fclose(file);
}