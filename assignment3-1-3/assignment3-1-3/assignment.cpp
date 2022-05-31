#include <iostream>
#include <cstring>
#include <stdlib.h>
#pragma warning(disable : 4996)
using namespace std;

class mystring {
public:
	char* string;
	mystring() { 
		this->string = (char*)malloc(sizeof(char));	//멤버변수 string 동적할당
		if (this->string != NULL) {	//동적할당이 성공하였을 경우
			this->string[0] = '\0';	//NULL값으로 초기화
		}
	}
	~mystring() {
		free(this->string);	//멤버변수 string 동적할당 해제
	}
};

void operator+=(mystring& A, char* B) {	//+=연산자 오버로딩
	int lenA = strlen(A.string);
	int lenB = strlen(B);
	A.string = (char*)realloc(A.string, sizeof(char) * (lenA + lenB + 1));	//두 입력 문자열의 길이보다 1 크도록 메모리 재할당
	if (A.string != NULL) {	//메모리 재할당 성공하였을 경우
		for (int i = 0; i < lenB; i++) {
			A.string[lenA + i] = B[i];
		}	//B의 문자들을 A.string의 가장 뒤에 복제
		A.string[lenA + lenB] = '\0';	//문자열의 끝을 알리는 NULL문자 삽입
	}
}

void operator-=(mystring& A, char B) {	//-=연산자 오버로딩
	int len = strlen(A.string);
	int i = 0;
	while (i < len) {	//탐색 중인 index가 전체 문자열의 길이를 벗어나지 않는 동안 반복
		if (A.string[i] == B) {	//탐색 중인 index의 문자가 입력값과 같은 경우
			if (i == len - 1) {	//마지막 문자인 경우
				A.string[i] = '\0';	//해당 문자를 NULL로 변경
			}
			else {	//마지막 문자가 아닌 경우
				for (int j = i; j < len-1; j++) {	//해당 문자 뒤의 모든 문자에 대하여
					A.string[j] = A.string[j + 1];	//index가 1 큰 문자로 해당 문자들을 덮어씌움(문자열을 한 칸씩 앞으로 당김)
				}
				A.string[len - 1] = '\0';	//맨 마지막 문자를 NULL로 변경
			}
			len--;	//길이값 1 감소
		}
		else {
			i++;	//탐색 index 1 증가
		}
	}
}

void operator--(mystring& A, int) {	//--연산자 오버로딩
	int len = strlen(A.string);
	if (len != 0) {
		A.string[len - 1] = '\0';	//마지막 문자를 NULL로 변경
	}
}

void operator&&(mystring& A, char B) {	//&&연산자 오버로딩
	int len = strlen(A.string);
	for (int i = 0; i < len; i++) {	//모든 문자를 순회하며
		if (A.string[i] != B) {	//탐색 중인 문자가 입력된 문자와 다를 경우
			A.string[i] = '0';	//해당 문자를 0으로 변경
		}
	}
}

int main() {
	int command = -1;
	mystring Mystring = mystring();
	
	do {
		cout << "Please Enter command(1 : add, 2 : delete_char, 3 : delete_lastchar, 4 : and_operator, 5 : print, 6 : exit) : ";
		cin >> command;	//첫번째 입력으로 command 받음

		if (command == 1) {	//첫번째 입력이 1인 경우
			char input[100];
			cin >> input;	//두번쨰 입력으로 input을 받음
			
			Mystring += input;	//+=연산
		}
		else if (command == 2) {	//첫번째 입력이 2인 경우
			char input;
			cin >> input;	//두번째 입력으로 input을 받음

			Mystring -= input;	//-=연산
		}
		else if (command == 3) {	//첫번째 입력이 3인 경우
			Mystring--;	//--연산
		}
		else if (command == 4) {	//첫번째 입력이 4인 경우
			char input;
			cin >> input;	//두번째 입력으로 input을 받음

			Mystring && input;	//&&연산
		}
		else if (command == 5) {	//첫번째 입력이 5인 경우
			cout << Mystring.string << "\n";	//멤버변수 출력
		}

	} while (command != 6);	//첫번째 입력이 6인 경우 반복문 종료

	return 0;
}