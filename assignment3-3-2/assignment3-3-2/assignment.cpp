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
	Node() { this->name = new char[20]; this->prev = NULL; this->next = NULL; }	//Node의 생성자
	Node(char* name, Node* prev, Node* next) {	//Node의 생성자 overloading
		this->name = new char[20];
		strcpy(this->name, name);
		this->prev = prev;
		this->next = next;
	}
	~Node() { 
		cout << this->getName() << "Node is destroyed" << "\n";
		delete this->name;
	}	//Node의 소멸자
	char* getName() { return this->name; }	//Node의 Name 반환함수
	Node* getPrev() { return this->prev; }	//Node의 Prev 반환함수
	Node* getNext() { return this->next; }	//Node의 Next 반환함수
	void setPrev(Node* prev) { this->prev = prev; }	//Node의 Prev Set함수
	void setNext(Node* next) { this->next = next; }	//Node의 Next Set함수
};

class DoublyLinkedList {
private:
	Node* head;
public:
	DoublyLinkedList() { this->head = NULL; }	//DoublyLinkedList의 생성자
	~DoublyLinkedList() { ; }	//DoublyLinkedList의 소멸자
	Node* getHead() { return this->head; }	//DoublyLinkedList의 Head 반환함수
	void insert(Node* input) {	//Node를 List의 마지막에 삽입하는 함수
		if (this->head == NULL) {	//List가 비어있는 경우
			this->head = input;	//input Node를 head로 지정
			return;	//함수종료
		}
		Node* now = this->head;	//탐색을 위해 현재 노드를 List의 head로 초기화
		while (now->getNext() != NULL) now = now->getNext();	//노드 삽입을 위해 마지막 노드까지 현재노드를 이동
		now->setNext(input);	//현재 노드의 Next로 input Node를 지정
		input->setPrev(now);	//현재노드를 input Node의 Prev로 지정
	}
	Node* findNode(const char* name) {	//파라미터로 입력된 string을 name으로 가지고 있는 node가 존재하는 경우 해당 노드를 반환하는 함수
		Node* now = this->head;	//탐색을 위해 현재 노드를 List의 head로 지정
		for (; now != NULL; now = now->getNext()) {	//마지막 노드까지 탐색
			if (!strcmp(now->getName(), name))  break;	//탐색 중 node의 name이 파라미터로 입력된 string과 같은 경우 반복문 종료
		}
		if (now == NULL) return NULL;	//반복문이 모든 노드 탐색으로 인해 종료되었거나 list가 비어있는 경우 NULL 반환
		return now;	//위에서 찾은 노드 반환
	}
};

class DoublyCircularLinkedList {
private:
	Node* head;
	Node* tail;
public:
	DoublyCircularLinkedList() { this->head = NULL; this->tail = NULL; }	//DoublyCircularLinkedList의 생성자
	~DoublyCircularLinkedList() { ; }	//DoublyCircularLinkedList의 소멸자
	Node* getHead() { return this->head; }	//DoublyCircularLinkedList의 head 반환함수
	void insert(Node* input) {	//Node를 List의 tail에 삽입하는 함수
		if (this->head == NULL) {	//List가 비어있는 경우
			this->head = input;	//input Node를 head로 지정
			this->tail = input;	//input Node를 tail로 지정
			input->setNext(input);
			input->setPrev(input);
			return;	//함수종료
		}
		Node* now = this->tail;	//삽입을 위해 현재 tail인 노드를 불러옴
		now->setNext(input);	//현재 tail인 노드의 next를 삽입노드로 지정
		head->setPrev(input);	//현재 head인 노드의 prev를 삽입노드로 지정
		input->setPrev(now);	//삽입노드의 prev를 현재 tail인 노드로 지정
		input->setNext(this->head);	//삽입노드의 next를 현재 head인 노드로 지정
		this->tail = input;	//tail을 삽입노드로 변경
	}
	Node* findNode(const char* name) {	//파라미터로 입력된 string을 name으로 가지고 있는 node가 존재하는 경우 해당 노드를 반환하는 함수
		if (!strcmp(this->head->getName(), name)) return this->head;	//head가 목표노드인 경우 head 반환 (아래 반복문의 조건문 흐름제어를 위한 예외처리)
		Node* now = this->head->getNext();	//탐색을 위해 현재 노드를 List의 head로 지정
		for (; now != this->head; now = now->getNext()) {	//마지막 노드까지 탐색
			if (!strcmp(now->getName(), name)) break;	//탐색 중 node의 name이 파라미터로 입력된 string과 같은 경우 반복문 종료
		}
		if (now == this->head) return NULL;	//반복문이 모든 노드 탐색으로 인해 종료되었거나 list가 비어있는 경우 NULL 반환
		return now;	//위에서 찾은 노드 반환
	}
};

