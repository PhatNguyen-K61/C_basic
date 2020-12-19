//tính S(n)=1^2 + 2^2 + 3^2 +...+ n^2?
#include<stdio.h>
int main (){
	int n;
	int sum;
	sum=0;
	printf("\nNhap n:");
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		sum= sum + i * i;
	}
	printf("\nTong tu 1^2 + 2^2 + ... + %d^2 là %d",n,sum);
	return 0;
}