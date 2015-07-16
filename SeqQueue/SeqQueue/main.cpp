// main.cpp
// ˳��洢����API�Ĳ��Գ���

#include <stdio.h>
#include "seqqueue.h"

const int maxn = 10;

void play()
{
	int i = 0, a[maxn];
	SeqQueue *sq = NULL;

	for (i = 0; i < maxn; ++i) {
		a[i] = i + 1;
	}

	sq = SeqQueue_Create(20); // ��������

	// �����
	for (i = 0; i < maxn; ++i) {
		SeqQueue_Append(sq, &a[i]);
	}

	// ��ȡ��������
	printf("header: %d\n", *((int *)SeqQueue_Header(sq)));
	printf("length: %d\n", SeqQueue_Length(sq));
	printf("capacity: %d\n", SeqQueue_Capacity(sq));

	// ������
	while (SeqQueue_Length(sq)) {
		int tmp = *((int *)SeqQueue_Retrieve(sq));
		printf("%d\n", tmp);
	}
	SeqQueue_Destroy(sq);

}

int main()
{
	play();

	return 0;
}