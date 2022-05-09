#include <iostream>
#pragma warning(disable : 4996)
using namespace std;

class Node {
private:
	int value;
	Node* next;
public:
	Node() {	//��� ������
		this->value = 0;
		this->next = NULL;
	}
	Node(int value, Node* next) {	//��� ������ overloading
		this->value = value;
		this->next = next;
	}
	~Node() { ; }	//��� �Ҹ���
	int get_value() {	//��� value ��ȯ�Լ�
		return this->value;
	}
	Node* get_next() {	//��� next ��ȯ�Լ�
		return this->next;
	}
	void set_next(Node* input) {	//��� next ����� �Լ�
		 this->next = input;
	}
};

class List {
private:
	Node* head;
public:
	List() { head = NULL; }	//List class ������
	~List() { ; }	//List class �Ҹ���
	void insert(Node* tmp) {	//insert �Լ�
		if (this->head == NULL) {	//list�� head�� �������� ������,
			this->head = tmp;	//�Ķ���ͷ� ���� ��带 head�� �ʱ�ȭ
		}
		else {	//list�� head�� �����ϸ�,
			Node* now = this->head;	//list ��ȸ�� �ӽ� ������ ����
			while (now->get_next() != NULL) {	//Ž�� ���� ����� ���� ��尡 ���� ������ �ݺ�
				now = now->get_next();	//Ž�� ���� ����� ���� ��带 Ž�� ���� ����
			}
			now->set_next(tmp);	//list�� ������ node�� next�� �Ķ���ͷ� ���� ���� �ʱ�ȭ
		}
	}
	void find(int target) {	//find �Լ�
		if (this->head == NULL) {	//list�� head�� �������� ������,
			cout << "empty list" << "\n";	//��� ��� �� �Լ� ����
		}
		else {	//list�� head�� �����ϸ�,
			Node* now = this->head;	//list ��ȸ�� �ӽ� ������ ����
			int index = 1;	//����� ���� index ���� ���� �� �ʱ�ȭ
			while (now->get_next() != NULL) {	//Ž�� ���� ����� ���� ��尡 ���� ������ �ݺ�
				if (now->get_value() == target) {	//Ž�� ���� ����� value�� �Ķ���� ���� ���� ���
					cout << "Found Index:" << index << "\n";	//Ž�� ���� ����� index�� ���
				}
				now = now->get_next();	//Ž�� ���� ����� ���� ��带 Ž�� ���� ����
				index++;	//index 1 ����
			}
			if (now->get_value() == target) {	//while���� �ݺ��� ���� ���� ������ ��忡 ���� �Ķ���Ϳ� ���� value�� ������ �˻�
				cout << "Found Index:" << index << "\n";
			}
		}
	}
	void delete_node(int target) {
		if (this->head == NULL) {	//list�� head�� �������� ������,
			cout << "empty list" << "\n";	//��� ��� �� �Լ� ����
		}
		else {	//list�� head�� �����ϸ�,
			while (head != NULL && this->head->get_value() == target) {	//head�� �����ϰ�, head�� value�� �Ķ���ͷ� ���� delete target�� ���� ��� 
				this->head = this->head->get_next();//list�� head�� ���� head�� next�� ����
			}
			if (this->head == NULL || this->head->get_next() == NULL) {	//head�� �������� �ʰų�, head�� ���� ��尡 �������� �ʴ� ���
				return;	//�Լ� ����(���� while������ �̹� head ���� ��ǥ�� ������ �ٸ��� ������, head�� ���� ����� ���� Ȯ���� �ص� �������� ����)
			}
			Node* now = this->head->get_next();	//list ��ȸ�� ������ ����(���� Ž����)
			Node* prev = this->head;	//list ��ȸ�� ������ ����(���� Ž�� ���)
			while (now->get_next() != NULL) {	//���� Ž�� ���� ����� ���� ��尡 ���� ������ �ݺ�
				if (now->get_value() == target) {	//���� Ž�� ���� ����� value�� delete target�� ���� ���
					prev->set_next(now->get_next());	//���� Ž�� ���� ��带 ����Ű�� �ִ� prev ����� next�� ���� Ž�� ���� ����� next�� ������.
				}
				else {
					prev = now;
				}	//���� Ž�� ���� ��带 list���� ������ ��� prev�� now�� ������Ʈ���� �ʿ䰡 ���� ������ list���� �������� ���� ��쿡�� prev�� now�� ������Ʈ����.
				now = now->get_next();	//Ž�� ���� ����� ���� ��带 Ž�� ���� ����
			}
			if (now->get_value() == target) {	//while���� �ݺ��� ���� ���� ������ ��忡 ���Ͽ� delete target�� ���ٸ�,
				prev->set_next(NULL);	//���� �ܰ� Ž�� ����� next�� NULL�� ����
			}
		}
	}
	void print() {
		int cnt = 1;
		if (this->head == NULL) {	//list�� head�� �������� ������,
			cout << "empty list" << "\n";	//��� ��� �� �Լ� ����
		}
		else {	//list�� head�� �����ϸ�,
			Node* now = this->head;	//list ��ȸ�� �ӽ� ������ ����
			while (now->get_next() != NULL) {
				cout << now->get_value() << "\n";
				now = now->get_next();
				cnt++;
			}
			cout << now->get_value() << "\n";
			cout << "Number of nodes in the list: " << cnt << "\n";
		}
	}
};

int main() {
	class List list = List();	//����Ʈ ����

	while (1) {
		char command[10];	//command ����
		cout << "Please Enter Command(1:insert,2:find,3:delete,4:print,5:quit) : ";
		cin >> command;	//command �Է¹���
		if(!strcmp(command,"insert")){	//command�� insert�� ���
			int input_value;
			cin >> input_value;	//�� ��° �Է����� input_value�� ����

			Node* tmp = new Node(input_value,NULL);	//�߰��� �������� �ϴ�, value�� input_value�� �ӽ� ��� ���� �� �ʱ�ȭ
			list.insert(tmp);	//������ �ʱ�ȭ�� tmp Node�� list�� �߰��ϴ� insert�Լ� ȣ��
		}
		else if (!strcmp(command, "find")) {	//command�� find�� ���
			int input_value;
			cin >> input_value;	//�� ��° �Է����� input_value�� ����

			list.find(input_value);	//list class�� find �Լ� ȣ��
		}
		else if (!strcmp(command, "delete")) {	//command�� delete�� ���
			int input_value;
			cin >> input_value;	//�� ��° �Է����� input_value�� ����

			list.delete_node(input_value);
		}
		else if (!strcmp(command, "print")) {	//command�� print�� ���
			list.print();	//list class�� print �Լ� ȣ��
		}
		else if (!strcmp(command, "quit")) {	//command�� quit�� ���
			break;	//�ݺ��� ����
		}
	}
	return 0;
}