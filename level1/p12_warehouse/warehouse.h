

#ifndef RUNNING_C_WAREHOUSE_H
#define RUNNING_C_WAREHOUSE_H


typedef struct Item_struct
{
    // ID
    char Item_Id[50];
    // 商品名
    char Item_Name[50];
    // 库存量
    int Item_Amount;
    // 价格
    float Item_Price;
}Item_struct,*pItem_data;

typedef struct Item_ListNode{

    Item_struct Item_data;
    struct Item_ListNode *Next;

}Item_ListNode,*pItem_ListNode;

void menu();
void rootMenu();//打印用户界面
void backRootMenu();//返回用户界面
void List_To_File(pItem_ListNode pHead);
pItem_ListNode File_To_List(); //文件传到链表;

void init_Items();//初始化商品
void Show_Items();
void save_NewItems();
void get_Items();

#endif //RUNNING_C_WAREHOUSE_H
