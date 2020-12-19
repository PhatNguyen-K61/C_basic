#include<stdio.h>
#define Max 100
void input(int a[], int &n);
int positiveNumbers(int a[], int n);
void output(int a[], int n);
int main (){
    int a[Max], n;
    input(a, n);
    positiveNumbers(a, n);
    output(a, n);
}
void input(int a[], int &n){
    printf("Enter n: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("\nenter a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}
int positiveNumbers(int a[], int n){
    int count=0;
    for(int i=0;i<n;i++){
        if(a[i]>0){
            count++;
        }
    }
    return count;
}
void output(int a[], int n){
    printf("\nthe number of positive ís %d", positiveNumbers(a,n));
}