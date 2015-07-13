// main.cpp
// ˳��ṹջ�Ĳ��Գ���

#include <stdio.h>
#include "seqstack.h"

void play()
{
	int i = 0; 
	SeqStack *stack = NULL;
	
	int a[10];
	for (i = 0; i < 10; ++i) {
		a[i] = i + 1;
	}

	stack = SeqStack_Create(20);

	// ��ջ
	for (int i = 0; i < 5; ++i) {
		SeqStack_Push(stack, &a[i]);
	}

	printf("len:%d \n", SeqStack_Size(stack));
	printf("capacity:%d \n", SeqStack_Capacity(stack));

	printf("top:%d \n", *((int *)SeqStack_Top(stack)));

	// Ԫ�س�ջ
	while (SeqStack_Size(stack)) {
		printf("%d ", *((int *)SeqStack_Pop(stack)));
	}

	SeqStack_Destroy(stack);
	return;
}

int main()
{
	play();

	return 0;
}
