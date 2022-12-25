#pragma once
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