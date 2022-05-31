#include <iostream>
#include <fstream>
#include <cassert>
#pragma warning(disable : 4996)
using namespace std;

int my_strcmp_nocase(const char* str1, const char* str2);
int my_strcmp_nocase(const char str1, const char str2);

class Node {	//각 알파벳 단어장 내에서 단어정보를 저장할 노드 선언
private:
	char data[20];	//data 멤버변수 선언
	Node* next;	//다음 노드를 가리키는 next 멤버변수 선언
public:
	Node() { strcpy(this->data,"\0"); this->next = NULL; }	//Node 객체 생성자
	Node(char* data, Node* next) { strcpy(this->data, data); this->next = next	; }	//Node 객체 생성자 overloading
	~Node() { ; }	//Node 객체 소멸자
	char* getData() { return this->data; }	//Node 객체 data 반환함수
	Node* getNext() { return this->next; }	//Node 객체 next 반환함수
	void setNext(Node* next) { this->next = next; }	//Node 객체 next 설정함수(insert에 사용)
};

class AlphaNode {	//각 알파벳정보를 저장할 AlphaNode 선언
private:
	char alpha;	//어떤 알파벳 List의 시작지점인지를 알려주기 위한 alpha 멤버변수 선언
	AlphaNode* next;	//다음 알파벳을 가리키기 위한 next 선언
	Node* head;	//해당 알파벳의 첫 번째 단어를 가리키기 위한 head 선언
public:
	AlphaNode() { this->alpha = NULL; this->next = NULL; this->head = NULL; }	//AlphaNode 객체 생성자
	AlphaNode(char alpha, AlphaNode* next, Node* head) {	//AlphaNode 객체 생성자 overloading
		this->alpha = alpha;
		this->next = next;
		this->head = head;
	}
	~AlphaNode() { ; }	//AlphaNode 객체 소멸자
	char getAlpha() { return this->alpha; }	//AlphaNode 객체 alpha 반환함수
	Node* getHead() { return this->head; }	//AlphaNode 객체 head 반환함수(해당알파벳으로 시작하는 단어 중 첫 번째)
	AlphaNode* getNext() { return this->next; }	//AlphaNode 객체 next 반환함수(다음 알파벳)
	void setNext(AlphaNode* next) { this->next = next; }	//AlphaNode 객체 next 설정함수(insert에 사용)
	void insert(char* word) {	//각 AlphaNode가 List를 담고 있으므로 AlphaNode 내의 LinkedList에 word를 data로 담고 있는 node를 생성해주는 함수
		class Node* newNode = new Node(word, NULL);	//삽입할 노드 동적할당
		if (this->head == NULL) {	//해당 알파벳의 list가 비어있는 경우
			this->head = newNode;	//삽입노드를 head로 지정
			return;	//함수 종료
		}
		Node* prev = NULL;
		Node* tmp = this->head;
		for (; tmp != NULL; tmp = tmp->getNext()) {	//해당 알파벳의 list에 존재하는 모든 node를 head에서부터 next를 통해 순회
			if (my_strcmp_nocase(tmp->getData(), word) > 0) {	//삽입하려는 node의 data와 탐색 중인 node의 data를 비교하였을 때 삽입노드의 data가 사전순으로 더 앞인 경우
				newNode->setNext(tmp);	//삽입노드의 next를 탐색 중인 노드로 지정
				if (prev != NULL)prev->setNext(newNode);	//prev가 NULL이 아닌 경우(삽입목표 위치가 head가 아닌 경우)	삽입위치 이전 노드의 next를 삽입노드로 지정
				if (prev == NULL)this->head = newNode;	//prev가 NULL인 경우(삽입목표 위치가 head인 경우) 해당 list의 head를 삽입노드로 지정
				return;	//함수 종료
			}
			prev = tmp;
		}	//삽입정렬 알고리즘
		prev->setNext(newNode);	//함수가 종료되지 않았을 경우(모든 node의 data가 입력값보다 앞에 있어야 하는 경우) 마지막 node의 next를 삽입노드로 지정
	}
};

