#include<stdio.h>
#include<math.h>
void nhapdayso(int &n);
void xuatdayso(int n);
void lietkesochan(int n);
void lietkesole(int n);
int lasonguyento(int n);
void lietkesonguyento(int n);
int tinhTongSonguyento(int n);
void tongSonguyento(int n);
int lasochinhphuong(int n);
void sochinhphuong(int n);
int laSodoixung(int n);
void sodoixung(int n);
int main (){
	int n;
	//nhap day so
	nhapdayso(n);
	xuatdayso(n);
	lietkesochan(n);
	lietkesole(n);
	lietkesonguyento(n);
	tongSonguyento(n);
	sochinhphuong(n);
	sodoixung(n);
	return 0;
}
void nhapdayso(int &n){
	printf("nhap day so: ");
	scanf("%d", &n);
}
void xuatdayso(int n){
	for(int i=1;i<=n;i++){
		printf("%d ", i);
	}
}
void lietkesochan(int n){
	printf("\nso chan la: ");
	for(int i=1;i<=n;i++){
		if(i%2==0){
				printf("%d  ", i);
		}
	}
}
void lietkesole(int n){
	printf("\nso le la: ");
	for(int i=1;i<=n;i++){
		if(i%2!=0){
			printf("%d ", i);
		}
	}
}
int lasonguyento(int n){
	int lasonguyento = 1;
	for(int i=2;i<n;i++){
		if(n%i==0){
			lasonguyento=0;
			break;
		}
	}
	return lasonguyento;
}
void lietkesonguyento(int n){
	printf("\nSo nguyen to la: ");
	for(int i=2;i<n;i++){
		if(lasonguyento(i)){
			printf("%d ", i);
		}
	}
}
int tinhTongSonguyento(int n){
	int tong=0;
	for(int i=2;i<n;i++){
		if(lasonguyento(i)){
			tong+=i;
		}
	}
	return tong;
}
void tongSonguyento(int n){
	int tong=tinhTongSonguyento(n);
	printf("\nTong cac so nguyen to la %d", tong);
}
int lasochinhphuong(int n){
	int lasochinhphuong=0;
	if(sqrt(n)==((int)sqrt(n))){
		lasochinhphuong=1;
	}
	return lasochinhphuong;
}
void sochinhphuong(int n){
	printf("\nSo chinh phuong: ");
	for(int i=1;i<n;i++){
		if(lasochinhphuong(i)){
			printf("%d ", i);
		}
	}
}
int laSodoixung(int n){
	int a[100];
	int laSodoixung=1;
	int giatri=(int)log10((float)n)+1;
	for(int i=0;i<giatri;i++){
		a[giatri-i-1]=n%10;
		n/=10;
	}
	for(int i=0;i<giatri;i++){
		if(a[i]!=a[giatri-i-1]){
			laSodoixung=0;
			break;
		}
	}
	return laSodoixung;
}
void sodoixung(int n){
	if(laSodoixung(n)){
		printf("\n%d la so doi xung", n);
	}else{
		printf("\n%d khong la so doi xung", n);
	}
}