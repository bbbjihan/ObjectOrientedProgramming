#include <iostream>
#include <fstream>
#include <cassert>
#pragma warning(disable : 4996)
using namespace std;

int my_strcmp_nocase(const char* str1, const char* str2);
int my_strcmp_nocase(const char str1, const char str2);

class Node {	//�� ���ĺ� �ܾ��� ������ �ܾ������� ������ ��� ����
private:
	char data[20];	//data ������� ����
	Node* next;	//���� ��带 ����Ű�� next ������� ����
public:
	Node() { strcpy(this->data,"\0"); this->next = NULL; }	//Node ��ü ������
	Node(char* data, Node* next) { strcpy(this->data, data); this->next = next	; }	//Node ��ü ������ overloading
	~Node() { ; }	//Node ��ü �Ҹ���
	char* getData() { return this->data; }	//Node ��ü data ��ȯ�Լ�
	Node* getNext() { return this->next; }	//Node ��ü next ��ȯ�Լ�
	void setNext(Node* next) { this->next = next; }	//Node ��ü next �����Լ�(insert�� ���)
};

class AlphaNode {	//�� ���ĺ������� ������ AlphaNode ����
private:
	char alpha;	//� ���ĺ� List�� �������������� �˷��ֱ� ���� alpha ������� ����
	AlphaNode* next;	//���� ���ĺ��� ����Ű�� ���� next ����
	Node* head;	//�ش� ���ĺ��� ù ��° �ܾ ����Ű�� ���� head ����
public:
	AlphaNode() { this->alpha = NULL; this->next = NULL; this->head = NULL; }	//AlphaNode ��ü ������
	AlphaNode(char alpha, AlphaNode* next, Node* head) {	//AlphaNode ��ü ������ overloading
		this->alpha = alpha;
		this->next = next;
		this->head = head;
	}
	~AlphaNode() { ; }	//AlphaNode ��ü �Ҹ���
	char getAlpha() { return this->alpha; }	//AlphaNode ��ü alpha ��ȯ�Լ�
	Node* getHead() { return this->head; }	//AlphaNode ��ü head ��ȯ�Լ�(�ش���ĺ����� �����ϴ� �ܾ� �� ù ��°)
	AlphaNode* getNext() { return this->next; }	//AlphaNode ��ü next ��ȯ�Լ�(���� ���ĺ�)
	void setNext(AlphaNode* next) { this->next = next; }	//AlphaNode ��ü next �����Լ�(insert�� ���)
	void insert(char* word) {	//�� AlphaNode�� List�� ��� �����Ƿ� AlphaNode ���� LinkedList�� word�� data�� ��� �ִ� node�� �������ִ� �Լ�
		class Node* newNode = new Node(word, NULL);	//������ ��� �����Ҵ�
		if (this->head == NULL) {	//�ش� ���ĺ��� list�� ����ִ� ���
			this->head = newNode;	//���Գ�带 head�� ����
			return;	//�Լ� ����
		}
		Node* prev = NULL;
		Node* tmp = this->head;
		for (; tmp != NULL; tmp = tmp->getNext()) {	//�ش� ���ĺ��� list�� �����ϴ� ��� node�� head�������� next�� ���� ��ȸ
			if (my_strcmp_nocase(tmp->getData(), word) > 0) {	//�����Ϸ��� node�� data�� Ž�� ���� node�� data�� ���Ͽ��� �� ���Գ���� data�� ���������� �� ���� ���
				newNode->setNext(tmp);	//���Գ���� next�� Ž�� ���� ���� ����
				if (prev != NULL)prev->setNext(newNode);	//prev�� NULL�� �ƴ� ���(���Ը�ǥ ��ġ�� head�� �ƴ� ���)	������ġ ���� ����� next�� ���Գ��� ����
				if (prev == NULL)this->head = newNode;	//prev�� NULL�� ���(���Ը�ǥ ��ġ�� head�� ���) �ش� list�� head�� ���Գ��� ����
				return;	//�Լ� ����
			}
			prev = tmp;
		}	//�������� �˰���
		prev->setNext(newNode);	//�Լ��� ������� �ʾ��� ���(��� node�� data�� �Է°����� �տ� �־�� �ϴ� ���) ������ node�� next�� ���Գ��� ����
	}
};

