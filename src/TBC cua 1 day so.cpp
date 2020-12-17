#include<stdio.h>

int main (){
    //declare array
    int a[100];
    //declare output
    float tbc = 0;
    int count = 0;
    int sum = 0;
    //input the number of element in array
    int n;
    printf("enter the number: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
    	printf("enter a[%d] : ",i);
        scanf("%d", &a[i]);
        }
    for(int i = 0 ; i < n; i++){
        if( a[i] % 2 == 1){
            sum += a[i];
            count ++;
        }
    }
    tbc += sum / count;
    printf("tbc: %.5f", tbc);
    return 0;
}