// dlinklist.h
// ˫������API����

#ifndef _DLINKLIST_H_
#define _DLINKLIST_H_

typedef void DLinkList;

typedef struct _tag_DLinkListNode
{
	_tag_DLinkListNode *next;
	_tag_DLinkListNode *pre;
}DLinkListNode;

// ��������
DLinkList* DLinkList_Create();

// ��������
void DLinkList_Destroy(DLinkList *list);

// �������
void DLinkList_Clear(DLinkList *list);

// ��ȡ������
int DLinkList_Length(DLinkList *list);

// ��posλ�ã�������node
int DLinkList_Insert(DLinkList *list, DLinkListNode *node, int pos);

// ��ȡposλ�õĽ�㣬���ظ��ϲ�
DLinkListNode* DLinkList_Get(DLinkList *list, int pos);

// ɾ��posλ�õĽ��
DLinkListNode* DLinkList_Delete(DLinkList *list, int pos);

// ɾ��ֵΪnode�Ľ��
DLinkListNode* DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node);

// �����α�
DLinkListNode* DLinkList_Reset(DLinkList* list);

// ��ȡ��ǰ�α���ָ�Ľ��
DLinkListNode* DLinkList_Current(DLinkList* list);

// ��ȡ�α굱ǰ��ָ��㣬Ȼ�����α�ָ����һ�����
DLinkListNode* DLinkList_Next(DLinkList* list);

// ��ȡ�α굱ǰ��ָ��㣬Ȼ�����α�ָ��ǰһ�����
DLinkListNode* DLinkList_Pre(DLinkList* list);


#endif