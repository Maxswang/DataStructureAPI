// linkstack.cpp
// ��ʽ�洢ջ��APIʵ��

#include <stdio.h>
#include <malloc.h>
#include "linkstack.h"
#include "linklist.h"

typedef void LinkStack;

typedef struct _tag_LinkStack
{
	LinkListNode node;
	void* item;
}TLinkStack;

// ����һ��ջ���൱�ڴ���һ�����Ա�
LinkStack* LinkStack_Create()
{
	return LinkList_Create();
}

// ����ջ
void LinkStack_Destroy(LinkStack* stack)
{
	LinkStack_Clear(stack); // �ͷ�ջ�Ľ��
	LinkList_Destroy(stack); // �ͷž��
	return;
}

// ���ջ
void LinkStack_Clear(LinkStack* stack)
{
	while (LinkList_Length(stack)) {
		LinkStack_Pop(stack);
	}
	return;
}

// ��ջ�����Ԫ�أ��൱����ͷ�巨�����Ա���ӽ��
int LinkStack_Push(LinkStack* stack, void* item)
{
	int ret = 0;
	TLinkStack *tStack = NULL;

	// ��void* itemת����������
	tStack = (TLinkStack *)malloc(sizeof(TLinkStack));
	tStack->item = item;

	// ͷ�巨������
	ret = LinkList_Insert(stack, (LinkListNode *)tStack, 0);
	if (ret) {
		printf("function LinkStack_Push err: %d.\n", ret);
		free(tStack);
		return ret;
	}

	return ret;
}

// ����ջ��Ԫ�أ��൱�ڴ����Ա���ɾ��0��Ԫ��
void* LinkStack_Pop(LinkStack* stack)
{
	TLinkStack *tStack = NULL;
	void* item = NULL;

	tStack = (TLinkStack *)LinkList_Delete(stack, 0);
	if (tStack == NULL) {
		printf("function LinkStack_Pop err.\n");
		return NULL;
	}

	// ��������ת����ջ���
	item = tStack->item;
	free(tStack); // �ǵ��ͷŴ���ʱ��malloc���ڴ�

	return item;
}

// ��ȡջ��Ԫ��
void* LinkStack_Top(LinkStack* stack)
{
	TLinkStack *tStack = NULL;
	void* item = NULL;

	tStack = (TLinkStack *)LinkList_Get(stack, 0);
	if (tStack == NULL) {
		printf("function LinkStack_Top err.\n");
		return NULL;
	}

	item = tStack->item;

	return item;
}

// ��ȡջ�Ĵ�С
int LinkStack_Size(LinkStack* stack)
{
	return LinkList_Length(stack);
}