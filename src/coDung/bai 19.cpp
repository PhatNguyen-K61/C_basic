#include<stdio.h>
void input(int a[], int &n);
void output(int a[], int n);
int countNegativeNumbers(int a[], int n);
void printNegativeNumbers(int a[], int n);

int main(){
    int n;
    int a[100];
    input(a,n);
    output(a,n);
    printNegativeNumbers(a,n);
    return 0;
}
void input(int a[], int &n){
    printf("enter the number: ");
    scanf("%d", &n);
    for(int i = 1; i<=n; i++){
        printf("enter the number a[%d]",i);
        scanf("%d", &a[i]);
    }
}
void output(int a[], int n){
    printf("\nyour numbers is here ");
    for(int i = 1; i<=n; i++){
        printf("%4d",a[i]);
    }
}
int countNegativeNumbers(int a[], int n){
    int count =0;
    for(int i = 1; i<=n; i++){
        if(a[i] < 0){
            count ++;
        }
    }
    return count;
}   
void printNegativeNumbers(int a[], int n){
    printf("\nthe number of negative is %d ", countNegativeNumbers(a,n));
}