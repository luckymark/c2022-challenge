#include<bits/stdc++.h>
using namespace std;
int ans[21],cnt;
typedef struct list{
	int num;
	int i;
	struct list *next;
}LI;
void link_creat_head(LI **p_head,LI *p_new)
{
	LI *p_mov=*p_head;
	if(*p_head==NULL)
	{
		*p_head=p_new;
		p_new->next=NULL;
	}
	else
	{
		while(p_mov->next!=NULL)
			p_mov=p_mov->next;
		p_mov->next=p_new;
		p_new->next=NULL;
	}
}
void link_print(LI *head)
{
	LI *p_mov;
	p_mov=head;
	while(p_mov!=NULL)
	{
		cout<<p_mov->num<<" ";
		p_mov=p_mov->next;
	}
	cout<<endl;
}
void link_reversal(LI **p_head)
{
	LI *p_cur=*p_head,*p_pre=NULL,*p_tmp=NULL;
	while(p_cur->next!=NULL)
	{
		p_tmp=p_cur->next;
		p_cur->next=p_pre;
		p_pre=p_cur;
		p_cur=p_tmp;
	}
	p_cur->next=p_pre;
	*p_head=p_cur;
}
void link_search_1(LI *head,int num)
{
	LI *p_mov;
	p_mov=head;
	while(p_mov!=NULL)
	{
		if(p_mov->num==num)
			ans[++cnt]=p_mov->i;
		p_mov=p_mov->next;
	}
	if(cnt==0)
		ans[++cnt]=-1;
}
int main()
{
	LI *head=NULL,*p_new=NULL;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		p_new=(LI*)malloc(sizeof(LI));
		cin>>p_new->num;
		p_new->i=i;
		link_creat_head(&head,p_new);
	}
	link_print(head);
	link_reversal(&head);
	link_print(head);
	link_search_1(head,5);
	for(int i=1;i<=cnt;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
} 
