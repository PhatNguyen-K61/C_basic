#include<stdio.h>
#include<math.h>
#define MAX_SIZE  100
struct Array{
    int numbers[MAX_SIZE];//các phần tử
    int size;//số phần tử trong mảng
};
void enter(Array &input);
void printValue(Array output);
Array findEvenNumbers(Array source);
void printEvenNumbers(Array source);
bool isPrime(Array source);
Array findPrime(Array source);
void printPrime(Array source);
int main(){
    Array list;
    enter(list);
    printValue(list);
    printEvenNumbers(list);
    printPrime(list);
}
void enter(Array &input){
    int temp;
    printf("Enter the size of array: ");
    scanf("%d", &input.size); 
    for(int index = 0; index < input.size; index++){
        printf("enter number a[%d]: ",index);
        scanf("%d", &temp);
        input.numbers[index] = temp;
    }
}
void printValue(Array output){
    for(int index = 0; index < output.size; index++){
        printf("%4d",output.numbers[index]);
    }
}
Array findEvenNumbers(Array source){
    Array even_numbers;
    even_numbers.size = 0;
    for(int index = 0; index < source.size; index++){
        if(source.numbers[index] % 2 == 0){
            even_numbers.size++;
            even_numbers.numbers[even_numbers.size-1] = source.numbers[index]; 
        }
    }
    return even_numbers;     
}
void printEvenNumbers(Array source){
    Array even_numbers = findEvenNumbers(source);
    printf("\nyour result: ");
    printValue(even_numbers);
}
bool isPrime(Array source){
    int isPrime = true;
    if(source.size<2){
        isPrime = false;
    }
    for(int index =2;index<sqrt(source.size);index++){
        if(source.size%index==0){
            isPrime=false;
        }
    }
    return isPrime;
}
Array findPrime(Array source){
    Array findPrime;
    findPrime.size=0;
    for(int index=0;index<source.size;index++){
        if(isPrime(source)){
            findPrime.size++;
            findPrime.numbers[findPrime.size-1] = source.numbers[index];
        }
    }
    return findPrime;
}
void printPrime(Array source){
    Array prime=findPrime(source);
    printf("\nPrime number in Array is: ");
    printValue(prime);
}