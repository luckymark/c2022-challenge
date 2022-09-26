#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int father_age,son_age;
	int child,teenager,single;
	int ans;
	for(int father_age=20;father_age<=100;father_age++)
	{
		child=father_age/6;
		teenager=father_age/12;
		single=father_age/7;
		if(child+teenager+single+5+father_age/2+4==father_age)
		{
			ans=father_age-4;
		}
	}
	cout<<"¶ù×ÓËÀÊ±¶ª·¬Í¼"<<ans<<"Ëê";
	return 0;
}
