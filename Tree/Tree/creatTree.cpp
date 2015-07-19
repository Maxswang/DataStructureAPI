// creatTree.cpp
// �����Ĳ���

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

// ��������ʾ��
typedef struct BiTNode
{
	int	data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

// �ݹ��������
void inOrder(BiTNode *T)
{
	if (T == NULL) {
		return;
	}

	inOrder(T->lchild);

	printf("%c ", T->data);

	inOrder(T->rchild);
}

// #�ŷ�������
BiTNode* BiTNodeCreate()
{
	BiTNode *tmp = NULL;
	char ch;
	scanf("%c", &ch);

	if (ch == '#') {
		return NULL;
	}
	else {
		tmp = (BiTNode *)malloc(sizeof(BiTNode));
		if (tmp == NULL) {
			return NULL;
		}
		tmp->data = ch;
		tmp->lchild = BiTNodeCreate();
		tmp->rchild = BiTNodeCreate();
		return tmp;
	}
}

// �ͷ��������ͷ������������ͷ������������ͷŸ����
void BiTNodeFree(BiTNode *T)
{
	if (!T) {
		return;
	}

	if (T->lchild) {
		BiTNodeFree(T->lchild);
		T->lchild = NULL;
	}

	if (T->lchild) {
		BiTNodeFree(T->lchild);
		T->lchild = NULL;
	}

	free(T);
}

void operatorTree()
{
	BiTNode *T = NULL;
	T = BiTNodeCreate();

	inOrder(T);
	printf("\n");
	BiTNodeFree(T);
}

int main()
{
	operatorTree();

	return 0;
}