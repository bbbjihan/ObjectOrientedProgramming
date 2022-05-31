#include <iostream>
using namespace std;

class Node {
private:
	int value;
	Node* left;
	Node* right;
public:
	Node() { this->value = -1; this->left = NULL; this->right = NULL; }	//������
	Node(int value) { this->value = value; this->left = NULL; this->right = NULL; }	//������ overloading
	~Node() { ; }	//�Ҹ���
	int getValue() { return this->value; }	//value ��ȯ�Լ�
	Node* getLeft() { return this->left; }	//left child pointer ��ȯ�Լ�
	Node* getRight() { return this->right; }	//right child pointer ��ȯ�Լ�
	void setLeft(Node* left) { this->left = left; }	//left child pointer set �Լ�
	void setRight(Node* right) { this->right = right; }	//right child pointer set �Լ�
	void setValue(int value) { this->value = value; }	//value set �Լ�
};

class Tree {
private:
	Node* root;
public:
	Tree() { this->root = NULL; }	//BST�� ������
	~Tree() { while(this->root != NULL) deleteNode(this->root->getValue()); }	//insertNode���� ��� ��带 �����Ҵ��������Ƿ� tree�� root�� NULL�� �� ������ root node�� �����ϴ� �Ҹ���
	void insertNode(int input) {	//��� ���� �Լ�
		class Node* newNode = new Node(input);	//������ ��带 �����Ҵ����� ����
		if (this->root == NULL) {	//root�� �������� �ʴ� ���
			this->root = newNode;	//root�� ���Գ��� ����
			return;	//�Լ� ����
		}
		Node* now = this->root;	//Ʈ�� �� ���� ��ġ�� Ȯ���ϱ� ���� Ž���� ���� Ž����带 root�� �ʱ�ȭ
		while (1) {
			if (input < now->getValue()) {	//���Ը�ǥ���� Ž������� value���� ���� ���
				if (now->getLeft() == NULL) {	//Ž������� left child�� �������� �ʴ� ���
					now->setLeft(newNode);	//Ž������� left child�� ��� ����
					return;	//�Լ� ����
				}
				now = now->getLeft();	//Ž������� left child�� �����ϴ� ��� �̸� Ž������ ����
			}
			else if (input > now->getValue()) {	//���Ը�ǥ���� Ž������� value���� ū ���
				if (now->getRight() == NULL) {	//Ž������� right child�� �������� �ʴ� ���
					now->setRight(newNode);	//Ž������� right child�� ��� ����
					return;	//�Լ� ����
				}
				now = now->getRight();	//Ž������� right child�� �����ϴ� ��� �̸� Ž������ ����
			}
			else {	//���Ը�ǥ���� Ž������� value�� ���� ���(�ߺ��� ����)
				delete newNode;	//������ ���� �Ҵ��� ��带 ����
				return;	//�Լ� ����
			}
		}
	}
	void deleteNode(int input) {
		Node* now = this->root;	//������ǥ��� Ž���� ���� root�� �ʱ�ȭ
		Node* prev = NULL;	//������ǥ����� �θ���. ������ǥ��尡 root�� ��� NULL�� ���·� �Ʒ� ����ó���� �����ϰ� ��.
		while (1) {	//������ǥ ��带 ã�� ���� �ݺ�
			if (now == NULL) break;	//������ǥ��带 ã�� ���ϰ� now�� NULL�� �Ǹ� �ݺ� ����
			if (input < now->getValue()) {	//������ǥ���� ���� ����� value���� ���� ���
				prev = now;
				now = now->getLeft();	//Ž�� ��带 left child�� ����
			}
			else if (input > now->getValue()) {	//������ǥ���� ���� ����� value���� ū ���
				prev = now;
				now = now->getRight();	//Ž�� ��带 right child�� ����
			}
			else {	//������ǥ���� ���� ����� value�� ���� ���
				break;	//���� ��带 ������ǥ���� ������ ä�� �ݺ� ����
			}
		}
		if (now != NULL) {	//������ǥ��带 ã�� ���� ���, �Ǵ� root�� NULL�� ��츦 ����ó��
			if (now->getLeft() == NULL && now->getRight() == NULL) {	//������ǥ����� child node�� ���� ���
				if (prev != NULL) {	//������ǥ��尡 root�� �ƴ� ���
					if (input < prev->getValue()) {	//������ǥ����� value�� �θ����� value���� ���� ���(�θ����� left child�� ���)
						prev->setLeft(NULL);	//������ǥ����� �θ����� left child ������ ����
					}
					else {	//������ǥ����� value�� �θ����� value���� ū ���(�θ����� right child�� ���)
						prev->setRight(NULL);	//������ǥ����� �θ����� right child ������ ����
					}
				}
				else {	//������ǥ��尡 root�� ���
					this->root = NULL;	//tree�� root node�� NULL�� �ʱ�ȭ
				}
				delete now;	//������ǥ��� �Ҵ� ����
				return;	//�Լ� ����
			}
			else if (now->getLeft() == NULL) {	//������ǥ����� left child�� �������� �ʴ� ���
				if (prev != NULL) {	//������ǥ��尡 root�� �ƴ� ���
					if (input < prev->getValue()) {	//������ǥ����� value�� �θ����� value���� ���� ���(�θ����� left child�� ���)
						prev->setLeft(now->getRight());	//������ǥ����� �θ����� left child�� ������ǥ����� right child�� ����(left�� NULL�̹Ƿ�)
					}
					else {	//������ǥ����� value�� �θ����� value���� ū ���(�θ����� right child�� ���)
						prev->setRight(now->getRight());	//������ǥ����� �θ����� right child�� ������ǥ����� right child�� ����(left�� NULL�̹Ƿ�)
					}
				}
				else {	//������ǥ��尡 root�� ���
					this->root = this->root->getRight();	//root�� ������ǥ����� right child�� ����(left�� �������� �ʱ� ����)
				}
				delete now;	//������ǥ��� �Ҵ� ����
				return;	//�Լ� ����
			}
			else if (now->getRight() == NULL) {
				if (prev != NULL) {	//������ǥ��尡 root�� �ƴ� ���
					if (input < prev->getValue()) {	//������ǥ����� value�� �θ����� value���� ���� ���(�θ����� left child�� ���)
						prev->setLeft(now->getLeft());	//������ǥ����� �θ����� left child�� ������ǥ����� left child�� ����(right�� NULL�̹Ƿ�)
					}
					else {	//������ǥ����� value�� �θ����� value���� ū ���(�θ����� right child�� ���)
						prev->setRight(now->getLeft());	//������ǥ����� �θ����� right child�� ������ǥ����� left child�� ����(right�� NULL�̹Ƿ�)
					}
				}
				else {	//������ǥ��尡 root�� ���
					this->root = this->root->getLeft();	//root�� ������ǥ����� left child�� ����(right�� �������� �ʱ� ����)
				}
				delete now;	//������ǥ��� �Ҵ� ����
				return;	//�Լ� ����
			}
			else {	//������ǥ����� left child�� right child�� ��� �����ϴ� ���
				Node* target = now->getRight();	//������ǥ���� value�� swap�ϱ� ���� ���� ����Ʈ���� ���� ���� ��带 Ž���ϱ� ���� target ��带 ���� ����Ʈ���� root�� right child�� �ʱ�ȭ
				Node* prevTarget = now;	//target node�� �θ��带 �����ϱ� ���� ��������� �ʱ�ȭ, now�� ���·� ���ǹ��� ����Ѵٸ�, target�� now�� right child�� �ǵ��� ��.
				while (target->getLeft() != NULL) {	//target���� ���� child(left child)�� �������� ���� ������ �ݺ�
					prevTarget = target;
					target = target->getLeft();
				}
				now->setValue(target->getValue());	//value swap. target node�� ������ �����ϰ� �ǹǷ� ���� target node�� value�� set������ �ʾƵ� ��.
				if (prevTarget == now) {	//target node�� now�� right child�� ���
					now->setRight(target->getRight());	//target node�� left child�� �������� �ʴ´ٴ� �ǹ��̹Ƿ� target node�� right child�� ������ǥ����� right child�� ����
				}
				else {	//target node�� now�� right child�� �ƴ�, ���� ����Ʈ���� ���� ���� ������ ������ ���
					prevTarget->setLeft(target->getRight());	//target node�� �θ����� left child �����͸� target�� right child�� ����
				}
				delete target;	//target node �Ҵ� ����
				return;	//�Լ� ����
			}
		}
	}
	void findNode(int input) {
		Node* now = this->root;	//��ǥ��� Ž���� ���� root�� �ʱ�ȭ
		while (1) {	//��ǥ ��带 ã�� ���� �ݺ�
			if (now == NULL) break;	//��ǥ��带 ã�� ���ϰ� now�� NULL�� �Ǹ� �ݺ� ����
			if (input < now->getValue()) {	//��ǥ���� Ž�� ����� value���� ���� ���(��ǥ ��尡 ���� ����Ʈ���� �����ϴ� ���)
				now = now->getLeft();	//Ž�� ��带 Ž�� ����� left child�� ����
			}
			else if (input > now->getValue()) {	//��ǥ���� Ž�� ����� value���� ū ���(��ǥ ��尡 ������ ����Ʈ���� �����ϴ� ���)
				now = now->getRight();	//Ž�� ��带 Ž�� ����� right child�� ����
			}
			else {	//Ž�� ����� ���� ��ǥ���� ���� ���
				break;	//�ݺ��� ����
			}
		}
		if (now == NULL) return;	//now�� NULL�̸� ���� �ݺ������� ��ǥ�� ã�� ���߰ų�, tree�� root�� NULL�� ����̹Ƿ� �Լ� ����
		cout << this->root->getValue();	//root�� ���
		now = this->root;	//��ǥ��� ��Ž���� ���� root�� �ʱ�ȭ
		while (1) {	//��ǥ ����� ��θ� ����ϱ� ���� ��ǥ��� ��Ž�� �� ��� ���
			if (now != this->root) cout << "->" << now->getValue();	//��� format�� �����ֱ� ���� root�� ��츦 �����ϰ� ȭ��ǥ�� �Բ� ���
			if (input < now->getValue()) {	//��ǥ���� Ž�� ����� value���� ���� ���(��ǥ ��尡 ���� ����Ʈ���� �����ϴ� ���)
				now = now->getLeft();	//Ž�� ��带 Ž�� ����� left child�� ����
			}
			else if (input > now->getValue()) {	//��ǥ���� Ž�� ����� value���� ū ���(��ǥ ��尡 ������ ����Ʈ���� �����ϴ� ���)
				now = now->getRight();	//Ž�� ��带 Ž�� ����� right child�� ����
			}
			else {	//Ž�� ����� ���� ��ǥ���� ���� ���
				break;	//�ݺ��� ����
			}
		}
		cout << "\n";	//���๮�� ���
	}
};

int main() {
	class Tree tree = Tree();
	int command = -1;
	do {
		cout << "Enter Any Command(1:Insert, 2:Delete, 3:Find, 4:Exit): ";
		cin >> command;	//�Է����� int�� �ʱ�ȭ
		if (command == 1) {	//ù ��° �Է��� 1�� ���
			int input_num;
			cin >> input_num;	//�� ��° �Է����� int value ����
			tree.insertNode(input_num);	//insertNode �Լ� ȣ��
		}
		else if (command == 2) {	//ù ��° �Է��� 2�� ���
			int input_num;
			cin >> input_num;	//�� ��° �Է����� int value ����
			tree.deleteNode(input_num);	//deleteNode �Լ� ȣ��
		}
		else if (command == 3) {	//ù ��° �Է��� 3�� ���
			int input_num;
			cin >> input_num;	//�� ��° �Է����� int value ����
			tree.findNode(input_num);	//findNode �Լ� ȣ��
		}
	} while (command != 4);	//�Է��� 4�� ��� �ݺ��� ����
	return 0;
}