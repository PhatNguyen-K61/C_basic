#include <stdio.h>
#include<stdlib.h>
#include <math.h>
struct VECTOR{
    int x;
    int y;
};
void enter(VECTOR *a, VECTOR *b);
void print(VECTOR *a, VECTOR *b);
int scalar(VECTOR *a, VECTOR *b);
bool checkChuan(VECTOR *input);
void Chuan(VECTOR *a, VECTOR *b);
int main (){
    VECTOR *first, *second;
    first = (VECTOR *)malloc(sizeof(VECTOR));
    second = (VECTOR *)malloc(sizeof(VECTOR));
    enter(first, second);
    print(first, second);
    printf("\nTich vo huong cua 2 vector A B la %d", scalar(first, second));
    Chuan(first, second);
    free(first);
    free(second);
    return 0;
}
void enter(VECTOR *a, VECTOR *b){
    printf("Nhap vector A: \n");
    printf("Nhap x: \n");
    scanf("%d", &a->x);
    printf("Nhap y: \n");
    scanf("%d", &a->y);
    printf("Nhap vector B: \n");
    printf("Nhap x: \n");
    scanf("%d", &b->x);
    printf("Nhap y: \n");
    scanf("%d", &b->y);
}
void print(VECTOR *a, VECTOR *b){
    printf("Vector A(%d,%d)\n", a->x, a->y);
    printf("Vector B(%d,%d)", b->x, b->y);
}
int scalar(VECTOR *a, VECTOR *b){
    int temp;
    temp = ((a->x * b->x) +(a->y * b->y));
    return temp;
}
bool checkChuan(VECTOR *input){
    bool check = false;
    if(sqrt(pow(input->x,2) + pow(input->y,2))==1){
        check = true;
    }
    return check;
}
void Chuan(VECTOR *a, VECTOR *b){
    if(checkChuan(a)){
        printf("\nVector A la vector truc chuan");
    }else{
        printf("\nVector A khong la vector truc chuan");
    }
    if(checkChuan(b)){
        printf("\nVector B la vector truc chuan");
    }else{
        printf("\nVector B khong la vector truc chuan");
    }
}