void printPath(const char* name1, const char* name2, DoublyLinkedList line1, DoublyCircularLinkedList line2) {
	Node* start1 = line1.findNode(name1);
	Node* start2 = line2.findNode(name1);
	Node* desti1 = line1.findNode(name2);
	Node* desti2 = line2.findNode(name2);
	if (!strcmp(name1, "시청")) {	//시작역이 시청인 경우의 예외처리
		if (desti1 == NULL) {
			start1 = NULL;
		}
		if (desti2 == NULL){
			start2 = NULL;
		}
	}
	if ((start1 == NULL && start2 == NULL) || (desti1 == NULL && desti2 == NULL)) {
		cout << "경로가 존재하지 않습니다.";
		return;
	}
	char Path[50][20];
	int cnt = 0;
	if (start2 == NULL) {	//시작역이 1호선인 경우
		if (desti2 == NULL) {	//시작역이 1호선이고, 끝역이 1호선인 경우
			Node* start = line1.findNode(name1);	//시작노드를 name1역의 노드로 초기화
			Node* desti = start;	//도착노드를 시작노드로 초기화
			while (desti!=NULL) {	//도착노드가 NULL이 아니면 반복(반복문 종료시 도착노드가 NULL이라면 시작노드의 next로 도착노드를 찾을 수 없다는 의미. 즉 head에 name1역보다 name2역이 더 가깝다는 뜻.)
				if (!strcmp(desti->getName(), name2)) {
					break;	//도착노드의 name이 name2와 같다면 반복문 종료
				}
				desti = desti->getNext();	//도착노드를 한 역씩 다음 역으로 변경
			}
			if (desti == NULL) {	//head에 name1 역이 더 가까운 경우 (prev로 탐색해야 도착역이 나오는 경우)
				desti = start;	//경로출력을 위해 도착노드를 시작노드로 초기화
				while (1) {
					if (!strcmp(desti->getName(), name2)) break;	//도착노드의 name이 name2와 같다면 반복문 종료
					strcpy(Path[cnt], desti->getName());	//도착노드가 현재 지나고 있는 노드의 이름을 경로에 저장
					cnt++;	//경로 카운터 1 증가
					desti = desti->getPrev();	//도착노드의 이전 노드로 도착노드 지정
				}
				strcpy(Path[cnt], desti->getName());	//마지막 노드의 이름도 경로에 저장
				cnt++;	//경로 카운터 1 증가
			}
			else {	//head에 name2 역이 더 가까운 경우 (next로 탐색해야 도착역이 나오는 경우)
				desti = start;	//경로출력을 위해 도착노드를 시작노드로 초기화
				while (1) {
					if (!strcmp(desti->getName(), name2)) break;	//도착노드의 name이 name2와 같다면 반복문 종료
					strcpy(Path[cnt], desti->getName());	//도착노드가 현재 지나고 있는 노드의 이름을 경로에 저장
					cnt++;	//경로 카운터 1 증가
					desti = desti->getNext();	//도착노드의 다음 노드로 도착노드 지정
				}
				strcpy(Path[cnt], desti->getName());	//마지막 노드의 이름도 경로에 저장
				cnt++;	//경로 카운터 1 증가
			}
			if (cnt > 0) {	//양식에 맞게 경로 출력
				cout << Path[0];
				for (int i = 1; i < cnt; i++) {
					cout << "->" << Path[i];
				}
			}
		}
		else {	//시작역이 1호선이고, 끝역이 2호선인 경우
			Node* start = line1.findNode(name1);	//시작노드를 name1역의 노드로 초기화
			Node* desti = start;	//도착노드를 시작노드로 초기화
			while (desti != NULL) {	//도착노드가 NULL이 아니면 반복(반복문 종료시 도착노드가 NULL이라면 시작노드의 next로 도착노드를 찾을 수 없다는 의미. 즉 head에 name1역보다 name2역이 더 가깝다는 뜻.)
				if (!strcmp(desti->getName(), "시청")) {
					break;	//도착노드의 name이 "시청"과 같다면 반복문 종료
				}
				desti = desti->getNext();	//도착노드를 한 역씩 다음 역으로 변경
			}
			if (desti == NULL) {	//head에 name1 역이 더 가까운 경우 (prev로 탐색해야 도착역이 나오는 경우)
				desti = start;	//경로출력을 위해 도착노드를 시작노드로 초기화
				while (1) {
					if (!strcmp(desti->getName(), "시청")) break;	//도착노드의 name이 name2와 같다면 반복문 종료
					strcpy(Path[cnt], desti->getName());	//도착노드가 현재 지나고 있는 노드의 이름을 경로에 저장
					cnt++;	//경로 카운터 1 증가
					desti = desti->getPrev();	//도착노드의 이전 노드로 도착노드 지정
				}
				strcpy(Path[cnt], desti->getName());	//마지막 노드의 이름도 경로에 저장
				cnt++;	//경로 카운터 1 증가
			}
			else {	//head에 "시청" 역이 더 가까운 경우 (next로 탐색해야 도착역이 나오는 경우)
				desti = start;	//경로출력을 위해 도착노드를 시작노드로 초기화
				while (1) {
					if (!strcmp(desti->getName(), "시청")) break;	//도착노드의 name이 name2와 같다면 반복문 종료
					strcpy(Path[cnt], desti->getName());	//도착노드가 현재 지나고 있는 노드의 이름을 경로에 저장
					cnt++;	//경로 카운터 1 증가
					desti = desti->getNext();	//도착노드의 다음 노드로 도착노드 지정
				}
				strcpy(Path[cnt], desti->getName());	//마지막 노드의 이름도 경로에 저장
				cnt++;	//경로 카운터 1 증가
			}
			cnt--;	//시청역 중복 출력 방지용 index 1 감소
			start = line2.findNode("시청");	//시작노드를 2호선의 시청노드로 초기화
			int disNext = 0;	//Next를 통해 name2역을 찾을 때까지 몇 개의 역을 지나야 하는지 저장하기 위한 distance of moving next 변수
			int disPrev = 0;	//Prev를 통해 name2역을 찾을 때까지 몇 개의 역을 지나야 하는지 저장하기 위한 distance of moving prev 변수 
			desti = start;
			for (; strcmp(desti->getName(), name2); desti = desti->getNext()) {	//도착노드가 name2역을 찾을 때까지 getNext를 통해 반복하며 값을 갱신
				disNext++;	//역을 하나 지날 때마다 disNext 변수값 1씩 증가
			}
			desti = start;	//도착노드를 시작노드로 초기화
			for (; strcmp(desti->getName(), name2); desti = desti->getPrev()) {	//도착노드가 name2역을 찾을 때까지 getPrev를 통해 반복하며 값을 갱신
				disPrev++;	//역을 하나 지날 때마다 disPrev 변수값 1씩 증가
			}
			if (disNext > disPrev) {	//start에서 Next로 name2역을 찾는 것보다 Prev로 name2역을 찾는 게 더 빠를 경우
				desti = start;	//경로출력을 위해 도착노드를 시작노드로 초기화
				while (1) {
					if (!strcmp(desti->getName(), name2)) break;	//도착노드의 name이 name2와 같다면 반복문 종료
					strcpy(Path[cnt], desti->getName());	//도착노드가 현재 지나고 있는 노드의 이름을 경로에 저장
					cnt++;	//경로 카운터 1 증가
					desti = desti->getPrev();	//도착노드의 이전 노드로 도착노드 지정
				}
				strcpy(Path[cnt], desti->getName());	//마지막 노드의 이름도 경로에 저장
				cnt++;	//경로 카운터 1 증가
			}
			else {	//start에서 Prev로 name2역을 찾는 것보다 Next로 name2역을 찾는 게 더 빠를 경우
				desti = start;	//경로출력을 위해 도착노드를 시작노드로 초기화
				while (1) {
					if (!strcmp(desti->getName(), name2)) break;	//도착노드의 name이 name2와 같다면 반복문 종료
					strcpy(Path[cnt], desti->getName());	//도착노드가 현재 지나고 있는 노드의 이름을 경로에 저장
					cnt++;	//경로 카운터 1 증가
					desti = desti->getNext();	//도착노드의 다음 노드로 도착노드 지정
				}
				strcpy(Path[cnt], desti->getName());	//마지막 노드의 이름도 경로에 저장
				cnt++;	//경로 카운터 1 증가
			}
			
			if (cnt > 0) {	//양식에 맞게 경로 출력
				cout << Path[0];
				for (int i = 1; i < cnt; i++) {
					cout << "->" << Path[i];
				}
			}
		}
	}
	else{	//시작역이 2호선인 경우
		if (desti2 == NULL) {	//시작역이 2호선이고, 끝역이 1호선인 경우
			Node* start = line2.findNode(name1);	//시작노드를 2호선의 head로 초기화
			int disNext = 0;	//Next를 통해 시청역을 찾을 때까지 몇 개의 역을 지나야 하는지 저장하기 위한 distance of moving next 변수
			int disPrev = 0;	//Prev를 통해 시청역을 찾을 때까지 몇 개의 역을 지나야 하는지 저장하기 위한 distance of moving prev 변수 
			Node* desti = start;	//도착노드를 시작노드로 초기화
			for (; strcmp(desti->getName(), "시청"); desti = desti->getNext()) {	//도착노드가 "시청"역을 찾을 때까지 getNext를 통해 반복하며 값을 갱신
				disNext++;	//역을 하나 지날 때마다 disNext 변수값 1씩 증가
			}
			desti = start;	//도착노드를 시작노드로 초기화
			for (; strcmp(desti->getName(), "시청"); desti = desti->getPrev()) {	//도착노드가 "시청"역을 찾을 때까지 getPrev를 통해 반복하며 값을 갱신
				disPrev++;	//역을 하나 지날 때마다 disPrev 변수값 1씩 증가
			}
			if (disNext > disPrev) {	//start에서 Next로 name2역을 찾는 것보다 Prev로 "시청"역을 찾는 게 더 빠를 경우
				desti = start;	//경로출력을 위해 도착노드를 시작노드로 초기화
				while (1) {
					if (!strcmp(desti->getName(), "시청")) break;	//도착노드의 name이 "시청"과 같다면 반복문 종료
					strcpy(Path[cnt], desti->getName());	//도착노드가 현재 지나고 있는 노드의 이름을 경로에 저장
					cnt++;	//경로 카운터 1 증가
					desti = desti->getPrev();	//도착노드의 이전 노드로 도착노드 지정
				}
				strcpy(Path[cnt], desti->getName());	//마지막 노드의 이름도 경로에 저장
				cnt++;	//경로 카운터 1 증가
			}
			else {	//start에서 Prev로 name2역을 찾는 것보다 Next로 "시청"역을 찾는 게 더 빠를 경우
				desti = start;	//경로출력을 위해 도착노드를 시작노드로 초기화
				while (1) {
					if (!strcmp(desti->getName(), "시청")) break;	//도착노드의 name이 "시청"과 같다면 반복문 종료
					strcpy(Path[cnt], desti->getName());	//도착노드가 현재 지나고 있는 노드의 이름을 경로에 저장
					cnt++;	//경로 카운터 1 증가
					desti = desti->getNext();	//도착노드의 다음 노드로 도착노드 지정
				}
				strcpy(Path[cnt], desti->getName());	//마지막 노드의 이름도 경로에 저장
				cnt++;	//경로 카운터 1 증가
			}
			start = line1.findNode("시청");	//시작노드를 name1역의 노드로 초기화
			desti = start;	//도착노드를 시작노드로 초기화
			while (desti != NULL) {	//도착노드가 NULL이 아니면 반복(반복문 종료시 도착노드가 NULL이라면 시작노드의 next로 도착노드를 찾을 수 없다는 의미. 즉 head에 name1역보다 name2역이 더 가깝다는 뜻.)
				if (!strcmp(desti->getName(), name2)) {
					break;	//도착노드의 name이 name2와 같다면 반복문 종료
				}
				desti = desti->getNext();	//도착노드를 한 역씩 다음 역으로 변경
			}
			if (desti == NULL) {	//head에 name1 역이 더 가까운 경우 (prev로 탐색해야 도착역이 나오는 경우)
				desti = start;	//경로출력을 위해 도착노드를 시작노드로 초기화
				while (1) {
					if (!strcmp(desti->getName(), name2)) break;	//도착노드의 name이 name2와 같다면 반복문 종료
					strcpy(Path[cnt], desti->getName());	//도착노드가 현재 지나고 있는 노드의 이름을 경로에 저장
					cnt++;	//경로 카운터 1 증가
					desti = desti->getPrev();	//도착노드의 이전 노드로 도착노드 지정
				}
				strcpy(Path[cnt], desti->getName());	//마지막 노드의 이름도 경로에 저장
				cnt++;	//경로 카운터 1 증가
			}
			else {	//head에 name2 역이 더 가까운 경우 (next로 탐색해야 도착역이 나오는 경우)
				desti = start;	//경로출력을 위해 도착노드를 시작노드로 초기화
				while (1) {
					if (!strcmp(desti->getName(), name2)) break;	//도착노드의 name이 name2와 같다면 반복문 종료
					strcpy(Path[cnt], desti->getName());	//도착노드가 현재 지나고 있는 노드의 이름을 경로에 저장
					cnt++;	//경로 카운터 1 증가
					desti = desti->getNext();	//도착노드의 다음 노드로 도착노드 지정
				}
				strcpy(Path[cnt], desti->getName());	//마지막 노드의 이름도 경로에 저장
				cnt++;	//경로 카운터 1 증가
			}
			if (cnt > 0) {	//양식에 맞게 경로 출력
				cout << Path[0];
				for (int i = 1; i < cnt; i++) {
					cout << "->" << Path[i];
				}
			}
		}
		else {	//시작역이 2호선이고, 끝역이 2호선인 경우
			Node* start = line2.findNode(name1);	//시작노드를 2호선의 head로 초기화
			int disNext = 0;	//Next를 통해 name2역을 찾을 때까지 몇 개의 역을 지나야 하는지 저장하기 위한 distance of moving next 변수
			int disPrev = 0;	//Prev를 통해 name2역을 찾을 때까지 몇 개의 역을 지나야 하는지 저장하기 위한 distance of moving prev 변수 
			Node* desti = start;	//도착노드를 시작노드로 초기화
			for (; strcmp(desti->getName(), name2); desti = desti->getNext()) {	//도착노드가 name2역을 찾을 때까지 getNext를 통해 반복하며 값을 갱신
				disNext++;	//역을 하나 지날 때마다 disNext 변수값 1씩 증가
			}
			desti = start;	//도착노드를 시작노드로 초기화
			for (; strcmp(desti->getName(), name2); desti = desti->getPrev()) {	//도착노드가 name2역을 찾을 때까지 getPrev를 통해 반복하며 값을 갱신
				disPrev++;	//역을 하나 지날 때마다 disPrev 변수값 1씩 증가
			}
			if (disNext > disPrev) {	//start에서 Next로 name2역을 찾는 것보다 Prev로 name2역을 찾는 게 더 빠를 경우
				desti = start;	//경로출력을 위해 도착노드를 시작노드로 초기화
				while (1) {
					if (!strcmp(desti->getName(), name2)) break;	//도착노드의 name이 name2와 같다면 반복문 종료
					strcpy(Path[cnt], desti->getName());	//도착노드가 현재 지나고 있는 노드의 이름을 경로에 저장
					cnt++;	//경로 카운터 1 증가
					desti = desti->getPrev();	//도착노드의 이전 노드로 도착노드 지정
				}
				strcpy(Path[cnt], desti->getName());	//마지막 노드의 이름도 경로에 저장
				cnt++;	//경로 카운터 1 증가
			}
			else {	//start에서 Prev로 name2역을 찾는 것보다 Next로 name2역을 찾는 게 더 빠를 경우
				desti = start;	//경로출력을 위해 도착노드를 시작노드로 초기화
				while (1) {
					if (!strcmp(desti->getName(), name2)) break;	//도착노드의 name이 name2와 같다면 반복문 종료
					strcpy(Path[cnt], desti->getName());	//도착노드가 현재 지나고 있는 노드의 이름을 경로에 저장
					cnt++;	//경로 카운터 1 증가
					desti = desti->getNext();	//도착노드의 다음 노드로 도착노드 지정
				}
				strcpy(Path[cnt], desti->getName());	//마지막 노드의 이름도 경로에 저장
				cnt++;	//경로 카운터 1 증가
			}
			
			if (cnt > 0) {	//양식에 맞게 경로 출력
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
	class DoublyLinkedList line1 = DoublyLinkedList();	//1호선 생성
	class DoublyCircularLinkedList line2 = DoublyCircularLinkedList();	//2호선 생성
	char station[20];	//역이름 받아올 char 배열 선언
	ifstream in1("Assignment3-3-2-1.txt");	//in1 객체로 Assignment3-3-2-1 text file 불러옴
	if (in1.is_open()) {
		while (in1 >> station) {	//eof까지 반복하여 역이름 받아옴
			class Node* newNode = new Node(station, NULL, NULL);	//받아온 역이름으로 new Node 생성
			line1.insert(newNode);	//1호선에 생성한 노드 삽입
		}
	}
	else {	//ifstream open 오류 예외처리
		cout << "Assignment3-3-2-1.txt cannot open." << endl;
		return 0;
	}
	in1.close();	//text file close
	ifstream in2("Assignment3-3-2-2.txt");	//in1 객체로 Assignment3-3-2-1 text file 불러옴
	if (in2.is_open()) {
		while (in2 >> station) {	//eof까지 반복하여 역이름 받아옴
			class Node* newNode = new Node(station, NULL, NULL);	//받아온 역이름으로 new Node 생성
			line2.insert(newNode);	//2호선에 생성한 노드 삽입
		}
	}
	else {	//ifstream open 오류 예외처리
		cout << "Assignment3-3-2-2.txt cannot open." << endl;
		return 0;
	}
	in2.close();	//text file close

	char start[20];	//출발역 선언
	char desti[20];	//도착역 선언
	strcpy(start, "\0");	//출발역 초기화
	strcpy(desti, "\0");	//도착역 초기화
	cout << "출발역 : ";
	cin >> start;	//출발역 입력받음
	cout << "도착역 : ";
	cin >> desti;	//도착역 입력받음
	printPath(start, desti, line1, line2);	//출발역->도착역 경로 출력함수 호출

	return 0;
}