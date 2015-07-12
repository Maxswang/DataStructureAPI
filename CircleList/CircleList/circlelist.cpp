// circlelist.cpp
// ѭ������APIʵ��

#include <iostream>
#include <cstdio>
#include "circlelist.h"

typedef struct _tag_CircleList
{
	CircleListNode header;
	CircleListNode *silder;
	int length;
}TCircleList;

// ��������
CircleList* CircleList_Create()
{
	TCircleList *ret = (TCircleList *)malloc(sizeof(TCircleList));
	if (ret == NULL) {
		return NULL;
	}

	// ��ʼ��
	ret->header.next = NULL;
	ret->silder = NULL;
	ret->length = 0;

	return ret;
}

// ��������
void CircleList_Destroy(CircleList* list)
{
	if (list == NULL) {
		return;
	}
	free(list);
	return;
}

// �������
void CircleList_Clear(CircleList* list)
{
	if (list == NULL) {
		return;
	}
	TCircleList *tList = (TCircleList *)list;
	tList->header.next = NULL;
	tList->silder = NULL;
	tList->length = 0;

	return;
}

// ��ȡ����ĳ���
int CircleList_Length(CircleList* list)
{
	if (list == NULL) {
		return -1;
	}
	TCircleList *tList = (TCircleList *)list;
	return tList->length;
}

// ��posλ�ò�����node
int CircleList_Insert(CircleList* list, CircleListNode* node, int pos)
{
	if (list == NULL || node == NULL || pos < 0) {
		return -1;
	}

	TCircleList *tList = (TCircleList *)list;

	CircleListNode *cur = (CircleListNode *)tList;

	for (int i = 0; i < pos; ++i) {
		cur = cur->next;
	}

	node->next = cur->next;
	cur->next = node;

	// ����ǵ�һ�β���
	if (tList->length == 0) {
		tList->silder = node;
	}

	++tList->length; // �ǵó��ȼ�1

	// �����ͷ�巨
	if (cur == (CircleListNode *)tList) {
		// ��ȡ���һ��Ԫ��
		CircleListNode *last = CircleList_Get(tList, tList->length - 1);
		last->next = cur->next;
	}

	return 0;
}

// ��ȡposλ�õĽ��
CircleListNode* CircleList_Get(CircleList* list, int pos)
{
	// ��Ϊ��ѭ�������������ﲻ��Ҫ�ų�pos>length�����
	if (list == NULL || pos < 0) {
		return NULL;
	}

	TCircleList *tList = (TCircleList *)list;
	CircleListNode *cur = (CircleListNode *)tList;

	for (int i = 0; i < pos; ++i) {
		cur = cur->next;
	}

	return cur->next;
}

// ɾ��posλ�õĽ��
CircleListNode* CircleList_Delete(CircleList* list, int pos)
{
	TCircleList *tList = (TCircleList *)list;
	CircleListNode *ret = NULL;

	if (tList != NULL && pos >= 0 && tList->length > 0) {
		CircleListNode *cur = (CircleListNode *)tList;
		for (int i = 0; i < pos; ++i) {
			cur = cur->next;
		}

		// ��ɾ��ͷ��㣬��Ҫ���β���
		CircleListNode *last = NULL;
		if (cur == (CircleListNode *)tList)  {
			last = CircleList_Get(tList, tList->length - 1);
		}

		ret = cur->next;
		cur->next = ret->next;

		--tList->length;

		// ��ɾ��ͷ���
		if (last != NULL) {
			tList->header.next = ret->next;
			last->next = ret->next;
		}

		// ��ɾ����Ԫ��Ϊ�α���ָ��Ԫ��
		if (tList->silder == ret) {
			tList->silder = ret->next;
		}

		// ��ɾ��Ԫ�غ�������Ϊ0
		if (tList->length == 0) {
			tList->header.next = NULL;
			tList->silder = NULL;
		}
	}

	return ret;
}

// ���ݽ���ֵ��������ɾ��
CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node)
{
	TCircleList *tList = (TCircleList *)list;
	CircleListNode *ret = NULL;

	if (list != NULL && node != NULL) {
		CircleListNode *cur = (CircleListNode *)tList;
		int i = 0;
		for (i = 0; i < tList->length; ++i) {
			if (cur->next == node) {
				ret = cur->next;
				break;
			}

			cur = cur->next;
		}

		// ����ҵ�
		if (ret != NULL) {
			CircleList_Delete(tList, i);
		}
	}

	return ret;
}

// �����α�
CircleListNode* CircleList_Reset(CircleList* list)
{
	TCircleList *tList = (TCircleList *)list;
	CircleListNode* ret = NULL;

	if (list != NULL) {
		tList->silder = tList->header.next;
		ret = tList->silder;
	}

	return NULL;
}

// ��ȡ��ǰ�α���ָ���
CircleListNode* CircleList_Current(CircleList* list)
{
	TCircleList *tList = (TCircleList *)list;
	CircleListNode* ret = NULL;
	if (list != NULL) {
		ret = tList->silder;
	}

	return ret;
}

// ��ԭʼ�α���ָ��㷵�ظ��ϲ㣬Ȼ�����α��Ƶ���һ�����
CircleListNode* CircleList_Next(CircleList* list)
{
	TCircleList *tList = (TCircleList *)list;
	CircleListNode* ret = NULL;
	if (list != NULL && tList->silder != NULL) {
		ret = tList->silder;
		tList->silder = ret->next;
	}
	return ret;
}