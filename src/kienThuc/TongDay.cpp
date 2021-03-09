#include<stdio.h>
void Tong(int n,int sum);

void Tong(int n,int sum){
	sum=0;
	scanf("%d", &n);
	for(int i=0; i<=n;i++){
		sum+=2*i+1;
	}
	printf("%d", sum);
}

int main(){
	int sum=0,n;
	scanf("%d", &n);
	return 0;
}