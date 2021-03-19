#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Date
{
    int day;
    int month;
    int year;
};
struct Author
{
    char name[30];
    Date *birthday;
};
struct book_st
{
    char name[30];
    Author *author;
    char type[30];
    int price;
};
void enter(Date *input);
bool validDay(Date *check);
void enter(book_st *input);
void enter(Author *input);
void enterBooks(book_st *&input, int &numberBooks);
void addBook(book_st *input, int &numberBooks, const book_st book);
void enterType(char search[30]);
int comicBooks(book_st *input, int numberBooks);
int swordHeroBooks(book_st *input, int numberBooks);
int curriculums(book_st *input, int numberBooks);
void printTypeBooks(book_st *output, int numberBooks);
void editBook(book_st *output, int numberBooks);
book_st *findBookByType(book_st *input, int numberBooks, int totalBooks, char search[30]);
int countBooksByType(book_st *input, int numberBooks, char search[30]);
void print(book_st *output, int numberBooks);
void arrangeBook(book_st *output, int numberBooks);
void exportBook(FILE *file, char *path, book_st *output, int numberBooks);
void menu(FILE *file, char *path, book_st *input, int numberBooks, int totalBooks, char search[30]);
int main()
{
    FILE *file;
    char *output_path = "./src/baiTapLon/book.dat";
    book_st *bookList;
    int numberBooks;
    int totalBooks;
    char search[30];
    bookList = (book_st *)malloc(sizeof(book_st));
    menu(file, output_path, bookList, numberBooks, totalBooks, search);
    free(bookList);
    return EXIT_SUCCESS;
}
bool validDay(Date *check)
{
    //kiểm tra ngày tháng
    bool validDay = true;
    if (check->month < 0 || check->month > 12)
    {
        validDay = false;
    }
    else
    {
        switch (check->month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (check->day < 1 || check->day > 31)
            {
                validDay = false;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (check->day < 1 || check->day > 30)
            {
                validDay = false;
            }
            break;
        case 2:
            if (check->year % 4 == 0 && check->day < 1 || check->day > 29)
            {
                validDay = false;
            }
            break;
        }
    }
    return validDay;
}
void enter(Date *input)
{
    printf("\nNgay: ");
    scanf("%d", &input->day);
    printf("Thang: ");
    scanf("%d", &input->month);
    printf("Nam: ");
    scanf("%d", &input->year);
}
void enter(Author *input)
{
    printf("\nNhap ten tac gia: ");
    gets(input->name);
    printf("-------- Nhap ngay thang nam sinh tac gia --------");
    do
    {
        input->birthday = (Date *)malloc(sizeof(Date));
        enter(input->birthday);
    } while (!validDay(input->birthday));
}
void enter(book_st *input)
{
    printf("\nTen: ");
    fflush(stdin);
    gets(input->name);
    printf("******** Nhap thong tin tac gia ********");
    input->author = (Author *)malloc(sizeof(Author));
    enter(input->author);
    fflush(stdin);
    printf("\nThe loai: ");
    gets(input->type);
    printf("Gia tien: ");
    scanf("%d", &input->price);
}
void enterBooks(book_st *&input, int &numberBooks)
{
    printf("->Nhap so cuon sach: ");
    scanf("%d", &numberBooks);
    input = (book_st *)realloc(input, (numberBooks) * sizeof(book_st));
    for (int index = 0; index < numberBooks; index++)
    {
        printf("\n++++++++ Nhap thong tin quyen sach %d ++++++++", index + 1);
        enter(&*(input + index));
    }
}
int comicBooks(book_st *input, int numberBooks)
{
    int count = 0;
    for (int i = 0; i < numberBooks; i++)
    {
        if (strcmp((input + i)->type, "truyen tranh") == 0)
        {
            count++;
        }
    }
    return count;
}
int swordHeroBooks(book_st *input, int numberBooks)
{
    int count = 0;
    for (int i = 0; i < numberBooks; i++)
    {
        if (strcmp((input + i)->type, "truyen kiem hiep") == 0)
        {
            count++;
        }
    }
    return count;
}
int curriculums(book_st *input, int numberBooks)
{
    int count = 0;
    for (int i = 0; i < numberBooks; i++)
    {
        if (strcmp((input + i)->type, "giao trinh") == 0)
        {
            count++;
        }
    }
    return count;
}
void printTypeBooks(book_st *output, int numberBooks)
{
    printf("\nTruyen tranh co %d quyen sach", comicBooks(output, numberBooks));
    printf("\nTruyen kiem hiep co %d quyen sach", swordHeroBooks(output, numberBooks));
    printf("\nGiao trinh co %d quyen sach\n", curriculums(output, numberBooks));
}
void editBook(book_st *output, int numberBooks){
    char book_name[30];
    int count = 0;
    printf("Nhap ten quyen sach can sua: ");
    fflush(stdin);
    gets(book_name);
    for(int index = 0; index < numberBooks; index++){
        if(strcmp(book_name, (output + index)->name) == 0){
            count ++;
        }
    }
    if(count != 0){
        for(int index = 0; index < numberBooks; index++){
            if(strcmp(book_name, (output + index)->name) == 0){
                printf("\n======== Sua thong tin sach ========");
                printf("\nTen: ");
                gets((output + index)->name);
                printf("******** Nhap thong tin tac gia ********");
                (output + index)->author = (Author *)malloc(sizeof(Author));
                enter((output + index)->author);
                fflush(stdin);
                printf("\nThe loai: ");
                gets((output + index)->type);
                printf("Gia tien: ");
                scanf("%d", &(output+index)->price);
                printf("\nDa hoan tat sua thong tin quyen sach nay !");
            }
        }
    }else{
        printf("\nKhong co quyen sach nay !");
    }
}
void addBook(book_st *input, int &numberBooks, const book_st book)
{
    numberBooks++;
    input = (book_st *)realloc(input, numberBooks * sizeof(book_st));
    *(input + numberBooks - 1) = book;
}
void enterType(char search[30])
{
    printf("\nNhap the loai: ");
    fflush(stdin);
    gets(search);
}
book_st *findBookByType(book_st *input, int numberBooks, int totalBooks, char search[30])
{
    book_st *result;
    book_st temp;
    totalBooks = 0;
    result = (book_st *)calloc(totalBooks, sizeof(book_st));
    for (int index = 0; index < numberBooks; index++)
    {
        if (strcmp((input + index)->type, search) == 0)
        {
            temp = *(input + index);
            addBook(result, totalBooks, temp);
        }
    }
    return result;
}
int countBooksByType(book_st *input, int numberBooks, char search[30])
{
    int count = 0;
    for (int i = 0; i < numberBooks; i++)
    {
        if (strcmp((input + i)->type, search) == 0)
        {
            count++;
        }
    }
    return count;
}
void print(book_st *output, int numberBooks)
{
    if (numberBooks == 0)
    {
        printf("Khong co quyen sach thuoc the loai nay");
    }
    else
    {
        printf("\nSTT||Ten\t\t||Tac gia\t\t\t ||The loai\t\t||Gia tien");
        for (int index = 0; index < numberBooks; index++)
        {
            printf("\n00%d||%-17s\t||%-17s(%d/ %d/ %d) ||%-17s\t||%d", (index + 1), (output + index)->name, (output + index)->author->name, (output + index)->author->birthday->day, (output + index)->author->birthday->month, (output + index)->author->birthday->year, (output + index)->type, (output + index)->price);
        }
    }
}
void arrangeBook(book_st *output, int numberBooks)
{
    book_st temp;
    for (int i = 0; i < numberBooks - 1; i++)
    {
        for (int j = i + 1; j < numberBooks; j++)
        {
            if (strcmp((output + i)->name, (output + j)->name) < 0)
            {
                temp = *(output + i);
                *(output + i) = *(output + j);
                *(output + j) = temp;
            }
        }
    }
}
void exportBook(FILE *file, char *path, book_st *output, int numberBooks)
{
    char *mode = "a";
    file = fopen(path, mode);
    fprintf(file, "\nSTT||Ten\t\t\t\t\t||Tac gia\t\t\t\t\t\t\t||The loai\t\t\t\t||Gia tien");
    for (int index = 0; index < numberBooks; index++)
    {
        fprintf(file, "\n00%d||%-20s\t||%-20s(%d/ %d/ %d) ||%-15s\t\t||%d", index + 1, (output + index)->name, (output + index)->author->name, (output + index)->author->birthday->day, (output + index)->author->birthday->month, (output + index)->author->birthday->year, (output + index)->type, (output + index)->price);
    }
    fclose(file);
}
void menu(FILE *file, char *path, book_st *input, int numberBooks, int totalBooks, char search[30])
{
    int choise;
    do
    {
        printf("\n-----------------------Menu--------------------\n");
        printf("1. Nhap du lieu cua tung quyen sach.\n");
        printf("2. Sap xep, thong kê va hien thi thong tin chi tiet cua tung quyen sach theo the loai (Z->A).\n");
        printf("3. Sua thong tin sach\n");
        printf("4. Tim  quyen sach theo the loai\n");
        printf("5. Ghi vao tap tin nhi phan book.dat.\n");
        printf("6. Thoat\n");
        printf("-------------------------------------------------\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
            enterBooks(input, numberBooks);
            break;
        case 2:
            arrangeBook(input, numberBooks);
            print(input, numberBooks);
            printTypeBooks(input, numberBooks);
            break;
        case 3:
            editBook(input, numberBooks);
            break;
        case 4:
            enterType(search);
            print(findBookByType(input, numberBooks, totalBooks, search), countBooksByType(input, numberBooks, search));
            break;
        case 5:
            exportBook(file, path, input, numberBooks);
            break;
        case 6:
            break;
        default:
            printf("Hay nhap lai\n");
            break;
        }
    } while (choise != 6);
}