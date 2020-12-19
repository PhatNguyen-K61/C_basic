#include<stdio.h>
#include<math.h>
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
    for(int i=1;i<=n;i++){
        sum+=pow(i,3);
    }
    printf("S= 1^3 + 2^3 + 3^3 + ... + n^3 = %d", sum);
}