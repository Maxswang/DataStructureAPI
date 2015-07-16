// main.cpp
// ������ʽ�洢API���Գ���

#include <stdio.h>
#include "linkqueue.h"

const int maxn = 10;

void play()
{
	int i = 0, a[maxn];
	LinkQueue *lq = NULL;

	for (i = 0; i < maxn; ++i) {
		a[i] = i + 1;
	}

	lq = LinkQueue_Create(); // ��������

	// �����
	for (i = 0; i < maxn; ++i) {
		LinkQueue_Append(lq, &a[i]);
	}

	// ��������
	printf("header: %d\n", *((int *)LinkQueue_Header(lq)));
	printf("length: %d\n", LinkQueue_Length(lq));

	// ������
	while (LinkQueue_Length(lq)) {
		int tmp = *((int *)LinkQueue_Retrieve(lq));
		printf("%d\n", tmp);
	}

	// ���ٶ���
	LinkQueue_Destroy(lq);
}

int main()
{
	play();

	return 0;
}