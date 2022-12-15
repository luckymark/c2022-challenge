#include"warehouse.h"


typedef struct Inform
{
	char name[20];
	char size[20];
	int num;
}cargoinform;

typedef struct Cargo
{
	cargoinform cargo[100];
	int n;
}cargo;


int Find_Cargo(const cargo* pc, char* name, char* size);
int Find_Cargo(const cargo* pc, char* name, char* size) {
	for (int i = 0; i < pc->n; i++) {
		if (0 == strcmp(pc->cargo[i].name, name) && 0 == strcmp(pc->cargo[i].size, size)) {
			return i;
		}
	}
	return -1;
}



void Init_Cargo(cargo* pc);
void Init_Cargo(cargo* pc) {
	pc->n = 0;
	memset(pc->cargo, 0, sizeof(pc->cargo));
	FILE* fp;

	fopen_s(&fp, "C:\\Users\\dell\\Desktop\\Github\\c2022-challenge\\level1\\p12_warehouse\\inform.txt", "rb");
	if (fp == NULL) {
		printf("error\n");
		return;
	}
	cargoinform buf = { 0 };
	while (fread(&buf, sizeof(cargoinform), 1, fp)) {
		pc->cargo[pc->n++] = buf;
	}
	fclose(fp);
	fp = NULL;
}

void Add_Cargo(cargo* pc);
void Add_Cargo(cargo* pc) {

	printf("Enter the name:\n");
	cin >> pc->cargo[pc->n].name;

	printf("Enter the size:\n");
	cin >> pc->cargo[pc->n].size;

	printf("Enter the num:\n");
	cin >> pc->cargo[pc->n].num;

	int pos = Find_Cargo(pc, pc->cargo[pc->n].name, pc->cargo[pc->n].size);
	if (pos == -1) {
		pc->n++;
	}
	else {
		pc->cargo[pos].num += pc->cargo[pc->n].num;
	}

}

void Print_Cargo(const cargo* pc);
void Print_Cargo(const cargo* pc) {
	printf("%-15s %-10s %-10s\n", "名称", "型号", "数量");
	for (int i = 0; i < pc->n; i++) {
		printf("%-15s %-15s %-15d\n", pc->cargo[i].name, pc->cargo[i].size, pc->cargo[i].num);
	}
	system("pause");
}



void Search_Cargo(const cargo* pc);
void Search_Cargo(const cargo* pc) {
	char name[20], size[20];

	printf("Enter Name:\n");
	cin >> name;

	cout << "Enter Size:" << endl;
	cin >> size;

	int pos = Find_Cargo(pc, name, size);
	if (pos == -1)
	{
		printf("None\n");
	}
	else
	{
		printf("%-15s %-15s %-15s\n", "名称", "型号", "数量");
		printf("%-15s %-15s %-15d\n", pc->cargo[pos].name, pc->cargo[pos].size, pc->cargo[pos].num);
	}
	system("pause");
}

void Out_Cargo(cargo* pc);
void Out_Cargo(cargo* pc) {
	char name[20], size[20];
	int outnum = 0;

	printf("Enter Name:\n");
	cin >> name;

	cout << "Enter Size" << endl;
	cin >> size;

	printf("Enter Num:\n");
	scanf_s("%d", &outnum);

	int pos = Find_Cargo(pc, name, size);
	if (pos == -1)
	{
		printf("None\n");
	}
	else
	{
		pc->cargo[pos].num -= outnum;
	}
}

void Delect_Cargo(cargo* pc);
void Delect_Cargo(cargo* pc) {
	char name[20], size[20];

	printf("Enter delete name:\n");
	cin >> name;

	cout << "Enter delete size:" << endl;
	cin >> size;

	int pos = Find_Cargo(pc, name, size);
	if (pos == -1) {
		printf("None\n");
	}
	else {
		for (int i = pos; i < pc->n - 1; i++) {
			pc->cargo[i] = pc->cargo[i + 1];
		}
		pc->n--;
	}
}

void Sort_Cargo(cargo* pc);
void Sort_Cargo(cargo* pc) {
	if (pc->n == 0) {
		printf("None\n");
	}
	else {
		for (int i = 0; i < pc->n - 1; i++) {
			for (int j = 0; j < pc->n - 1 - i; j++) {
				if ((strcmp(pc->cargo[j].name, pc->cargo[j + 1].name)) > 0) {
					cargoinform t = pc->cargo[j];
					pc->cargo[j] = pc->cargo[j + 1];
					pc->cargo[j + 1] = t;
				}
			}
		}
	}
}

void Save_inform(cargo* pc);
void Save_inform(cargo* pc) {
	FILE* fp;
	fopen_s(&fp, "C:\\Users\\dell\\Desktop\\Github\\c2022-challenge\\level1\\p12_warehouse\\inform.txt", "wb");
	if (fp == NULL) {
		perror("Save");
		printf("保存失败\n");
		return;
	}
	for (int i = 0; i < pc->n; i++) {
		fwrite(&pc->cargo[i], sizeof(cargoinform), 1, fp);
	}
	fclose(fp);
	fp = NULL;
}

void menu();
void menu() {

	printf("1.显示库存\n");
	printf("2.实现入库\n");
	printf("3.实现出库\n");
	printf("4.查找货物\n");
	printf("5.排序货物\n");
	printf("6.完事退出\n");
	return;
}

int main() {
	int input = 0;
	Cargo thecargo;

	Init_Cargo(&thecargo);

	do {
		system("cls");
		menu();
		printf("Enter Your Choice:\n");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:Print_Cargo(&thecargo); break;
		case 2:Add_Cargo(&thecargo); break;
		case 3:Out_Cargo(&thecargo); break;
		case 4:Search_Cargo(&thecargo); break;
		case 5:Sort_Cargo(&thecargo); break;
		case 6:Save_inform(&thecargo); exit(0); break;
		default:printf("非法输入\n"); break;
		}
	} while (input);

	return 0;
}
