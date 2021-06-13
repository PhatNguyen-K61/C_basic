#include<stdio.h>
#include <stdlib.h>
struct NHANSU{
    char name[30];
    float salary;
    char position[30];
};
void enter(NHANSU *input);
void enter(NHANSU *&input, int &n);
void printTxtFile(FILE *file, char *path1, NHANSU *output, int n);
void printBinaryFile(FILE *file, char *path2, NHANSU *output, int n);
void enterTxtFile(int &n, NHANSU *&input, char *path1);
void enterBinaryFile(int &n, NHANSU *&input, char *path2);
void print(NHANSU *output, int n);
int main(){
    FILE *file;
    char *path1 = "./src/ky2TrenTruong/nhansu";
    char *path2 = "./src/ky2TrenTruong/nhansu2";
    NHANSU *nhansu;
    int n;
    nhansu =(NHANSU*)malloc(sizeof(NHANSU));
    enter(nhansu, n);
    printTxtFile(file,path1,nhansu,n);
    printBinaryFile(file,path2,nhansu,n);
    printf("\nXuat thong tin tu file van ban:");
    enterTxtFile(n,nhansu,path1);
    print(nhansu,n);
    printf("\nXuat thong tin tu file nhi phan:");
    enterBinaryFile(n,nhansu,path2);
    print(nhansu,n);
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
void printTxtFile(FILE *file, char *path1, NHANSU *output, int n){
    char *mode = "w";
    file = fopen(path1, mode);
    fprintf(file,"%d", n);
    for(int i=0; i < n; i++){
        fprintf(file, "\n%s\n%.2f\n%s", (output+i)->name, (output+i)->salary, (output+i)->position);
    }
    fclose(file);
}
void printBinaryFile(FILE *file, char *path2, NHANSU *output, int n){
    char *mode = "wb";
    file = fopen(path2, mode);
    fwrite(&n, sizeof(int), 1, file);
    for(int i=0; i < n; i++){
        fwrite(&*(output+i)->name,sizeof(char), 2, file);
        fwrite(&(output+i)->salary,sizeof(float), 5, file);
        fwrite(&*(output+i)->position,sizeof(char), 4, file);
    }
    fclose(file);
}
void enterTxtFile(int &n, NHANSU *&input, char *path1){
    FILE *file;
    file = fopen(path1, "r");
    fscanf(file, "%d", &n);
    input=(NHANSU*)calloc(n, sizeof(NHANSU));
    for(int i=0; i < n; i++){
        fread(&*(input+i)->name,sizeof(char),2,file);
        fscanf(file, "%f", &(input+i)->salary);
        fread(&*(input+i)->position,sizeof(char),4,file);
    }
    fclose(file);
}
void enterBinaryFile(int &n, NHANSU *&input, char *path2){
    FILE *file;
    file = fopen(path2, "r");
    fread(&n,sizeof(int),1,file);
    input=(NHANSU*)calloc(n, sizeof(NHANSU));
    for(int i=0; i < n; i++){
        fread(&*(input+i)->name,sizeof(char),2,file);
        fread(&(input+i)->salary,sizeof(float),5,file);
        fread(&*(input+i)->position,sizeof(char),4,file);
    }
    fclose(file);
}
void print(NHANSU *output, int n){
    for(int i=0; i < n; i++){
        printf("\nTen: %s, He so luong: %.2f, Chuc vu: %s", (output+i)->name, (output+i)->salary, (output+i)->position);
    }
}