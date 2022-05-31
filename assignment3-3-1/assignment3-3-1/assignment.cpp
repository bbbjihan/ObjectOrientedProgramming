#include <iostream>
using namespace std;

class Node {
private:
	int value;
	Node* left;
	Node* right;
public:
	Node() { this->value = -1; this->left = NULL; this->right = NULL; }	//생성자
	Node(int value) { this->value = value; this->left = NULL; this->right = NULL; }	//생성자 overloading
	~Node() { ; }	//소멸자
	int getValue() { return this->value; }	//value 반환함수
	Node* getLeft() { return this->left; }	//left child pointer 반환함수
	Node* getRight() { return this->right; }	//right child pointer 반환함수
	void setLeft(Node* left) { this->left = left; }	//left child pointer set 함수
	void setRight(Node* right) { this->right = right; }	//right child pointer set 함수
	void setValue(int value) { this->value = value; }	//value set 함수
};

class Tree {
private:
	Node* root;
public:
	Tree() { this->root = NULL; }	//BST의 생성자
	~Tree() { while(this->root != NULL) deleteNode(this->root->getValue()); }	//insertNode에서 모든 노드를 동적할당해줬으므로 tree의 root가 NULL이 될 때까지 root node를 삭제하는 소멸자
	void insertNode(int input) {	//노드 삽입 함수
		class Node* newNode = new Node(input);	//삽입할 노드를 동적할당으로 생성
		if (this->root == NULL) {	//root가 존재하지 않는 경우
			this->root = newNode;	//root를 삽입노드로 설정
			return;	//함수 종료
		}
		Node* now = this->root;	//트리 내 삽입 위치를 확인하기 위한 탐색을 위해 탐색노드를 root로 초기화
		while (1) {
			if (input < now->getValue()) {	//삽입목표값이 탐색노드의 value보다 작은 경우
				if (now->getLeft() == NULL) {	//탐색노드의 left child가 존재하지 않는 경우
					now->setLeft(newNode);	//탐색노드의 left child로 노드 삽입
					return;	//함수 종료
				}
				now = now->getLeft();	//탐색노드의 left child가 존재하는 경우 이를 탐색노드로 지정
			}
			else if (input > now->getValue()) {	//삽입목표값이 탐색노드의 value보다 큰 경우
				if (now->getRight() == NULL) {	//탐색노드의 right child가 존재하지 않는 경우
					now->setRight(newNode);	//탐색노드의 right child로 노드 삽입
					return;	//함수 종료
				}
				now = now->getRight();	//탐색노드의 right child가 존재하는 경우 이를 탐색노드로 지정
			}
			else {	//삽입목표값과 탐색노드의 value가 같은 경우(중복값 존재)
				delete newNode;	//삽입을 위해 할당한 노드를 삭제
				return;	//함수 종료
			}
		}
	}
	void deleteNode(int input) {
		Node* now = this->root;	//삭제목표노드 탐색을 위해 root로 초기화
		Node* prev = NULL;	//삭제목표노드의 부모노드. 삭제목표노드가 root인 경우 NULL인 상태로 아래 삭제처리에 진입하게 됨.
		while (1) {	//삭제목표 노드를 찾기 위해 반복
			if (now == NULL) break;	//삭제목표노드를 찾지 못하고 now가 NULL이 되면 반복 종료
			if (input < now->getValue()) {	//삭제목표값이 현재 노드의 value보다 작은 경우
				prev = now;
				now = now->getLeft();	//탐색 노드를 left child로 변경
			}
			else if (input > now->getValue()) {	//삭제목표값이 현재 노드의 value보다 큰 경우
				prev = now;
				now = now->getRight();	//탐색 노드를 right child로 변경
			}
			else {	//삭제목표값이 현재 노드의 value와 같은 경우
				break;	//현재 노드를 삭제목표노드로 저장한 채로 반복 종료
			}
		}
		if (now != NULL) {	//삭제목표노드를 찾지 못한 경우, 또는 root가 NULL인 경우를 예외처리
			if (now->getLeft() == NULL && now->getRight() == NULL) {	//삭제목표노드의 child node가 없는 경우
				if (prev != NULL) {	//삭제목표노드가 root가 아닌 경우
					if (input < prev->getValue()) {	//삭제목표노드의 value가 부모노드의 value보다 작은 경우(부모노드의 left child인 경우)
						prev->setLeft(NULL);	//삭제목표노드의 부모노드의 left child 포인터 해제
					}
					else {	//삭제목표노드의 value가 부모노드의 value보다 큰 경우(부모노드의 right child인 경우)
						prev->setRight(NULL);	//삭제목표노드의 부모노드의 right child 포인터 해제
					}
				}
				else {	//삭제목표노드가 root인 경우
					this->root = NULL;	//tree의 root node를 NULL로 초기화
				}
				delete now;	//삭제목표노드 할당 해제
				return;	//함수 종료
			}
			else if (now->getLeft() == NULL) {	//삭제목표노드의 left child가 존재하지 않는 경우
				if (prev != NULL) {	//삭제목표노드가 root가 아닌 경우
					if (input < prev->getValue()) {	//삭제목표노드의 value가 부모노드의 value보다 작은 경우(부모노드의 left child인 경우)
						prev->setLeft(now->getRight());	//삭제목표노드의 부모노드의 left child를 삭제목표노드의 right child로 지정(left가 NULL이므로)
					}
					else {	//삭제목표노드의 value가 부모노드의 value보다 큰 경우(부모노드의 right child인 경우)
						prev->setRight(now->getRight());	//삭제목표노드의 부모노드의 right child를 삭제목표노드의 right child로 지정(left가 NULL이므로)
					}
				}
				else {	//삭제목표노드가 root인 경우
					this->root = this->root->getRight();	//root를 삭제목표노드의 right child로 지정(left는 존재하지 않기 때문)
				}
				delete now;	//삭제목표노드 할당 해제
				return;	//함수 종료
			}
			else if (now->getRight() == NULL) {
				if (prev != NULL) {	//삭제목표노드가 root가 아닌 경우
					if (input < prev->getValue()) {	//삭제목표노드의 value가 부모노드의 value보다 작은 경우(부모노드의 left child인 경우)
						prev->setLeft(now->getLeft());	//삭제목표노드의 부모노드의 left child를 삭제목표노드의 left child로 지정(right가 NULL이므로)
					}
					else {	//삭제목표노드의 value가 부모노드의 value보다 큰 경우(부모노드의 right child인 경우)
						prev->setRight(now->getLeft());	//삭제목표노드의 부모노드의 right child를 삭제목표노드의 left child로 지정(right가 NULL이므로)
					}
				}
				else {	//삭제목표노드가 root인 경우
					this->root = this->root->getLeft();	//root를 삭제목표노드의 left child로 지정(right는 존재하지 않기 때문)
				}
				delete now;	//삭제목표노드 할당 해제
				return;	//함수 종료
			}
			else {	//삭제목표노드의 left child와 right child가 모두 존재하는 경우
				Node* target = now->getRight();	//삭제목표노드와 value를 swap하기 위한 우측 서브트리의 가장 작은 노드를 탐색하기 위해 target 노드를 우측 서브트리의 root인 right child로 초기화
				Node* prevTarget = now;	//target node의 부모노드를 저장하기 위한 노드포인터 초기화, now인 상태로 조건문을 통과한다면, target이 now의 right child가 되도록 함.
				while (target->getLeft() != NULL) {	//target보다 작은 child(left child)가 존재하지 않을 때까지 반복
					prevTarget = target;
					target = target->getLeft();
				}
				now->setValue(target->getValue());	//value swap. target node는 어차피 삭제하게 되므로 굳이 target node의 value를 set해주지 않아도 됨.
				if (prevTarget == now) {	//target node가 now의 right child인 경우
					now->setRight(target->getRight());	//target node의 left child가 존재하지 않는다는 의미이므로 target node의 right child를 삭제목표노드의 right child로 지정
				}
				else {	//target node가 now의 right child가 아닌, 우측 서브트리의 가장 작은 값으로 설정된 경우
					prevTarget->setLeft(target->getRight());	//target node의 부모노드의 left child 포인터를 target의 right child로 지정
				}
				delete target;	//target node 할당 해제
				return;	//함수 종료
			}
		}
	}
	void findNode(int input) {
		Node* now = this->root;	//목표노드 탐색을 위해 root로 초기화
		while (1) {	//목표 노드를 찾기 위해 반복
			if (now == NULL) break;	//목표노드를 찾지 못하고 now가 NULL이 되면 반복 종료
			if (input < now->getValue()) {	//목표값이 탐색 노드의 value보다 작은 경우(목표 노드가 왼쪽 서브트리에 존재하는 경우)
				now = now->getLeft();	//탐색 노드를 탐색 노드의 left child로 지정
			}
			else if (input > now->getValue()) {	//목표값이 탐색 노드의 value보다 큰 경우(목표 노드가 오른쪽 서브트리에 존재하는 경우)
				now = now->getRight();	//탐색 노드를 탐색 노드의 right child로 지정
			}
			else {	//탐색 노드의 값이 목표값과 같은 경우
				break;	//반복문 종료
			}
		}
		if (now == NULL) return;	//now가 NULL이면 위의 반복문에서 목표를 찾지 못했거나, tree의 root가 NULL인 경우이므로 함수 종료
		cout << this->root->getValue();	//root값 출력
		now = this->root;	//목표노드 재탐색을 위해 root로 초기화
		while (1) {	//목표 노드의 경로를 출력하기 위해 목표노드 재탐색 및 경로 출력
			if (now != this->root) cout << "->" << now->getValue();	//출력 format에 맞춰주기 위해 root인 경우를 제외하고 화살표와 함께 출력
			if (input < now->getValue()) {	//목표값이 탐색 노드의 value보다 작은 경우(목표 노드가 왼쪽 서브트리에 존재하는 경우)
				now = now->getLeft();	//탐색 노드를 탐색 노드의 left child로 지정
			}
			else if (input > now->getValue()) {	//목표값이 탐색 노드의 value보다 큰 경우(목표 노드가 오른쪽 서브트리에 존재하는 경우)
				now = now->getRight();	//탐색 노드를 탐색 노드의 right child로 지정
			}
			else {	//탐색 노드의 값이 목표값과 같은 경우
				break;	//반복문 종료
			}
		}
		cout << "\n";	//개행문자 출력
	}
};

int main() {
	class Tree tree = Tree();
	int command = -1;
	do {
		cout << "Enter Any Command(1:Insert, 2:Delete, 3:Find, 4:Exit): ";
		cin >> command;	//입력으로 int값 초기화
		if (command == 1) {	//첫 번째 입력이 1인 경우
			int input_num;
			cin >> input_num;	//두 번째 입력으로 int value 받음
			tree.insertNode(input_num);	//insertNode 함수 호출
		}
		else if (command == 2) {	//첫 번째 입력이 2인 경우
			int input_num;
			cin >> input_num;	//두 번째 입력으로 int value 받음
			tree.deleteNode(input_num);	//deleteNode 함수 호출
		}
		else if (command == 3) {	//첫 번째 입력이 3인 경우
			int input_num;
			cin >> input_num;	//두 번째 입력으로 int value 받음
			tree.findNode(input_num);	//findNode 함수 호출
		}
	} while (command != 4);	//입력이 4인 경우 반복문 종료
	return 0;
}