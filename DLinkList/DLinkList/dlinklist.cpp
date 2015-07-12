// dlinklist.cpp
// ѭ������APIʵ��

#include <cstdio>
#include <malloc.h>
#include "dlinklist.h"

typedef struct _tag_DLinkList
{
	DLinkListNode header;
	DLinkListNode *slider;
	int length;
}TDLinkList;

// ��������
DLinkList* DLinkList_Create()
{
	TDLinkList *ret = (TDLinkList *)malloc(sizeof(TDLinkList));
	
	if (ret != NULL) {
		ret->header.next = NULL;
		ret->header.pre = NULL;
		ret->slider = NULL;
		ret->length = 0;
	}

	return ret;
}

// ��������
void DLinkList_Destroy(DLinkList *list)
{
	if (list != NULL) {
		free(list);
	}

	return;
}

// �������
void DLinkList_Clear(DLinkList *list)
{
	TDLinkList *tList = (TDLinkList *)list;

	if (tList != NULL) {
		tList->header.next = NULL;
		tList->header.pre = NULL;
		tList->slider = NULL;
		tList->length = 0;
	}
	
	return;
}

// ��ȡ������
int DLinkList_Length(DLinkList *list)
{
	TDLinkList *tList = (TDLinkList *)list;
	int ret = -1;

	if (tList != NULL) {
		ret = tList->length;
	}

	return ret;
}

// ��posλ�ã�������node
int DLinkList_Insert(DLinkList *list, DLinkListNode *node, int pos)
{
	TDLinkList *tList = (TDLinkList *)list;
	int ret = -1, i = 0;

	if (list != NULL && node != NULL && pos >= 0)
	{
		ret = 0;

		DLinkListNode *cur = (DLinkListNode *)tList;
		DLinkListNode *next = NULL;

		for (i = 0; i < pos && cur->next != NULL; ++i) {
			cur = cur->next;
		}

		next = cur->next;

		cur->next = node;
		node->next = next;

		// ����������һ�����ʱ��Ҫ�������⴦��
		if (next != NULL) {
			next->pre = node;
		}
		node->pre = cur;

		if (tList->length == 0)	 {
			tList->slider = node; // ����������һ��Ԫ�ش����α�
		}

		// ����0λ�ò��룬��Ҫ���⴦�������Ľ��nextǰpreָ��NULL
		if (cur == (DLinkListNode *)tList) {
			node->pre = NULL;
		}
		++tList->length;
	}

	return ret;
}

// ��ȡposλ�õĽ�㣬���ظ��ϲ�
DLinkListNode* DLinkList_Get(DLinkList *list, int pos)
{
	TDLinkList *tList = (TDLinkList *)list;
	DLinkListNode* ret = NULL;
	int i = 0;
	
	if (list != NULL && pos >= 0 && pos < tList->length) {
		DLinkListNode *cur = (DLinkListNode *)tList;

		for (i = 0; i < pos; ++i) {
			cur = cur->next;
		}

		ret = cur->next;
	}

	return ret;
}

// ɾ��posλ�õĽ��
DLinkListNode* DLinkList_Delete(DLinkList *list, int pos)
{
	TDLinkList *tList = (TDLinkList *)list;
	DLinkListNode* ret = NULL;
	int	i = 0;

	if (tList != NULL && pos >= 0) {
		DLinkListNode *cur = (DLinkListNode *)tList;
		DLinkListNode *next = NULL;

		for (i = 0; i < pos && cur->next != NULL; ++i) {
			cur = cur->next;
		}

		ret = cur->next;
		next = ret->next;

		cur->next = next;

		if (next != NULL) {
			next->pre = cur;

			if (cur == (DLinkListNode *)tList) { // ��0��λ�ã���Ҫ���⴦��
				next->pre = NULL;
			}
		}

		if (tList->slider == ret) {
			tList->slider = next;
		}

		--tList->length;
	}

	return ret;
}

// ɾ��ֵΪnode�Ľ��
DLinkListNode* DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node)
{
	TDLinkList *tList = (TDLinkList *)list;
	DLinkListNode* ret = NULL;
	int	i = 0;

	if (tList != NULL) {
		DLinkListNode *cur = (DLinkListNode *)tList;

		for (i = 0; i < DLinkList_Length(tList); ++i) {
			if (cur->next == node) {
				ret = cur->next;
				break;
			}

			cur = cur->next;
		}

		if (!ret) {
			DLinkList_Delete(tList, i);
		}
	}

	return ret;
}

// �����α�
DLinkListNode* DLinkList_Reset(DLinkList* list)
{
	TDLinkList *tList = (TDLinkList *)list;
	DLinkListNode* ret = NULL;
	
	if (tList != NULL) {
		tList->slider = tList->header.next;
		ret = tList->slider;
	}

	return ret;
}

// ��ȡ��ǰ�α���ָ�Ľ��
DLinkListNode* DLinkList_Current(DLinkList* list)
{
	TDLinkList *tList = (TDLinkList *)list;
	DLinkListNode* ret = NULL;

	if (tList != NULL) {
		ret = tList->slider;
	}

	return ret;
}

// ��ȡ�α굱ǰ��ָ��㣬Ȼ�����α�ָ����һ�����
DLinkListNode* DLinkList_Next(DLinkList* list)
{
	TDLinkList *tList = (TDLinkList *)list;
	DLinkListNode* ret = NULL;

	if (tList != NULL && tList->slider != NULL) {
		ret = tList->slider;
		tList->slider = ret->next;
	}

	return ret;
}

// ��ȡ�α굱ǰ��ָ��㣬Ȼ�����α�ָ��ǰһ�����
DLinkListNode* DLinkList_Pre(DLinkList* list)
{
	TDLinkList *tList = (TDLinkList *)list;
	DLinkListNode* ret = NULL;

	if (tList != NULL && tList->slider != NULL) {
		ret = tList->slider;
		tList->slider = ret->pre;
	}

	return ret;
}