// linkqueue.h
// ������ʽ�洢API����

#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_

typedef void LinkQueue;

// ��������
LinkQueue* LinkQueue_Create();

// ���ٶ���
void LinkQueue_Destroy(LinkQueue* queue);

// ��ն���
void LinkQueue_Clear(LinkQueue* queue);

// �����
int LinkQueue_Append(LinkQueue* queue, void* item);

// ������
void* LinkQueue_Retrieve(LinkQueue* queue);

// ��ȡ��ͷԪ��
void* LinkQueue_Header(LinkQueue* queue);

// ��ȡ���г���
int LinkQueue_Length(LinkQueue* queue);

#endif //_MY_LINKQUEUE_H_
