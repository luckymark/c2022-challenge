#include<stdio.h>
#include<windows.h>
const int max = 1000;
typedef struct {
	char name[20];
	int amount;
}Goods;
typedef struct Shop {
	Goods goods[max];
	int num=0;
}Shop;
void menu(void) {
	system("cls");
	printf("0.exit\n1.import\n2.export\n3.show record\n");
}
void import(Shop*shop) {
	if (shop->num = max) {
		printf("full");
	}
	else {
		system("cls");
		printf("cin>>name");
		scanf_s(" %s", shop->goods[shop->num].name, 20);
		printf("cin>>amount");
		scanf_s("%d", &shop->goods[shop->num].amount);
		++shop->num;
	}
}
int searchGoods(Shop*shop,char name[20]) {
	for (int i = 0; i < shop->num; ++i) {
		if (!strcmp(shop->goods[i].name,name) ){
			return i;
		}
		else { return 0; }
	}
	return 0;
}
void ex(Shop* shop) {
	printf("cin>>name");
	char name[20];
	scanf_s("%s", name, 20);
	int i = searchGoods(shop,name);
	if (!i) {
		printf("none");
	}
	else {
		printf("cin>>amount");
		scanf_s("%d", &shop->goods[i].amount);
	}
}
void show(Shop*shop) {
	system("cls");
	if (shop->num == 0){
		printf("empty");
	}
	else{
		for (int i = 0; i < shop->num; ++i)
		{
			printf("name:"); 
			printf("%s ", shop->goods[i].name);
			printf("amount:");
			printf("%d\n", shop->goods[i].amount);
		}
	}
}
int read(Shop*shop) {
	FILE* fp;
	 fopen_s(&fp,"record.txt", "r");
	if (!fp)
	{
		printf("fail");
		return -1;
	}
	for (int i = 0; !feof(fp); ++i)
	{
		
		fscanf_s(fp, "%s %d\n", shop->goods[i].name,20, &shop->goods[i].amount);
		
			shop->num = i + 1;
		
	}
	fclose(fp);
	return 0;
}
int save(Shop*shop) {
	FILE* fp;
	fopen_s(&fp,"record.txt", "w");
	if (!fp){
		printf("fail");
		return -1; 
	}
	for (int i = 0; !feof(fp); ++i){
		fprintf(fp, "%s %d\n", shop->goods[i].name, shop->goods[i].amount);
	}
	fclose(fp);
	return 0;
}
int main() {
	Shop* shop=(Shop*)malloc(sizeof(Shop*));
	read(shop);
	int deside;
	while (1){
		menu();
		scanf_s("%d", &deside);
		switch (deside){
		case 0:save(shop); break;
		case 1:import(shop);break;
		case 2:ex(shop);break;
		case 3:show(shop);break;
		default:printf("error");
		}
	}
	return 0;
}