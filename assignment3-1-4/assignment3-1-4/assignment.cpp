#include <iostream>
#pragma warning(disable : 4996)

using namespace std;

class Node {
public:
	Node* prev;	//이전 노드의 주소
	Node* next;	//다음 노드의 주소
	int id;	//data 중 id
	char name[10];	//data 중 name
	Node() {	//생성자
		prev = NULL;
		next = NULL;
		id = 0;
		strcpy(name, "\0");
	}
	Node(Node* prev, Node* next, int id, char* name) {	//생성자 오버로딩
		this->prev = prev;
		this->next = next;
		this->id = id;
		strcpy(this->name, name);
	}
	~Node() { ; }	//소멸자
	friend void swap(Node* A, Node* B) {	//연속된 두 노드의 위치를 변경해주는 함수
		Node* prevswap = A->prev;	//연속된 두 노드의 앞선 노드의 주소값 저장
		Node* nextswap = B->next;	//연속된 두 노드의 다음 노드의 주소값 저장
		A->prev = B;
		B->next = A;
		B->prev = prevswap;
		A->next = nextswap;
		if (prevswap != NULL) prevswap->next = B;	//prevswap이 null인 경우 prevswap->next의 참조가 불가하기 때문에 예외처리
		if (nextswap != NULL) nextswap->prev = A;	//nextswap이 null인 경우 nextswap->prev의 참조가 불가하기 때문에 예외처리
	}
};

