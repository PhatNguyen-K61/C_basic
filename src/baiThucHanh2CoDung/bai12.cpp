#include<stdio.h>
void enter(int &n, int &m, int a[]);
void printValue(int n, int m, int a[]);
void printCountNumber(int n, int m, int a[]);
int countNumber(int n, int m, int a[]);
void printNumber(int n, int m, int a[]);
int main(){
    int a[100];
    int n;
    int m;
    enter(n,m, a);
    printValue(n,m,a);
    printCountNumber(n,m,a);
    printNumber(n,m,a);
    return 0;
}
void enter(int &n,int &m, int a[]){
    printf("Enter the N number: ");
    scanf("%d", &n);
    do{
    printf("\nEnter the M number with m < n: ");
    scanf("%d", &m);
    } while (n<m);
    for(int i = m; i<=n; i++){
        printf("enter the number a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}
void printValue(int n, int m, int a[]){
    for(int i = m; i<=n; i++){
        printf("%4d", a[i]);
        if(i % 10 == 0){
            printf("\n");
        }
    }
}
int countNumber(int n, int m, int a[]){
    int count = 0;
    for(int i = m; i<=n; i++){
        if(a[i] % 5 == 2){
            count++;
        }
    }
    return count;
}
void printCountNumber(int n, int m, int a[]){
    int count_number =  countNumber(n,m,a);
    printf("\nThe amount of number in array is %d ", count_number);
}
void printNumber(int n, int m, int a[]){
    printf("\nYour result: ");
    for(int i = m; i<=n; i++){
        if(a[i] % 5 == 2){
            printf("%4d", a[i]);
        }
    }
}