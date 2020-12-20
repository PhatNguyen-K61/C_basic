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
    do{
    printf("enter n: ");
    scanf("%d", &n);
    }while(n<1);
}
void output(int n){
    float sum=0;
    for(int i=1;i<=n;i++){
        sum+=1.0/(i*(i+1));
    }
    printf("S= 1+ 1/2*3 + ... + 1/n*(n+1)= %.4f", sum);
}