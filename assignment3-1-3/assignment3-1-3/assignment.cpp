#include <iostream>
#include <cstring>
#include <stdlib.h>
#pragma warning(disable : 4996)
using namespace std;

class mystring {
public:
	char* string;
	mystring() { 
		this->string = (char*)malloc(sizeof(char));	//������� string �����Ҵ�
		if (this->string != NULL) {	//�����Ҵ��� �����Ͽ��� ���
			this->string[0] = '\0';	//NULL������ �ʱ�ȭ
		}
	}
	~mystring() {
		free(this->string);	//������� string �����Ҵ� ����
	}
};

void operator+=(mystring& A, char* B) {	//+=������ �����ε�
	int lenA = strlen(A.string);
	int lenB = strlen(B);
	A.string = (char*)realloc(A.string, sizeof(char) * (lenA + lenB + 1));	//�� �Է� ���ڿ��� ���̺��� 1 ũ���� �޸� ���Ҵ�
	if (A.string != NULL) {	//�޸� ���Ҵ� �����Ͽ��� ���
		for (int i = 0; i < lenB; i++) {
			A.string[lenA + i] = B[i];
		}	//B�� ���ڵ��� A.string�� ���� �ڿ� ����
		A.string[lenA + lenB] = '\0';	//���ڿ��� ���� �˸��� NULL���� ����
	}
}

void operator-=(mystring& A, char B) {	//-=������ �����ε�
	int len = strlen(A.string);
	int i = 0;
	while (i < len) {	//Ž�� ���� index�� ��ü ���ڿ��� ���̸� ����� �ʴ� ���� �ݺ�
		if (A.string[i] == B) {	//Ž�� ���� index�� ���ڰ� �Է°��� ���� ���
			if (i == len - 1) {	//������ ������ ���
				A.string[i] = '\0';	//�ش� ���ڸ� NULL�� ����
			}
			else {	//������ ���ڰ� �ƴ� ���
				for (int j = i; j < len-1; j++) {	//�ش� ���� ���� ��� ���ڿ� ���Ͽ�
					A.string[j] = A.string[j + 1];	//index�� 1 ū ���ڷ� �ش� ���ڵ��� �����(���ڿ��� �� ĭ�� ������ ���)
				}
				A.string[len - 1] = '\0';	//�� ������ ���ڸ� NULL�� ����
			}
			len--;	//���̰� 1 ����
		}
		else {
			i++;	//Ž�� index 1 ����
		}
	}
}

void operator--(mystring& A, int) {	//--������ �����ε�
	int len = strlen(A.string);
	if (len != 0) {
		A.string[len - 1] = '\0';	//������ ���ڸ� NULL�� ����
	}
}

void operator&&(mystring& A, char B) {	//&&������ �����ε�
	int len = strlen(A.string);
	for (int i = 0; i < len; i++) {	//��� ���ڸ� ��ȸ�ϸ�
		if (A.string[i] != B) {	//Ž�� ���� ���ڰ� �Էµ� ���ڿ� �ٸ� ���
			A.string[i] = '0';	//�ش� ���ڸ� 0���� ����
		}
	}
}

int main() {
	int command = -1;
	mystring Mystring = mystring();
	
	do {
		cout << "Please Enter command(1 : add, 2 : delete_char, 3 : delete_lastchar, 4 : and_operator, 5 : print, 6 : exit) : ";
		cin >> command;	//ù��° �Է����� command ����

		if (command == 1) {	//ù��° �Է��� 1�� ���
			char input[100];
			cin >> input;	//�ι��� �Է����� input�� ����
			
			Mystring += input;	//+=����
		}
		else if (command == 2) {	//ù��° �Է��� 2�� ���
			char input;
			cin >> input;	//�ι�° �Է����� input�� ����

			Mystring -= input;	//-=����
		}
		else if (command == 3) {	//ù��° �Է��� 3�� ���
			Mystring--;	//--����
		}
		else if (command == 4) {	//ù��° �Է��� 4�� ���
			char input;
			cin >> input;	//�ι�° �Է����� input�� ����

			Mystring && input;	//&&����
		}
		else if (command == 5) {	//ù��° �Է��� 5�� ���
			cout << Mystring.string << "\n";	//������� ���
		}

	} while (command != 6);	//ù��° �Է��� 6�� ��� �ݺ��� ����

	return 0;
}