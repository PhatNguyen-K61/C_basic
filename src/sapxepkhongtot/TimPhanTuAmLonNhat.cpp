#include<stdio.h>
void nhapmang(int a[], int &n);
int timphantulonnhat(int a[], int n);
void xuatmang(int a[], int n);
void nhapmang(int a[], int &n){ 
  printf("nhap so phan tu :" );
  scanf("%d",&n);
  for(int i=0;i<n;i++){ 
      printf(" phan tu thu %d :",i);
    scanf("%d",&a[i]);
  }
}
void xuatmang(int a[],int n){
  for(int i=0;i<n;i++){
        printf("%d \t",a[i]);
     }
 }
int timphantulonnhat(int a[],int n)
{
 int max;
 for(int i=0;i<n;i++){
  if(a[i]<0){
    max=a[i];
    for(int j=0;j<n;j++){
     if(a[j]>max && a[j]<0) 
      max=a[j];
    }
  }
 }
 return max;
}
int main(){
 int a[50],n;
 nhapmang(a,n);
 xuatmang(a,n);
 printf("\nphan tu am lon nhat la: %d",timphantulonnhat(a,n));
 return 0;
}