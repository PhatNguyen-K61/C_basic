#include<stdio.h>
void enter(int &n, int a[]);
void printValue(int n, int a[]);
int countpositiveNumbers(int n, int a[]);
void printpositiveNumbers(int n,  int a[]);
void printTheNumberOfpositive(int n, int a[]);
int main(){
    int a[100];
    int n;
    enter(n, a);
    printValue(n, a);
    printTheNumberOfpositive(n,a);
    printpositiveNumbers(n,a);
    return 0;
}
void enter(int &n, int a[]){
    printf("enter the number: ");
    scanf("%d", &n);
    for(int i = 1; i<=n; i++){
        printf("enter the number a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

void printValue(int n, int a[]){
    for(int i = 1; i<=n; i++){
        printf("%4d", a[i]);
    }
}
int countpositiveNumbers(int n, int a[]){
    int count = 0;
    for(int i = 1; i<=n; i++){
        if(a[i]>0){
            count++;
            }
        }
        return count;
    }
void printTheNumberOfpositive(int n, int a[]){
    int count_positive_numbers =  countpositiveNumbers(n,a);
    printf("\nthe amount of positive numbers in array is %d", count_positive_numbers);
}
void printpositiveNumbers(int n,  int a[]){
    printf("\nthe positive numbers in array is: ");
    for(int i = 1; i<=n; i++){
        if(a[i]>0){
            printf("%4d", a[i]);
        }
    }
}