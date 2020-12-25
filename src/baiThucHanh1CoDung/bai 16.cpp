#include<stdio.h>
#define Max 100
void input(int a[], int &n);
void square(int a[], int n);
int main (){
    int a[Max], n;
    input(a, n);
    square(a,n);
}
void input(int a[], int &n){
    printf("Enter n: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        printf("\nenter a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}
void square(int a[], int n){
    for (int i = 0; i < n; i++){
        if (i % 10 == 0){
            printf("\n");
            }
            printf("%4d", a[i]);
        }
}
    