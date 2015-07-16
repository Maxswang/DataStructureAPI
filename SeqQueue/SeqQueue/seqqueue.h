// seqqueue.h
// ˳��洢����API����

#ifndef _MY_SEQQUEUE_H_
#define _MY_SEQQUEUE_H_

typedef void SeqQueue;

//  ��������
SeqQueue* SeqQueue_Create(int capacity);

// ���ٶ���
void SeqQueue_Destroy(SeqQueue* queue);

// ��ն���
void SeqQueue_Clear(SeqQueue* queue);

// �����
int SeqQueue_Append(SeqQueue* queue, void* item);

// ������
void* SeqQueue_Retrieve(SeqQueue* queue);

// ��ȡ��ͷԪ��
void* SeqQueue_Header(SeqQueue* queue);

// ��ȡ���г���
int SeqQueue_Length(SeqQueue* queue);

// ��ȡ��������
int SeqQueue_Capacity(SeqQueue* queue);

#endif //_MY_SEQQUEUE_H_
