#include "control.h"
#include"chess.h"
#include"man.h"
#include "ai.h"

void Man_AIplay()
{
	init();//init������chess��
	while (1) {
		goMan();//������man�У�����������
		if (checkOver()) {
			//chess->init();
			dispose();
			continue;
		}
		goAI();
		if (checkOver()) {
			//chess->init();
			dispose();
			continue;
		}
	}
}

void Man_ManPlay()
{
	init();
	while (1) {
		goMan();
		if (checkOver()) {
			dispose();
			continue;
		}
	}
}
