#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
struct repo* repo1 = NULL;
struct repo* repo2 = NULL;
int AIresult[2];//����ֵ
pthread_mutex_t lock;//����
int* AI(int[320][320],int X,int Y);

void PushRepo(struct repo**, int, int, int);
void ChangeRepo(struct repo*,int,int,int);
void DeleteRepo(struct repo**, int, int);
struct repo* createRepo(struct repo* repo);
struct repo* reverse(struct repo* head);
struct repo* getTail(struct repo* L);
struct repo* Quicksort(struct repo** listHead, struct repo** listTail);
int evaluate(int pawn[320][320], int xPos, int yPos);
int IniEvaluate(int pawn[320][320], int xPos, int yPos);

int Getmax1(int pawn[320][320], struct repo* repo,struct repo* revrepo, int xPos, int yPos, int alpha, int beta);
int Getmin1(int pawn[320][320], struct repo* repo,struct repo* revrepo, int xPos, int yPos, int alpha, int beta);
int Getmax2(int pawn[320][320], struct repo* repo,struct repo* revrepo, int xPos, int yPos, int alpha, int beta);
int Getmin2(int pawn[320][320], struct repo* repo,struct repo* revrepo, int xPos, int yPos, int alpha, int beta);
int Evaluate(int pawn[320][320], int xPos,int yPos);
//���߳�
void* multithread(void* args);


//����һ���ֿⴢ��ÿ��ÿ����λ�ļ�ֵ���Ա㾡���֦��������ҪƵ��ɾ�ģ�����ʹ������
struct repo {
	int xPos;
	int yPos;
	int value;
	struct repo* next;
};
struct arg {
	int (*pawn)[320];
	struct repo* repo;
	int xPos;
	int yPos;
};

