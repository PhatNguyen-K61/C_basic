#include<stdio.h>
void input(int &a1, int &b1, int &a2, int &b2, int &c1, int &c2);
void calculate(int a1, int b1, int a2, int b2, int c1, int c2, int d, int dx, int dy);
void output(int d, int dx, int dy, int x, int y);
int main(){
    int a1, b1, a2, b2, c1, c2;
    float d, dx, dy, x, y;
    input(a1,b1,a2,b2,c1,c2);
    calculate(a1,b1,a2,b2,c1,c2,d,dx,dy);
    output(d, dx, dy, x, y);
}
void input(int &a1, int &b1, int &a2, int &b2, int &c1, int &c2){
    printf("\na1: ");
    scanf("%d", &a1);
    printf("b1: ");
    scanf("%d", &a2);
    printf("a2: ");
    scanf("%d", &b1);
    printf("b2: ");
    scanf("%d", &b2);
    printf("c1: ");
    scanf("%d", &c1);
    printf("c2: ");
    scanf("%d", &c2);
}
void calculate(int a1, int b1, int a2, int b2, int c1, int c2, int d, int dx, int dy){
    d=a1*b2-a1*b1;
    dx=c1*b2-c2*b1;
    dy=a1*c2-a2*c1;
}
void output(int d, int dx, int dy, int x, int y){
   if (d){
        x=dx/d;
        y=dy/d;
        printf(" He phuong trinh co nghiem duy nhat (x,y)=(%.2f,%.2f)",x,y);
    }else if (dx) printf(" he phuong trinh vo nghiem");
    else printf (" He phuong trinh co vo so nghiem");
}