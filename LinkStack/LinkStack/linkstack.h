// linkstack.h
// ��ʽ�洢ջ��API����

#ifndef _MY_LINKSTACK_H_
#define _MY_LINKSTACK_H_

typedef void LinkStack;

// ����ջ
LinkStack* LinkStack_Create();

// ����ջ
void LinkStack_Destroy(LinkStack* stack);

// ���ջ
void LinkStack_Clear(LinkStack* stack);

// ��item��ջ
int LinkStack_Push(LinkStack* stack, void* item);

// ����ջ��Ԫ��
void* LinkStack_Pop(LinkStack* stack);

// ��ȡջ��Ԫ��
void* LinkStack_Top(LinkStack* stack);

// ��ȡջ�Ĵ�С
int LinkStack_Size(LinkStack* stack);

#endif //_MY_LINKSTACK_H_
