#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "warehouse.h"

void main(){
    char opt_Type;
    menu();
    printf("输入1进入用户界面,请按0退出\n");
    fflush(stdout);
    scanf("%c", &opt_Type);

    while(opt_Type != '0')
    {
        if(opt_Type == '1')
        {
            backRootMenu();
            break;
        }
        scanf("%c", &opt_Type);
    }
    if(opt_Type == '0')
        printf("已退出系统！\n");
}

void menu()
{
    printf("******************                 你的仓库             ***************************\n");
    printf("*************************************************************************************\n");
    printf("                                    请选择                                           \n");
    printf("                                    0.退出                                           \n");
    printf("                                    1.用户界面                                       \n");
    printf("*************************************************************************************\n");
    printf("\n");
}

void rootMenu()
{
    printf("******************                  你的仓库                       *****************\n");
    printf("                                  1.初始化仓库                                      \n");
    printf("                                  2.入库                                           \n");
    printf("                                  3.打印已有商品                                     \n");
    printf("                                  4.出库                                           \n");
    printf("                                  5.退出                                           \n");
//    printf("                                  6.删除图书                                        \n");
//
//    printf("                                  7.打印已有商品                                    \n");
//    printf("                                  8.入库                                            \n");
//    printf("                                  9.出库                                            \n");
    printf("************************************************************************************\n");
    printf("\n");
    fflush(stdout);
}

void init_Items() {

    Item_struct Item_Info;

    FILE *fp;
    int Type_Num=999;
    char Temp;

    printf("请输入商品种类数目\n");
    fflush(stdout);

    do {
        fflush(stdin);
        scanf("%[1-9]", &Temp);

    }while(Temp<'1'||Temp>'9');

    Type_Num = Temp - '0';
    fp=fopen("Items.txt","w");
    assert((fp!=NULL)||fp!=0);

    for (int i=1;i<=Type_Num;i++){
        printf("请输入第%d种商品的\nid   商品名称   数量   单价: ",i);
        fflush(stdout);
        scanf("%s%s%d%f",
              Item_Info.Item_Id,
              Item_Info.Item_Name,
              &Item_Info.Item_Amount,
              &Item_Info.Item_Price
              );

        fprintf(fp, "%-20s%-15s%-14d%-12.2f\n",
                Item_Info.Item_Id,
                Item_Info.Item_Name,
                Item_Info.Item_Amount,
                Item_Info.Item_Price
                );
    }
fclose(fp);
}

void Show_Items(){
    FILE *fp;
    fp = fopen("Items.txt","r");
    if(!fp)
    {
        printf("无法打开文件\n");
        exit(0);
    }

    Item_struct Item_Info;

    while(fscanf(fp,"%s%s%d%f",
                 Item_Info.Item_Id,
                Item_Info.Item_Name,
                &Item_Info.Item_Amount,
                &Item_Info.Item_Price)!=EOF)
    {
        printf("%-20s%-15s%-14d%-12.2f\n",Item_Info.Item_Id,Item_Info.Item_Name,Item_Info.Item_Amount,Item_Info.Item_Price);
        fflush(stdout);
    }

    fclose(fp);

}

void backRootMenu(){

FILE *fp;
char opt_Select='999';

    while(opt_Select!='0'){
        rootMenu();
        printf("请选择操作\n");
        fflush(stdout);

        do {
            fflush(stdin);
            printf("请输入正确数字后,点击Enter:");
            fflush(stdout);
            scanf("%c", &opt_Select);
        }  while(opt_Select>'5'||opt_Select<'1');



        fp = fopen("Items.txt","r");
        if((opt_Select>'2'&&opt_Select<'5')&&(fp==NULL||fgetc(fp)==EOF)){
            printf("库存为空建议先入库或初始化\n点击Enter继续\n");
            fflush(stdout);
            fflush(stdin);
            getchar();
            continue;
        }
        else{
            switch(opt_Select){
                case '1':
                   init_Items();
                   printf("数据已储存,输入Enter返回\n");
                   fflush(stdout);
                   getchar();
                   getchar();
                    break;
                case '2':
                    save_NewItems();break;
                case '3':
                    Show_Items();
                    printf("Enter返回用户目录\n");
                    fflush(stdout);
                    getchar();
                    getchar();
                    break;
                case '4':
                    get_Items();
                    getchar();
                    getchar();
                    break;

                case '5':opt_Select=0;break;
            }
        }
        fclose(fp);
    }
    putchar('\n');
    printf("已退出系统"); //输入为0
}

