#include<stdio.h>
float Sum (int n);
int main (){
    int n;
    printf("enter the number ");
    scanf("%d", &n);
    printf("your result here %.2f ", Sum(n));
    return 0;
}
float Sum (int n){
    float S = 0;
    for (int i = 0; i<n; i++){
        S += i*(i+1)*(i+2);
    }
    return S;
}