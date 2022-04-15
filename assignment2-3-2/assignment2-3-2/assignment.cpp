#include <iostream>
using namespace std;

int mystrcmp(const char* str1, const char* str2);
int mystrlen(const char* str);

class My_string {
private:
	char* str;
public:
	My_string(char* constructor) { this->str = constructor; }		//������
	~My_string() { ; }	//�Ҹ���

	int my_strlen() {	//get string length function
		int i = 0;
		while (this->str[++i] != '\0');
		return i;
	}

	void my_strcpy(char* input) {	
		int length = mystrlen(input);
		for (int i = 0; i < length; i++) {
			this->str[i] = input[i];	//������� ���� �Ķ���ͷ� ���޵� ���ڿ��� �����Ѵ�.
		}
		this->str[length] = '\0';	//���ڿ��� ���� �����Ͽ� ��ġ�� �κ��� �����ϵ��� �����.
	}

	void my_strcat(char* input) { //�Ķ���ͷ� ���޵� ���ڿ��� Ŭ������ ����Լ� �ڿ� �̾���̴� �Լ��̴�.
		int length = my_strlen();
		int length_input = mystrlen(input);
		for (int i = 0; i < length; i++) {
			this->str[i + length] = input[i];	//������� ���ڿ��� ������ ����� '\0' ���ں��� �����鼭 �����Ѵ�.
		}
		this->str[length + length_input] = '\0';	//���ڿ��� �� ����
	}

	void print() {	//print string
		cout << "Current String : " << this->str << "\n";
	}
};

int main() {
	char* input = new char[100];
	cout << "First String : ";
	cin >> input;
	class My_string *my_string = new class My_string(input);
	//�Է¹��� ���ڿ��� ���� ���ο� Ŭ���� �����Ҵ�
	while (1) {	//�����ǹݺ�
		char* command = new char[100];	//�Է¹� �����Ҵ�
		cout << "Please Enter Command(strlen, strcpy, strcat, print, quit) :";
		cin >> command;

		if (!mystrcmp(command, "strlen")) {	//strlen�� �Էµ� ���
			cout << "String Length :" << my_string->my_strlen() << "\n";	//strlen�� ���� ��ȯ���� ���� ���
		}
		else if (!mystrcmp(command, "strcpy")) {	//strcpy�� ù ��° �Է����� ���� ���
			char* cpy_string = new char[100];	//�� ��° �Է� �����Ҵ�
			cin >> cpy_string;	//�� ��° �Է� ���ڿ� �޾Ƽ�
			my_string->my_strcpy(cpy_string);	//����Լ� my_strcpy�� �Ķ���ͷ� ȣ��
			cout << "strcpy is done\n";	//�ȳ����ڿ� ���
			delete[] cpy_string;	//�����Ҵ� ����

		}
		else if (!mystrcmp(command, "strcat")) {	//strcat�� ù ��° �Է����� ���� ���
			char* cat_string = new char[100];	//�� ��° �Է� �����Ҵ�
			cin >> cat_string;	//�� ��° �Է� ���ڿ� �޾Ƽ�
			my_string->my_strcat(cat_string);	//����Լ� my_strcat�� �Ķ���ͷ� ȣ��
			cout << "strcat is done\n";	//�ȳ����ڿ� ���
			delete[] cat_string;	//�����Ҵ� ����
		}
		else if (!mystrcmp(command, "print")) {	//print�� �Էµ� ���
			my_string->print();	//Ŭ���� �� ����Լ� 'print'ȣ��
		}
		else if (!mystrcmp(command, "quit")) {	//quit�� �Էµ� ���
			delete[] command;	//�����Ҵ� ����
			break;	//�ݺ��� Ż��
		}
	}

	delete my_string;	//Ŭ���� �����Ҵ� ����
	delete[] input;
	return 0;
}

int mystrcmp(const char* str1, const char* str2) {	//��ɹ� ��ȿ�� �˻縦 ���� strcmp�Լ�
	int i = 0;
	while (str1[i] != '\0' || str2[i] != '\0') {
		if (str1[i] != str2[i]) {
			return str1[i] - str2[i];
		}
		i++;
	}
	return 0;
};

int mystrlen(const char* str) {	//������� �� for���� ���ͷ����� ������ ���� strlen�Լ�
	int i = 0;
	while (str[i] != '\0') {
		i++;
	}
	return i;
};