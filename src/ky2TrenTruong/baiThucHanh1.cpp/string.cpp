#include<stdio.h>
#include<string.h>
void NhapChuoi(char *s){
    fflush(stdin);
    printf("vui long nhap chuoi: ");
    gets(s);
    puts(s);
}

int KiemTraChuoi( char *s){
        int count = 0;
        for (int i = 0; i < strlen(s); i++){
            for( int j = 48; j < 57; j++){
                if(s[i] == j)
                    count++;
        }
    }   return count;
}

int DemSoTu( char *s){
        int count = 0;
        for (int i = 0; i < strlen(s); i++){
            for( int j = 48; j < 57; j++){
                if(s[i] == j)
                    count++;
        }
    }   return count;
}

void LayKiTuBenTrai(char *s, int &n){
    printf("\nNhap vao so luong ky tu: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        printf("%c", s[i]);
    }
}

char*  LayKiTuBenPhai(char *s, int &n){
    char desk[12];
    memset(desk, '\0', sizeof(desk));
    printf("\nNhap vao so luong muon lay: ");
    scanf("%d",&n);
    return strcpy(desk, s + strlen(s) - n);
}

int main(){
    char s[100];
    int n;
    NhapChuoi(s);
    if (KiemTraChuoi(s) > 1 && KiemTraChuoi(s) == strlen (s) ){
        printf("Day la chuoi so");
    }
    else 
        printf("Day khong phai chuoi so");
    int sotu = strlen(s) - DemSoTu(s);
    printf("\nSo tu trong chuoi la: %d ",sotu);
    LayKiTuBenTrai(s, n);
    printf("Lay %d ky tu ben phai: %s",n,LayKiTuBenPhai(s,n));
}