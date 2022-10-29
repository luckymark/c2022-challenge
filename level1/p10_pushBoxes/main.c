#include"pushboxes.h"
int main(void)
{
	pushboxes *boxes=NULL;
	struct pushboxes mallocbox;
	boxes = (pushboxes*)malloc(sizeof(mallocbox));
	int read(pushboxes * boxes);
	void printPushboxes1(pushboxes * boxes);
	void printPushboxes2(pushboxes * boxes);
	void findPosition(pushboxes * boxes);
	void ChangePosition(pushboxes * boxes);
	void RecordFile(pushboxes * boxes);
	free(boxes);
	system("pause");
	return 0;
}