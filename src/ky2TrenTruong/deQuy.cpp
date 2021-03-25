#include <stdio.h>
void enter(int &n);
void enter(int a[], int n);
int Tong_DeQuy(int a[], int n);
int main(){
    int a[100], n;
    enter(n);
    enter(a, n);
    printf("%d",Tong_DeQuy(a, n));
}
void enter(int &n){
    printf("\nNhap n: ");
    scanf("%d", &n);
}
void enter(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("\nNhap a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}
int Tong_DeQuy(int a[], int n){
    if(n == 1){
        return a[0];
    }else{
        return (a[n-1]+Tong_DeQuy(a,n-1));
    }
}