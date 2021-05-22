#include<stdio.h>
int main()
{
 int ngay,thang,nam;
 int x;
 scanf("%d%d%d",&ngay,&thang,&nam);
 switch(thang){
 case 1:case 3:case 5:case 7:case 8:case 10:case 12:x=31;break;
 case 4: case 6:case 9:case 11:x=30;break;
 case 2:
  if(nam%400==0 || (nam%4==0 && nam%100!=0))
   x=29;
  else x=28;
  break;
 default:x=0;
 }
  if(ngay==x)
  {
   if(thang==12)
   {
    ngay=1;
    thang=1;
    nam++;
   }
   else
   {
    ngay=1;
    thang++;
   }
  }
  else
   ngay++;
  printf("%d/%d/%d",ngay,thang,nam);
}