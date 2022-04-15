#include <iostream>
using namespace std;

char* my_strtok(char* string);
int strtok_flag = 0;
char* prev_strtok;

int main() {
	char* input = new char [100];	//�Է� ���ڿ� �����޸��Ҵ�
	char** string = new char* [10];	//tokenized string �����޸��Ҵ�
	cout << "Please Enter Any String :";
	cin >> input;

	int idx = 0;
	string[idx] = my_strtok(input);	//strtok ù ��° ȣ��(string[0]�� input[0]�� ���� �ּҸ� ����Ű�� ��)
	while (string[idx] != NULL) {	//string[0]!=NULL�̹Ƿ� �ݺ��� ����, '/'�� �ڿ� ���� �κй��ڿ��� �߻��ϸ� �Լ� ������ NULL�� ��ȯ�ϹǷ� �� �� �ݺ��� ����.
		string[++idx] = my_strtok(NULL);	//idx�� 1�� ���� �� my_strtok(NULL) ȣ��
	}
	for (int i = 0; i < idx; i++) {	//string[idx] == NULL �̹Ƿ� �� ���� ������ ���
		cout << string[i] << endl;
	}

	delete[] string;
	delete[] input;	//�����Ҵ� ����
	return 0;
}

char* my_strtok(char* string) {
	if (string == NULL) {	//���ڷ� �Էµ� ���ڿ��� NULL�� ���
		if (!strtok_flag) {	//strtok_flag�� 0�� ��� NULL�� ��ȯ�� -> ó�� ����ϴµ� NULL�� ���ڰ� �Էµ� ��쳪 �� �̻� ���ڿ��� '/'�� �������� �ʴ� ���
			return NULL;
		}
		else {
			char* strtok = prev_strtok + 1;
			char* strtok_rtn = prev_strtok + 1;
			//prev_strtok�� ������ NULL�� ġȯ�� �ּҰ��̹Ƿ� �̺��� 1 ū ������ �ʱ�ȭ����.
			while (*strtok != '/') {	//strtok�� ����Ű�� ���ڰ� '/'�� �� ������ �����Ͱ� ����
				if (*strtok == NULL) {	//���ڿ��� �� �̻� '/'�� �������� �ʴ� ��� strtok_flag�� ���ҽ��� ���� ȣ�� �� NULL�� ��ȯ�ǵ��� ����
					strtok_flag--;
					return strtok_rtn;	//���� ȣ�� �� NULL�� ġȯ���� �޸��ּ� + 1�� ��ȯ
				}
				strtok++;
			}
			*strtok = NULL;	//strtok�� ����Ű�� '/'���ڸ� NULL�� ġȯ
			prev_strtok = strtok;	//return�ϸ� ���� ������Ƿ� ���������� �̹� ȣ��� NULL�� ġȯ�� �ּҸ� ��������
			return strtok_rtn;	//���� ȣ�� �� NULL�� ġȯ���� �޸��ּ� + 1�� ��ȯ
		}
	}
	else {	//���ڷ� �Էµ� ���ڿ��� NULL�� �ƴ� ���
		char* strtok = string;
		while (*strtok != '/') {	//strtok�� ����Ű�� ���ڰ� '/'�� �� ������ �����Ͱ� ����
			if (*strtok == NULL) {	//���ڿ��� '/'�� ���Ե��� ���� ��� strtok_flag�� ������Ű�� �����Ƿ� ���� �Լ� ȣ�� �� NULL�� ��ȯ�ǰ� ����
				return string;
			}
			strtok++;
		}
		*strtok = NULL;	//strtok�� ����Ű�� '/'���ڸ� NULL�� ġȯ
		prev_strtok = strtok;	//return�ϸ� ���� ������Ƿ� ���������� NULL�� ġȯ�� �ּ� ����
		strtok_flag++;	//strtok_flag�� �������Ѽ� ���� ȣ�� �� NULL�� ��ȯ���� �ʵ��� ��
		return string;	//ù ��°'/'�� �̹� NULL�� ġȯ�����Ƿ� string�� ����Ű�� ù ��° ������ ����ϸ� NULL�� ���� ���ڿ��� �߸��� ��
	}
}