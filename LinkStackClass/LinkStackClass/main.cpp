// main.cpp
// ��ʽ�洢ջ��Ĳ��Գ���

#include <iostream>
#include <cstdio>
#include "linkstack.hpp"

using namespace std;

struct Student
{
	char name[32];
	int age;
};

void play()
{
	Student s1, s2, s3;
	s1.age = 21;
	s2.age = 22;
	s3.age = 23;

	LinkStack<Student> ls; // ����ջ

	// ��ջ
	ls.push(s1);
	ls.push(s2);
	ls.push(s3);

	// ��ȡջ��Ԫ��
	Student tmp;
	ls.top(tmp);
	cout << "top of stack: " << tmp.age << endl;
	cout << "size of stack: " << ls.size() << endl;

	// ��ջ
	while (ls.size() > 0) {
		ls.pop(tmp);
	}

	ls.clear();

}

int main()
{
	play();

	return 0;
}