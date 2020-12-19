#include<stdio.h>
void input (int &a, int &b);
void output (int a, int b);
int main (){
    int a,b;
    input(a,b);
    output(a,b);
    return 0;
}
void input (int &a, int &b){
    do{
        printf("enter the edge 1: ");
        scanf("%d", &a);
        printf("enter the edge 2: ");
        scanf("%d", &b);
    } while (a,b < 0);
}
void output (int a, int b){
    int S = 0;
    int CV = 0;
    S += a*b;
    CV = (a+b)*2;
    printf("your result: \n");
    printf("\nthe edge 1: %d", a);
    printf("\nthe edge 2: %d", b);
    printf("\nCV is %d", CV);
    printf("\nS is %d", S);
}