#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<windows.h>
using namespace std;
struct element
{
	string name; int number;
	friend bool operator < (const element& A,const element& B)
	{
		return A.name<B.name;
	}
};
vector <element> list;
void Clear_Screen(void)
{
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}
void Display_Menu(void)
{
	Clear_Screen();
	puts("----------Menu----------");
	puts("Please enter the corresponding serial number!");
	puts("1.Display the stock list.");
	puts("2.Warehouse");
	puts("3.Out of stock");
	puts("4.Savedata&&Exit");
	puts("------------------------");
}
void Display_List(void)
{
	Clear_Screen();
	for (auto it:list)
	{
		int len=it.name.size();
		for (int i=0;i<len;++i) printf("%c",it.name[i]);
		printf(" %d\n",it.number);
	}
	Sleep(2000);
}
void Warehouse(void)
{
	Clear_Screen();
	puts("Please enter the name of the stock and its amount!");
	char s[100]; scanf("%s",s+1);
	int len=strlen(s+1),x;
	string tmp="";
	scanf("%d",&x);
	for (int i=1;i<=len;++i) tmp+=s[i];
	bool flag=0;
	for (int i=0;i<list.size()&&!flag;++i)
	{
		if (list[i].name==tmp) list[i].number+=x,flag=1;
	}
	if (!flag)
	{
		list.push_back({tmp,x});
		sort(list.begin(),list.end());
	}
}
void Dislodge(void)
{
	Clear_Screen();
	puts("Please enter the name of the stock that you need to dislodge!");
	char s[100]; scanf("%s",s+1);
	int len=strlen(s+1);
	string tmp="";
	for (int i=1;i<=len;++i) tmp+=s[i];
	bool flag=0;
	for (auto it=list.begin();it!=list.end();++it)
	{
		if (it->name==tmp)
		{
			list.erase(it);
			flag=1;
			break;
		}
	}
	if (!flag)
	{
		puts("Can't find this stock,please try again!");
		Sleep(1000);
		Dislodge();
	}
}
int main()
{
	FILE *reader=fopen("savedata.txt","r");
	char s[100];
	while (fscanf(reader,"%s",s+1)!=EOF)
	{
		int len=strlen(s+1),x;
		string tmp="";
		fscanf(reader,"%d",&x);
		for (int i=1;i<=len;++i) tmp+=s[i];
		list.push_back({tmp,x});
	}
	fclose(reader);
	bool flag=1;
	for (sort(list.begin(),list.end());flag;)
	{
		Display_Menu();
		int opt; scanf("%d",&opt);
		switch (opt)
		{
			case 1:
				Display_List(); break;
			case 2:
				Warehouse(); break;
			case 3:
				Dislodge(); break;
			case 4:
				flag=0; break;
		}
		Sleep(500);
	}
	FILE *printer=fopen("savedata.txt","w");
	for (auto it:list)
	{
		int len=it.name.size();
		for (int i=0;i<len;++i) fprintf(printer,"%c",it.name[i]);
		fprintf(printer," %d\n",it.number);
	}
	fclose(printer);
	return 0;
}