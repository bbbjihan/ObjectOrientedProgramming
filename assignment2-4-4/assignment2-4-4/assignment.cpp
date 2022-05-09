#include <iostream>
#pragma warning(disable : 4996)
using namespace std;

int my_strcmp_nocase(const char* str1, const char* str2);
int my_strcmp_nocase(const char str1, const char str2);

class Node {
private:
	char word[30];
	Node* next;
public:
	Node() {	//��� ������
		strcpy(this->word, "");
		this->word[29] = 0;
		this->next = NULL;
	}
	Node(char* word, Node* next) {	//��� ������ overloading
		strcpy(this->word, word);
		this->word[29] = 0;
		this->next = next;
	}
	~Node() { ; }	//��� �Ҹ���
	char* get_word() {	//��� word ��ȯ�Լ�
		return this->word;
	}
	Node* get_next() {	//��� next ��ȯ�Լ�
		return this->next;
	}
	void set_next(Node* input) {	//��� next ����� �Լ�
		this->next = input;
	}
	char get_last() {	//����� word�� ������ ���� ��ȯ�Լ�(ó������ 0�� ������ �ڸ��� �ձ��� ��ȯ)
		for (int i = 1; i < 30; i++) {
			if (this->word[i] == 0) {
				return this->word[i-1];
			}
		}
		return this->word[29];
	}
	char get_first() {	//����� word�� ù��° ���� ��ȯ�Լ�
		return this->word[0];
	}
};

class List {
private:
	Node* head;
public:
	List() { //List class ������
		head = NULL;
	}
	~List() { ; }	//List class �Ҹ���
	void insert(Node* input) {
		if (this->head == NULL) {	//head�� NULL�� ���
			this->head = input;	//�Է� ��带 head�� ����
		}
		else {	//head�� NULL�� �ƴ� ���
			Node* now = this->head;	//list ��ȸ�� �ӽ� ������ ����
			while (now->get_next() != NULL) {	//Ž�� ���� ����� ���� ��尡 ���� ������ �ݺ�
				if (!my_strcmp_nocase(now->get_word(), input->get_word())) {	//�ݺ��ϴ� ���� ���� �Է��Ϸ��� �ܾ Ž�� ����� �ܾ� �߿� �����ϸ�
					cout << "Already Exists\n";	//��� ���
					return;	//�Լ� ����
				}
				now = now->get_next();	//Ž�� ���� ����� ���� ��带 Ž�� ���� ����
			}
			if (!my_strcmp_nocase(now->get_word(), input->get_word())) {	//while���� �ݺ��� ���� ���� ������ ��忡 ���� �Է��ϴ� �ܾ�� ���� ���
				cout << "Already Exists\n";	//��� ���
				return;	//�Լ� ����
			}
			//������� ���ǹ��� ��� ����� ���, �ߺ��Ǵ� �ܾ ���� ������.
			if (!my_strcmp_nocase(now->get_last(), input->get_first())) {	//list�� ������ �ܾ��� ������ ���ڿ� �Է��ϴ� �ܾ��� ù ���ڰ� ���� ���
				now->set_next(input);	//list�� ������ ����� next�� �Է� �ܾ word�� ���� ���� ��������
			}
			else {	//list�� ������ �ܾ��� ������ ���ڿ� �Է� �ܾ��� ù��° ���ڰ� �ٸ� ���
				cout << "Not Chained\n";	//��� ���
			}
		}
	}
	void print() {	//List �� ��� Node ����Լ�
		Node* now = this->head;	//list ��ȸ�� �ӽ� ������ ����
		while (now->get_next() != NULL) {	//Ž�� ���� ����� ���� ��尡 ���� ������ �ݺ�
			cout << now->get_word() << "->";	//���� Ž�� ���� ����� word ���
			now = now->get_next();	//Ž�� ���� ����� ���� ��带 Ž�� ���� ����
		}
		cout << now->get_word() << "->\n";	//while���� �ݺ��� ���� ���� ������ ��� ���
	}
};

int main() {
	class List list = List();	//����Ʈ ����

	while (1) {
		char command[100];	//command ����
		cout << "CMD(Word/ext)>> ";
		cin >> command;	//command �Է¹���
		if (!strcmp(command, "exit")) {	//command�� exit�̸�
			break;	//�ݺ��� ����
		}
		else {	//exit ���� �� �Էµ� ���
			Node* tmp = new Node(command, NULL);	//�Է°��� word�� �ϴ� �ӽ� ��� ����
			list.insert(tmp);	//list Ŭ������ insert �Լ� ȣ��
			list.print();	//list Ŭ������ print �Լ� ȣ��
		}
	}

	return 0;
}

int my_strcmp_nocase(const char* str1, const char* str2) {	//��ҹ��� �������� �ʴ� strcmp
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

int my_strcmp_nocase(const char str1, const char str2) {	//��ҹ��� �������� �ʴ�, �� ���� �񱳿� strcmp overloading
	int a = str1;
	int b = str2;
	if (a > 96) { a -= 32; }
	if (b > 96) { b -= 32; }
	if (a != b) {
		return a - b;
	}
	return 0;
}