#include<stdio.h>
#define MAXSIZE 100
void inputArray(int a[],int &x, int &n);
void outputArray(int a[], int n);
void findTheSmallestElement(int a[], int n);
int isFristPosition(int a[], int n, int x);
void descendingNumbers(int a[], int n);
void menu(int a[], int n, int x);
int main(){
	int a[MAXSIZE], x, n;
	inputArray(a,x,n);
	outputArray(a, n);
    menu(a,n,x);
}
void inputArray(int a[], int &x, int &n){
	printf("n = ");
	scanf("%d", &n);
    printf("x= ");
    scanf("%d", &x);
    for(int i=0;i<n;i++){
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}
void outputArray(int a[], int n){
	for(int i=0;i<n;i++){
        printf("%4d", a[i]);
    }
}
void findTheSmallestElement(int a[], int n){
	int min=a[0];
	for(int i=1;i<n;i++){
		if(min>a[i]){
			min=a[i];
		}
	}
	printf("\nmin = %d", min);
}
int isFristPosition (int a[], int n, int x) {
    for (int i = 0; i < n; i++){
        if (a[i] == x){
            return i+1;
        }
    }
    return -1;
}
void descendingNumbers(int a[], int n){
    printf("\nDay so giam dan: ");
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]<a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
void menu(int a[], int n, int x){
    int choise;
    do{
        printf("\n----------\tMenu\t----------\n");
        printf("1. Tim phan tu nho nhat\n");
        printf("2. Tim vi tri x xuat hien dau tien\n");
        printf("3. Sap xep cac phan tu giam dan\n");
        printf("----------------------------------");
        printf("\nban chon so: ");
        scanf("%d", &choise);

    switch(choise){
        case 1:
        findTheSmallestElement(a, n);
        break;
        case 2:
        isFristPosition (a,n,x);
        printf("\nPhan tu %d xuat hien dau tien tai vi tri %d", x, isFristPosition (a,n,x));
        break;
        case 3:
        descendingNumbers(a, n);
        for(int i=0;i<n;i++){
            printf("%4d", a[i]);
        }
        break;
        default:
        printf("\nHay chon lai!");
        break;
    }
    printf("\nBan co muon thoat khong? (chon 0)");
    } 
    while(choise);
}