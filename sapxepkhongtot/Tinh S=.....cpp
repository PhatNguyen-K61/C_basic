//Tinh S(n)= 1 + 1/2 + 1/3 + ... + 1/n ?
#include<stdio.h>
int main(){
	int i, n;
	float sum;
	sum=0; i=1;
	do {
		printf("\nNhap n :");
		scanf("%d", &n);
} while(n<1);
	while(i<=n) {		
		sum = sum + 1.0/i;
		i++;
}	
printf("\nTong cua 1+ 1/2 + 1/3 + ... + 1/%d la %f", n, sum);
return 0;
}
