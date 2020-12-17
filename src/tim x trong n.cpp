#include<stdio.h>
#define MAX 100
void input(int a[],int &n ,int &x);
void output(int a[], int n);
int isFristPosition (int a[], int n, int x);
int main (){
    int n, x;
    int a[MAX];
    input(a,n,x);
    output(a,n);
    // fristPosition(n,a,x);
    printf("\n frist position of %d in %d",x,isFristPosition(a,n,x));
    return 0;
}
void input(int a[],int &n,int &x){
    printf("enter the N number: ");
    scanf("%d", &n);
    printf("enter the X number: ");
    scanf("%d", &x);
    for (int i = 0; i < n; i++){
        printf("enter number [%d]: ", i);
        scanf("%d", &a[i]);
    }
}
void output (int a[], int n){
    for (int i = 0; i < n; i++){
        printf("\n %4d", a[i]);
    }
}
int isFristPosition (int a[], int n, int x) {
    for (int i = 0; i < n; i++){
        if (a[i] == x){
            return i+1;
        }
    }
    return -1;
}