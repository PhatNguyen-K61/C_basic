#include<stdio.h>
#include<stdlib.h>
int enter(int **array);
void print(int *array, int size);
int findMax(int *array, int size);
void printMax(int *array, int size);
int findMin(int *array, int size);
void printMin(int *array, int size);
int main(){
    int *array, value;
    int size;
    size = enter(&array);
    print(array,size);
    printMax(array,size);
    printMin(array,size);
    free(array);
}
int enter(int **array){
    int size;
    int temp;
    printf("size of array: ");
    scanf("%d",&size);
    *array = (int*)malloc(size*sizeof(int));
    for(int index=0;index<size;index++){
        printf("array[%d]: ",index);
        scanf("%d",&temp);
        *(*array+index) = temp;
    }
    return size;
}
void print(int *array, int size){
    if(size ==0){
        printf("empty!");
    }
    else{
        for(int index = 0; index < size; index++){
            printf("%d ",array[index]);
        }
    }
}
int findMax(int *array, int size){
    int max=*(array+0);
    for(int i=1;i<size;i++){
        if(max<*(array+i)){
            max=*(array+i);
        }
    }
    return max;
}
void printMax(int *array, int size){
    printf("\nMax number of array is: %d",findMax(array,size));
}
int findMin(int *array, int size){
     int min=*(array+0);
    for(int i=1;i<size;i++){
        if(min>*(array+i)){
            min=*(array+i);
        }
    }
    return min;
}
void printMin(int *array, int size){
    printf("\nMin number of array is: %d",findMin(array,size));
}