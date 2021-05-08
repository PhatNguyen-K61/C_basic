#include<stdio.h>
#include<math.h>
void enter(int &n);
void enterPolynomial(int a[], int n);
void print(int a[], int n);
void enterX(int &x);
float caculate(int a[], int x, int n);
void printSum(int a[], int x, int n);
void derivative(int a[], int n);
int main()
{
    int a[100], b[100],n, m, x1, x2;
    enter(n);
    enterPolynomial(a,n);
    enter(m);
    enterPolynomial(b, m);
    print(a,n);
    print(b, m);
    derivative(a,n);
    derivative(b,n);
    enterX(x1);
    enterX(x2);
    printSum(a, x1, n);
    printSum(b, x2, m);
    printf("Tong 2 da thuc la: %.1f",caculate(a,x1,n)+caculate(b,x2,m));
}
void enter(int &n){
    printf("Nhap bac cua da thuc: ");
    scanf("%d", &n);
}
void enterPolynomial(int a[], int n){
    for(int i=0;i<=n;i++){
    printf("Nhap gia tri x^%d\n",i);
    scanf("%d",&a[i]); 
    }
}
void print(int a[], int n){
    for(int i=n; i>=0; i--){
        if(i>0){
            printf("%dx^%d+", a[i], i);
        }else{
            printf("%d^%d=", a[i], i);
        }
    }
    printf("0");
    printf("\n");
}
void enterX(int &x){
    printf("Nhap x: ");
    scanf("%d", &x);
}
float caculate(int a[], int x, int n){
    float sum =0;
    for(int i=0;i<=n;i++){
        sum+=a[i]*pow(x,i);
    }
    return sum;
}
void printSum(int a[], int x, int n){
    for(int i=n; i>=0; i--){
        if(i>0){
            printf("%dx^%d+", a[i], i);
        }else{
            printf("%d^%d=", a[i], i);
        }
    }
    printf("%d",caculate(a,x,n));
    printf("\n");
}
void derivative(int a[], int n){
    //dao ham
    for(int i=n-1;i>=0; i--){
        if(i>0){
            printf("%dx^%d+", a[i]*i, i);
        }else{
            printf("%d^%d=", a[i], i);
        }
    }
    printf("0");
    printf("\n");
}