int* AI(int pawn[320][320],int X,int Y)
{
	
	
	int left = 20;//����λ��
	int right = 300;
	int bottom = 300;
	int top = 20;
	int width = 20;
	int value = 0;
	int alpha = -9999999;
    int beta = 99999999;
	
	struct repo* current=NULL;
	

//���ڵ㣬�����
//��һ�ε���AI����ʱ��ʼ���ֿ�
	if (repo1 == NULL)
	{
		int flag = -1;
		int i = 160;
		int j = 160;
		if (pawn[i][j] == 0)//�Կհ�λ�ô��
		{
			value = IniEvaluate(pawn,i, j);
			PushRepo(&repo1, i, j, value);
			PushRepo(&repo2, i, j, value);
			if (value > alpha)
			{
				alpha = value;
				AIresult[0] = i;
				AIresult[1] = j;
			}
		}
		for (int count = 1; count < 15; count++)//�������м俪ʼ����
		{
			for (int m = 0; m < count; m++)
			{
				j += (flag * width);
				if (pawn[i][j] == 0)//�Կհ�λ�ô��
				{
					value = IniEvaluate(pawn, i, j);
					PushRepo(&repo1, i, j, value);
					PushRepo(&repo2, i, j, value);
					if (value > alpha)
					{
						alpha = value;
						AIresult[0] = i;
						AIresult[1] = j;
					}
				}
			}
			for (int m = 0; m < count; m++)
			{
				i += (flag * width);
				
				if (pawn[i][j] == 0)//�Կհ�λ�ô��
				{
					value = IniEvaluate(pawn, i, j);
					PushRepo(&repo1, i, j, value);
					PushRepo(&repo2, i, j, value);
					if (value > alpha)
					{
						alpha = value;
						AIresult[0] = i;
						AIresult[1] = j;
					}
				}
	}
			flag *= -1;


		}
		for (int i = 300, j = 280; j > 0; j -= 20)
		{
			if (pawn[i][j] == 0)//�Կհ�λ�ô��
			{
				value = IniEvaluate(pawn, i, j);
				PushRepo(&repo1, i, j, value);
				PushRepo(&repo2, i, j, value);
				if (value > alpha) 
				{
					alpha = value;
					AIresult[0] = i;
					AIresult[1] = j;
				}
			}
		}
		
		
	}
	else {
		//pthread_t threads[10];
		int count = 0;
		//pthread_mutex_init(&lock, NULL);
		DeleteRepo(&repo1,X,Y);
		DeleteRepo(&repo2,X,Y);//ɾ������¹���λ��
		struct repo* temp = repo1;
		//struct arg* multiarg = (struct arg*)malloc(sizeof(struct arg));
		while (temp != NULL)
		{
			temp->value=IniEvaluate(pawn, temp->xPos, temp->yPos);
			temp = temp->next;
		}
		struct repo* listTail = getTail(repo1);
		Quicksort(&repo1, &listTail);
	    listTail = getTail(repo2);
		Quicksort(&repo2, &listTail);
		repo2 = reverse(repo2);
		current = repo1;
		//multiarg->pawn = pawn;
		//multiarg->repo = repo1;
		while (current != NULL)
		{
			if (count == 9)
			{
				break;
			}
			/*multiarg->xPos = current->xPos;
			multiarg->yPos = current->yPos;*/
			//pthread_create(&threads[count], NULL, multithread,(void*)multiarg);
			value=Getmin1(pawn, repo1, repo1, current->xPos, current->yPos, alpha, beta);
			if (value > alpha)
			{
				alpha = value;
				AIresult[0] = current->xPos;
				AIresult[1] = current->yPos;
			}
			current = current->next;
			count++;
		}	
		/*for (int i = 0; i < 9; i++)
		{
			pthread_join(threads[i],NULL);

		}*/
		

	}
	
	DeleteRepo(&repo1,AIresult[0],AIresult[1]);
	DeleteRepo(&repo2,AIresult[0],AIresult[1]);
	
 
	


	
return AIresult;
}
int Getmin1(int pawn[320][320], struct repo* repo,struct repo* revrepo, int xPos, int yPos, int alpha, int beta)
{
	pawn[xPos][yPos] = 1;
	struct repo* current=repo;
	int value;
	while(current!=NULL)
	{
		if (pawn[current->xPos][current->yPos] == 0)
		{
			value = Getmax2(pawn, revrepo,repo ,current->xPos, current->yPos, alpha, beta);
			if (value <beta)
			{
				beta = value;
			}
			if (alpha >= beta)
			{
				goto OK;
			}
		}
		current = current->next;
    }
OK:
	pawn[xPos][yPos] = 0;
	return beta;

}
int Getmax2(int pawn[320][320], struct repo* repo,struct repo* revrepo, int xPos, int yPos, int alpha, int beta)
{
	pawn[xPos][yPos] = -1;
	struct repo* current = repo;
	int value;
	while (current != NULL)
	{
		if (pawn[current->xPos][current->yPos] == 0)
		{
        value = Getmin2(pawn,revrepo,repo, current->xPos, current->yPos, alpha, beta);
		if (value > alpha)
		{
			alpha = value;
		}
		if (alpha >= beta)
		{
			goto OK;
		}
		}
		
		current = current->next;
	}
OK:
	pawn[xPos][yPos] = 0;
	return alpha;
}
int Getmin2(int pawn[320][320], struct repo* repo,struct repo* revrepo, int xPos, int yPos, int alpha, int beta)
{
	pawn[xPos][yPos] = 1;
	struct repo* current = repo;
	int value;
	while (current != NULL)
	{
		if (pawn[current->xPos][current->yPos] == 0)
		{
			value =Evaluate(pawn,current->xPos,current->yPos);
			if (value < beta)
			{
				beta = value;
			}
			if (alpha >= beta) 
			{
				goto OK;
			}
		}

		current = current->next;
	}
OK:
	pawn[xPos][yPos] = 0;
	return beta;
}
int Evaluate(int pawn[320][320],int xPos,int yPos)
{
	pawn[xPos][yPos] = -1;
	int left = 20;//����λ��
	int right = 300;
	int bottom = 300;
	int top = 20;
	int width = 20;
	int value = 0;
	int clonepawn[320][320];
	for (int i = left; i <= right; i += width)
	{
		for (int j = top; j <= bottom; j += width)
		{
			clonepawn[i][j] = -pawn[i][j];
		}
	}
	for (int i = left; i <= right; i += width)
	{
		for (int j = top; j <= bottom; j += width)
		{

			value += evaluate(pawn, i, j);
			value -= evaluate(clonepawn, i, j);


		}
	}
	pawn[xPos][yPos]=0;
	return value;
}
int IniEvaluate(int pawn[320][320],int xPos, int yPos)
{
	pawn[xPos][yPos] = 1;
	
	int left = 20;//����λ��
	int right = 300;
	int bottom = 300;
	int top = 20;
	int width = 20;
	int value = 0;
	int clonepawn[320][320];
	for (int i = left; i <= right; i += width)
	{
		for (int j = top; j <= bottom; j += width)
		{
			clonepawn[i][j] = -pawn[i][j];
		}
	}
	for (int i = left; i <= right; i += width)
	{
 		for (int j = top; j <= bottom; j += width)
		{
			
                value += evaluate(pawn, i, j);
				value -= evaluate(clonepawn, i, j);
			
			

		}
	}
	
	pawn[xPos][yPos] = 0;
	return value;
}











struct repo* createRepo(struct repo* repo)
{
	struct repo* new = NULL;
	new = (struct repo*)malloc(sizeof(struct repo));
	new->value = repo->value;
	new->xPos = repo->xPos;
	new->yPos = repo->yPos;
	return new;
}

