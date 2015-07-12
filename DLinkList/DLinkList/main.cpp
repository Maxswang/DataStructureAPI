// main.cpp
// ѭ���߱���Գ���

#include <cstdio>
#include "dlinklist.h"

const int maxn = 5;

struct Student
{
	DLinkListNode node;
	int age;
};

void play()
{
	Student s[maxn];
	for (int i = 0; i < maxn; ++i) {
		s[i].age = i + 21;
	}

	DLinkList *list = NULL;
	list = DLinkList_Create(); // ��������

	// ������
	for (int i = 0; i < maxn; ++i) {
		int ret = DLinkList_Insert(list, (DLinkListNode *)&s[i], DLinkList_Length(list));
		if (ret < 0) {
			return;
			printf("function DLinkList_Insert err.\n");
		}
	}

	// ��������
	for (int i = 0; i < DLinkList_Length(list); ++i) {
		Student *tmp = (Student *)DLinkList_Get(list, i);
		if (tmp == NULL) {
			printf("function DLinkList_Get err.\n");
			return;
		}
		printf("age: %d\n", tmp->age);
	}

	DLinkList_Delete(list, DLinkList_Length(list) - 1); // ɾ��β���
	DLinkList_Delete(list, 0); // ɾ��ͷ���

	// ���α��������
	for (int i = 0; i < DLinkList_Length(list); ++i) {
		Student *tmp = (Student *)DLinkList_Next(list);
		if (tmp == NULL) {
			printf("function DLinkList_Next err.\n");
			return;
		}
		printf("age: %d\n", tmp->age);
	}

	printf("\n");

	DLinkList_Reset(list);
	DLinkList_Next(list);

	Student *tmp = (Student *)DLinkList_Current(list);
	if (tmp == NULL) {
		printf("function DLinkList_Current err.\n");
		return;
	}
	printf("age: %d\n", tmp->age);

	DLinkList_DeleteNode(list, (DLinkListNode*)tmp);
	tmp = (Student *)DLinkList_Current(list);
	if (tmp == NULL) {
		printf("function DLinkList_Current err.\n");
		return;
	}
	printf("age: %d\n", tmp->age);
	printf("length: %d\n", DLinkList_Length(list));

	DLinkList_Pre(list);
	tmp = (Student *)DLinkList_Current(list);
	if (tmp == NULL) {
		printf("function DLinkList_Current err.\n");
		return;
	}
	printf("age: %d\n", tmp->age);

	printf("length: %d\n", DLinkList_Length(list));
	DLinkList_Destroy(list);

	return;
}

int main()
{
	play();

	return 0;
}