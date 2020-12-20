#include<stdio.h>
void arrDescendingNumber(int a[], int n);
void input (int a[], int n);
void output (int a[], int n);
void input (int a[], int n){
   for (int i = 0; i < n; i++){
        printf("number[%d]: ", i);
        scanf("%d", &a[i]);
    } 
}
void output(int a[], int n){
    for (int i = 0; i < n; i++){
        printf("%4d", a[i]);
    }
}
void arrDescendingNumber(int a[], int n){
    int temp;
    for (int i = 0; i < n -1; i++){
        for (int j = i+1; j < n; j++){
            if (a[i] < a[j]){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            }
        }
    }
}
int main(){
    int a[100];
    int n;
    printf("enter the number: ");
    scanf("%d", &n);
    input (a,n);
    arrDescendingNumber(a,n);
    printf("\nDescending number is: ");
    output (a,n);
    return 0;
}  



