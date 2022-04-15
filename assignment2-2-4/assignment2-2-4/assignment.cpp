#include <iostream>
using namespace std;

int my_strlen(char* str);
int my_strcmp(const char* str1, const char* str2);
int my_strcmp_nocase(const char* str1, const char* str2);
int cnt = 0;	//�ܾ��� �� �ܾ� ���� ���������� ����

int main() {
	char** words = new char* [100];
	while (1) {	//������ �ݺ�
		char* command = new char[100];
		cin >> command;

		if (my_strcmp(command, "END") == 0) {	//command�� END�� �Էµ� ���
			break;	//�ݺ��� ����
		}

		if (my_strcmp(command, "INSERT") == 0) {	//command�� INSERT�� �Էµ� ���
			char* target = new char[100];
			cin >> target;	//�� ���� �Է����� target�� ����.

			if(cnt == 100){	//�ܾ 100�� ����Ǿ����� ��� ����� ��� �� �߰����� ����
				cout << "wordbook is full!" << "\n";
				delete[] target;	//�������� �Ҵ� ����
				continue;
			}

			int target_length = my_strlen(target);	//�Է¹��� �ܾ��� ���� ����
			int insertion_idx = 0;	//�ܾ���� �ε����� 0���� �ʱ�ȭ
			int overlap = 0;	//�ߺ��� �ܾ �����ϴ� �� Ȯ���ϱ� ���� �÷��� �ʱ�ȭ

			for (int i = 0; i < cnt; i++) {
				if (my_strcmp_nocase(words[i], target) == 0) {	//�����Ϸ��� �ܾ �ܾ��� ���� �����ϴ� ���
					overlap = 1;	//�ߺ� �÷��� 1�� ���� �� �ݺ��� ����
					break;
				}
				if (my_strcmp_nocase(words[i], target) > 0) {	//�����Ϸ��� �ܾ�� ���� ū �ܾ �߰��� ���
					insertion_idx = i;	//���� ū �ܾ��� �ε����� ���� ��ǥ �ε����� ���� �� �ݺ��� ����
					break;
				}
			}

			if (!overlap) {	//�Է� �ܾ�� �ߺ��� �ܾ �������� �ʴ� ���
				cnt++;	//�ܾ� ���� �� �� ����
				words[cnt - 1] = new char[100];	//�ܾ��� �׸� �� �� �߰�

				if (cnt > 1 && my_strcmp_nocase(words[cnt - 2], target) < 0) {
					insertion_idx = cnt - 1;
				}	//�����Ϸ��� �ܾ�� �ܾ����� ������ �ܾ��� ���� �� ���� ���(�ܾ����� �������� �߰��ؾ� �ϴ� ���)

				for (int i = cnt - 1; i > insertion_idx; i--) {
					for (int j = 0; j < strlen(words[i - 1]); j++) {
						words[i][j] = words[i - 1][j];
					}
					words[i][strlen(words[i - 1])] = '\0';
				}	//�ܾ����� ������ �ε������� ��ǥ �ε������� �� ĭ�� �ڷ� �о

				for (int i = 0; i < target_length; i++) {
					words[insertion_idx][i] = target[i];
				}	//�Է´ܾ ��ǥ �ε����� ����
				words[insertion_idx][target_length] = '\0';	//�ܾ��� �� �Է�
			}

			for (int i = 0; i < cnt; i++) {
				cout << i << "." << words[i] << "\n";
			}	//�ߺ� ���ο� ���� ���� �ܾ��� ��ü ���

			delete[] target;	//�������� �Ҵ� ����
		}

		if (my_strcmp(command, "FIND") == 0) {	//command�� FIND�� �Էµ� ���
			char* target = new char[100];
			cin >> target;	//�� ��° �Է����� target�� ����.
			int found = 0;	//found flag�� false�� �ʱ�ȭ
			for (int i = 0; i < cnt; i++) {	//cnt���� ���� ��� �ε����� ��ȸ�ϸ鼭 �˻�
				if (my_strcmp(words[i], target) == 0) {	//i��° �ܾ Ÿ�ٰ� ������
					cout << i << "." << words[i] << "\n";	//�ܾ� ���
					found = 1;	//found flag�� true�� �ٲٰ�
					break;	//�ݺ��� Ż��
				}
			}
			if (!found) {	//found flag�� false�̸�
				cout << "Not Found\n";	//Not Found ���
			}
			delete[] target;	//�������� �Ҵ� ����
		}

	}

	for (int i = 0; i < cnt; i++) {	//cnt���� ���� ��� �ε����� ��ȸ�ϸ鼭 �Ҵ� ����
		delete[] words[i];
	}
	delete[] words;	//�ܾ��� �Ҵ� ����
	return 0;
}

int my_strlen(char* str) {	//���ڿ� ������ ���� ���ڿ� ���� ��ȯ �Լ�
	for (int i = 0; i < 100; i++) {
		if (str[i] == NULL) {
			return i;
		}
	}
	return 99;
}

int my_strcmp(const char* str1, const char* str2) {	//command ��ȿ�� �˻縦 ���� ���ڿ����� �Լ�
	int i = 0;
	while (str1[i] != '\0' || str2[i] != '\0') {
		if (str1[i] != str2[i]) {
			return str1[i] - str2[i];
		}
		i++;
	}
	return 0;
}

int my_strcmp_nocase(const char* str1, const char* str2) {	//insert�� ���� ��ҹ��� �������� �ʴ� strcmp
	int i = 0;
	while (str1[i] != '\0' || str2[i] != '\0') {
		int a = str1[i];
		int b = str2[i];
		if (a > 96) { a -= 32; }
		if (b > 96) { b -= 32; }
		if (a != b) {
			return a - b;
		}
		i++;
	}
	return 0;
}