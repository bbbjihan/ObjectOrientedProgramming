#include <iostream>
#pragma warning(disable : 4996)

using namespace std;

class Node {
public:
	Node* prev;	//���� ����� �ּ�
	Node* next;	//���� ����� �ּ�
	int id;	//data �� id
	char name[10];	//data �� name
	Node() {	//������
		prev = NULL;
		next = NULL;
		id = 0;
		strcpy(name, "\0");
	}
	Node(Node* prev, Node* next, int id, char* name) {	//������ �����ε�
		this->prev = prev;
		this->next = next;
		this->id = id;
		strcpy(this->name, name);
	}
	~Node() { ; }	//�Ҹ���
	friend void swap(Node* A, Node* B) {	//���ӵ� �� ����� ��ġ�� �������ִ� �Լ�
		Node* prevswap = A->prev;	//���ӵ� �� ����� �ռ� ����� �ּҰ� ����
		Node* nextswap = B->next;	//���ӵ� �� ����� ���� ����� �ּҰ� ����
		A->prev = B;
		B->next = A;
		B->prev = prevswap;
		A->next = nextswap;
		if (prevswap != NULL) prevswap->next = B;	//prevswap�� null�� ��� prevswap->next�� ������ �Ұ��ϱ� ������ ����ó��
		if (nextswap != NULL) nextswap->prev = A;	//nextswap�� null�� ��� nextswap->prev�� ������ �Ұ��ϱ� ������ ����ó��
	}
};

class List {
public:
	Node* head;	//ù ��° ����� �ּ�
	List() {	//������
		head = NULL;
	}
	~List() {	//�Ҹ���. insert ������ ��带 �����Ҵ����ָ� �����ϱ� ������ ��ȸ�ϸ� �����Ҵ� �������ִ� ����
		Node* now = head;
		Node* prev = NULL;
		if (now != NULL) {
			while (now->next != NULL) {	//Ž�� ���� ��尡 ������ ��尡 �� ������
				prev = now;
				now = now->next;
				delete prev;	//Ž�� ���� ����� �ռ� ��� �Ҵ� ����
			}
			delete now;	//������ ��� �Ҵ� ����
		}
	}
	void insert(int id, char* name) {	//�������Լ�
		Node* now = head;
		if (now == NULL) {	//����Ʈ�� ��尡 �ϳ��� ���� ���
			Node* newNode = new Node(NULL, NULL, id, name);	//������ ���ο� ��� �����Ҵ�
			this->head = newNode;	//ù��° ���� ����
		}
		else {
			while (now->next != NULL) {	//������ ������ Ž���ϸ�
				if (now->id == id) return;	//���� ���� �ߺ��� ��尡 �ִ� ��� �����Լ� ����
				now = now->next;
			}
			if (now->id == id) return;	//������ ��尡 ���� ���� �ߺ��� ��� �����Լ� ����

			now = head;
			Node* newNode = new Node(NULL, NULL, id, name);	//������ ���ο� ��� �����Ҵ�
			while (now->next != NULL) {	//������ ������ Ž���ϸ�
				if (now->id > id) {	//Ž�� ���� ����� id�� �����Ϸ��� id���� ū ���
					if (now == head) this->head = newNode;
					newNode->prev = now->prev;
					newNode->next = now;
					if (now->prev != NULL) (now->prev)->next = newNode;
					now->prev = newNode;
					return;	//Ž�� ���� ����� �ڸ��� ������ ��� ����
				}
				now = now->next;	//���� ��� Ž��
			}
			if (now->id > id) {	//������ ����� id�� �����Ϸ��� id���� ū ���
				if (now == head) this->head = newNode;
				newNode->prev = now->prev;
				newNode->next = now;
				if (now->prev != NULL) (now->prev)->next = newNode;
				now->prev = newNode;	//������ ����� ���ڸ��� ������ ��� ����
			}
			else {	//������ ����� id���� ����id���� ���� ���(�����Ϸ��� id�� ����Ʈ ������ ���� ū id�� ���)
				now->next = newNode;
				newNode->prev = now;	//�������� ��� ����
			}
		}
	}
	void print() {
		Node* now = head;
		if (now != NULL) {
			while (now->next != NULL) {	//������ ������ Ž���ϸ�
				cout << now->id << " " << now->name << "\n";	//node date ���
				now = now->next;
			}
			cout << now->id << " " << now->name << "\n";	//������ ��� ���
		}
	}
	void print_reverse() {
		Node* now = head;
		if (now != NULL) {
			while (now->next != NULL) {	//now�� ������ ���� �ʱ�ȭ����.
				now = now->next;
			}
			while (now->prev != NULL) {	//������ ������ ù ������ Ž���ϸ�
				cout << now->id << " " << now->name << "\n";	//node data ���
				now = now->prev;
			}
			cout << now->id << " " << now->name << "\n";	//ù��° ��� ���
		}
	}
	void sort_by_name() {	//�̸������� ����Ʈ ������ ���������ϴ� �Լ�
		Node* inode = head;
		Node* jnode = inode;
		if (head != NULL) {
			while (inode->next != NULL) {	//������ ������ �� �ܰ踶�� ���� ����
				jnode = head;	//ù ��° ���� jnode �ʱ�ȭ
				while (jnode != inode && jnode->next != NULL) {	//jnode�� inode�� �������ų� jnode�� list�� �������� �������� ���� ��� ����
					if (strcmp(jnode->name, jnode->next->name)>0) {	//Ž�� ���� ����� name�� ���� ����� name�� ���Ͽ� Ž�� ���� ����� name���� �� ū ���
						if (jnode == head) head = jnode->next;
						swap(jnode, jnode->next);	//�� ����� ��ġ�� ��ü����.
					}
					else {
						jnode = jnode->next;
					}
				}
				inode = inode->next;
			}
		}
	}
	void sort_by_ID() {	//id������ ����Ʈ ������ ���������ϴ� �Լ�
		Node* inode = head;
		Node* jnode = inode;
		if (head != NULL) {
			while (inode->next != NULL) {
				jnode = head;	//ù ��° ���� jnode �ʱ�ȭ
				while (jnode != inode && jnode->next != NULL) {	//jnode�� inode�� �������ų� jnode�� list�� �������� �������� ���� ��� ����
					if (jnode->id > jnode->next->id) {	//Ž�� ���� ����� id�� ���� ����� id�� ���Ͽ� Ž�� ���� ����� id���� �� ū ���
						if (jnode == head) head = jnode->next;
						swap(jnode, jnode->next);	//�� ����� ��ġ�� ��ü����.
					}
					else {
						jnode = jnode->next;
					}
				}
				inode = inode->next;
			}
		}
	}
	void delete_node(int id) {
		Node* now = head;
		if (now != NULL) {
			while (now->next != NULL) {	//������ ������ Ž���ϸ�
				if (now->id == id) {	//Ž�� ���� ����� id�� ���� ��ǥ id�� ���� ���
					if (now->prev == NULL) {	//Ž�� ���� ��尡 head�� ���
						this->head = now->next;	//list�� head�� �� ��° ���� ����
					}
					else {
						now->prev->next = now->next;	//�ռ� ����� ���� ��带 Ž�� ���� ����� �������� ����
					}
					now->next->prev = now->prev;	//Ž�� ���� ����� ���� ����� �ռ� ��带 Ž�� ����� �� ���� ����
					delete now;	//Ž�� ��� �����Ҵ� ����
					return;	//�Լ� ����(�ߺ� id�� �������� �����Ƿ� �ٷ� �����ص� ��)
				}
				now = now->next;
			}
			if (now->id == id) {	//������ ����� id�� ���� ��ǥ id�� ���� ���
				if (now->prev == NULL) {	//��尡 �ϳ��ۿ� �������� �ʴ� ���
					this->head = NULL;	//head�� NULL�� �ʱ�ȭ
				}
				else {	//������ ��尡 ù��° ��尡 �ƴ� ���
					now->prev->next = now->next;	//�ڿ��� �ι�° ����� ���� ��带 NULL�� ����
				}
				delete now;	//Ž�� ��� �����Ҵ� ����
			}
		}
	}
};

