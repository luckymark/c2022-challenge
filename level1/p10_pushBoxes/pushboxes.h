#include <stdio.h>
#define MAX 15
typedef struct pushboxes
{
	int x_now, y_now;//人目前位置
	int X_now, Y_now;//箱子目前位置
	int X, Y;//箱子目的位置
	int len, wid;//地图的长，宽
	int map_data[MAX][MAX];//记录所有位置上的物体
	char map_dataprint[MAX][MAX];
	int grades;
}pushboxes;

int read(pushboxes* boxes);
void printPushboxes1(pushboxes* boxes);
void printPushboxes2(pushboxes* boxes);
void findPosition(pushboxes* boxes);
void ChangePosition(pushboxes* boxes);
void RecordFile(pushboxes* boxes);
