// seqqueue.cpp
// ˳��洢����APIʵ��
// ������˳��洢���API

#include <stdio.h>
#include "seqqueue.h"
#include "seqlist.h"

// ���������൱�ڴ���һ������
SeqQueue* SeqQueue_Create(int capacity)
{
	return SeqList_Create(capacity);
}

// ���ٶ����൱����������
void SeqQueue_Destroy(SeqQueue* queue)
{
	SeqList_Destroy(queue);
	return;
}

// ��ն����൱���������
void SeqQueue_Clear(SeqQueue* queue)
{
	SeqList_Clear(queue);
	return;
}

// ������൱��������β������Ԫ��
int SeqQueue_Append(SeqQueue* queue, void* item)
{
	return SeqList_Insert(queue, item, SeqList_Length(queue));
}

// �������൱��ɾ������0��λ�õ�Ԫ��
void* SeqQueue_Retrieve(SeqQueue* queue)
{
	return SeqList_Delete(queue, 0);
}

// ��ȡ��ͷԪ���൱�ڻ�ȡ����0��λ��Ԫ��
void* SeqQueue_Header(SeqQueue* queue)
{
	return SeqList_Get(queue, 0);
}

// ��ȡ���г����൱�ڻ�ȡ������
int SeqQueue_Length(SeqQueue* queue)
{
	return SeqList_Length(queue);
}

// ��ȡ���������൱�ڻ�ȡ��������
int SeqQueue_Capacity(SeqQueue* queue)
{
	return SeqList_Capacity(queue);
}