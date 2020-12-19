#include<stdio.h>
int factorial (int n);
int main (){
    int n;
    printf("enter the number: ");
    scanf ("%d", &n);
    printf("\n your result here: %d", factorial(n));
}
int factorial (int n){
    int S = 1;
    for(int i = 1 ; i <= n; i++){
        S *=i;    
    }
    return S;
}