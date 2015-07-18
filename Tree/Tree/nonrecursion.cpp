// nonrecursion.cpp
// �����Ĳ���

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

	printf("%d ", T->data);

	inOrder(T->rchild);
}

BiTNode* goFarLeft(BiTNode *T, stack<BiTNode *> &s)
{
	if (T == NULL) {
		return NULL;
	}
	while (T->lchild) {
		s.push(T);
		T = T->lchild; // ��ָ������
	}
	return T;
}

void nonRecursionInOrder(BiTNode *T)
{
	stack<BiTNode *> s;
	BiTNode *tmp = goFarLeft(T, s);

	while (tmp) {
		printf("%d ", tmp->data);

		// ����������������ظ�����1
		if (tmp->rchild) {
			tmp = goFarLeft(tmp->rchild, s);
		}
		// �����û������������ջ�Ƿ�Ϊ��
		else if (!s.empty()) {
			tmp = s.top();
			s.pop();
		}
		else {
			tmp = NULL;
		}
	}
}

void operatorTree()
{
	BiTNode nodeA, nodeB, nodeC, nodeD, nodeE;

	memset(&nodeA, 0, sizeof(BiTNode));
	memset(&nodeB, 0, sizeof(BiTNode));
	memset(&nodeC, 0, sizeof(BiTNode));
	memset(&nodeD, 0, sizeof(BiTNode));
	memset(&nodeE, 0, sizeof(BiTNode));

	nodeA.data = 1;
	nodeB.data = 2;
	nodeC.data = 3;
	nodeD.data = 4;
	nodeE.data = 5;

	nodeA.lchild = &nodeB;
	nodeA.rchild = &nodeC;
	nodeB.lchild = &nodeD;
	nodeC.lchild = &nodeE;
	
	// �ǵݹ��������
	nonRecursionInOrder(&nodeA);
	// 4 2 1 5 3
	printf("\n");

}

int main()
{
	operatorTree();

	return 0;
}