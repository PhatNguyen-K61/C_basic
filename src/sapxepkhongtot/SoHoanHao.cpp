#include <stdio.h>
void nhap(int a[],int n);
void xuat(int a[],int n);
bool kiemTra(int a[],int n);
int soHoanHao(int x);
int main(){
    int a[100],n;
    printf("So phan tu cua mang: ");
    scanf("%d",&n);
    printf("Nhap mang duong: \n");
    nhap(a,n);
    xuat(a,n);
    return 0;
}
void nhap(int a[],int n)//Nhap mang duong
{
    for(int i=0;i<n;i++){
        if(a[i]>0){
            printf("a[%d] ",i+1);
            scanf("%d",&a[i]);
        }
        else{
            printf("Mang khong chua phan tu am.vui long nhap lai: ");
            scanf("%d ",&a[i]);
        }
    }
}
bool kiemTra(int a[],int n)// kiem tra a[i] co phai la so hoan hao
{
for(int i=0;i<n;i++){
    if(soHoanHao(a[i]) && a[i]>0){
    return true;
     }
    }
return false;
}
int soHoanHao(int x){
    int S=0;
    for(int i=1;i<x;i++){
        if(x%i==0){
            S+=i;
        }
        if(S==x){
        return 1;
        }
    }
return 0;
}
void xuat(int a[],int n){
    printf("\nSo hoan hao co trong day la: ");
    for(int i=0;i<n;i++){
        if(soHoanHao(a[i])){
            printf("%d ",a[i]);
        }
    }
}