#include <iostream>
#include <fstream>
#pragma warning(disable : 4996)
using namespace std;

class Node {
private:
	char* name;
	Node* prev;
	Node* next;
public:
	Node() { this->name = new char[20]; this->prev = NULL; this->next = NULL; }	//Node�� ������
	Node(char* name, Node* prev, Node* next) {	//Node�� ������ overloading
		this->name = new char[20];
		strcpy(this->name, name);
		this->prev = prev;
		this->next = next;
	}
	~Node() { 
		cout << this->getName() << "Node is destroyed" << "\n";
		delete this->name;
	}	//Node�� �Ҹ���
	char* getName() { return this->name; }	//Node�� Name ��ȯ�Լ�
	Node* getPrev() { return this->prev; }	//Node�� Prev ��ȯ�Լ�
	Node* getNext() { return this->next; }	//Node�� Next ��ȯ�Լ�
	void setPrev(Node* prev) { this->prev = prev; }	//Node�� Prev Set�Լ�
	void setNext(Node* next) { this->next = next; }	//Node�� Next Set�Լ�
};

class DoublyLinkedList {
private:
	Node* head;
public:
	DoublyLinkedList() { this->head = NULL; }	//DoublyLinkedList�� ������
	~DoublyLinkedList() { ; }	//DoublyLinkedList�� �Ҹ���
	Node* getHead() { return this->head; }	//DoublyLinkedList�� Head ��ȯ�Լ�
	void insert(Node* input) {	//Node�� List�� �������� �����ϴ� �Լ�
		if (this->head == NULL) {	//List�� ����ִ� ���
			this->head = input;	//input Node�� head�� ����
			return;	//�Լ�����
		}
		Node* now = this->head;	//Ž���� ���� ���� ��带 List�� head�� �ʱ�ȭ
		while (now->getNext() != NULL) now = now->getNext();	//��� ������ ���� ������ ������ �����带 �̵�
		now->setNext(input);	//���� ����� Next�� input Node�� ����
		input->setPrev(now);	//�����带 input Node�� Prev�� ����
	}
	Node* findNode(const char* name) {	//�Ķ���ͷ� �Էµ� string�� name���� ������ �ִ� node�� �����ϴ� ��� �ش� ��带 ��ȯ�ϴ� �Լ�
		Node* now = this->head;	//Ž���� ���� ���� ��带 List�� head�� ����
		for (; now != NULL; now = now->getNext()) {	//������ ������ Ž��
			if (!strcmp(now->getName(), name))  break;	//Ž�� �� node�� name�� �Ķ���ͷ� �Էµ� string�� ���� ��� �ݺ��� ����
		}
		if (now == NULL) return NULL;	//�ݺ����� ��� ��� Ž������ ���� ����Ǿ��ų� list�� ����ִ� ��� NULL ��ȯ
		return now;	//������ ã�� ��� ��ȯ
	}
};

class DoublyCircularLinkedList {
private:
	Node* head;
	Node* tail;
public:
	DoublyCircularLinkedList() { this->head = NULL; this->tail = NULL; }	//DoublyCircularLinkedList�� ������
	~DoublyCircularLinkedList() { ; }	//DoublyCircularLinkedList�� �Ҹ���
	Node* getHead() { return this->head; }	//DoublyCircularLinkedList�� head ��ȯ�Լ�
	void insert(Node* input) {	//Node�� List�� tail�� �����ϴ� �Լ�
		if (this->head == NULL) {	//List�� ����ִ� ���
			this->head = input;	//input Node�� head�� ����
			this->tail = input;	//input Node�� tail�� ����
			input->setNext(input);
			input->setPrev(input);
			return;	//�Լ�����
		}
		Node* now = this->tail;	//������ ���� ���� tail�� ��带 �ҷ���
		now->setNext(input);	//���� tail�� ����� next�� ���Գ��� ����
		head->setPrev(input);	//���� head�� ����� prev�� ���Գ��� ����
		input->setPrev(now);	//���Գ���� prev�� ���� tail�� ���� ����
		input->setNext(this->head);	//���Գ���� next�� ���� head�� ���� ����
		this->tail = input;	//tail�� ���Գ��� ����
	}
	Node* findNode(const char* name) {	//�Ķ���ͷ� �Էµ� string�� name���� ������ �ִ� node�� �����ϴ� ��� �ش� ��带 ��ȯ�ϴ� �Լ�
		if (!strcmp(this->head->getName(), name)) return this->head;	//head�� ��ǥ����� ��� head ��ȯ (�Ʒ� �ݺ����� ���ǹ� �帧��� ���� ����ó��)
		Node* now = this->head->getNext();	//Ž���� ���� ���� ��带 List�� head�� ����
		for (; now != this->head; now = now->getNext()) {	//������ ������ Ž��
			if (!strcmp(now->getName(), name)) break;	//Ž�� �� node�� name�� �Ķ���ͷ� �Էµ� string�� ���� ��� �ݺ��� ����
		}
		if (now == this->head) return NULL;	//�ݺ����� ��� ��� Ž������ ���� ����Ǿ��ų� list�� ����ִ� ��� NULL ��ȯ
		return now;	//������ ã�� ��� ��ȯ
	}
};

