// threadTree.cpp
// ����������

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

// Link == 0��ʾָ�����Һ���ָ��
// Thread==1��ʾָ��ǰ�����ߺ�̵�����
#define Thread 1
#define Link 0

// ���������洢���ṹ
typedef struct BiThrNode
{
	char data;
	struct BiThrNode *lchild, *rchild;
	int LTag;
	int RTag; // ���ұ�־
}BiThrNode, *BiThrTree;

char Nil = '#'; // �ַ����Կո��Ϊ��

// ��ǰ����������������н���ֵ���������������T
BiThrNode* createBiThrTree()
{
	BiThrNode *tmp = NULL;
	char ch;
	scanf("%c", &ch);
	
	if (ch == '#') {
		return NULL;
	}
	else {
		tmp = (BiThrNode *)malloc(sizeof(BiThrNode));
		if (tmp == NULL) {
			return NULL;
		}
		memset(tmp, 0, sizeof(BiThrNode));
		tmp->data = ch;
		tmp->lchild = createBiThrTree(); // �ݹ鹹��������
		tmp->rchild = createBiThrTree();
	}
	return tmp;
}

BiThrNode *pre; // ȫ�ֱ�����ʼ��ָ��ոշ��ʹ��Ľ��

// ���������������������
void inThreading(BiThrNode *p)
{
	if (p) {
		inThreading(p->lchild); // �ݹ�������������
		if (!p->lchild) { // û��������
			p->LTag = Thread; // ǰ������
			p->lchild = pre;// ����ָ��ǰ��
		}
		if (!pre->rchild) { // ǰ��û���ֺ���
			pre->RTag = Thread; // �������
			pre->rchild = p; // ǰ���ֺ���ָ����
		}
		pre = p; // ����preָ��p��ǰ��
		inThreading(p->rchild); // �ݹ�������������
	}
}

// �������������T��������������������thrtָ��ͷ���
BiThrNode* inOrderThreading(BiThrTree T)
{
	BiThrNode *Thrt = NULL;

	Thrt = (BiThrNode *)malloc(sizeof(BiThrNode));
	if (!Thrt) {
		return NULL;
	}
	memset(Thrt, 0, sizeof(BiThrNode));

	Thrt->LTag = Link; // ����Ϊ����ָ��
	Thrt->RTag = Thread; // �Һ���Ϊ��������ָ��
	Thrt->rchild = Thrt; // ��ָ���ָ
	if (!T) { // ��������Ϊ�գ�����ָ���ָ
		Thrt->lchild = Thrt;
	}
	else {
		Thrt->lchild = T; // ����1
		pre = Thrt;
		inThreading(T); // ���������������������
		pre->rchild = Thrt;// ����4
		pre->RTag = Thread; // ���һ�����������
		Thrt->rchild = pre; // ����2
	}
	return Thrt;
}

/* �����������������T(ͷ���)�ķǵݹ��㷨 */
int InOrderTraverse_Thr(BiThrNode* T)
{
	BiThrNode* p;
	p = T->lchild; /* pָ������ */
	while (p != T)
	{
		/* �������������ʱ,p==T */
		while (p->LTag == Link)
			p = p->lchild;
		printf("%c ", p->data);

		//���������������һ������ �Һ��� == T ˵�������һ����� ,��������..
		while (p->RTag == Thread && p->rchild != T)
		{
			p = p->rchild;
			printf("%c ", p->data);
		}
		p = p->rchild;
	}
	return 0;
}

/* �����������������T(ͷ���)�ķǵݹ��㷨 */
int InOrderTraverse_Thr2(BiThrNode* T)
{
	BiThrNode* p;
	p = T->rchild; /* pָ������ */
	while (p != T)
	{
		/* �������������ʱ,p==T */
		while (p->RTag == Link)
			p = p->rchild;
		printf("%c ", p->data);

		//���������������һ������ �Һ��� == T ˵�������һ����� ,��������..
		while (p->LTag == Thread && p->lchild != T)
		{
			p = p->lchild;
			printf("%c ", p->data);
		}
		p = p->lchild;
	}
	return 0;
}


void operatorTree()
{
	BiThrTree T, H;
	printf("�밴ǰ�����������(��:'ABDH##I##EJ###CF##G##')\n");
	T = createBiThrTree(); // ��ǰ����������� 
	H = inOrderThreading(T); // �������,������������������ 
	printf("�������(���)����������:\n");
	InOrderTraverse_Thr(H); // �������(���)���������� 
	// H D I B J E A F C G

	printf("\n�������:");
	InOrderTraverse_Thr2(H);
	// G C F A E J B I D H

	printf("\n");
}

int main()
{
	operatorTree();

	return 0;
}