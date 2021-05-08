#include <stdio.h>
#include <math.h>
#include <conio.h>
void enter(int &a, int &b);
int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
float divide(int a, int b);
int exponential(int a, int b);
void menu(int a, int b);
int main(){
    int a, b;
    enter(a,b);
    menu(a,b);
    return 0;
}
void enter(int &a, int &b){
    printf("Enter a: ");
    scanf("%d", &a);
    printf("Enter b: ");
    scanf("%d", &b);
}
int add(int a, int b){
    return a+b;
}
int sub(int a, int b){
    return a-b;
}
int mul(int a, int b){
    return a*b;
}
float divide(int a, int b){
    return (float)a/b;
}
int exponential(int a, int b){
    return pow(a,b);
}
void menu(int a, int b){
    int choise;
    char k, c;
    do{
        printf("\n--------Menu--------\n");
        printf("1. Phep cong\n");
        printf("2. Phep tru\n");
        printf("3. Phep nhan\n");
        printf("4. Phep chia\n");
        printf("5. Luy thua\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choise);
        switch (choise){
            case 1:
            printf("%d + %d = %d\n", a, b, add(a, b));
            break;
            case 2:
            printf("%d - %d = %d\n", a, b, sub(a, b));
            break;
            case 3:
            printf("%d * %d = %d\n", a, b, mul(a, b));
            break;
            case 4:
            printf("%d / %d = %.2f\n", a, b, divide(a, b));
            break;
            case 5:
            printf("%d ^ %d = %d\n", a, b, exponential(a, b));
            break;
            default:
            printf("Khong hop le\n");
            break;
        }
        printf("Ban co muon thoat (esc)\n");
        k=getch();
        c=k;
    }while(c != 27);
}