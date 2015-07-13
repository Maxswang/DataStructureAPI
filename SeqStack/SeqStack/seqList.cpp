// seqList.cpp
// ˳��洢�ṹ��ջAPIʵ��

#include <iostream>
#include <cstdio>
#include "seqlist.h"

using namespace std;

typedef struct _tag_SeqList
{
	int capacity;
	int length;
	int **node;
}TSeqList;

//���� ����
SeqList* SeqList_Create(int capacity)
{
	int ret = -1;
	TSeqList *tmp = NULL;
	tmp = (TSeqList *)malloc(sizeof(TSeqList));
	if (tmp == NULL) {
		ret = 1;
		printf("function SeqList_Create() err:%d\n", ret);
		return NULL;
	}
	memset(tmp, 0, sizeof(TSeqList));
	tmp->capacity = capacity;
	tmp->length = 0;
	tmp->node = (int **)malloc(sizeof(void *) * capacity);
	if (tmp->node == NULL) {
		ret = 2;
		printf("function SeqList_Create() err:%d\n", ret);
		return NULL;
	}
	memset(tmp->node, 0, sizeof(void *) * capacity);

	return tmp;
}

//���� ����
int SeqList_Create2(int capacity, SeqList**handle)
{
	int			ret = 0;
	TSeqList	*tmp = NULL;
	tmp = (TSeqList *)malloc(sizeof(TSeqList));
	if (tmp == NULL)
	{
		ret = 1;
		printf("func SeqList_Create2() err :%d \n", ret);
		return ret;
	}
	memset(tmp, 0, sizeof(TSeqList));
	tmp->capacity = capacity;
	tmp->length = 0;
	tmp->node = (int **)malloc(sizeof(void *) * capacity);
	if (tmp->node == NULL)
	{
		ret = 2;
		printf("func SeqList_Create2() malloc err :%d \n", ret);
		return ret;
	}

	*handle = tmp;
	return ret;
}

//���� ����
void SeqList_Destroy(SeqList* list)
{
	if (list == NULL) {
		return;
	}

	TSeqList *tmp = (TSeqList *)list;
	if (tmp->node != NULL) {
		free(tmp->node);
	}
	free(tmp);

	return;
}

////���� ���
void SeqList_Clear(SeqList* list)
{
	if (list == NULL) {
		return;
	}

	TSeqList *tmp = (TSeqList *)list;
	tmp->length = 0;
	memset(tmp->node, 0, sizeof(tmp->node));

	return;
}

//���� ����
int SeqList_Length(SeqList* list)
{
	if (list == NULL) {
		return -1;
	}

	TSeqList *tmp = (TSeqList *)list;
	return tmp->length;
}

//���� ���� 
int SeqList_Capacity(SeqList* list)
{
	if (list == NULL) {
		return -1;
	}

	TSeqList *tmp = (TSeqList *)list;
	return tmp->capacity;
}

//���� ��ĳһ��λ�� ����Ԫ��
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos)
{
	if (list == NULL || node == NULL || pos < 0) {
		return -1;
	}

	TSeqList *tList = (TSeqList *)list;

	// �������
	if (tList->length >= tList->capacity) {
		return -2;
	}

	// ���pos��λ�ó�����length�����м����һЩλ��
	if (pos > tList->length) {
		pos = tList->length;
	}

	for (int i = tList->length; i > pos; --i) {
		tList->node[i] = tList->node[i - 1];
	}
	tList->node[pos] = (int *)node;
	++tList->length;

	return 0;
}

//��ȡĳһ��λ�õ�������
SeqListNode* SeqList_Get(SeqList* list, int pos)
{
	TSeqList *tList = (TSeqList *)list;
	if (list == NULL || pos < 0 || pos >= tList->length)
	{
		return NULL;
	}

	SeqListNode *tListNode = NULL;
	tListNode = (int *)tList->node[pos];

	return tListNode;
}

//ɾ��ĳһ��λ�õĽ��
SeqListNode* SeqList_Delete(SeqList* list, int pos)
{
	TSeqList *tList = (TSeqList *)list;
	SeqListNode *tListNode = NULL;
	if (list == NULL || pos < 0 || pos >= tList->length) {
		return NULL;
	}

	tListNode = tList->node[pos];
	for (int i = pos + 1; i < tList->length; ++i) {
		tList->node[i - 1] = tList->node[i];
	}
	--tList->length; // �����˳��ȼ�һ

	return tListNode;
}