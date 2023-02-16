//¼ÇÂ¼²½Êý
#include"wuziqi.h"
void count_step(int x, int y,int color) {
	TCHAR stepch[10];
	step++;

	stackpush(stack, x);
	stackpush(stack, y);
	if (step%2 == 1) {
		settextcolor(RGB(255, 255, 255));
	}
	else{
		settextcolor(RGB(0, 0, 0));
	}

	_stprintf_s(stepch, _T("%d"), step);
	if (step >= 100){
		LOGFONT f;
		gettextstyle(&f);
		f.lfHeight = 13;
		f.lfQuality = ANTIALIASED_QUALITY;
		settextstyle(&f);
		setbkmode(TRANSPARENT);
		outtextxy((y + 1) * 50 - 30, (x + 1) * 50 - 6, stepch);
	}
	else if (step >= 10){
		LOGFONT f;
		gettextstyle(&f);
		f.lfHeight = 20;
		f.lfQuality = ANTIALIASED_QUALITY;
		settextstyle(&f);
		setbkmode(TRANSPARENT);
		outtextxy((y + 1) * 50 - 20, (x + 1) * 50 - 11, stepch);
	}
	else{
		outtextxy((y + 1) * 50 - 9, (x + 1) * 50 - 20, stepch);
	}
}