#include<stdio.h>
#include<windows.h>
int main()
{
	int speed = 1;
	int head = 1;
	while (1)
	{
		for (int i = 0; i < head; i++)
		{
			putchar(' ');
		}
		putchar('#');
		head+=speed;
		if (head == 0 || head == 100)
		{
			speed = -speed;
		}
		Sleep(20);
		system("cls");
	}
	return 0;
}