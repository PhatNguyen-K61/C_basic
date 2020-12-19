#include<stdio.h>
#include<math.h>
void input(int &a, int&b, int &c);
void output(int a, int b, int c);
void perimeter(int a, int b, int c);
void acreage(int a, int b, int c);
int main(){
    int a, b, c;
    input(a, b, c);
    output(a, b, c);
    perimeter(a, b, c);
    acreage(a, b, c);
}
void input(int &a, int &b, int &c){
    do{
    printf("Enter a: ");
    scanf("%d", &a);
    printf("Enter b: ");
    scanf("%d", &b);
    printf("Enter c: ");
    scanf("%d", &c);
    }while(a<0 || b<0 || c<0);
}
void output(int a, int b, int c){
    printf("\na=%d, b=%d, c=%d", a, b, c);
}
void perimeter(int a, int b, int c){
    printf("\nPerimeter is %d", a+b+c);
}
void acreage(int a, int b, int c){
    float p=(a+b+c)/2;
    printf("\nAcreage is %.4f", sqrt(p*(p-a)*(p-b)*(p-c)));
}