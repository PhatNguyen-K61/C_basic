#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Book{
    char name[30];
    char author[30];
    int publicYear;
};
void enter(Book *input);
void enter(Book *&input, int &numberbooks);
void print(Book *output);
void print(Book *output, int numberbooks);
int check(Book *input, int numberbooks);
void printPublicYear(Book *output, int numberbooks);
void menu(Book *output, int numberbooks);
int main(){
    Book *book;
    int numberbooks;
    book = (Book *)malloc(sizeof(Book));
    menu(book, numberbooks);
    free(book);
    return 0;
}
void enter(Book *input){
    printf("\nNhap ten sach: ");
    fflush(stdin);
    gets(input->name);
    printf("Nhap ten tac gia: ");
    gets(input->author);
    printf("Nhap nam xuat ban: ");
    scanf("%d", &input->publicYear);
}
void enter(Book *&input, int &numberbooks){
    printf("\nNhap so cuon sach: ");
    scanf("%d", &numberbooks);
    input = (Book *)realloc(input, (numberbooks) * sizeof(Book));
    for(int i=0; i<numberbooks; i++){
        printf("\n Nhap thong tin cuon sach %d", i+1);
        enter(&*(input+i));
    }
}
void print(Book *output, int numberbooks){
    for(int i=0; i<numberbooks; i++){
        printf("\nTen sach: %s, ten tac gia: %s, nam xuat ban: %d", (output+i)->name, (output+i)->author, (output+i)->publicYear);
    }
}
int check(Book *input, int numberbooks){
    int count=0;
    char author_name[30];
    printf("\nNhap ten tac gia can tim: ");
    fflush(stdin);
    gets(author_name);
    for(int i=0; i<numberbooks; i++){
        if(strcmp(author_name, (input+i)->author)==0){
            count++;
        }
    }
    return count;
}
void printPublicYear(Book *output, int numberbooks){
    int year;
    printf("\nNhap nam xuat ban can tim: ");
    scanf("%d", &year);
    for(int i=0; i<numberbooks; i++){
        if(year == (output+i)->publicYear){
            printf("\nTen sach: %s, ten tac gia: %s, nam xuat ban: %d", (output+i)->name, (output+i)->author, (output+i)->publicYear);
        }
    }
}
void menu(Book *output, int numberbooks){
    int choise;
    do{
        printf("\n--------------------------Menu------------------------------\n");
        printf("1. Nhap thong tin sach.\n");
        printf("2. Xuat thong tin sach\n");
        printf("3. Nhap vao ten mot tac gia đem xem tac gia cua bao nhieu cuon\n");
        printf("4. Thong ke theo nam xuat ban\n");
        printf("Nhap 0 de thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choise);
        switch(choise){
            case 0:
            return;
            case 1:
            enter(output, numberbooks);
            break;
            case 2:
            print(output, numberbooks);
            break;
            case 3:
            printf("Tac gia co %d sach", check(output, numberbooks));
            break;
            case 4:
            printPublicYear(output, numberbooks);
            break;
            default:
            printf("\nHay nhap lai!");
            break;
        }
    }while(choise);
}