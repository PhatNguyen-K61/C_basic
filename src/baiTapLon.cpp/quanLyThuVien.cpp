#include<stdio.h>
#include<stdlib.h>
struct book_st{
    char name[30];
    char type[30];
    int price;
};
void enter(book_st *input);
void enterBooks(book_st *input, int numberBooks);
void print(book_st *input, int numberBooks);
int main(){
    book_st *bookList;
    int numberBooks = 3;
    bookList = (book_st *)malloc(numberBooks*sizeof(book_st));// cấp phát numberBook cuốn sách
    enterBooks(bookList,numberBooks);
    print(bookList, numberBooks);
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
    printf("STT||Ten\t\t||The loai\t\t||Gia tien");
    for(int index=0; index < numberBooks; index++){
        printf("\n00%d||%s\t\t||%s\t\t||%d",index+1,(input+index)->name,(input+index)->type,(input+index)->price);
    }
}