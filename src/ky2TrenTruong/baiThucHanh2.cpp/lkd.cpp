#include<stdio.h>
#include<stdlib.h>
// Tạo cấu trúc dữ liệu cho danh sách liên kết đơn
struct Node
{
    int item;
    Node *Next;
};
struct SingleList
{
    Node *Head;
    Node *Tail;
};
void Initialize(SingleList *&list);
Node *TaoMoi(int x);
Node *ThemDau(SingleList *&list, int x);
Node *ThemCuoi(SingleList *&list, int x);
int main(int argc, char** argv) {
    SingleList *list;
    Initialize(list);
    return 0;
}
// Khởi tạo cho pHead và pTail 
void Initialize(SingleList *&list)
{
    list=(SingleList *)malloc(sizeof(SingleList));
    list->Head=list->Tail=NULL;
}
//Tạo Node mới
Node *TaoMoi(int x){
    Node *p=(Node *)malloc(sizeof(Node));
    if(p==NULL)
    {
        printf("Loi cap bo nho");
    }
    p->item=x;
    p->Next=NULL;
    return p;
}
// Thêm Node mới vào đầu danh sách
Node *ThemDau(SingleList *&list, int x){
    Node *H=TaoMoi(x);
    if(list->Head=NULL){
        list->Head=list->Tail=H;
    }else{
        H->Next = list->Head;
        list->Head=H;
    }
}
// Thêm Node mới vào cuối danh sách
Node *ThemCuoi(SingleList *&list, int x){
    Node *H=TaoMoi(x);
    if(list->Tail=NULL){
        list->Head=list->Tail=H;
    }else{
        list->Tail->Next=H;
        list->Tail=H;
    }
}