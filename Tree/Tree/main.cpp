// main.cpp
// ���ı�ʾ��

#include <iostream>
#include <cstdio>

// ��������ʾ��
typedef struct BiTNode
{
	int	data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;


// ���������ʾ��
typedef struct TriTNode
{
	int data;
	
	// ���Һ���ָ��
	TriTNode *lchild, *rchild;
	// ��ָ��
	TriTNode *parent;
}TriTNode, *TriTree;


// ˫�������ʾ��
typedef struct BPTNode
{
	int data;
	int parentPosition; // ָ��˫�׵�ָ�룬�����±�
	char LRTag; // ���Һ���ָ����
}BPTNode;

typedef struct BPTree
{
	BPTNode nodes[100]; // ��Ϊ���֮���Ƿ�ɢ�ģ���Ҫ�ѽ��洢��������
	int numOfNode; // �����Ŀ
	int root; // ���ڵ�λ�ã�ע�����洢���Ǹ��׽ڵ���������±�
};


int main()
{

	return 0;
}