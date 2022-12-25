#include"p12_warehouse.h"
int main() {
	Shop* shop = (Shop*)malloc(sizeof(Shop));
	if (shop) {
		shop->num = 0;
	}
	read(shop);
	int decision, ret;
	while (1) {
		menu();
		do {
			ret = scanf_s("%d", &decision);
			if (ret < 1 || getchar() != '\n')
			{
				ret = -1;; while (getchar() != '\n'); printf("error\n");
			}
		} while (ret < 1);//·ÀÖ¹·Ç·¨ÊäÈë
		switch (decision) {
		case 0:save(shop); exit(0); break;
		case 1:import(shop); break;
		case 2:_export(shop); break;
		case 3:show(shop); break;
		default:break;
		}
	}
	return 0;
}