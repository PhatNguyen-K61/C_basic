#include<stdio.h>
#include<math.h>
struct DIEM{
   int x, y;
};
void nhapDiem(DIEM input[], int &n);
void xuatDiem(DIEM output[], int n);
void timxMin(DIEM output[], int n);
void timViTriDiem(DIEM output[], int n);
float TinhKhoangCach(DIEM a, DIEM b);
void KhoangCachMax(DIEM output[], int n);
int main(){
   DIEM diem[100];
   int n;
   nhapDiem(diem, n);
   xuatDiem(diem, n);
   timxMin(diem, n);
   timViTriDiem(diem, n);
   KhoangCachMax(diem, n);
   return 0;
}
void nhapDiem(DIEM input[], int &n){
   printf("Nhap so diem: ");
   scanf("%d", &n);
   for(int i = 0 ; i < n ; i++){
      printf("Nhap diem thu %d: ", i+1);
      scanf("%d%d", &input[i].x, &input[i].y);
   }
}
void xuatDiem(DIEM output[], int n){
   printf("\nCac diem: ");
   for(int i=0;i<n;i++){
      printf("(%d,%d) ", output[i].x, output[i].y);
   }
}
void timxMin(DIEM output[], int n){
   DIEM min = output[0];
   for(int i=1; i < n; i++){
      if(output[i].x<min.x){
         min = output[i];
      }
   }
   printf("\nDiem co hoanh do nho nhat la: (%d,%d)", min.x, min.y);
}
void timViTriDiem(DIEM output[], int n){
   int I=0, II=0, III=0, IV=0, temp=0;
   for(int i=0; i < n; i++){
      if(output[i].x>0 && output[i].y>0){
         I++;
      }else if(output[i].x<0 && output[i].y>0){
         II++;
      }else if(output[i].x<0 && output[i].y<0){
         III++;
      }else if(output[i].x>0 && output[i].y<0){
         IV++;
      }else{
         temp++;
      }
   }
   printf("\nSo diem nam o phan tu I: %d", I);
   printf("\nSo diem nam o phan tu II: %d", II);
   printf("\nSo diem nam o phan tu III: %d", III);
   printf("\nSo diem nam o phan tu IV: %d", IV);
   printf("\nSo diem nam o tren 2 truc toa do: %d", temp);
}
float TinhKhoangCach(DIEM a, DIEM b)
{
	return (float)sqrt(pow((b.x-a.x),2)+pow((b.y-a.y),2));
}
void KhoangCachMax(DIEM output[], int n)
{
	float KCmax=TinhKhoangCach(output[2],output[1]);
	int d1=1,d2=2;
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(KCmax<TinhKhoangCach(output[j],output[i]))
			{
				KCmax=TinhKhoangCach(output[j],output[i]);
				d1=i;
				d2=j;
			}
		}
	}
	printf("\n2 Diem co khoang cac lon nhat la: (%d,%d) (%d,%d)", output[d1].x, output[d1].y, output[d2].x, output[d2].y);
	printf("\nVa Khoang cach cua 2 diem do la: %.2f", KCmax);
}