void printPath(const char* name1, const char* name2, DoublyLinkedList line1, DoublyCircularLinkedList line2) {
	Node* start1 = line1.findNode(name1);
	Node* start2 = line2.findNode(name1);
	Node* desti1 = line1.findNode(name2);
	Node* desti2 = line2.findNode(name2);
	if (!strcmp(name1, "��û")) {	//���ۿ��� ��û�� ����� ����ó��
		if (desti1 == NULL) {
			start1 = NULL;
		}
		if (desti2 == NULL){
			start2 = NULL;
		}
	}
	if ((start1 == NULL && start2 == NULL) || (desti1 == NULL && desti2 == NULL)) {
		cout << "��ΰ� �������� �ʽ��ϴ�.";
		return;
	}
	char Path[50][20];
	int cnt = 0;
	if (start2 == NULL) {	//���ۿ��� 1ȣ���� ���
		if (desti2 == NULL) {	//���ۿ��� 1ȣ���̰�, ������ 1ȣ���� ���
			Node* start = line1.findNode(name1);	//���۳�带 name1���� ���� �ʱ�ȭ
			Node* desti = start;	//������带 ���۳��� �ʱ�ȭ
			while (desti!=NULL) {	//������尡 NULL�� �ƴϸ� �ݺ�(�ݺ��� ����� ������尡 NULL�̶�� ���۳���� next�� ������带 ã�� �� ���ٴ� �ǹ�. �� head�� name1������ name2���� �� �����ٴ� ��.)
				if (!strcmp(desti->getName(), name2)) {
					break;	//��������� name�� name2�� ���ٸ� �ݺ��� ����
				}
				desti = desti->getNext();	//������带 �� ���� ���� ������ ����
			}
			if (desti == NULL) {	//head�� name1 ���� �� ����� ��� (prev�� Ž���ؾ� �������� ������ ���)
				desti = start;	//�������� ���� ������带 ���۳��� �ʱ�ȭ
				while (1) {
					if (!strcmp(desti->getName(), name2)) break;	//��������� name�� name2�� ���ٸ� �ݺ��� ����
					strcpy(Path[cnt], desti->getName());	//������尡 ���� ������ �ִ� ����� �̸��� ��ο� ����
					cnt++;	//��� ī���� 1 ����
					desti = desti->getPrev();	//��������� ���� ���� ������� ����
				}
				strcpy(Path[cnt], desti->getName());	//������ ����� �̸��� ��ο� ����
				cnt++;	//��� ī���� 1 ����
			}
			else {	//head�� name2 ���� �� ����� ��� (next�� Ž���ؾ� �������� ������ ���)
				desti = start;	//�������� ���� ������带 ���۳��� �ʱ�ȭ
				while (1) {
					if (!strcmp(desti->getName(), name2)) break;	//��������� name�� name2�� ���ٸ� �ݺ��� ����
					strcpy(Path[cnt], desti->getName());	//������尡 ���� ������ �ִ� ����� �̸��� ��ο� ����
					cnt++;	//��� ī���� 1 ����
					desti = desti->getNext();	//��������� ���� ���� ������� ����
				}
				strcpy(Path[cnt], desti->getName());	//������ ����� �̸��� ��ο� ����
				cnt++;	//��� ī���� 1 ����
			}
			if (cnt > 0) {	//��Ŀ� �°� ��� ���
				cout << Path[0];
				for (int i = 1; i < cnt; i++) {
					cout << "->" << Path[i];
				}
			}
		}
		else {	//���ۿ��� 1ȣ���̰�, ������ 2ȣ���� ���
			Node* start = line1.findNode(name1);	//���۳�带 name1���� ���� �ʱ�ȭ
			Node* desti = start;	//������带 ���۳��� �ʱ�ȭ
			while (desti != NULL) {	//������尡 NULL�� �ƴϸ� �ݺ�(�ݺ��� ����� ������尡 NULL�̶�� ���۳���� next�� ������带 ã�� �� ���ٴ� �ǹ�. �� head�� name1������ name2���� �� �����ٴ� ��.)
				if (!strcmp(desti->getName(), "��û")) {
					break;	//��������� name�� "��û"�� ���ٸ� �ݺ��� ����
				}
				desti = desti->getNext();	//������带 �� ���� ���� ������ ����
			}
			if (desti == NULL) {	//head�� name1 ���� �� ����� ��� (prev�� Ž���ؾ� �������� ������ ���)
				desti = start;	//�������� ���� ������带 ���۳��� �ʱ�ȭ
				while (1) {
					if (!strcmp(desti->getName(), "��û")) break;	//��������� name�� name2�� ���ٸ� �ݺ��� ����
					strcpy(Path[cnt], desti->getName());	//������尡 ���� ������ �ִ� ����� �̸��� ��ο� ����
					cnt++;	//��� ī���� 1 ����
					desti = desti->getPrev();	//��������� ���� ���� ������� ����
				}
				strcpy(Path[cnt], desti->getName());	//������ ����� �̸��� ��ο� ����
				cnt++;	//��� ī���� 1 ����
			}
			else {	//head�� "��û" ���� �� ����� ��� (next�� Ž���ؾ� �������� ������ ���)
				desti = start;	//�������� ���� ������带 ���۳��� �ʱ�ȭ
				while (1) {
					if (!strcmp(desti->getName(), "��û")) break;	//��������� name�� name2�� ���ٸ� �ݺ��� ����
					strcpy(Path[cnt], desti->getName());	//������尡 ���� ������ �ִ� ����� �̸��� ��ο� ����
					cnt++;	//��� ī���� 1 ����
					desti = desti->getNext();	//��������� ���� ���� ������� ����
				}
				strcpy(Path[cnt], desti->getName());	//������ ����� �̸��� ��ο� ����
				cnt++;	//��� ī���� 1 ����
			}
			cnt--;	//��û�� �ߺ� ��� ������ index 1 ����
			start = line2.findNode("��û");	//���۳�带 2ȣ���� ��û���� �ʱ�ȭ
			int disNext = 0;	//Next�� ���� name2���� ã�� ������ �� ���� ���� ������ �ϴ��� �����ϱ� ���� distance of moving next ����
			int disPrev = 0;	//Prev�� ���� name2���� ã�� ������ �� ���� ���� ������ �ϴ��� �����ϱ� ���� distance of moving prev ���� 
			desti = start;
			for (; strcmp(desti->getName(), name2); desti = desti->getNext()) {	//������尡 name2���� ã�� ������ getNext�� ���� �ݺ��ϸ� ���� ����
				disNext++;	//���� �ϳ� ���� ������ disNext ������ 1�� ����
			}
			desti = start;	//������带 ���۳��� �ʱ�ȭ
			for (; strcmp(desti->getName(), name2); desti = desti->getPrev()) {	//������尡 name2���� ã�� ������ getPrev�� ���� �ݺ��ϸ� ���� ����
				disPrev++;	//���� �ϳ� ���� ������ disPrev ������ 1�� ����
			}
			if (disNext > disPrev) {	//start���� Next�� name2���� ã�� �ͺ��� Prev�� name2���� ã�� �� �� ���� ���
				desti = start;	//�������� ���� ������带 ���۳��� �ʱ�ȭ
				while (1) {
					if (!strcmp(desti->getName(), name2)) break;	//��������� name�� name2�� ���ٸ� �ݺ��� ����
					strcpy(Path[cnt], desti->getName());	//������尡 ���� ������ �ִ� ����� �̸��� ��ο� ����
					cnt++;	//��� ī���� 1 ����
					desti = desti->getPrev();	//��������� ���� ���� ������� ����
				}
				strcpy(Path[cnt], desti->getName());	//������ ����� �̸��� ��ο� ����
				cnt++;	//��� ī���� 1 ����
			}
			else {	//start���� Prev�� name2���� ã�� �ͺ��� Next�� name2���� ã�� �� �� ���� ���
				desti = start;	//�������� ���� ������带 ���۳��� �ʱ�ȭ
				while (1) {
					if (!strcmp(desti->getName(), name2)) break;	//��������� name�� name2�� ���ٸ� �ݺ��� ����
					strcpy(Path[cnt], desti->getName());	//������尡 ���� ������ �ִ� ����� �̸��� ��ο� ����
					cnt++;	//��� ī���� 1 ����
					desti = desti->getNext();	//��������� ���� ���� ������� ����
				}
				strcpy(Path[cnt], desti->getName());	//������ ����� �̸��� ��ο� ����
				cnt++;	//��� ī���� 1 ����
			}
			
			if (cnt > 0) {	//��Ŀ� �°� ��� ���
				cout << Path[0];
				for (int i = 1; i < cnt; i++) {
					cout << "->" << Path[i];
				}
			}
		}
	}
	else{	//���ۿ��� 2ȣ���� ���
		if (desti2 == NULL) {	//���ۿ��� 2ȣ���̰�, ������ 1ȣ���� ���
			Node* start = line2.findNode(name1);	//���۳�带 2ȣ���� head�� �ʱ�ȭ
			int disNext = 0;	//Next�� ���� ��û���� ã�� ������ �� ���� ���� ������ �ϴ��� �����ϱ� ���� distance of moving next ����
			int disPrev = 0;	//Prev�� ���� ��û���� ã�� ������ �� ���� ���� ������ �ϴ��� �����ϱ� ���� distance of moving prev ���� 
			Node* desti = start;	//������带 ���۳��� �ʱ�ȭ
			for (; strcmp(desti->getName(), "��û"); desti = desti->getNext()) {	//������尡 "��û"���� ã�� ������ getNext�� ���� �ݺ��ϸ� ���� ����
				disNext++;	//���� �ϳ� ���� ������ disNext ������ 1�� ����
			}
			desti = start;	//������带 ���۳��� �ʱ�ȭ
			for (; strcmp(desti->getName(), "��û"); desti = desti->getPrev()) {	//������尡 "��û"���� ã�� ������ getPrev�� ���� �ݺ��ϸ� ���� ����
				disPrev++;	//���� �ϳ� ���� ������ disPrev ������ 1�� ����
			}
			if (disNext > disPrev) {	//start���� Next�� name2���� ã�� �ͺ��� Prev�� "��û"���� ã�� �� �� ���� ���
				desti = start;	//�������� ���� ������带 ���۳��� �ʱ�ȭ
				while (1) {
					if (!strcmp(desti->getName(), "��û")) break;	//��������� name�� "��û"�� ���ٸ� �ݺ��� ����
					strcpy(Path[cnt], desti->getName());	//������尡 ���� ������ �ִ� ����� �̸��� ��ο� ����
					cnt++;	//��� ī���� 1 ����
					desti = desti->getPrev();	//��������� ���� ���� ������� ����
				}
				strcpy(Path[cnt], desti->getName());	//������ ����� �̸��� ��ο� ����
				cnt++;	//��� ī���� 1 ����
			}
			else {	//start���� Prev�� name2���� ã�� �ͺ��� Next�� "��û"���� ã�� �� �� ���� ���
				desti = start;	//�������� ���� ������带 ���۳��� �ʱ�ȭ
				while (1) {
					if (!strcmp(desti->getName(), "��û")) break;	//��������� name�� "��û"�� ���ٸ� �ݺ��� ����
					strcpy(Path[cnt], desti->getName());	//������尡 ���� ������ �ִ� ����� �̸��� ��ο� ����
					cnt++;	//��� ī���� 1 ����
					desti = desti->getNext();	//��������� ���� ���� ������� ����
				}
				strcpy(Path[cnt], desti->getName());	//������ ����� �̸��� ��ο� ����
				cnt++;	//��� ī���� 1 ����
			}
			start = line1.findNode("��û");	//���۳�带 name1���� ���� �ʱ�ȭ
			desti = start;	//������带 ���۳��� �ʱ�ȭ
			while (desti != NULL) {	//������尡 NULL�� �ƴϸ� �ݺ�(�ݺ��� ����� ������尡 NULL�̶�� ���۳���� next�� ������带 ã�� �� ���ٴ� �ǹ�. �� head�� name1������ name2���� �� �����ٴ� ��.)
				if (!strcmp(desti->getName(), name2)) {
					break;	//��������� name�� name2�� ���ٸ� �ݺ��� ����
				}
				desti = desti->getNext();	//������带 �� ���� ���� ������ ����
			}
			if (desti == NULL) {	//head�� name1 ���� �� ����� ��� (prev�� Ž���ؾ� �������� ������ ���)
				desti = start;	//�������� ���� ������带 ���۳��� �ʱ�ȭ
				while (1) {
					if (!strcmp(desti->getName(), name2)) break;	//��������� name�� name2�� ���ٸ� �ݺ��� ����
					strcpy(Path[cnt], desti->getName());	//������尡 ���� ������ �ִ� ����� �̸��� ��ο� ����
					cnt++;	//��� ī���� 1 ����
					desti = desti->getPrev();	//��������� ���� ���� ������� ����
				}
				strcpy(Path[cnt], desti->getName());	//������ ����� �̸��� ��ο� ����
				cnt++;	//��� ī���� 1 ����
			}
			else {	//head�� name2 ���� �� ����� ��� (next�� Ž���ؾ� �������� ������ ���)
				desti = start;	//�������� ���� ������带 ���۳��� �ʱ�ȭ
				while (1) {
					if (!strcmp(desti->getName(), name2)) break;	//��������� name�� name2�� ���ٸ� �ݺ��� ����
					strcpy(Path[cnt], desti->getName());	//������尡 ���� ������ �ִ� ����� �̸��� ��ο� ����
					cnt++;	//��� ī���� 1 ����
					desti = desti->getNext();	//��������� ���� ���� ������� ����
				}
				strcpy(Path[cnt], desti->getName());	//������ ����� �̸��� ��ο� ����
				cnt++;	//��� ī���� 1 ����
			}
			if (cnt > 0) {	//��Ŀ� �°� ��� ���
				cout << Path[0];
				for (int i = 1; i < cnt; i++) {
					cout << "->" << Path[i];
				}
			}
		}
		else {	//���ۿ��� 2ȣ���̰�, ������ 2ȣ���� ���
			Node* start = line2.findNode(name1);	//���۳�带 2ȣ���� head�� �ʱ�ȭ
			int disNext = 0;	//Next�� ���� name2���� ã�� ������ �� ���� ���� ������ �ϴ��� �����ϱ� ���� distance of moving next ����
			int disPrev = 0;	//Prev�� ���� name2���� ã�� ������ �� ���� ���� ������ �ϴ��� �����ϱ� ���� distance of moving prev ���� 
			Node* desti = start;	//������带 ���۳��� �ʱ�ȭ
			for (; strcmp(desti->getName(), name2); desti = desti->getNext()) {	//������尡 name2���� ã�� ������ getNext�� ���� �ݺ��ϸ� ���� ����
				disNext++;	//���� �ϳ� ���� ������ disNext ������ 1�� ����
			}
			desti = start;	//������带 ���۳��� �ʱ�ȭ
			for (; strcmp(desti->getName(), name2); desti = desti->getPrev()) {	//������尡 name2���� ã�� ������ getPrev�� ���� �ݺ��ϸ� ���� ����
				disPrev++;	//���� �ϳ� ���� ������ disPrev ������ 1�� ����
			}
			if (disNext > disPrev) {	//start���� Next�� name2���� ã�� �ͺ��� Prev�� name2���� ã�� �� �� ���� ���
				desti = start;	//�������� ���� ������带 ���۳��� �ʱ�ȭ
				while (1) {
					if (!strcmp(desti->getName(), name2)) break;	//��������� name�� name2�� ���ٸ� �ݺ��� ����
					strcpy(Path[cnt], desti->getName());	//������尡 ���� ������ �ִ� ����� �̸��� ��ο� ����
					cnt++;	//��� ī���� 1 ����
					desti = desti->getPrev();	//��������� ���� ���� ������� ����
				}
				strcpy(Path[cnt], desti->getName());	//������ ����� �̸��� ��ο� ����
				cnt++;	//��� ī���� 1 ����
			}
			else {	//start���� Prev�� name2���� ã�� �ͺ��� Next�� name2���� ã�� �� �� ���� ���
				desti = start;	//�������� ���� ������带 ���۳��� �ʱ�ȭ
				while (1) {
					if (!strcmp(desti->getName(), name2)) break;	//��������� name�� name2�� ���ٸ� �ݺ��� ����
					strcpy(Path[cnt], desti->getName());	//������尡 ���� ������ �ִ� ����� �̸��� ��ο� ����
					cnt++;	//��� ī���� 1 ����
					desti = desti->getNext();	//��������� ���� ���� ������� ����
				}
				strcpy(Path[cnt], desti->getName());	//������ ����� �̸��� ��ο� ����
				cnt++;	//��� ī���� 1 ����
			}
			
			if (cnt > 0) {	//��Ŀ� �°� ��� ���
				cout << Path[0];
				for (int i = 1; i < cnt; i++) {
					cout << "->" << Path[i];
				}
			}
		}
	}
}

