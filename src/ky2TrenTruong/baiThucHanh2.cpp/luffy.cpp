#include<stdio.h>
#include<math.h>
int main(){
   int n,a[100];
   scanf("%d",&n);
   for(int i=0;i<n;i++){
      scanf("%d",&a[i]);
   }
   printf("%d",abs(a[0]-a[n-1]));
   return 0;
}
