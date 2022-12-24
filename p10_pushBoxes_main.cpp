#include"p10_pushBoxes.h"
char MAP1[100] = "C:\\Users\\86134\\source\\repos\\p10_pushBoxes\\p10_pushBoxes_map1.txt";
char MAP2[100] = "C:\\Users\\86134\\source\\repos\\p10_pushBoxes\\p10_pushBoxes_map2.txt";
char ar[ROW][QUEUE] ;
int main() {
	map(MAP1);
	int Goal=play();
	savegoal(Goal);
	printf("\nNext?\n1.yes 2.no\n");
	int choose = 2;
	scanf_s("%d", &choose);
	if (choose == 1) {
		map(MAP2);
		Goal=play();
		savegoal(Goal);
		return 0;
	}else{ return 0; }
}