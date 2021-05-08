#include<stdio.h>
#define MAXSIZE 100
void input(int a[], int &n);
int sum(int a[], int n);
int average(int a[], int n);
int findMax(int a[], int n);
int findMin(int a[], int n);
void outputMax(int a[], int n);
void outputMin(int a[], int n);
void sort(int a[], int n);
void evenNumber(int a[], int &x, int n);
int main (){
	int a[MAXSIZE], x, n;
	input(a, n);
	outputMax(a, n);
	outputMin(a, n);
    printf("\nTong cua day la: %d\n", sum(a, n));
    printf("TBC cua day la: %d\n", average(a, n));
    evenNumber(a, x, n);
    return 0;
}
void input(int a[], int &n){
	printf("nhap n: ");
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		printf("Nhap a[%d]: ", i);
		scanf("%d", &a[i]);
	}
}
int sum(int a[], int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += a[i];
    }
    return sum;
}
int average(int a[], int n){
    return (float)(sum(a, n)/n);
}
int findMax(int a[], int n){
	int gtln=a[0];
	for(int i=1;i<n;i++){
		if(a[i]>gtln){
			gtln=a[i];
		}
	}
	return gtln;
}
void outputMax(int a[], int n){
	int gtln=findMax(a, n);
	printf("\nGia tri lon nhat la %d\n", gtln);
}
int findMin(int a[], int n){
	int gtnn=a[0];
	for(int i=1;i<n;i++){
		if(a[i]<gtnn){
			gtnn=a[i];
		}
	}
	return gtnn;
}
void outputMin(int a[], int n){
	int gtnn=findMin(a,n);
	printf("\nGia tri nho nhat la %d", gtnn);
}
void sort(int a[], int n){
    int temp ;
    for (int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if (a[i] > a[j]){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
void evenNumber(int a[], int &x, int n){
    printf("Nhap x: ");
	scanf("%d", &x);
    sort(a, n);
    printf("So chan nho hon %d la: ", x);
    for(int i = 0; i < n; i++){
        if(a[i] %2 == 0 && a[i] < x){
            printf("%d ", a[i]);
        }
    }
}