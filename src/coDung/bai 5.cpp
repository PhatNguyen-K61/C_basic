#include<stdio.h>
void input (int &n);
void output (int n);
bool isNumberInFibo(int n);

int main(){
    int n;
    input (n);
    output(n);
    return 0;
}
void input (int &n){
    printf("\nenter the number:");
    scanf("%d", &n);    
    for(int i = 0; i < n; i++){
        printf("%4d",i);
    }
}
void output(int n){
    printf("\nnumbers in fibo: \n");
    for(int i = 0; i<n; i++){
        if(isNumberInFibo(i)){
            printf("\n%d",i);
        }
    }
}
bool isNumberInFibo(int n){
    int numberinfibo = false;
    int letter[100];
    letter[0] = 1,letter[1] =1;
    if(n==letter[0] || n ==letter[1]){
        numberinfibo = true;
    }
    else{
        for(int i=2;i<n;i++){
            letter[i]= letter[i-2]+letter[i-1];
            if(n==letter[i]){
                numberinfibo = true;
                break;
            }
        }
    }
    return numberinfibo;
}