void PushRepo(struct repo** repo, int xPos, int yPos, int value)
{
	struct repo* new=NULL;
	struct repo* previous=NULL;
	struct repo* current=*repo;
	new = (struct repo*)malloc(sizeof(struct repo));
	new->xPos = xPos;
	new->yPos = yPos;
	new->value = value;
	while (current != NULL && value < current->value)
	{
		previous = current;
		current = current->next;
	}
	new->next = current;
	if (previous == NULL)
	{
		*repo = new;
	}
	else {
		previous->next = new;
	}
}
void ChangeRepo(struct repo* repo, int xPos, int yPos, int value)
{
	struct repo* temp = repo;
	while (temp != NULL)
	{
		if (temp->xPos == xPos && temp->yPos)
		{
			temp->value = value;
			break;
		}
		temp = temp->next;
	}
};

void DeleteRepo(struct repo** repo, int xPos, int yPos)
{
	struct repo* temp = *repo;
	struct repo* previous = NULL;
	while (temp != NULL)
	{

		if (temp->xPos == xPos && temp->yPos == yPos)
		{
			break;
		}
		previous = temp;
		temp = temp->next;
	}
	if (previous == NULL)
	{

		*repo = temp->next;
	}
	else 
	{

		previous->next =temp->next;
	}
}

struct repo* getTail(struct repo* L)
{
	while (L->next)
		L = L->next;
	return L;
}
struct repo* Quicksort(struct repo** listHead,struct repo** listTail)
{
	struct repo* current;
	struct repo* lessHead = NULL, * lessTail = NULL, * moreHead = NULL, * moreTail = NULL;
	current = (*listHead)->next;//ÿ��ȡ�׽ڵ�Ϊ��Ŧ��currentָ��ڶ����ڵ����ڱ���
	if ((*listHead)->next != NULL)//������ڵ�����Ϊ1ʱ(˵������δ�ź���)
	{
		for (current = (*listHead)->next; current; current = current->next)
		{
			if (current->value >= (*listHead)->value)
			{
				if (lessHead == NULL)
					lessHead = current;
				else
					lessTail->next = current;
				lessTail = current;
			}//current���keyС����Ŧkeyʱ����less����
			else
			{
				if (moreHead == NULL)
					moreHead = current;
				else
					moreTail->next = current;
				moreTail = current;
			}//current���key������Ŧkeyʱ����more����
		}
		//������Ŧ��㽫T�����Ϊless��more��������
		if (moreTail)
			moreTail->next = NULL;
		if (lessTail)
			lessTail->next = NULL;
		//��more����β���next���ÿ�
		if (moreHead != NULL)
		{
			moreTail->next = NULL;
			Quicksort(&moreHead, &moreTail);
			(*listHead)->next = moreHead;
			*listTail = moreTail;
		}
		//��moreHead���գ���currentΪmore�����β��㣬��more������еݹ鴦��,��more���������Ŧ�ڵ��
		else
		{
			(*listHead)->next = NULL;
			*listTail = *listHead;
		}
		//��moreHeadΪ�գ���ֻ��less����(�����keyȫС����Ŧ)������Ŧ������less�ڵ��
		if (lessHead != NULL)
		{
			lessTail->next = NULL;
			Quicksort(&lessHead, &lessTail);
			lessTail->next = *listHead;
			*listHead = lessHead;
		}
		//��lesseHead���գ���less������еݹ鴦���ٽ���Ŧ�ڵ����less�����
		else
		{
			lessHead = *listHead;
		}
		//��lesseHeadΪ�գ�����Ŧ�����Ϊ�׽ڵ�
		return lessHead;
	}
	else
		return *listHead;
}
struct repo* reverse(struct repo* head)
{
	
		struct repo* pre = NULL;   //��ʼ����ǰ��ǰ��ΪNULL
		struct repo* nextp = NULL;   //����ָ��nextp���ڴ�ŵ�ǰ�ڵ�ĺ��
		while (head->next != NULL) {      //�����ǰ�ڵ���ں����ѭ������������ָ��Ϊ����ǰ��ָ��    
			nextp = head->next;            //���浱ǰ�ڵ�ĺ�̽ڵ�ָ��
			head->next = pre;            // ����ǰ�ڵ�ĺ�̽ڵ�ָ�����Ϊ����ǰ���ڵ�ָ��
			pre = head;                    //��ǰ���ڵ�ָ�뽫��ǰ�ڵ��ָ��
			head = nextp;                //������һ�ڵ�
		}
		//ʹ��head->next�Ƿ�ΪNULL���ж��Ƿ���������һ���ڵ㣬ѭ���л�û�и������һ���ڵ�ĺ��ָ��
		if (head->next == NULL)
			head->next = pre;         //�������һ���ڵ�ĺ��ָ��
		return head;    //���ط�ת��Ľڵ�ָ��
}
//void* multithread(void* args)
//{
//	struct arg* multiarg = (struct arg*)args;
//	int value = Getmin1(multiarg->pawn,multiarg->repo,multiarg->repo,multiarg->xPos,multiarg->yPos,alpha,beta);
//	//pthread_mutex_lock(&lock);
//	if (value > alpha)
//	{
//		alpha = value;
//		AIresult[0] = multiarg->xPos;
//		AIresult[1] = multiarg->yPos;		
//	}
//	//pthread_mutex_unlock(&lock);
//};
