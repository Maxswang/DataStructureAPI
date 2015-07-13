// seqstack.cpp
// ˳��洢�ṹջ��APIʵ��
// ������֮ǰд�õ�˳������API

#include <cstdio>
#include "seqlist.h"
#include "seqstack.h"

// ����ջ���൱�ڴ���һ�����Ա�
SeqStack* SeqStack_Create(int capacity)
{
	return SeqList_Create(capacity);
}

// ����ջ���൱����������
void* SeqStack_Destroy(SeqStack* stack)
{
	SeqList_Destroy(stack);

	return NULL;
}

// ���ջ���൱���������
void* SeqStack_Clear(SeqStack* stack)
{
	SeqList_Clear(stack);
	return NULL;
}

// Ԫ����ջ���൱�������Ա����飩��β�����Ԫ��
int SeqStack_Push(SeqStack* stack, void* item)
{
	return SeqList_Insert(stack, item, SeqList_Length(stack));
}

// ����ջ��Ԫ�أ��൱�ڴ����Ա��β��ɾ��Ԫ��
void* SeqStack_Pop(SeqStack* stack)
{
	return SeqList_Delete(stack, SeqList_Length(stack) - 1);
}

// ��ȡջ��Ԫ�أ��൱�ڻ�ȡ�����β��Ԫ��
void* SeqStack_Top(SeqStack* stack)
{
	return SeqList_Get(stack, SeqList_Length(stack) - 1);
}

// ��ȡջ�Ĵ�С���൱�ڻ�ȡ����ĳ���
int SeqStack_Size(SeqStack* stack)
{
	return SeqList_Length(stack);
}

// ��ȡջ������
int SeqStack_Capacity(SeqStack* stack)
{
	return SeqList_Capacity(stack);
}