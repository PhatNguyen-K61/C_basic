#include<stdio.h>
#define Max 100
void input(int a[], int &n);
void descendingNumbers(int a[], int n);
void output(int a[], int n);
int main(){
    int n, a[Max];
    input(a,n);
    descendingNumbers(a,n);
    output(a,n);
}
void input(int a[], int &n){
    printf("Nhap n: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}
void descendingNumbers(int a[], int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]<a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
void output(int a[], int n){
    printf("Day so giam dan: ");
    for(int i=0;i<n;i++){
        printf("%4d", a[i]);
    }
}
