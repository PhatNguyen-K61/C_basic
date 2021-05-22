#include<stdio.h>
int main(){
   int n,a[100];
   scanf("%d",&n);
   for(int i=0;i<n;i++){
      scanf("%d",&a[i]);
   }
   printf("%d",a[1]-a[0]);
   return 0;
}