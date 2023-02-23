#include "control.h"
#include"chess.h"
#include"man.h"
#include "ai.h"

void Man_AIplay()
{
	init();//init定义在chess中
	while (1) {
		goMan();//定义在man中，让真人走棋
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
