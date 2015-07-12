// main.cpp
// ѭ��������Գ���

#include <iostream>
#include <cstdio>
#include "circlelist.h"
#include "joseph.h"

const int maxn = 5;

struct Student
{
	CircleListNode circlenode;
	char name[32];
	int age;
};

void play01()
{
	Student s[maxn];
	for (int i = 0; i < maxn; ++i) {
		s[i].age = i + 1;
	}

	CircleList *list = NULL;

	list = CircleList_Create(); // ��������

	// ����Ԫ��
	for (int i = 0; i < maxn; ++i) {
		// β�巨
		int ret = CircleList_Insert(list, (CircleListNode *)&s[i], CircleList_Length(list));
		if (ret < 0) {
			printf("function CircleList_Insert err: %d\n", ret);
		}
	}

	// ��������
	// ���������ӡ���ߣ�����֤������һ��ѭ������
	for (int i = 0; i < 2 * CircleList_Length(list); ++i) {
		Student *tmp = (Student *)CircleList_Get(list, i);
		if (tmp == NULL) {
			printf("function CircleList_Get err.\n");
		}
		printf("age: %d\n", tmp->age);
	}

	// ɾ����㣬ͨ�����λ��
	while (CircleList_Length(list)) {
		Student *tmp = (Student *)CircleList_Delete(list, CircleList_Length(list) - 1);
		if (tmp == NULL) {
			printf("function CircleList_Delete err.\n");
		}
		printf("age: %d\n", tmp->age);
	}

	// ��������
	CircleList_Destroy(list);

}

int main()
{
	play01(); // Ϊ�˲������ݵ��������ڣ�������дһ��������������
	joseph();

	return 0;
}