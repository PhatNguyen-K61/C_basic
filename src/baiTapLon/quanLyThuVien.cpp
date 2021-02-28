#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct book_st{
    char name[30];
    char type[30];
    int price;
};
void enter(book_st *input);
void enterBooks(book_st *input, int numberBooks);
void print(book_st *input, int numberBooks);
void arrangeBook(book_st *input, int numberBooks);
int comicBooks(book_st *input, int numberBooks);
int swordHeroBooks(book_st *input, int numberBooks);
void printTypeBooks(book_st *input, int numberBooks);
void enterType(char typeBook[30]);
book_st *findBookByType(book_st *input, int numberBooks, const char typeBook[30]);
int countBooks(book_st *input, int numberBooks, const char typeBook[30]);
void exportBook(FILE *file, char *path, book_st *output, int numberBooks);
int main(){
    FILE *file;
    char *output_path=".baiTapLon/book.dat";
    book_st *bookList;
    int numberBooks = 3;
    char typeBook[30];
    bookList = (book_st *)malloc(numberBooks*sizeof(book_st));// cấp phát numberBook cuốn sách
    enterBooks(bookList,numberBooks);
    arrangeBook(bookList, numberBooks);
    print(bookList, numberBooks);
    printTypeBooks(bookList, numberBooks);
    enterType(typeBook);
    print(findBookByType(bookList, numberBooks, typeBook), countBooks(bookList, numberBooks, typeBook));
    exportBook(file,output_path,bookList,numberBooks);
}
void enter(book_st *input){
    printf("\nTen: ");
    fflush(stdin);
    gets(input->name);
    printf("The loai: ");
    gets(input->type);
    printf("Gia tien: ");
    scanf("%d", &input->price);
}
void enterBooks(book_st *input, int numberBooks){
    for(int index=0;index<numberBooks;index++){
        printf("\nNhap quyen sach %d", index+1);
        enter(input+index);
    }
}
void print(book_st *input,int numberBooks){
    if(numberBooks==0){
        printf("Khong co quyen sach thuoc the loai nay!");
    }else{
        printf("\nSTT||Ten\t\t||The loai\t\t||Gia tien");
        for(int index=0; index < numberBooks; index++){
            printf("\n00%d||%s\t\t||%s\t\t||%d",index+1,(input+index)->name,(input+index)->type,(input+index)->price);
        }
    }
}
void arrangeBook(book_st *input, int numberBooks){
    book_st temp;
    for(int i = 0; i < numberBooks-1; i++){
        for(int j = i+1; j <numberBooks; j++){
            if(strcmp((input+i)->name, (input+j)->name) < 0){
                temp = *(input+i);
                *(input+i)= *(input+j);
                *(input+j) = temp;
            }
        }
    }
}
int comicBooks(book_st *input, int numberBooks){
    int count = 0;
    for(int i=0; i < numberBooks; i++){
        if(strcmp((input+i)->type,"truyen tranh") ==0){
            count++;
        }
    }
    return count;
}
int swordHeroBooks(book_st *input, int numberBooks){
    int count = 0;
    for(int i=0; i < numberBooks; i++){
        if(strcmp((input+i)->type,"truyen kiem hiep") ==0){
            count++;
        }
    }
    return count;
}
void printTypeBooks(book_st *input, int numberBooks){
    printf("\nTruyen tranh co %d quyen sach", comicBooks(input, numberBooks));
    printf("\nTruyen kiem hiep co %d quyen sach", swordHeroBooks(input, numberBooks));
}
void enterType(char typeBook[30]){
    fflush(stdin);
    printf("\nNhap the loai: ");
    gets(typeBook);
    fflush(stdin);
}
book_st *findBookByType(book_st *input, int numberBooks, const char typeBook[30]){
    for(int i=0; i < numberBooks; i++){
        if(strcmp((input+i)->type,typeBook)==0){
            return (input+i);
        }
    }
}
int countBooks(book_st *input, int numberBooks, const char typeBook[30]){
    int count=0;
    for(int i=0; i < numberBooks; i++){
        if(strcmp((input+i)->type,typeBook)==0){
            count++;
        }
    }
    return count;
}
void exportBook(FILE *file, char *path, book_st *output, int numberBooks){
    char *mode = "a";
    file = fopen(path,mode);
    fprintf(file,"\nSTT||Ten\t\t||The loai\t\t||Gia tien");
        for(int index=0; index < numberBooks; index++){
            fprintf(file,"\n00%d||%s\t\t||%s\t\t||%d",index+1,(output+index)->name,(output+index)->type,(output+index)->price);
        }
    fclose(file);
}