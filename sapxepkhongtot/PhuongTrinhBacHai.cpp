#include<stdio.h>
#include<math.h>
int delta(int a, int b, int c);
int main(){
	int a,b,c, x1, x2, x;
	printf("enter the number: ");
	scanf("%d%d%d", &a, &b, &c);
//	delta(a,b,c);
	printf("\nham so co nghiem la ", delta(a,b,c));
	return 0;
}
int delta(int a, int b, int c){
	float delta = b*b - (4*a*c);
	int x,x1, x2;
	if (delta == 0) {
		x = (float) -b / 2 *a;
		printf("\n ham co nghiem kep: x = %d", x);
		return x;
		
	} else if (delta < 0) {
		printf ("\nham vo nghiem, bye");
	} else {
		printf("\nham co 2 nghiem: %d %d ", x1 ,x2);
		x2 = (-b - sqrt(delta)) / (float)2*a;
		x1 = (-b + sqrt(delta)) / (float)2*a;
		return x1, x2;
	}
}