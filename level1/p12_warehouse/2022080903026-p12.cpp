#include<iostream>
#include<fstream>
#include<istream>
#include<vector>
using namespace std;
void reveal_goods();
void output();
char* turn(int num);
int turn(char* ch);
void input();
struct Goods
{
	char name[10] = { 0 };
	char num[5] = { 0 };
};
const char* file_name = "warehouse.txt";
int main()
{

	while (true)
	{
		cout << "请选择功能" << endl;
		cout << "1.显示存货列表" << endl;
		cout << "2.出库" << endl;
		cout << "3.入库" << endl;
		cout << "4.退出程序" << endl;
		char bottom;
		cin >> bottom;
		switch (bottom)
		{
		case '1':
			//显示存货列表
			reveal_goods();
			break;
		case '2':
			//出库
			output();
			break;
		case '3':
			//入库
			input();
			break;
		case '4':
			//退出程序
			exit(0);
			break;
		default:

			break;
		}
	}
	return 0;
}

void reveal_goods()
{
	char ch[200] = { 0 };
	FILE* fp;
	errno_t err = fopen_s(&fp, file_name, "r");
	while (fgets(ch, 100, fp))
	{
		cout << ch << endl;
	}
	fclose(fp);
}

void output()
{
	FILE* fp;
	errno_t err = fopen_s(&fp, file_name, "r+");
	char ch [100][10] = { NULL };
	char temp;
	char name[10] = { 0 };
	char num[10] = { 0 };
	int index = -1;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if ((temp = fgetc(fp)) == ' ')
			{
				break;
			}
			if (temp == EOF)
			{
				goto mark;
			}
			ch[i][j] = temp;
		}
	}
mark:for (int i = 0;i < 100;i++)
	{
		if (ch[i][0] == '\0')
		{
			break;
		}
		cout << ch[i] << ' ';
	}
	cout << endl;
	cout << "请输入要出库的货物名称" << endl;
	cin >> name;
	cout << "请输入要出库的货物数量" << endl;
	cin >> num;
	
	for (int i = 0; i < 100; i += 2)
	{
		for (int j = 0; j < 10; j++)
		{
			if (ch[i][j] != name[j])
			{
				break;
			}
			if (name[j] == '\0')
			{
				index = i;
				break;
			}
		}
		if (index != -1)
		{
			break;
		}
	}
	for (int j = 0; j < 10; j++)
	{

	}
	int original = turn(ch[index + 1]);
	int change = turn(num);
	if (original - change <= 0)
	{
		cout << "已全部出库" << endl;
		for (int i = 0; i < 10; i++)
		{
			if (ch[index][i] == '\0')
			{
				break;
			}
			else
			{
				ch[index][i] = NULL;
			}

		}
		for (int i = 0; i < 10; i++)
		{
			if (ch[index+1][i] == '\0')
			{
				break;
			}
			else
			{
				ch[index+1][i] = NULL;
			}

		}
	}
	else
	{
		char* temp = turn(original-change);
		for (int i = 0; i < 10; i++)
		{
			ch[index + 1][i] = '\0';
			if (temp[i] == '\0')
			{
				continue;
			}
			else
			{
				ch[index + 1][i] = temp[i];
			}

		}
	}

	fclose(fp);
	err = fopen_s(&fp, file_name, "w");
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (ch[i][j] == '\0')
			{
				fputc(' ', fp);
				break;
			}
			else
			{
				fputc(ch[i][j], fp);
			}
		}

	}

	fclose(fp);

	
}

char* turn(int num)
{
	char ch[10] = { NULL };
	int temp;
	int i = 0;
	for (int i = 1; i <= 1000000000; i *= 10)
	{
		if (num / i == 0)
		{
			temp = i / 10;
			break;
		}
	}
	while (1)
	{

		ch[i] = num / temp+48;
		num = num % temp;
		if (temp == 1)
		{
			break;
		}
		temp  /= 10;
		i++;
	}
	return ch;

}

int turn(char* ch)
{
	int rs = 0;
	int index=0;
	for (int j = 0; j < 10; j++)
	{
		if (ch[j] == '\0')
		{
			break;
		}
		index++;
	}
	for (int j = index - 1; j >= 0; j--)
	{
		int num = 1;
		for (int i = 1; i <(index-j); i++)
		{
			num *= 10;
		}
		rs += (ch[j]-48) * num;
	}
	return rs;
}

void input()
{

	char name[10] = { 0 };
	char num[10] = { 0 };
	FILE* fp;
	errno_t err = fopen_s(&fp, file_name, "a+");
	cout << "请输入货物名称" << endl;
	cin >> name;
	for (int i = 0; i < 10; i++)
	{
		if (name[i] == '\0')
		{
			break;
			
		}
		fputc(name[i], fp);
	}
	fputc(' ', fp);
	cout << "请输入货物数量" << endl;
	cin >> num;
	for (int i = 0; i < 10; i++)
	{
		if (num[i] == '\0')
		{
			break;
		}
		fputc(num[i], fp);
	}
	fputc(' ', fp);
	fclose(fp);
}