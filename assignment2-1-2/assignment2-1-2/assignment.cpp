#include <iostream>
using namespace std;

int main() {
	char str1[100], str2[100];	//�Է¹޴� ���ڿ��� �����Ҵ����� �ʾƵ� ��.
	cout << "String 1 : ";
	cin.getline(str1, 100);
	cout << "String 2 : ";
	cin.getline(str2, 100);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	//�Է¹��� �� ���ڿ��� ���̸� ����

	char* str3 = new char[len1+len2+1];	//�Է¹��� �� ���ڿ� ������ �հ�, "\0"���ڸ� ������ �� ĭ��ŭ�� �ּҸ� �����Ҵ��� �ִ������ ����.

	for (int i = 0; i < len1; i++) {
		*(str3 + i) = str1[i];
	}//ù��° ���ڿ��� ù��° ���ں��� ��ȸ�ϸ� �����Ҵ�� �迭�� ���������� ����
	for (int i = 0; i < len2; i++) {
		*(str3 + len1 + i) = str2[i];
	}//�ι�° ���ڿ��� ù��° ���ں��� ��ȸ�ϸ� �����Ҵ�� �迭�� ù��°���ڿ����� ��° �ε������� ���������� ����

	cout << "Result : ";
	for (int i = 0; i < len1 + len2 ; i++) {
		cout << *(str3 + i);
	}

	delete[] str3;
	return 0;
}

int strlen(char* string) {
	for (int i = 100; i > 0; i--) {
		if (string[i] != '\0') {
			return i+1;
		}
	}	// �Է��ִ���̰� 100�̹Ƿ� 100���� �������� �� ĭ�� �ٿ����� ���ڿ��� "\0"���� ��ġ�� Ž���ϰ� ��ȯ��.
	return 100;
}