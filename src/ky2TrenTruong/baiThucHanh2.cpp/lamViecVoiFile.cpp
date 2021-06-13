#include<stdio.h>
#include<stdlib.h>
void enter(float **a, int *n);
void print(float *a, int n);
void enterTxtFile(int &n, float *&a, char *fname);
void enterBinaryFile(int &n, float *&a, char *fname);
void printTxtFile(int n, float *a, char *fname);
void printBinaryFile(int n, float *a, char *fname);
int Menu();
int main(){
	float *a;
	int n, kt = 0, ktvb = 0, ktnp = 0;
	char *name;
    int choice;
    name = (char*)calloc(50,sizeof(char));
	a=(float*)malloc(sizeof(float));
	while (1)
    	      {
    	      	choice = Menu();
    	      	switch(choice)
    	      	      {
    	      	       case 1:{
                               nhap: enter(&a,&n);    	      	       	
							   kt = 1;
						      } break;
					   case 2:{
						       vb:  if(kt == 0)
						           {
						           	printf("BAN CHUA NHAP DAY, VUI LONG NHAP!!!");
						           	goto nhap;
								   }
								printf("Ten file can xuat day: ");
								fflush(stdin);
								gets(name);
								printTxtFile(n,a,name);
								ktvb = 1;
					          } break;	
					    case 3:{
						       np: if(kt == 0)
						           {
						           	puts("BAN CHUA NHAP DAY, VUI LONG NHAP!!!");
						           	goto nhap;
								   }
								printf("Ten file can xuat day: ");
								fflush(stdin);
								gets(name);
								printBinaryFile(n,a,name);
								ktnp = 1 ;
					          } break;
					    case 4:{
								printf("Ten file can doc day: ");
								fflush(stdin);
								gets(name);
								enterTxtFile(n,a,name);
								print(a,n);
					          } break;
					    case 5:{	    	 
								printf("Ten file can doc day: ");
								fflush(stdin);
								gets(name);
								enterBinaryFile(n,a,name);
								print(a,n);
					          } break;
					    case 6 : exit(1);
					    default: printf("NHAP SAI, NHAP LAI");
					  }
			  }
	if(a!= NULL) free(&a);
}
void enter(float **a, int *n){
	printf("Enter n: ");
	scanf("%d", n);
	*a= (float*)realloc(*a,(*n)*sizeof(float));
	for(int i=0;i<*n;i++){
		printf("a[%d]: ", i);
		scanf("%f", &*(*a+i));
	}
}
void print(float *a, int n){
	for(int i=0;i<n;i++){
		printf("%.2f\t",*(a+i));
	}
}
void enterTxtFile(int &n, float *&a, char *fname)
     { FILE *pf;
     	pf = fopen(fname,"r");
     	if( pf == NULL)
     	  {
     	   fprintf(stderr,"Khong the mo FILE %s",pf);
			perror("Ly do: ");	
		  }
		fscanf(pf,"%d",&n);
		a = (float*)calloc(n,sizeof(float));
		for(int i = 0 ; i < n ; i ++)
		   {
		   	fscanf(pf,"%f",&*(a+i));
		   }
		fclose(pf);
	 }
void enterBinaryFile(int &n, float *&a, char *fname)
     {
     	FILE *pf;
     		pf = fopen(fname,"rb");
     	if( pf == NULL)
     	  {
     	    fprintf(stderr,"Khong the mo FILE %s",pf);
			perror("Ly do: ");	
		  }
		fread(&n,sizeof(int),1,pf);
		a = (float*)calloc(n,sizeof(float));
		for(int i = 0 ; i < n ; i ++)
		   {
		   	fread(&*(a+i),sizeof(float),1,pf);
		   }
		fclose(pf);
	 }

void printTxtFile(int n, float *a, char *fname)
     {
     	FILE *pf;
     	pf = fopen(fname,"w");
     	if(pf == NULL)
     	  {
     	   fprintf(stderr,"Khong the mo file %s",fname);
		   perror("Ly do: ");	
		  }
		fprintf(pf,"%d",n);
		for(int i = 0 ; i < n ; i++)
		   {
		   	fprintf(pf," %.2f",*(a+i));
		   }
		fclose(pf);
	 }

void printBinaryFile(int n, float *a, char *fname)
     {
     	FILE *pf;
     	pf = fopen(fname,"wb");
     	if(pf == NULL)
     	  {
     	   fprintf(stderr,"Khong the mo file %s",fname);
		   perror("Ly do: ");	
		  }
		   fwrite(&n,sizeof(int),1,pf);
		for(int i = 0 ; i < n ; i++)
		   {
		   	fwrite((a+i),sizeof(float),1,pf);
		   }
		fclose(pf);
	 }

int Menu()
    {
    	int x;
    	printf("1. Nhay day a tu ban phim\n2. Xuat day a ra file van ban\n3. Xuat day a ra file nhi phan\n4. Doc day tu file van ban xuat ra man hinh\n5. Doc day tu file nhi phan xuat ra man hinh\n6.Thoat");
    	printf("	CHON: ");
    	scanf("%d",&x);
    	return x;
	}