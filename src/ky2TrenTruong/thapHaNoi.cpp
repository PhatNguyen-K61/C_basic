#include<stdio.h>
void tower(int num, char x, char y, char z);
int main() {
   int num;
   printf("\nNhap so dia: ");
   scanf("%d", &num);
   tower(num - 1, 'A', 'B', 'C');
   return 0;
}
 
void tower(int num, char x, char y, char z) {
   if (num > 0) {
      tower(num - 1, x, z, y);
      printf("\n%c -> %c", x, y);
      tower(num - 1, z, y, x);
   }
}