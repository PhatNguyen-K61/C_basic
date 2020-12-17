//Nhap xuat mang 1 chieu
#include<stdio.h>
#define MAXSIZE 100
void input(int a[], int &x, int &n);
int findMax(int a[], int n);
int findMin(int a[], int n);
int listMax(int a[], int n);
int listMin(int a[], int n);
int findX(int a[], int x, int n);
void output(int a[], int n);
void outputMax(int a[], int n);
void outputMin(int a[], int n);
void outputListMax(int a[], int n);
void outputListMin(int a[], int n);
void evenNumber(int a[], int n);
void oddNumber(int a[], int n);
void X(int a[], int x, int n);
int main (){
	//khai bao bien
	int a[MAXSIZE], x, n;
	//nhap mang
	input(a, x, n);
	//xuat mang
	output(a, n);
	//xuat GTLN
	outputMax(a, n);
	//xuat GTNN
	outputMin(a, n);
	//xuat vi tri GTLN
	outputListMax(a, n);
	//xuat vi tri GTNN
	outputListMin(a, n);
	//Xuat chẵn và lẻ
	evenNumber(a, n);
	oddNumber(a, n);
	//tìm x 
	X(a, x, n);
	return 0;
}
void input(int a[], int &x, int &n){
	printf("nhap n: ");
	scanf("%d", &n);
	printf("Nhap x: ");
	scanf("%d", &x);
	for(int i=0;i<n;i++){
		printf("Nhap a[%d]: ", i);
		scanf("%d", &a[i]);
	}
}
void output(int a[], int n){
	printf("cac phan tu la: ");
	for(int i=0;i<n;i++){
		printf("\n%d ", a[i]);
	}
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
	printf("\nGia tri lon nhat la %d", gtln);
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
	printf("\nGia tri nho nhat là %d", gtnn);
}
int listMax(int a[], int n){
	int count=0;
	int gtln=findMax(a,n);
	for(int i=0;i<n;i++){
		if(a[i]==gtln){
			count++;
		}
	}
	return count;
}
void outputListMax(int a[], int n){
	int count=listMax(a, n);
	printf("\nSo GTLN la %d", count);
}
int listMin(int a[], int n){
	int count=0;
	int gtnn=findMin(a,n);
	for(int i=0;i<n;i++){
		if(a[i]==gtnn){
			count++;
		}
	}
	return count;
}
void outputListMin(int a[], int n){
	int count=listMin(a, n);
	printf("\nSo GTNN la %d", count);
}
void evenNumber(int a[], int n){
	printf("\nSo chan la: ");
	for(int i=0;i<n;i++){
		if(a[i]%2==0){
		printf("%4d",a[i]);
		}
	}
}
void oddNumber(int a[], int n){
	printf("\nSo le la: ");
	for(int i=0;i<n;i++){
		if(a[i]%2!=0){
		printf("%4d",a[i]);
		}
	}
}
int findX(int a[], int x, int n){
	for(int i=0;i<n;i++){
		if(a[i]==x){
			return i+1;
		}
	}
	return -1;
}
void X(int a[], int x, int n){
	printf("\nPhan tu x xuat hien lan dau o vi tri %d", findX(a, x, n));
}
