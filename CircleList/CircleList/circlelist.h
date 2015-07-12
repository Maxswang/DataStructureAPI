// circlelist.h
// ѭ������API����

#ifndef _CIRCLELIST_H_
#define _CIRCLELIST_H_

typedef void CircleList;

typedef struct _tag_CircleListNode
{
	struct _tag_CircleListNode *next;
}CircleListNode;

// ��������
CircleList* CircleList_Create();

// ��������
void CircleList_Destroy(CircleList* list);

// �������
void CircleList_Clear(CircleList* list);

// ��ȡ����ĳ���
int CircleList_Length(CircleList* list);

// ��posλ�ò�����node
int CircleList_Insert(CircleList* list,CircleListNode* node, int pos);

// ��ȡposλ�õĽ��
CircleListNode* CircleList_Get(CircleList* list, int pos);

// ɾ��posλ�õĽ��
CircleListNode* CircleList_Delete(CircleList* list, int pos);

// ���ݽ���ֵ��������ɾ��
CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node);

// �����α�
CircleListNode* CircleList_Reset(CircleList* list);

// ��ȡ��ǰ�α���ָ���
CircleListNode* CircleList_Current(CircleList* list);

// ��ԭʼ�α���ָ��㷵�ظ��ϲ㣬Ȼ�����α��Ƶ���һ�����
CircleListNode* CircleList_Next(CircleList* list);

#endif