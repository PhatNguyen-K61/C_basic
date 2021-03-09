#include<stdio.h>
#include<math.h>
void input(int &a, int &b);
int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
float chia(int a, int b);
int residue(int a, int b);
int division(int a, int b);
long dec2Bin (int n);
int andCaculator(int a, int b);
int orCaculator(int a, int b);
int notCaculator(int a, int b);
int xorCaculator(int a, int b);
void menu(int a, int b);
int main(){
    int a, b;
    input(a, b);
    menu(a, b);
}
void input(int &a, int &b){
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
float chia(int a, int b){
    return (float) a/b;
}
int residue(int a, int b){
    return a%b;
}
int division(int a, int b){
    return a/b;
}
long dec2Bin (int n){
    long long binaryNumber = 0;
    int p = 0;
    while (n > 0){
        binaryNumber += n % 2 * pow(10,p);
        p++;
        n /= 2;
    }
    return binaryNumber;
}
int andCaculator(int a, int b){
    return a&b;
}
int orCaculator(int a, int b){
    return a|b;
}
int notCaculator(int a, int b){
    return ~a;
}
int xorCaculator(int a, int b){
    return a^b;
}
int leftCaculator(int a, int b){
    return a<<b;
}
int rightCaculator(int a, int b){
    return a>>b;
}
void menu(int a, int b){
    char choise;
    do
    {
        printf("\n--------Menu--------\n");
        printf("1. Phep cong\n");
        printf("2. Phep tru\n");
        printf("3. Phep nhan\n");
        printf("4. Phep chia có du\n");
        printf("5. Phep chia lay phan du\n");
        printf("6. Phep chia nguyen\n");
        printf("7. Phep AND\n");
        printf("8. Phep or\n");
        printf("9. Phep not\n");
        printf("10. Phep xor\n");
        printf("11. Phep dich trai\n");
        printf("12. Phep dich phai\n");
        printf("------------------------\n");
        printf("\nYour choise: ");
        fflush(stdin);
        scanf("%c", &choise);
        switch(choise){
            case '1':
            printf("\n%d",add(a, b));
            printf("\nBinary: %d", dec2Bin(add(a, b)));
            break;
            case '2':
            printf("\n%d", sub(a, b));
            printf("\nBinary: %d", dec2Bin(sub(a, b)));
            break;
            case '3':
            printf("\n%d", mul(a, b));
            printf("\nBinary: %d", dec2Bin(mul(a, b)));
            break;
            case '4':
            printf("\n%f", chia(a, b));
            printf("\nBinary: %d", dec2Bin(chia(a, b)));
            break;
            case '5':
            printf("\n%d",residue(a, b));
            printf("\nBinary: %d", dec2Bin(residue(a, b)));
            break;
            case '6':
            printf("\n%d", division(a, b));
            printf("\nBinary: %d", dec2Bin(division(a, b)));
            break;
            case '7':
            printf("\n%d", andCaculator(a, b));
            break;
            case '8':
            printf("\n%d", orCaculator(a, b));
            break;
            case '9':
            printf("\n%d", notCaculator(a, b));
            break;
            case '10':
            printf("\n%d",xorCaculator(a, b));
            break;
            case '11':
            printf("\n%d",leftCaculator(a, b));
            break;
            case '12':
            printf("\n%d", rightCaculator(a, b));
            break;
        }
        printf("\nDo you want to exit?");
        fflush(stdin);
        scanf("%c", &choise);
    }while(choise!=27);
}