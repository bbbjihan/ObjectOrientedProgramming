#include <iostream>
using namespace std;

int my_strcmp(char* str1, const char* str2);

int main() {
	int* stack = new int[100];	//stack으로 사용될 메모리 동적할당
	int i = 0;	//stack의 가장 끝 메모리 인덱스
	while (1) {
		char* command = new char[100];
		int number;
		cout << "Please Enter Command(push, pop) :";
		cin >> command;	//command를 첫 번째 입력으로 받음

		if (!my_strcmp(command, "push")) {	//입력이 push인 경우
			cin >> number;	//number를 두 번째 입력으로 받음
			*(stack + i) = number;	//스택의 가장 끝 값을 number로 변경
			i++;	//스택의 메모리 인덱스 1 추가
		}
		else if (!my_strcmp(command, "pop")) {	//입력이 pop인 경우
			i--;	//스택의 메모리 인덱스 1 감소
		}

		for (int j = 0; j < i; j++) {
			cout << *(stack + j) << "\n";
		}	//스택의 모든 값 출력

		delete[] command;	//반복문 내 지역변수 command 동적할당 해제
	}
	delete[] stack;	//stack 동적할당 해제
	return 0;
}

int my_strcmp(char* str1, const char* str2) {	//command의 유효성 검사를 위한 strcmp 함수
	int i = 0;
	while (str1[i] != '\0' || str2[i] != '\0') {
		if (str1[i] != str2[i]){
			return str1[i] - str2[i];
		}
		i++;
	}
	return 0;
}