class List {	//AlphaNode들을 저장할 List 객체 선언
private:
	AlphaNode* head;	//Linked List의 head 선언
public:
	List() { this->head = NULL; }	//List 객체의 생성자
	~List() { ; }	//List객체의 소멸자
	void insert(char* word) {	//AlphaNode를 각 node로 가지는 list에 AlphaNode를 삽입하는 함수
		class AlphaNode* newAlpha = new AlphaNode(toupper(word[0]), NULL, NULL);
		//word의 첫문자의 대문자값을 alpha 멤버변수로 하는 AlphaNode newAlpha 객체 동적할당
		if (this->head == NULL) {	//List의 head가 NULL인 경우(List가 빈 경우)
			this->head = newAlpha;	//List의 head를 newAlpha로 지정
			newAlpha->insert(word);	//newAlpha AlphaNode의 멤버함수 insert 호출로 첫 단어 삽입
			return;	//함수 종료
		}
		AlphaNode* prev = NULL;
		AlphaNode* tmp = this->head;
		for (; tmp != NULL; tmp = tmp->getNext()) {		//해당 list에 존재하는 모든 node를 head에서부터 next를 통해 순회
			if (!my_strcmp_nocase(tmp->getAlpha(), word[0])) {	//삽입하려는 알파벳의 AlphaNode가 이미 존재하는 경우
				tmp->insert(word);	//그 AlphaNode의 멤버함수 insert 호출로 새로운 단어 삽입
				delete newAlpha;	//삽입하려는 AlphaNode 삭제
				return;	//함수 종료
			}
			else if (my_strcmp_nocase(tmp->getAlpha(), word[0]) > 0) {	//처음으로 삽입AlphaNode보다 뒤에 와야하는 AlphaNode를 찾는 경우
				newAlpha->setNext(tmp);	//삽입 AlphaNode의 next를 탐색 AlphaNode로 지정
				if (prev != NULL)prev->setNext(newAlpha);	//prev가 NULL이 아닌 경우(삽입위치가 head가 아닌 경우) 탐색노드의 직전노드의 next를 삽입노드로 지정
				newAlpha->insert(word);	//삽입 AlphaNode의 멤버변수 insert로 첫 단어 삽입
				if (prev == NULL) this->head = newAlpha;	//prev가 NULL인 경우(삽입위치가 head인 경우) 해당 list의 head를 삽입노드로 지정
				return;	//함수 종료
			}
			prev = tmp;
		}
		prev->setNext(newAlpha);	//위에서 함수 종료되지 않은 경우 모든 node의 맨 마지막의 next로 삽입노드 지정(맨 뒤에 삽입)
		newAlpha->insert(word);	//삽입 AlphaNode의 멤버변수 insert로 첫 단어 삽입
	}
	void print() {	//2차원 Linked List 출력함수
		for (AlphaNode* tmpAlpha = this->head; tmpAlpha != NULL; tmpAlpha = tmpAlpha->getNext()) {	//모든 AlphaNode에 대하여 head부터 순회
			cout << tmpAlpha->getAlpha();	//각 AlphaNode가 무슨 알파벳을 의미하는지 출력
			for (Node* tmpNode = tmpAlpha->getHead(); tmpNode != NULL; tmpNode = tmpNode->getNext()) {	//각 AlphaNode에 연결된 모든 Node에 대하여 head부터 순회
				cout << " -> " << tmpNode->getData();	//"->"와 각 Node가 저장하고 있는 단어 출력
			}
			cout << "\n";	//각 AlphaNode마다 개행문자 출력
		}
	}
};

int main() {
	char tmp[20];
	class List list = List();	//Linked List 객체 선언

	ifstream inobj("Assignment.txt");	//단어 저장된 file open
	if (!inobj) {	//open error 예외처리
		cout << "Assignment.txt cannot open." << "\n";
		assert(false);
	}
	while (!inobj.eof()) {	//eof까지 반복
		inobj >> tmp;	//tmp에 단어 하나씩 출력
		list.insert(tmp);	//출력된 단어들 List에 삽입
	}
	inobj.close();	//file close

	list.print();	//Linked List print
	return 0;
}

int my_strcmp_nocase(const char* str1, const char* str2) {	//대소문자 구분하지 않는 strcmp
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

int my_strcmp_nocase(const char str1, const char str2) {	//대소문자 구분하지 않는, 한 글자 비교용 strcmp overloading
	int a = str1;
	int b = str2;
	if (a > 96) { a -= 32; }
	if (b > 96) { b -= 32; }
	return a - b;
}