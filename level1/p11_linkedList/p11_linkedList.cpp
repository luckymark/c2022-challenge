#include<cstdio>
#include<assert.h>
using namespace std;
struct node
{
	int data; node *next;
};
node *head; int size;
void init(void)
{
	head=new node;
	head->next=NULL;
	size=0;
}
void insert(const int& pos,const int& val)
{
	assert(pos<=size);
	node *cur=new node;
	cur->data=val;
	cur->next=NULL;
	node *tar=head;
	for (int i=0;i<pos;++i)
	{
		tar=tar->next;
	}
	cur->next=tar->next;
	tar->next=cur;
	++size;
}
void insert_front(const int& val)
{
	insert(0,val);
}
void insert_back(const int& val)
{
	insert(size,val);
}
void remove(const int& pos)
{
	assert(pos<=size);
	node *tar=head;
	for (int i=0;i<pos;++i)
	{
		tar=tar->next;
	}
	tar->next=tar->next->next;
	--size;
}
void remove_front(void)
{
	remove(0);
}
void remove_back(void)
{
	remove(size-1);
}
inline void reverse(void)
{
	if (!size) return;
	node* stack[100]; int top=0;
	for (node* cur=head->next;cur!=NULL;cur=cur->next)
	{
		stack[++top]=cur;
	}
	head->next=stack[top];
	for (int i=top;i>1;--i)
	{
		stack[i]->next=stack[i-1];
	}
	stack[1]->next=NULL;
}
inline int find(int st,const int val)
{
	if (st>=size) return -1;
	node *cur=head;
	for (int i=0;i<=st;++i)
	{
		cur=cur->next;
	}
	for (;cur!=NULL;cur=cur->next,++st)
	{
		if (cur->data==val) return st;
	}
	return -1;
}
void print(void)
{
	puts("The elements of the list are:");
	for (node *cur=head->next;cur!=NULL;cur=cur->next)
	{
		printf("%d ",cur->data);
	}
	putchar('\n');
}
int main()
{
	init();
	insert_back(1); insert_back(2); insert_back(3); insert_front(4); insert_front(5); insert(2,6);
	//expected:5 4 6 1 2 3
	print();
	remove_front(); remove_back();
	//expected:4 6 1 2
	print();
	reverse();
	//expected:2 1 6 4
	print();
	insert_front(5); insert_back(5);
	//expected:5 2 1 6 4 5
	int fst=find(0,5);
	if (fst!=-1)
	{
		printf("find 5 at position %d\n",fst);
		int snd=find(fst+1,5);
		if (snd!=-1)
		{
			printf("find next 5 at position %d\n",snd);
		} else
		{
			puts("Can't find 5 second time");
		}
	} else
	{
		puts("Can't find 5 first time");
	}
	return 0;
}