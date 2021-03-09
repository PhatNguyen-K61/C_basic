#include<stdio.h>
void nhap(int &day, int &month, int &year);
bool laNgayHopLe(int day, int month, int year);
bool laNamNhuan(int year);
void xuat(int day, int month, int year);
bool laNgayHopLe(int day, int month, int year);
int timSTTNam(int day, int month, int year);
void khoangCach(int day1, int month1, int year1, int day2, int month2, int year2);
int main(){
    int day1,month1,year1,day2,month2,year2;
    nhap(day1,month1,year1);
    xuat(day1,month1,year1);
    nhap(day2,month2,year2);
    xuat(day2,month2,year2);
    khoangCach(day1,month1,year1,day2,month2,year2);
}
void nhap(int &day, int &month, int &year){
    do{
    printf("\n nhap ngay thang nam: ");
    scanf("%d%d%d", &day,&month,&year);
    } while(!laNgayHopLe(day,month,year));
}
// kiem tra xem xem no co phai nam nhuan hay khong
void xuat(int day, int month, int year){
    printf("\n ngay %d thang %d nam %d", day,month,year);
}
bool laNgayHopLe(int day, int month, int year){
    bool langayhople = true;
    if(month<0 || month>12){
        langayhople = false;
    }
    else{
        switch (month)
        {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if(day<1||day>31){
                langayhople = false;
            }
            break;

        case 4: case 6: case 9: case 11:
            if(day<1 || day>30){
                langayhople =false;
            }
            break;
        case 2:
            if(laNamNhuan(year) && (day<1||day>29)){
                langayhople =false;  
            }
            break;
        }
    }
    return langayhople;
}
bool laNamNhuan(int year){
    return year%4==0;
}
int timSTTNam(int day, int month, int year){
   int S = day;
	for(int i = 1; i < month; i++) { 
		switch (i){
			case 4: case 6: case 9 : case 11: 
                S += 30; 
                break;
			case 2: 
                S += (laNamNhuan(year)) ? 29 : 28;
				break;
		default: S += 31;
		}
	}
	return S;
}
void khoangCach(int day1, int month1, int year1, int day2, int month2, int year2){
    printf("\nKhoang cach giua 2 ngay la: ");
    int STT1=timSTTNam(day1,month1,year1);
    int STT2=timSTTNam(day2,month2,year2);
    if(STT1>STT2){
        printf("%d",STT1-STT2);
    }else{
        printf("%d", STT2-STT1);
    }
}