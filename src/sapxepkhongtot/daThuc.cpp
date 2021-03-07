#include<stdio.h>
#include<math.h>
void enter(int &n);
void enterA(int a[], int n);
void print(int a[], int n);
void enterX(int &x);//bài này a sửa cho Minh rồi á. e hỏi nó. tại a code thì nó khác dữ lắm ý nên có thể phân tích style.
int caculate(int a[], int x, int n);//REVIEW: a,n,x sắp xếp những cái liên quan gần nhau
void printSum(int a[], int x, int n);
int main()
{
int a[100], b[100],n, m, x1, x2;
    enter(n);
    enterA(a,n);
    enter(m);
    enterA(b, m);
    print(a,n);
    print(b, m);
    enterX(x1);
    enterX(x2);
    printSum(a, x1, n);
    printSum(b, x2, m);
}
void enter(int &n){
    printf("Nhap bac cua da thuc: ");
    scanf("%d", &n);
}
void enterA(int a[], int n){
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
    printf("\nNhap x: ");
    scanf("%d", &x);
}
int caculate(int a[], int x, int n){
    int sum =0;
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