#include <stdio.h>
#define MAX 15
typedef struct pushboxes
{
	int x_now, y_now;//��Ŀǰλ��
	int X_now, Y_now;//����Ŀǰλ��
	int X, Y;//����Ŀ��λ��
	int len, wid;//��ͼ�ĳ�����
	int map_data[MAX][MAX];//��¼����λ���ϵ�����
	char map_dataprint[MAX][MAX];
	int grades;
}pushboxes;

int read(pushboxes* boxes);
void printPushboxes1(pushboxes* boxes);
void printPushboxes2(pushboxes* boxes);
void findPosition(pushboxes* boxes);
void ChangePosition(pushboxes* boxes);
void RecordFile(pushboxes* boxes);
