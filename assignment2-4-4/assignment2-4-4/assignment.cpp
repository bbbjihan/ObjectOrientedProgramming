#include <iostream>
#pragma warning(disable : 4996)
using namespace std;

int my_strcmp_nocase(const char* str1, const char* str2);
int my_strcmp_nocase(const char str1, const char str2);

class Node {
private:
	char word[30];
	Node* next;
public:
	Node() {	//노드 생성자
		strcpy(this->word, "");
		this->word[29] = 0;
		this->next = NULL;
	}
	Node(char* word, Node* next) {	//노드 생성자 overloading
		strcpy(this->word, word);
		this->word[29] = 0;
		this->next = next;
	}
	~Node() { ; }	//노드 소멸자
	char* get_word() {	//노드 word 반환함수
		return this->word;
	}
	Node* get_next() {	//노드 next 반환함수
		return this->next;
	}
	void set_next(Node* input) {	//노드 next 변경용 함수
		this->next = input;
	}
	char get_last() {	//노드의 word의 마지막 글자 반환함수(처음으로 0이 나오는 자리의 앞글자 반환)
		for (int i = 1; i < 30; i++) {
			if (this->word[i] == 0) {
				return this->word[i-1];
			}
		}
		return this->word[29];
	}
	char get_first() {	//노드의 word의 첫번째 글자 반환함수
		return this->word[0];
	}
};

class List {
private:
	Node* head;
public:
	List() { //List class 생성자
		head = NULL;
	}
	~List() { ; }	//List class 소멸자
	void insert(Node* input) {
		if (this->head == NULL) {	//head가 NULL인 경우
			this->head = input;	//입력 노드를 head로 지정
		}
		else {	//head가 NULL이 아닌 경우
			Node* now = this->head;	//list 순회용 임시 포인터 생성
			while (now->get_next() != NULL) {	//탐색 중인 노드의 다음 노드가 없을 때까지 반복
				if (!my_strcmp_nocase(now->get_word(), input->get_word())) {	//반복하는 동안 현재 입력하려는 단어가 탐색 노드의 단어 중에 존재하면
					cout << "Already Exists\n";	//경고문 출력
					return;	//함수 종료
				}
				now = now->get_next();	//탐색 중인 노드의 다음 노드를 탐색 노드로 변경
			}
			if (!my_strcmp_nocase(now->get_word(), input->get_word())) {	//while문의 반복이 끝난 이후 마지막 노드에 대해 입력하는 단어와 같은 경우
				cout << "Already Exists\n";	//경고문 출력
				return;	//함수 종료
			}
			//여기까지 조건문을 모두 통과한 경우, 중복되는 단어가 없는 상태임.
			if (!my_strcmp_nocase(now->get_last(), input->get_first())) {	//list의 마지막 단어의 마지막 글자와 입력하는 단어의 첫 글자가 같은 경우
				now->set_next(input);	//list의 마지막 노드의 next를 입력 단어를 word로 가진 노드로 지정해줌
			}
			else {	//list의 마지막 단어의 마지막 글자와 입력 단어의 첫번째 글자가 다른 경우
				cout << "Not Chained\n";	//경고문 출력
			}
		}
	}
	void print() {	//List 내 모든 Node 출력함수
		Node* now = this->head;	//list 순회용 임시 포인터 생성
		while (now->get_next() != NULL) {	//탐색 중인 노드의 다음 노드가 없을 때까지 반복
			cout << now->get_word() << "->";	//현재 탐색 중인 노드의 word 출력
			now = now->get_next();	//탐색 중인 노드의 다음 노드를 탐색 노드로 변경
		}
		cout << now->get_word() << "->\n";	//while문의 반복이 끝난 이후 마지막 노드 출력
	}
};

int main() {
	class List list = List();	//리스트 선언

	while (1) {
		char command[100];	//command 선언
		cout << "CMD(Word/ext)>> ";
		cin >> command;	//command 입력받음
		if (!strcmp(command, "exit")) {	//command가 exit이면
			break;	//반복문 종료
		}
		else {	//exit 외의 값 입력될 경우
			Node* tmp = new Node(command, NULL);	//입력값을 word로 하는 임시 노드 생성
			list.insert(tmp);	//list 클래스의 insert 함수 호출
			list.print();	//list 클래스의 print 함수 호출
		}
	}

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
	if (a != b) {
		return a - b;
	}
	return 0;
}