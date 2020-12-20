#include<stdio.h>
#include<math.h>
long dec2Bin (int decimalNumber){
    long long binaryNumber = 0;
    int p = 0;
    while (decimalNumber > 0){
        binaryNumber += decimalNumber % 2 * pow(10,p);
        p++;
        decimalNumber /= 2;
    }
    return binaryNumber;
}

int main(){
    int decimalNumber;
    printf("enter the decimal number: ");
    scanf("%d", &decimalNumber);
    printf ("Bin = %d", dec2Bin(decimalNumber));
}