class List {
public:
	Node* head;	//첫 번째 노드의 주소
	List() {	//생성자
		head = NULL;
	}
	~List() {	//소멸자. insert 내에서 노드를 동적할당해주며 삽입하기 때문에 순회하며 동적할당 해제해주는 형식
		Node* now = head;
		Node* prev = NULL;
		if (now != NULL) {
			while (now->next != NULL) {	//탐색 중인 노드가 마지막 노드가 될 때까지
				prev = now;
				now = now->next;
				delete prev;	//탐색 중인 노드의 앞선 노드 할당 해제
			}
			delete now;	//마지막 노드 할당 해제
		}
	}
	void insert(int id, char* name) {	//노드삽입함수
		Node* now = head;
		if (now == NULL) {	//리스트에 노드가 하나도 없을 경우
			Node* newNode = new Node(NULL, NULL, id, name);	//삽입할 새로운 노드 동적할당
			this->head = newNode;	//첫번째 노드로 삽입
		}
		else {
			while (now->next != NULL) {	//마지막 노드까지 탐색하며
				if (now->id == id) return;	//삽입 노드와 중복된 노드가 있는 경우 삽입함수 종료
				now = now->next;
			}
			if (now->id == id) return;	//마지막 노드가 삽입 노드와 중복된 경우 삽입함수 종료

			now = head;
			Node* newNode = new Node(NULL, NULL, id, name);	//삽입할 새로운 노드 동적할당
			while (now->next != NULL) {	//마지막 노드까지 탐색하며
				if (now->id > id) {	//탐색 중인 노드의 id가 삽입하려는 id보다 큰 경우
					if (now == head) this->head = newNode;
					newNode->prev = now->prev;
					newNode->next = now;
					if (now->prev != NULL) (now->prev)->next = newNode;
					now->prev = newNode;
					return;	//탐색 중인 노드의 자리에 생성한 노드 삽입
				}
				now = now->next;	//다음 노드 탐색
			}
			if (now->id > id) {	//마지막 노드의 id가 삽입하려는 id보다 큰 경우
				if (now == head) this->head = newNode;
				newNode->prev = now->prev;
				newNode->next = now;
				if (now->prev != NULL) (now->prev)->next = newNode;
				now->prev = newNode;	//마지막 노드의 앞자리에 생성한 노드 삽입
			}
			else {	//마지막 노드의 id까지 삽입id보다 작은 경우(삽입하려는 id가 리스트 내에서 가장 큰 id인 경우)
				now->next = newNode;
				newNode->prev = now;	//마지막에 노드 삽입
			}
		}
	}
	void print() {
		Node* now = head;
		if (now != NULL) {
			while (now->next != NULL) {	//마지막 노드까지 탐색하며
				cout << now->id << " " << now->name << "\n";	//node date 출력
				now = now->next;
			}
			cout << now->id << " " << now->name << "\n";	//마지막 노드 출력
		}
	}
	void print_reverse() {
		Node* now = head;
		if (now != NULL) {
			while (now->next != NULL) {	//now를 마지막 노드로 초기화해줌.
				now = now->next;
			}
			while (now->prev != NULL) {	//마지막 노드부터 첫 노드까지 탐색하며
				cout << now->id << " " << now->name << "\n";	//node data 출력
				now = now->prev;
			}
			cout << now->id << " " << now->name << "\n";	//첫번째 노드 출력
		}
	}
	void sort_by_name() {	//이름순으로 리스트 내에서 버블정렬하는 함수
		Node* inode = head;
		Node* jnode = inode;
		if (head != NULL) {
			while (inode->next != NULL) {	//마지막 노드까지 한 단계마다 정렬 수행
				jnode = head;	//첫 번째 노드로 jnode 초기화
				while (jnode != inode && jnode->next != NULL) {	//jnode가 inode와 같아지거나 jnode가 list의 마지막에 도달하지 않은 경우 수행
					if (strcmp(jnode->name, jnode->next->name)>0) {	//탐색 중인 노드의 name과 다음 노드의 name을 비교하여 탐색 중인 노드의 name값이 더 큰 경우
						if (jnode == head) head = jnode->next;
						swap(jnode, jnode->next);	//두 노드의 위치를 교체해줌.
					}
					else {
						jnode = jnode->next;
					}
				}
				inode = inode->next;
			}
		}
	}
	void sort_by_ID() {	//id순으로 리스트 내에서 버블정렬하는 함수
		Node* inode = head;
		Node* jnode = inode;
		if (head != NULL) {
			while (inode->next != NULL) {
				jnode = head;	//첫 번째 노드로 jnode 초기화
				while (jnode != inode && jnode->next != NULL) {	//jnode가 inode와 같아지거나 jnode가 list의 마지막에 도달하지 않은 경우 수행
					if (jnode->id > jnode->next->id) {	//탐색 중인 노드의 id와 다음 노드의 id를 비교하여 탐색 중인 노드의 id값이 더 큰 경우
						if (jnode == head) head = jnode->next;
						swap(jnode, jnode->next);	//두 노드의 위치를 교체해줌.
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
			while (now->next != NULL) {	//마지막 노드까지 탐색하며
				if (now->id == id) {	//탐색 중인 노드의 id가 삭제 목표 id와 같은 경우
					if (now->prev == NULL) {	//탐색 중인 노드가 head인 경우
						this->head = now->next;	//list의 head를 두 번째 노드로 변경
					}
					else {
						now->prev->next = now->next;	//앞선 노드의 다음 노드를 탐색 중인 노드의 다음으로 변경
					}
					now->next->prev = now->prev;	//탐색 중인 노드의 다음 노드의 앞선 노드를 탐색 노드의 앞 노드로 변경
					delete now;	//탐색 노드 동적할당 해제
					return;	//함수 종료(중복 id가 존재하지 않으므로 바로 종료해도 됨)
				}
				now = now->next;
			}
			if (now->id == id) {	//마지막 노드의 id가 삭제 목표 id와 같은 경우
				if (now->prev == NULL) {	//노드가 하나밖에 존재하지 않는 경우
					this->head = NULL;	//head를 NULL로 초기화
				}
				else {	//마지막 노드가 첫번째 노드가 아닌 경우
					now->prev->next = now->next;	//뒤에서 두번째 노드의 다음 노드를 NULL로 변경
				}
				delete now;	//탐색 노드 동적할당 해제
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
		if (command == 1) {	//첫번째 입력이 1인 경우
			int input_id;
			char input_name[10];
			cin >> input_id >> input_name;	//2,3번째 입력으로 id와 name을 받음

			list.insert(input_id, input_name);	//삽입함수 호출
		}
		else if (command == 2) {	//첫번째 입력이 2인 경우
			list.print();	//print 함수 호출
		}
		else if (command == 3) {	//첫번째 입력이 3인 경우
			list.print_reverse();	//print_reverse함수 호출
		}
		else if (command == 4) {	//첫번째 입력이 4인 경우
			list.sort_by_name();	//sort_by_name함수 호출
		}
		else if (command == 5) {	//첫번째 입력이 5인 경우
			list.sort_by_ID();	//sort_by_ID함수 호출
		}
		else if (command == 6) {	//첫번째 입력이 6인 경우
			int input_id;
			cin >> input_id;	//두번째 입력으로 id를 받음

			list.delete_node(input_id);	//delete_node함수 호출
		}
	} while (command != 7);	//첫번째 입력이 7인 경우 반복문 종료
	return 0;
}