class List {	//AlphaNode���� ������ List ��ü ����
private:
	AlphaNode* head;	//Linked List�� head ����
public:
	List() { this->head = NULL; }	//List ��ü�� ������
	~List() { ; }	//List��ü�� �Ҹ���
	void insert(char* word) {	//AlphaNode�� �� node�� ������ list�� AlphaNode�� �����ϴ� �Լ�
		class AlphaNode* newAlpha = new AlphaNode(toupper(word[0]), NULL, NULL);
		//word�� ù������ �빮�ڰ��� alpha ��������� �ϴ� AlphaNode newAlpha ��ü �����Ҵ�
		if (this->head == NULL) {	//List�� head�� NULL�� ���(List�� �� ���)
			this->head = newAlpha;	//List�� head�� newAlpha�� ����
			newAlpha->insert(word);	//newAlpha AlphaNode�� ����Լ� insert ȣ��� ù �ܾ� ����
			return;	//�Լ� ����
		}
		AlphaNode* prev = NULL;
		AlphaNode* tmp = this->head;
		for (; tmp != NULL; tmp = tmp->getNext()) {		//�ش� list�� �����ϴ� ��� node�� head�������� next�� ���� ��ȸ
			if (!my_strcmp_nocase(tmp->getAlpha(), word[0])) {	//�����Ϸ��� ���ĺ��� AlphaNode�� �̹� �����ϴ� ���
				tmp->insert(word);	//�� AlphaNode�� ����Լ� insert ȣ��� ���ο� �ܾ� ����
				delete newAlpha;	//�����Ϸ��� AlphaNode ����
				return;	//�Լ� ����
			}
			else if (my_strcmp_nocase(tmp->getAlpha(), word[0]) > 0) {	//ó������ ����AlphaNode���� �ڿ� �;��ϴ� AlphaNode�� ã�� ���
				newAlpha->setNext(tmp);	//���� AlphaNode�� next�� Ž�� AlphaNode�� ����
				if (prev != NULL)prev->setNext(newAlpha);	//prev�� NULL�� �ƴ� ���(������ġ�� head�� �ƴ� ���) Ž������� ��������� next�� ���Գ��� ����
				newAlpha->insert(word);	//���� AlphaNode�� ������� insert�� ù �ܾ� ����
				if (prev == NULL) this->head = newAlpha;	//prev�� NULL�� ���(������ġ�� head�� ���) �ش� list�� head�� ���Գ��� ����
				return;	//�Լ� ����
			}
			prev = tmp;
		}
		prev->setNext(newAlpha);	//������ �Լ� ������� ���� ��� ��� node�� �� �������� next�� ���Գ�� ����(�� �ڿ� ����)
		newAlpha->insert(word);	//���� AlphaNode�� ������� insert�� ù �ܾ� ����
	}
	void print() {	//2���� Linked List ����Լ�
		for (AlphaNode* tmpAlpha = this->head; tmpAlpha != NULL; tmpAlpha = tmpAlpha->getNext()) {	//��� AlphaNode�� ���Ͽ� head���� ��ȸ
			cout << tmpAlpha->getAlpha();	//�� AlphaNode�� ���� ���ĺ��� �ǹ��ϴ��� ���
			for (Node* tmpNode = tmpAlpha->getHead(); tmpNode != NULL; tmpNode = tmpNode->getNext()) {	//�� AlphaNode�� ����� ��� Node�� ���Ͽ� head���� ��ȸ
				cout << " -> " << tmpNode->getData();	//"->"�� �� Node�� �����ϰ� �ִ� �ܾ� ���
			}
			cout << "\n";	//�� AlphaNode���� ���๮�� ���
		}
	}
};

int main() {
	char tmp[20];
	class List list = List();	//Linked List ��ü ����

	ifstream inobj("Assignment.txt");	//�ܾ� ����� file open
	if (!inobj) {	//open error ����ó��
		cout << "Assignment.txt cannot open." << "\n";
		assert(false);
	}
	while (!inobj.eof()) {	//eof���� �ݺ�
		inobj >> tmp;	//tmp�� �ܾ� �ϳ��� ���
		list.insert(tmp);	//��µ� �ܾ�� List�� ����
	}
	inobj.close();	//file close

	list.print();	//Linked List print
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
	return a - b;
}