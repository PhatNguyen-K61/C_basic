#include<stdio.h>
void nhap(int &a);
bool laSoNguyenTo(int a);
void soNguyenTo(int a);
int main(){
    int a;
    nhap(a);
    soNguyenTo(a);
}
void nhap(int &a){
    printf("Nhap 1 so: ");
    scanf("%d", &a);
}
bool laSoNguyenTo(int a){
	bool lasonguyento = true;
	for(int i=2;i<a;i++){
		if(a%i==0){
			lasonguyento=false;
            break;
		}
	}
	return lasonguyento;
}
void soNguyenTo(int a){
	if(laSoNguyenTo(a)){
        printf("\n%d la So nguyen to", a);
    }
}