#include<stdio.h>
int giaithua(int so);
void xuatStrong(int so);// định nghĩa
int main(){
    int so = 145;
    xuatStrong(so);
}
int giaithua(int so){
    int ketqua = 1;// kĩ thuật đặt lính canh
    for(int i = 1;i<=so;i++){
        ketqua = ketqua*i;
    }
    return ketqua;
}
void xuatStrong(int so){ //xây dựng
    int tam = so;
    // tách số 145: 1,4,5
    int tong_giai_thua = 0;// 1! + 4! + 5!
    while(tam%10!=0){// NOTE: tính tổng giai thừa các chữ số
        tong_giai_thua = tong_giai_thua + giaithua(tam%10);// 5!+ 4! + 1!
        tam = tam/10;
    }
    // kiểm tra strong
    if(tong_giai_thua==so){
        printf("1");
    }
    else{
        printf("0");
    }
}