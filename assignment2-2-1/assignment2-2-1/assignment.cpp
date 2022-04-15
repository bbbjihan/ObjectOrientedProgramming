#include <iostream>
using namespace std;

int my_strcmp(char* str1, const char* str2);

int main() {
	int* stack = new int[100];	//stack���� ���� �޸� �����Ҵ�
	int i = 0;	//stack�� ���� �� �޸� �ε���
	while (1) {
		char* command = new char[100];
		int number;
		cout << "Please Enter Command(push, pop) :";
		cin >> command;	//command�� ù ��° �Է����� ����

		if (!my_strcmp(command, "push")) {	//�Է��� push�� ���
			cin >> number;	//number�� �� ��° �Է����� ����
			*(stack + i) = number;	//������ ���� �� ���� number�� ����
			i++;	//������ �޸� �ε��� 1 �߰�
		}
		else if (!my_strcmp(command, "pop")) {	//�Է��� pop�� ���
			i--;	//������ �޸� �ε��� 1 ����
		}

		for (int j = 0; j < i; j++) {
			cout << *(stack + j) << "\n";
		}	//������ ��� �� ���

		delete[] command;	//�ݺ��� �� �������� command �����Ҵ� ����
	}
	delete[] stack;	//stack �����Ҵ� ����
	return 0;
}

int my_strcmp(char* str1, const char* str2) {	//command�� ��ȿ�� �˻縦 ���� strcmp �Լ�
	int i = 0;
	while (str1[i] != '\0' || str2[i] != '\0') {
		if (str1[i] != str2[i]){
			return str1[i] - str2[i];
		}
		i++;
	}
	return 0;
}
