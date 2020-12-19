#include<stdio.h>
void input(int &n);
void output(int n);
int main(){
    int n;
    input(n);
    output(n);
}
void input(int &n){
    printf("enter n: ");
    scanf("%d", &n);
}
void output(int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=2*i;
    }
    printf("S= 2 + 4 + 6 + ... + 2*n = %d", sum);
}