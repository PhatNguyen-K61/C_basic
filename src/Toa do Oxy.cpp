#include<stdio.h>
#include<math.h>
//khai báo dữ liệu điểm OXY
struct Diem{
	float X;
	float Y;
};
typedef struct Diem DIEM;

void NhapDiem(DIEM &);
void XuatDiem(DIEM);

float TinhKhoangCachGiua2Diem(DIEM, DIEM);
DIEM TimDiemDoiXungQuaOy(DIEM);

// Nhập tọa độ điểm trong mặt phẳng
void NhapDiem(DIEM &a)
{
	printf("\nNhap X: ");
	scanf("%f", &a.X);

	printf("\nNhap Y: ");
	scanf("%f", &a.Y);
};

// Xuất tọa độ điểm trong mặt phẳng
void XuatDiem(DIEM a)
{
	printf("<%.2f, %.2f>", a.X, a.Y);
}

// Tính khoảng cách giữa 2 điểm

float TinhKhoangCachGiua2Diem(DIEM a, DIEM b)
{
	return sqrt(pow((b.X - a.X), 2) + pow((b.Y - a.Y), 2));
}

// Tìm điểm đối xứng qua trục tung
DIEM TimDiemDoiXungQuaOy(DIEM a)
{
    DIEM c;
    c.X = -1 * a.X;
    c.Y = 1 * a.Y;
    return c;
}
// kiểm tra xem a có thuộc phần tư thứ 2 không
bool thuocGocPhanTuThuHai1(DIEM a){
    return a.X <0 && a.Y >0;
}
void gocPhanTuThuHai1(DIEM a){
    if(thuocGocPhanTuThuHai1(a)){
        printf("\nDiem a thuoc goc phan tu thu hai");
    }
}
// kiểm tra xem b có thuộc phần tư thứ 2 không
bool thuocGocPhanTuThuHai2(DIEM b){
    return b.X <0 && b.Y >0;
}
void gocPhanTuThuHai2(DIEM b){
    if(thuocGocPhanTuThuHai1(b)){
        printf("\nDiem b thuoc goc phan tu thu hai");
    }
}
int main()
{
	DIEM a, b;
	NhapDiem(a);
	XuatDiem(a);

	NhapDiem(b);
	XuatDiem(b);

	float khoangcach = TinhKhoangCachGiua2Diem(a, b);
	printf("\nKhoang cach giua 2 diem A, B = %.2f", khoangcach);

	DIEM e = TimDiemDoiXungQuaOy(a);
	printf("\nDiem E doi xung diem A qua Oy: ");
	XuatDiem(e);

    gocPhanTuThuHai1(a);
    gocPhanTuThuHai2(b);
	return 0;
}