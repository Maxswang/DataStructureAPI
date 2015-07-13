// seqstack.h
// ˳��洢�ṹ��ջAPI����

#ifndef __SEQSTACK_H__
#define __SEQSTACK_H__

typedef void SeqStack;

// ����ջ
SeqStack* SeqStack_Create(int capacity);

// ����ջ
void* SeqStack_Destroy(SeqStack* stack);

// ���ջ
void* SeqStack_Clear(SeqStack* stack);

// Ԫ����ջ
int SeqStack_Push(SeqStack* stack, void* item);

// ����ջ��Ԫ��
void* SeqStack_Pop(SeqStack* stack);

// ��ȡջ��Ԫ��
void* SeqStack_Top(SeqStack* stack);

// ��ȡջ�Ĵ�С
int SeqStack_Size(SeqStack* stack);

// ��ȡջ������
int SeqStack_Capacity(SeqStack* stack);

#endif