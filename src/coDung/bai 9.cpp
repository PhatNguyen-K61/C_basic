#include<stdio.h>
float Sum(int n);
int main(){
    int n;
    printf("enter the number: ");
    scanf("%d", &n);
    printf("your result is %.2f", Sum(n));
}
float Sum (int n){
    float S = 0;
    for (int i = 0; i <= n; i++){
        S += (2*i + 1);
    }
    return S;
}