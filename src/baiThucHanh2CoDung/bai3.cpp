#include<stdio.h>
#define Max 100
void input(int &n, int a[]);
void ascending(int n, int a[]);
void output(int n, int a[]);
int main(){
    int n, a[Max];
    input(n, a);
    ascending(n, a);
    output(n, a);
}
void input(int &n, int a[]){
    printf("Enter n: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        printf("\nEnter a[%d]: ", i+1);
        scanf("%d", &a[i]);
    }
}
void ascending(int n, int a[]){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
void output(int n, int a[]){
    printf("\nAscending number: ");
    for(int i=0;i<n;i++){
        printf("%4d", a[i]);
    }
}