int main()
{
	class DoublyLinkedList line1 = DoublyLinkedList();	//1ȣ�� ����
	class DoublyCircularLinkedList line2 = DoublyCircularLinkedList();	//2ȣ�� ����
	char station[20];	//���̸� �޾ƿ� char �迭 ����
	ifstream in1("Assignment3-3-2-1.txt");	//in1 ��ü�� Assignment3-3-2-1 text file �ҷ���
	if (in1.is_open()) {
		while (in1 >> station) {	//eof���� �ݺ��Ͽ� ���̸� �޾ƿ�
			class Node* newNode = new Node(station, NULL, NULL);	//�޾ƿ� ���̸����� new Node ����
			line1.insert(newNode);	//1ȣ���� ������ ��� ����
		}
	}
	else {	//ifstream open ���� ����ó��
		cout << "Assignment3-3-2-1.txt cannot open." << endl;
		return 0;
	}
	in1.close();	//text file close
	ifstream in2("Assignment3-3-2-2.txt");	//in1 ��ü�� Assignment3-3-2-1 text file �ҷ���
	if (in2.is_open()) {
		while (in2 >> station) {	//eof���� �ݺ��Ͽ� ���̸� �޾ƿ�
			class Node* newNode = new Node(station, NULL, NULL);	//�޾ƿ� ���̸����� new Node ����
			line2.insert(newNode);	//2ȣ���� ������ ��� ����
		}
	}
	else {	//ifstream open ���� ����ó��
		cout << "Assignment3-3-2-2.txt cannot open." << endl;
		return 0;
	}
	in2.close();	//text file close

	char start[20];	//��߿� ����
	char desti[20];	//������ ����
	strcpy(start, "\0");	//��߿� �ʱ�ȭ
	strcpy(desti, "\0");	//������ �ʱ�ȭ
	cout << "��߿� : ";
	cin >> start;	//��߿� �Է¹���
	cout << "������ : ";
	cin >> desti;	//������ �Է¹���
	printPath(start, desti, line1, line2);	//��߿�->������ ��� ����Լ� ȣ��

	return 0;
}