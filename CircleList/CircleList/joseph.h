// joseph.h
// ��ѭ������API���Լɪ������

#include <cstdio>
#include "circlelist.h"

const int maxp = 8;

struct Person
{
	CircleListNode circlenode;
	int id;
};

void joseph()
{
	Person s[maxp];
	for (int i = 0; i < maxp; ++i) {
		s[i].id = i + 1;
	}

	CircleList *list = NULL;
	list = CircleList_Create();

	// ����Ԫ��
	for (int i = 0; i < maxp; ++i) {
		// β�巨
		int ret = CircleList_Insert(list, (CircleListNode *)&s[i], CircleList_Length(list));
		if (ret < 0) {
			printf("function CircleList_Insert err: %d\n", ret);
		}
	}

	// ��������
	for (int i = 0; i < CircleList_Length(list); ++i) {
		Person *tmp = (Person *)CircleList_Get(list, i);
		if (tmp == NULL) {
			printf("function CircleList_Get err.\n");
		}
		printf("age: %d\n", tmp->id);
	}

	// ���Լɪ������
	while (CircleList_Length(list) > 0)
	{
		Person* pv = NULL;
		for (int i = 1; i < 3; i++)
		{
			CircleList_Next(list);
		}
		pv = (Person*)CircleList_Current(list);
		printf("%d ", pv->id);
		CircleList_DeleteNode(list, (CircleListNode *)pv); //���ݽ���ֵ,���н��Ԫ�ص�ɾ��
	}
	printf("\n");

	CircleList_Destroy(list);

}