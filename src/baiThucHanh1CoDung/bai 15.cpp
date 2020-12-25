#include<stdio.h>
void input(int &n, int a[]);
void output(int n, int a[]);
float Sum (int a[], int n);
float avereage (int a[], int n);

int main (){
    int n;
    int a[100];
    input(n,a);
    output(n,a);
    printf("\nyour result is here %.2f", avereage(a,n));
    return 0;
}
void input(int &n, int a[]){
    printf("enter the number: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        printf("\nenter the number a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}
void output(int n, int a[]){
    printf("\nyour numbers in here: ");
    for (int i = 1; i <=n ; i++){
        printf("%4d", a[i]);
    }
}
float  Sum (int a[], int n){
    float S = 0;
    for(int i = 1; i<=n; i++){
        S += a[i];
    }
    return S;
}
float  avereage (int a[], int n){
    return Sum(a,n)/n;
}