void save_NewItems() {


    pItem_ListNode pNew,pTail,pHead;
    pHead = File_To_List();

    int Type_Num;

    printf("请输入商品种类数目\n");
    fflush(stdout);
    fflush(stdin);
    scanf("%*[^0-9]%d", &Type_Num, &Type_Num);

//    fp = fopen("Items.txt", "w");
//    assert((fp != NULL) || fp != 0);
    char Temp[Type_Num][50];

    for (int i=1;i<=Type_Num;i++) {//循环Type_Num次输入
        pTail=pHead->Next;//确保每一次循环都是重新循环

        printf("请输入要入库的第%d种商品名称:\n", i);
        fflush(stdout);
        scanf("%s", Temp[i - 1]);

        int length = strlen(Temp[i-1]);
        int flag=0;

        do { //先遍历一遍检查有没有该商品
            if (pTail!=NULL)
            {
                if (strncmp(pTail->Item_data.Item_Name, Temp[i - 1], length) == 0) {
                    flag = 1;//标记有此商品
                    printf("该商品已存在\n请问需要入库多少件？\n");
                    fflush(stdout);
                    int save_ItemNum;
                    scanf("%d", &save_ItemNum);

                    pTail->Item_data.Item_Amount += save_ItemNum;
                } else {
                    pTail = pTail->Next;
                }
            }
        }while(pTail!=NULL&&pTail->Next!=NULL&&flag==0);

        if(flag==0){//如果没有该商品
            printf("请输入要入库商品\'%s\'的\nid   数量   单价: ",Temp[i-1]);
            fflush(stdout);

            pNew=(pItem_ListNode)malloc(sizeof(Item_ListNode));//分配新节点

            pTail=pHead;
            pTail->Next=pNew;
            scanf("%s%d%f",
                  pNew->Item_data.Item_Id,
                  &pNew->Item_data.Item_Amount,
                  &pNew->Item_data.Item_Price
            );
            strcpy(pNew->Item_data.Item_Name,Temp[i-1]);//不懂为什么不可以直接赋值，所以用这个
            pNew->Next=NULL;
            pTail = pNew;
        }
        List_To_File(pHead);

        Show_Items();
        printf("已入库\n");
        getchar();
    }

}

void get_Items(){
    int Item_Type_Num=0;

    printf("目前已有库存: \n");
    fflush(stdout);
    Show_Items();

    printf("请输入要取出的商品种类\n");
    fflush(stdout);
    fflush(stdin);
    scanf("%*[^0-9]%d",&Item_Type_Num,&Item_Type_Num);

    char Temp[Item_Type_Num][50];

    for (int i=1;i<=Item_Type_Num;i++){
        printf("请输入要取出的第%d种商品ID或名称:\n",i);
        fflush(stdout);
        fflush(stdin);
        scanf("%s",Temp[i-1]);


    }

    pItem_ListNode p1,p2,pHead;
    pHead = File_To_List();
    p1=pHead->Next;
    p2=pHead;

    for(int i=1;i<=Item_Type_Num;i++){
        int length = strlen(Temp[i-1]);
        int flag=0;
        do{

            if (strncmp(p1->Item_data.Item_Id, Temp[i - 1],length)==0||strncmp(p1->Item_data.Item_Name,Temp[i - 1],length)==0) {
                flag=1;//标记有此商品
                int getItemCount;

               printf("请输入商品\'%s\'要取出的数目\n",Temp[i-1]);
               fflush(stdout);
               scanf("%d",&getItemCount);

               p1->Item_data.Item_Amount-=getItemCount;

               if(p1->Item_data.Item_Amount<=0){
                   printf("已取出商品\"%s\"%d件\n输入Enter返回\n",Temp[i-1],getItemCount+p1->Item_data.Item_Amount);
                   fflush(stdout);
               }
                printf("已取出商品\"%s\"%d件\n输入Enter返回\n",Temp[i-1],getItemCount);
               fflush(stdout);


               if(p1->Item_data.Item_Amount<=0){  //商品数为 0 删除商品
                   while(p2->Next!=p1){
                       p2=p2->Next;
                    }
                   p2->Next=p1->Next;
                   free(p1);
               }
            }

            else { p1 = p1->Next;}
        }while(p1!=NULL&&p1->Next!=NULL&&flag==0);

        if(flag==0){
            printf("查无ID或商品名称为%s的商品\n输入Enter返回\n",Temp[i-1]) ;
            fflush(stdout);
        }
    }
    List_To_File(pHead);
}

pItem_ListNode File_To_List(){
    pItem_ListNode pHead,pNew = NULL,pTail = NULL;
    pHead =(pItem_ListNode) malloc(sizeof(Item_ListNode));
    Item_struct Item_Data;

    pHead->Next=NULL;
    pTail=pHead;
    FILE *fp = fopen("Items.txt","r");
    while(fscanf(fp,"%s%s%d%f",Item_Data.Item_Id,Item_Data.Item_Name,&Item_Data.Item_Amount,&Item_Data.Item_Price)!=EOF)
    {
        pNew = (pItem_ListNode) malloc(sizeof(Item_ListNode));
        pNew->Item_data=Item_Data;

        pTail->Next=pNew;
        pNew->Next=NULL;
        pTail=pNew;

    }
    fclose(fp);
    return pHead;
}

void List_To_File(pItem_ListNode pHead){

    pItem_ListNode pTemp = pHead;

    FILE *fp = fopen("Items.txt","w");

    while((pTemp->Next)!=NULL) {
        pTemp = pTemp->Next;
        fprintf(fp, "%-20s%-15s%-14d%-12.2f\n",
                pTemp->Item_data.Item_Id,
                pTemp->Item_data.Item_Name,
                pTemp->Item_data.Item_Amount,
                pTemp->Item_data.Item_Price
        );
    }
    fclose(fp);
}
