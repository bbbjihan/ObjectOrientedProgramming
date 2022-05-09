#include <iostream>
#pragma warning(disable : 4996)
using namespace std;

class Node {
private:
	int value;
	Node* next;
public:
	Node() {	//노드 생성자
		this->value = 0;
		this->next = NULL;
	}
	Node(int value, Node* next) {	//노드 생성자 overloading
		this->value = value;
		this->next = next;
	}
	~Node() { ; }	//노드 소멸자
	int get_value() {	//노드 value 반환함수
		return this->value;
	}
	Node* get_next() {	//노드 next 반환함수
		return this->next;
	}
	void set_next(Node* input) {	//노드 next 변경용 함수
		 this->next = input;
	}
};

class List {
private:
	Node* head;
public:
	List() { head = NULL; }	//List class 생성자
	~List() { ; }	//List class 소멸자
	void insert(Node* tmp) {	//insert 함수
		if (this->head == NULL) {	//list의 head가 존재하지 않으면,
			this->head = tmp;	//파라미터로 받은 노드를 head로 초기화
		}
		else {	//list의 head가 존재하면,
			Node* now = this->head;	//list 순회용 임시 포인터 생성
			while (now->get_next() != NULL) {	//탐색 중의 노드의 다음 노드가 없을 때까지 반복
				now = now->get_next();	//탐색 중인 노드의 다음 노드를 탐색 노드로 변경
			}
			now->set_next(tmp);	//list의 마지막 node의 next를 파라미터로 받은 노드로 초기화
		}
	}
	void find(int target) {	//find 함수
		if (this->head == NULL) {	//list의 head가 존재하지 않으면,
			cout << "empty list" << "\n";	//경고문 출력 및 함수 종료
		}
		else {	//list의 head가 존재하면,
			Node* now = this->head;	//list 순회용 임시 포인터 생성
			int index = 1;	//출력을 위한 index 변수 선언 및 초기화
			while (now->get_next() != NULL) {	//탐색 중인 노드의 다음 노드가 없을 때까지 반복
				if (now->get_value() == target) {	//탐색 중인 노드의 value가 파라미터 값과 같은 경우
					cout << "Found Index:" << index << "\n";	//탐색 중인 노드의 index값 출력
				}
				now = now->get_next();	//탐색 중인 노드의 다음 노드를 탐색 노드로 변경
				index++;	//index 1 증가
			}
			if (now->get_value() == target) {	//while문의 반복이 끝난 이후 마지막 노드에 대해 파라미터와 같은 value를 갖는지 검사
				cout << "Found Index:" << index << "\n";
			}
		}
	}
	void delete_node(int target) {
		if (this->head == NULL) {	//list의 head가 존재하지 않으면,
			cout << "empty list" << "\n";	//경고문 출력 및 함수 종료
		}
		else {	//list의 head가 존재하면,
			while (head != NULL && this->head->get_value() == target) {	//head가 존재하고, head의 value가 파라미터로 받은 delete target과 같은 경우 
				this->head = this->head->get_next();//list의 head를 현재 head의 next로 변경
			}
			if (this->head == NULL || this->head->get_next() == NULL) {	//head가 존재하지 않거나, head의 다음 노드가 존재하지 않는 경우
				return;	//함수 종료(위의 while문에서 이미 head 노드는 목표와 무조건 다르기 때문에, head의 다음 노드의 존재 확인을 해도 문제되지 않음)
			}
			Node* now = this->head->get_next();	//list 순회용 포인터 생성(현재 탐색중)
			Node* prev = this->head;	//list 순회용 포인터 생성(이전 탐색 노드)
			while (now->get_next() != NULL) {	//현재 탐색 중인 노드의 다음 노드가 없을 때까지 반복
				if (now->get_value() == target) {	//현재 탐색 중인 노드의 value가 delete target과 같은 경우
					prev->set_next(now->get_next());	//현재 탐색 중인 노드를 가리키고 있는 prev 노드의 next를 현재 탐색 중인 노드의 next로 변경함.
				}
				else {
					prev = now;
				}	//현재 탐색 중인 노드를 list에서 제거한 경우 prev를 now로 업데이트해줄 필요가 없기 때문에 list에서 제거하지 않은 경우에만 prev를 now로 업데이트해줌.
				now = now->get_next();	//탐색 중인 노드의 다음 노드를 탐색 노드로 변경
			}
			if (now->get_value() == target) {	//while문의 반복이 끝난 이후 마지막 노드에 대하여 delete target과 같다면,
				prev->set_next(NULL);	//이전 단계 탐색 노드의 next를 NULL로 지정
			}
		}
	}
	void print() {
		int cnt = 1;
		if (this->head == NULL) {	//list의 head가 존재하지 않으면,
			cout << "empty list" << "\n";	//경고문 출력 및 함수 종료
		}
		else {	//list의 head가 존재하면,
			Node* now = this->head;	//list 순회용 임시 포인터 생성
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
	class List list = List();	//리스트 선언

	while (1) {
		char command[10];	//command 선언
		cout << "Please Enter Command(1:insert,2:find,3:delete,4:print,5:quit) : ";
		cin >> command;	//command 입력받음
		if(!strcmp(command,"insert")){	//command가 insert인 경우
			int input_value;
			cin >> input_value;	//두 번째 입력으로 input_value를 받음

			Node* tmp = new Node(input_value,NULL);	//추가를 목적으로 하는, value가 input_value인 임시 노드 선언 및 초기화
			list.insert(tmp);	//위에서 초기화한 tmp Node를 list에 추가하는 insert함수 호출
		}
		else if (!strcmp(command, "find")) {	//command가 find인 경우
			int input_value;
			cin >> input_value;	//두 번째 입력으로 input_value를 받음

			list.find(input_value);	//list class의 find 함수 호출
		}
		else if (!strcmp(command, "delete")) {	//command가 delete인 경우
			int input_value;
			cin >> input_value;	//두 번째 입력으로 input_value를 받음

			list.delete_node(input_value);
		}
		else if (!strcmp(command, "print")) {	//command가 print인 경우
			list.print();	//list class의 print 함수 호출
		}
		else if (!strcmp(command, "quit")) {	//command가 quit인 경우
			break;	//반복문 종료
		}
	}
	return 0;
}