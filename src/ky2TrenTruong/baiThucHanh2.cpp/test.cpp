#include <stdio.h>
#include <string.h>
int main()
{
   int a =1;
   switch(a+1){
      case 1:
         a = a+1;
         break;
      case 2:
         a = a-1;
         break;
   }
   printf("%d", a);
}