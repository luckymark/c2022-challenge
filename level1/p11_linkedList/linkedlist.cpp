#include <stdio.h> 
#include <stdlib.h>

struct Stu* create(int n);
void print(struct Stu* head);
void NiXu(struct Stu* head);

struct Stu {
	int num;
	int value;
	struct Stu* next;
};
int main() {
	int n;
	struct Stu* head = NULL;
	printf("请输入你想要创建的节点个数：\n");
	scanf("%d", &n);
	head = create(n);
	NiXu(head);
	print(head);
}
struct Stu* create(int n) {
	struct Stu* head, * node, * end;
	head = (struct Stu*)malloc(sizeof(struct Stu));
	end = head;
	for (int i = 0; i < n; i++) {
		node = (struct Stu*)malloc(sizeof(struct Stu));
		node->num = i + 1;
		scanf("%d", &node->value);
		end->next = node;
		end = node;
	}
	end->next = NULL;
	return head;
}

void NiXu(struct Stu* head) {
	struct Stu* end;
	struct Stu* temp[3];
	end = (struct Stu*)malloc(sizeof(struct Stu));
	temp[0] = end;
	end = (struct Stu*)malloc(sizeof(struct Stu));
	temp[1] = end;
	end = (struct Stu*)malloc(sizeof(struct Stu));
	temp[2] = end;
	int n=1;
	int i = 2;
	int j = 0;

	end = head->next;
	while (end->next != NULL) {
		end = end->next;
		n++;
	}
	end->next = head->next;

	temp[0] = head->next->next;//逻辑上的第二个节点 
	temp[1] = temp[0]->next;//逻辑上的第三个节点
	temp[2] = temp[1]->next;//逻辑上的第四个节点
	temp[0]->next = head->next;
	temp[1]->next = temp[0];
	temp[0] = temp[2]->next; 
	while (j<n-3) {
		temp[i]->next = temp[(i + 2) % 3];
		temp[(i + 2) % 3] = temp[(i + 1) % 3]->next;
		i = (i + 1) % 3;
		j++;
	}
	if (temp[0]->num == 2) {
		temp[2]->next = NULL;
		head->next = temp[1];
	}
	else if (temp[1]->num == 2) {
		temp[0]->next = NULL;
		head->next = temp[2];
	}
	else if (temp[2]->num == 2) {
		temp[1]->next = NULL;
		head->next = temp[0];
	}
}

void print(struct Stu* head) {
	struct Stu* p = head;
	p = p->next;

	printf("value值等于5的序号\n");
	while (p != NULL) {
		if (p->value == 5) {
			printf("%d\n", p->num);
		}
		p = p->next;
	}
}


