// linkqueue.cpp
// ������ʽ�洢APIʵ��
// ��������ʽ�洢���Ա�

#include <stdio.h>
#include "linkqueue.h"
#include "linklist.h"
#include <malloc.h>

typedef struct _tag_LinkQueue
{
	LinkListNode node;
	void* item;
}TLinkQueue;

// ���������൱�ڴ�������
LinkQueue* LinkQueue_Create()
{
	return LinkList_Create();
}

// ���ٶ����൱�ڴ�������
void LinkQueue_Destroy(LinkQueue* queue)
{
	LinkQueue_Clear(queue);
	LinkList_Destroy(queue);
}

// ��ն����൱���������
void LinkQueue_Clear(LinkQueue* queue)
{
	while (LinkQueue_Length(queue)) {
		LinkQueue_Retrieve(queue);
	}
}

// ������൱��������β������Ԫ��
int LinkQueue_Append(LinkQueue* queue, void* item)
{
	TLinkQueue *tmp = NULL;
	int ret = 0;

	tmp = (TLinkQueue *)malloc(sizeof(TLinkQueue));
	if (tmp == NULL) { // ����ʧ��
		return -1;
	}

	tmp->item = item;

	ret = LinkList_Insert(queue, (LinkListNode *)tmp, LinkList_Length(queue));
	if (ret) {
		printf("function LinkQueue_Append err: %d\n", ret);
		free(tmp);
		return ret;
	}

	return ret;
}

// �������൱��ɾ������0��λ�õ�Ԫ��
void* LinkQueue_Retrieve(LinkQueue* queue)
{
	TLinkQueue *tmp = NULL;
	void* item = NULL;
	tmp = (TLinkQueue *)LinkList_Delete(queue, 0);
	if (tmp == NULL) {
		return NULL;
	}

	item = tmp->item;
	free(tmp); // ��Ҫ���ǳ����е�ʱ���ͷŽ��
		
	return item;
}

// ��ȡ��ͷԪ���൱�ڻ�ȡ����0��λ��Ԫ��
void* LinkQueue_Header(LinkQueue* queue)
{
	TLinkQueue *tmp = NULL;
	tmp = (TLinkQueue *)LinkList_Get(queue, 0);
	if (tmp == NULL) {
		return NULL;
	}
	return tmp->item;
}

// ��ȡ���г���
int LinkQueue_Length(LinkQueue* queue)
{
	return LinkList_Length(queue);
}