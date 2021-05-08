#include <stdio.h>
#include <stdlib.h>
#define MAX 50
struct SinhVien{
    char hoten [25];
    char truong [50];
    int diem;
};
void enter (SinhVien *sinhvien);
void enter (SinhVien *sinhvien,int &sosinhvien);
void print (SinhVien *sinhvien);
void print (SinhVien *sinhvien,int sosinhvien);
void sort (SinhVien *sinhvien, int sosinhvien);

int main (){
    SinhVien *sinhvien;
    int sosinhvien;
    sinhvien = (SinhVien*) malloc (sizeof (SinhVien));
    enter (sinhvien,sosinhvien);
    print (sinhvien,sosinhvien);
    sort (sinhvien,sosinhvien);
    print (sinhvien,sosinhvien);
    if(sinhvien != NULL)
    free (sinhvien);
    return 0;
}
void enter (SinhVien *sinhvien){
    fflush (stdin);
    printf ("Nhap Ho Va Ten Thi Sinh: ");
    gets (sinhvien->hoten);
    printf ("Nhap Truong Thi Sinh: ");
    gets (sinhvien->truong);
    printf ("Nhap So Diem Thi Sinh: ");
    scanf ("%d",&sinhvien->diem);
}
void print (SinhVien *sinhvien){
    printf ("\nTen: %-25s||Truong: %-25s||Diem: %-2d",sinhvien->hoten,sinhvien->truong,sinhvien->diem);
}
void enter (SinhVien *sinhvien,int &sosinhvien){
    do {
    printf ("\n\n\t\tNhap So Luong Thí Sinh: ");
    scanf("%d",&sosinhvien);
        if (sosinhvien <= 0||sosinhvien > MAX){
            printf ("Xin Vui Long Nhap Lai!!!");
            printf ("\nNhap So Luong Thi sinh: ");
            scanf("%d",&sosinhvien);
        }
    }while (sosinhvien <= 0||sosinhvien > MAX);
    sinhvien = (SinhVien*)realloc(sinhvien,(sosinhvien)*sizeof(SinhVien));
    for (int i = 0; i < sosinhvien ; i++){
        printf ("\n\n--------------------------------");
        printf ("\nNhap Thong Tin Thi Sinh %d\n",i+1);
        enter(&*(sinhvien+i));
    }
}
void print (SinhVien *sinhvien, int sosinhvien){
    for (int i = 0; i < sosinhvien ; i++){
        print(sinhvien+i);
    }
}
void sort (SinhVien *sinhvien, int sosinhvien){
    SinhVien temp ;
    for (int i = 0; i < sosinhvien-1; i++){
        for(int j = i+1; j < sosinhvien; j++){
            if ((sinhvien+i)->diem < (sinhvien+j)->diem){
                temp = *(sinhvien+i);
                *(sinhvien+i) = *(sinhvien+j);
                *(sinhvien+j) = temp;
            }
        }
    }
}
