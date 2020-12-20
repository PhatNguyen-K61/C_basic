#include<stdio.h>
int USCLN (int a, int b){
    if (b == 0) return a;
    return USCLN(b, a %b);
}
int BSCNN (int a, int b){
    return (a*b)/ USCLN (a,b);
}
int main(){
    int a,b;
    printf("enter the number 1: ");
    scanf("%d", &a);
    printf("enter the number 2: ");
    scanf("%d", &b);
    printf("\nUSCLN of %d and %d is %d: ", a,b,USCLN(a,b));
    printf("\nBCNN of %d and %d is %d: ", a,b,BSCNN(a,b));
    return 0;    
}