int main() {
	int command = -1;
	List list = List();

	do {
		cout << "Please Enter command(1 : insert, 2 : print, 3 : print_reverse, 4 : sort_by_name, 5 : sort_by_ID, 6 : delete, 7 : exit)  : ";
		cin >> command;
		if (command == 1) {	//ù��° �Է��� 1�� ���
			int input_id;
			char input_name[10];
			cin >> input_id >> input_name;	//2,3��° �Է����� id�� name�� ����

			list.insert(input_id, input_name);	//�����Լ� ȣ��
		}
		else if (command == 2) {	//ù��° �Է��� 2�� ���
			list.print();	//print �Լ� ȣ��
		}
		else if (command == 3) {	//ù��° �Է��� 3�� ���
			list.print_reverse();	//print_reverse�Լ� ȣ��
		}
		else if (command == 4) {	//ù��° �Է��� 4�� ���
			list.sort_by_name();	//sort_by_name�Լ� ȣ��
		}
		else if (command == 5) {	//ù��° �Է��� 5�� ���
			list.sort_by_ID();	//sort_by_ID�Լ� ȣ��
		}
		else if (command == 6) {	//ù��° �Է��� 6�� ���
			int input_id;
			cin >> input_id;	//�ι�° �Է����� id�� ����

			list.delete_node(input_id);	//delete_node�Լ� ȣ��
		}
	} while (command != 7);	//ù��° �Է��� 7�� ��� �ݺ��� ����
	return 0;
}