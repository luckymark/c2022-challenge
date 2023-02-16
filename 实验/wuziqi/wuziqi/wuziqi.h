//������ͷ�ļ���
#include <graphics.h>
#include <conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//�궨����ȫ�ֱ�������
#define HIGH 800//UI����ĸ߶�
#define WIDTH 1400//UI����Ŀ��
#define ROW 15//��������
#define COL 15//��������
#define DEPTH 4
#define THEBLACK 1
#define THEWHITE -1

extern int board[ROW][COL] ;//�������� 0��������� 1������� -1�������
extern int vision[ROW][COL];
extern int step;//��¼����

typedef struct {
    int sp;
    int* data;
} Stack;

extern Stack* stack;

//��������
int InitUI(void);//��ʼ�����UI
int GameUI(void);//��Ϸ�������UI

void Game(int t);//ѡ����Ϸģʽ
void InitBoard();//��ʼ������

int ButtonClick1();//������Ϸ������
int ButtonClick2();//����һ�ֻ����˳���Ϸ
void count_step(int x, int y, int color);//��¼��ս����

void AI(int color);//AI����
int Move(void);//��Ҷ���
int PlayerMove(int color);//�˻���սʱ���������
void set(int row, int col);//���ӹ��ܵļ���ģ��

void Judge(int row, int col);//�ж�ʤ����ƽ�֣�ƽ���ж���
int Kill(int depth, int player, int color);//��ɱ
int check(int row, int col);//��鲿������
int thedefend(int row, int col, int color);//����
int fobidden(int row, int col);//����

int Chess_type(int row, int col, int direction);//�����ж� ������ֵ
int Opposite_shore(int row, int col, int direction, int color);//�����жϱ�������

int SituationValuation(int row, int col, int color);//�������ж����ֵ�ָ������ģ��
int Settled_Situation(int color);//����ȫ�ֹ�ֵ 
int min_max_dfs(int depth, int player, int color, int a, int b);//dfs

void Neighbor_Location(int row, int col, int t);//λ�ü�֦

int Compete_Chess_Repentance();//����

Stack* creatRepentanceStack(int size);
void stackpush(Stack* pStack, int data);
int stackpop(Stack* pStack);


