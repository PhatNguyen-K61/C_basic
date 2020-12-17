//tinh tong 1 day so le
#include<stdio.h>
int main() {
	int n, a[100],sum=0;
	printf("nhap so phan tu : ");
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		printf("nhap so: ");
		scanf("%d", &a[i]);
	}
	for(int i=0; i<n; i++) {
		if(a[i]%2!=0)
			sum=sum+a[i];
	}
	printf("%d", sum);
}