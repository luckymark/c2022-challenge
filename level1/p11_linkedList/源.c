#include<stdio.h>
int main()
{
	typedef struct stu
	{
		int math;
		struct stu* next;
	}s;
	s* f = (s*)malloc(sizeof(s));
	s* e;
	f->next = NULL;
	e = f;
	int i;
	for (i = 0; i < 10; i++)
	{
		s* note = (s*)malloc(sizeof(s));
		note->math = i;
		note->next = NULL;
		e->next = note;
		e = e->next;
	}
	s* p;
	p = f->next;
	for (i = 0; i < 10; i++)
	{
		printf("%d\t", p->math);
		p = p->next;
	}
	p = f->next;
	s* q=p->next;
	s* w = p;
	p = q;
	w->next = NULL;
	for (i = 0; i < 8; i++)
	{
		q = p->next;
		p->next = w;
		w = p;
		p = q;
	}
	p->next = w;
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d\t", p->math);
		p = p->next;
	}
	int count = 0;
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		if (q->math == 5)
		{
			printf("%d", i + 1); break;
		}
		count++;
		q = q->next;
	}
	if (count == 10)
	{
		printf("-1");
	}
}