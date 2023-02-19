#include<stdio.h>
#include<windows.h>

const int max = 1000;

typedef struct {
	char name[21];
	int amount;
}Goods;
typedef struct {
	Goods goods[max];
	int num;
}Shop;

void read(Shop* shop);
void save(Shop* shop);
int searchGoods(Shop* shop, char name[21]);
void _export(Shop* shop);
void show(Shop* shop);
void import(Shop* shop);
void menu(void);
int main() {
	Shop* shop=(Shop*)malloc(sizeof(Shop));
	if (shop) {
		shop->num = 0;
	}
	read(shop);
	int decision,ret;
	while (1){
		menu(); 
		do {
			ret=scanf_s("%d", &decision);
			if (ret < 1|| getchar() != '\n')
			{
				ret = -1;; while (getchar() != '\n'); printf("error\n");
			}
		} while (ret<1);//·ÀÖ¹·Ç·¨ÊäÈë
		switch (decision){
		case 0:save(shop); exit(0); break;
		case 1:import(shop);break;
		case 2:_export(shop);break;
		case 3:show(shop);break;
		default:break;
		}
	}
	return 0;
}
void read(Shop* shop) {
	FILE* fp;
	fopen_s(&fp, "C:\\Users\\86134\\source\\repos\\warehouse\\record.txt", "r");
	if (fp == NULL) {
		printf("fail\n");
		system("pause");
		exit(-1);
	}
	for (int i = 0; feof(fp) == 0; ++i) {
		fscanf_s(fp, "%s %d\n", shop->goods[i].name, 21, &shop->goods[i].amount);
		++shop->num;
	}
	fclose(fp);
}
void save(Shop* shop) {
	FILE* fp;
	fopen_s(&fp, "C:\\Users\\86134\\source\\repos\\warehouse\\record.txt", "w");
	if (fp == NULL) {
		printf("fail");
		system("pause");
		exit(-1);
	}
	for (int i = 0; i < shop->num; ++i) {
		fprintf(fp, "%s %d\n", shop->goods[i].name, shop->goods[i].amount);
	}
	fclose(fp);
}
void show(Shop* shop) {
	system("cls");
	if (shop->num == 0) {
		printf("empty\n");
	}
	else {
		for (int i = 0; i < shop->num; ++i)
		{
			printf("name:");
			printf("%s ", shop->goods[i].name);
			printf("amount:");
			printf("%d\n", shop->goods[i].amount);
		}
	}
	system("pause");
}
int searchGoods(Shop* shop, char name[21]) {
	int i;
	for (i = 0; i < shop->num; ++i) {
		if (strcmp(shop->goods[i].name, name) == 0) {
			return i;
		}
	}
	if (i == shop->num) { return -1; }
}

void _export(Shop* shop) {
	int ifContinue = 0;
	do {
		system("cls");
		printf("cin>>name less than 20 character\n");
		char name[21];
		int ifError;
		do {
			ifError = scanf_s("%s", name, 21);
			while ((getchar() != '\n'));
			if (ifError < 1) { printf("error\n"); }
		} while (ifError < 1);
		int i = searchGoods(shop, name);
		if (i == -1) {
			system("cls");
			printf("none\n");
			system("pause");
		}
		else {
			printf("cin>>amount out\n");
			int ret;
			do {
				int n;
				ret = scanf_s("%d", &n);
				int nowamount = shop->goods[i].amount - n;
				if (ret < 1 || getchar() != '\n')
				{
					ret = -1;   while (getchar() != '\n'); printf("error\n");
				}
				else if (nowamount < 0) { ret = -1; printf("error\n"); }
				else { shop->goods[i].amount = nowamount; }
			} while (ret < 1);
		}
		system("cls");
		printf("continue? 1.yes 0.no\n");
		int ret;
		do {
			ret = scanf_s("%d", &ifContinue);
			if (ret < 1) { while (getchar() != '\n'); printf("error\n"); }
			else if (getchar() != '\n') { ret = -1; printf("error\n"); }
		} while (ret < 1);
	} while (ifContinue == 1);
}
void menu(void) {
	system("cls");
	printf("0.exit\n1.import\n2.export\n3.show record\n");
}
void import(Shop* shop) {
	if (shop->num == max) {
		system("cls");
		printf("full\n");
		system("pause");
	}
	else {
		int ifContinue = 0;
		do {
			system("cls");
			printf("cin>>name less than 20 character\n");
			int ifError;
			do {
				ifError = scanf_s("%s", shop->goods[shop->num].name, 21);
				while ((getchar() != '\n'));
				if (ifError < 1) { printf("error\n"); }
			} while (ifError < 1);
			printf("cin>>amount in\n");
			int ret;
			do {
				ret = scanf_s("%d", &shop->goods[shop->num].amount);
				if (ret < 1 || getchar() != '\n')
				{
					ret = -1; while (getchar() != '\n'); printf("error\n");
				}
			} while (ret < 1);
			++shop->num;

			system("cls");
			printf("continue? 1.yes 0.no\n");
			do {
				ret = scanf_s("%d", &ifContinue);
				if (ret < 1) { while (getchar() != '\n'); printf("error\n"); }
				else if (getchar() != '\n') { ret = -1; printf("error\n"); }
			} while (ret < 1);
		} while (ifContinue == 1);
	}
}