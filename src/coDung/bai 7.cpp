#include<stdio.h>
#include<math.h>

void input (int &a, int &b, int &x, int &y, &int r);
void output (int a, int b, int x, int y, int r);
int distance (int a, int b, int x, int y, int r );


int main (){
    int a,b,x,y;
    input (a,b,x,y);
    output(a,b,x,y);
}
void input (int &a, int &b, int &x, int &y){
    int a,b,x,y;
    printf("enter cordinate x: ");
    scanf("%d", &x);
    printf("enter cordinate y: ");
    scanf("%d", &y);
    printf("enter cordinate y: ");
    scanf("%d", &y);
    printf("enter the number a: ");
    scanf("%d", &a);
    printf("enter the number b: ");
    scanf("%d", &b);
}
void ouput(int a, int b, int x, int y){
    if (distance(a,b,x,y) < )
}
int distance(int a, int b, int x, int y){
    float S = 0; + 
    S += (abs(x*a - y*b + b))/(float)(sqrt(a*a + 1));
    return S;
}