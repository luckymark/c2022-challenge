#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define LEN 30
typedef struct item {
    char model[LEN];
    int amount;
}Item;
typedef struct node {
    Item cargo;
    struct node* next;
}Node;
typedef struct list {
    Node* head;
    Node* end;
}List;
void showMenu(void);
void initializeList(List* plist);
char* fsgets(char* st, int n, FILE* fp);                      //scanf和fgets对多个单词的字符串处理都不理想
bool listIsEmpty(List* plist);
void addItem(Item cargo, List* plist);
void show(List* plist);
void deleteItem(char* model, List* plist);
void importData(List* plist);
void saveData(List* plist);
bool beenInitialized;

int main(void) {
    beenInitialized = false;
    List repo;
    char input;
    bool status = true;
    while (status) {                           //实际上处理非法输入要花挺多力气，这里没要求就不多写了
        showMenu();
        scanf("%c", &input);
        getchar();                                   //处理缓冲区换行符
        switch (input) {
        case '1':
            initializeList(&repo);
            break;
        case '2': {
            Item cargo;
            puts("enter the product model:");
            scanf("%s", cargo.model);
            puts("enter the amount:");
            scanf("%d", &cargo.amount);
            getchar();                                //处理换行符
            addItem(cargo, &repo);
            break;
        }
        case '3':
            show(&repo);
            break;
        case '4': {
            char model[LEN];
            puts("enter the product model:");
            fsgets(model, LEN, stdin);
            deleteItem(model, &repo);
            break;
        }
        case '5':
            importData(&repo);
            puts("existing data has been added!");
            break;
        case '6':
            status = false;
            saveData(&repo);
            break;
        default:
            puts("please enter 1,2,3,4 or 5");
            break;
        }
    }
    return 0;
}

void showMenu(void) {
    puts("enter your choice:");
    puts("1: initialize the list to be empty");
    puts("2: add new cargo");
    puts("3: show all the existing cargo");
    puts("4: take out existing cargo");
    puts("5: import existing data");
    puts("6: save the data and exit");
}
void initializeList(List* plist) {
    (*plist).head = NULL;
    (*plist).end = NULL;
    beenInitialized = true;
}
char* fsgets(char* st, int n, FILE* fp) {
    char* ret;
    char* find;
    ret = fgets(st, n, fp);
    if (ret) {
        find = strchr(st, '\n');
        if (find) {
            *find = '\0';
        }
        else {
            while (getchar() != '\n') {
                continue;
            }
        }
    }
    return ret;
}
bool listIsEmpty(List* plist) {
    return ((*plist).head == NULL) ? true : false;
}
void addItem(Item cargo, List* plist) {
    if (!beenInitialized) {
        puts("you haven't initialized!");
        return;
    }
    Node* pnew = (Node*)malloc(sizeof(Node));
    if (pnew == NULL) {
        puts("can't create new item!");
        return;
    }
    strcpy(pnew->cargo.model, cargo.model);
    pnew->cargo.amount = cargo.amount;
    pnew->next = NULL;
    if ((*plist).head == NULL) {
        (*plist).head = (*plist).end = pnew;
    }
    else {
        (*plist).end->next = pnew;
        (*plist).end = pnew;
        (*plist).end->next = NULL;
    }
    return;
}
void show(List* plist) {
    if (!beenInitialized) {
        puts("you haven't initialized!");
        return;
    }
    Node* pnode = (*plist).head;
    if (listIsEmpty(plist)) {
        puts("the list is empty!");
        return;
    }
    while (pnode != NULL) {
        printf("there are %d items of product model %s.\n", pnode->cargo.amount, pnode->cargo.model);
        pnode = pnode->next;
    }
    return;
}
void deleteItem(char* model, List* plist) {
    if (!beenInitialized) {
        puts("you haven't initialized!");
        return;
    }
    if (listIsEmpty(plist)) {
        puts("the list is empty!");
        return;
    }
    Node* pnode = (*plist).head;
    Node* psave = pnode;
    if ((strcmp(model, pnode->cargo.model)) != 0) {          //先把pnode后移一位才能让psave保存上一个节点的地址
        pnode = pnode->next;
    }
    else {                                           //head指向的恰好为待删除的item
        (*plist).head = (*plist).head->next;
        free(pnode);
        puts("succeed in deleting the item!");
        return;
    }
    while (pnode != NULL) {
        if ((strcmp(model, pnode->cargo.model)) != 0) {
            pnode = pnode->next;
            psave = psave->next;
        }
        else {
            psave->next = pnode->next;
            free(pnode);
            puts("succeed in deleting the item!");
            return;
        }
    }
    puts("there is no such item!");
    return;
}
void importData(List* plist) {
    if (!beenInitialized) {
        puts("you haven't initialized!");          //注意：这里import是个可选项，所以必须initialize之后才可以载入文件中的数据
        return;
    }
    FILE* fp = fopen("repo.txt", "r");
    if (fp == NULL) {
        puts("can't open the file");
        return;
    }
    if ((getc(fp)) == EOF) {
        puts("there's nothing in the warehouse!");
    }
    else {
        char ending;
        do {
            Item temp;
            while ((ending=getc(fp)) != ':'&&ending!=' '&&ending!='\0'&&ending!=EOF) {
                continue;
            }
            fsgets(temp.model, LEN, fp);
            while ((ending=getc(fp)) != ':'&&ending!=' ' && ending != '\0' && ending != EOF) {
                continue;
            }
            fscanf(fp, "%d", &temp.amount);
            addItem(temp, plist);
            ending = getc(fp);
        } while ((ending=getc(fp)) != EOF&&ending!=' ' && ending != '\0');                             //同时可以处理掉amount行最后的换行符
    }
    fclose(fp);
}
void saveData(List* plist) {
    if (plist == NULL) {
        exit(0);
    }
    FILE* fp = fopen("repo.txt", "w");             //"w"清空原文件内容，防止重复
    if (fp == NULL) {
        puts("can't open the file");
    }
    else {        
        Node* pnode = (*plist).head;
        while (pnode != NULL) {
            fprintf(fp, "model:%s\n", pnode->cargo.model);
            fprintf(fp, "amount:%d\n", pnode->cargo.amount);
            pnode = pnode->next;
        }
    }
    return;
}