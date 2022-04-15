#include <iostream>
using namespace std;

int my_strlen(char* str);
int my_strcmp(const char* str1, const char* str2);
int my_strcmp_nocase(const char* str1, const char* str2);
int cnt = 0;	//단어장 내 단어 갯수 전역변수로 선언

int main() {
	char** words = new char* [100];
	while (1) {	//무조건 반복
		char* command = new char[100];
		cin >> command;

		if (my_strcmp(command, "END") == 0) {	//command로 END가 입력된 경우
			break;	//반복문 종료
		}

		if (my_strcmp(command, "INSERT") == 0) {	//command로 INSERT가 입력된 경우
			char* target = new char[100];
			cin >> target;	//두 번쨰 입력으로 target을 받음.

			if(cnt == 100){	//단어가 100개 저장되어있을 경우 경고문구 출력 및 추가과정 생략
				cout << "wordbook is full!" << "\n";
				delete[] target;	//지역변수 할당 해제
				continue;
			}

			int target_length = my_strlen(target);	//입력받은 단어의 길이 저장
			int insertion_idx = 0;	//단어삽입 인덱스를 0으로 초기화
			int overlap = 0;	//중복된 단어가 존재하는 지 확인하기 위한 플래그 초기화

			for (int i = 0; i < cnt; i++) {
				if (my_strcmp_nocase(words[i], target) == 0) {	//삽입하려는 단어가 단어장 내에 존재하는 경우
					overlap = 1;	//중복 플래그 1로 변경 및 반복문 종료
					break;
				}
				if (my_strcmp_nocase(words[i], target) > 0) {	//삽입하려는 단어보다 값이 큰 단어를 발견한 경우
					insertion_idx = i;	//값이 큰 단어의 인덱스를 삽입 목표 인덱스로 설정 및 반복문 종료
					break;
				}
			}

			if (!overlap) {	//입력 단어와 중복된 단어가 존재하지 않는 경우
				cnt++;	//단어 갯수 한 개 증가
				words[cnt - 1] = new char[100];	//단어장 항목 한 개 추가

				if (cnt > 1 && my_strcmp_nocase(words[cnt - 2], target) < 0) {
					insertion_idx = cnt - 1;
				}	//삽입하려는 단어보다 단어장의 마지막 단어의 값이 더 작은 경우(단어장의 마지막에 추가해야 하는 경우)

				for (int i = cnt - 1; i > insertion_idx; i--) {
					for (int j = 0; j < strlen(words[i - 1]); j++) {
						words[i][j] = words[i - 1][j];
					}
					words[i][strlen(words[i - 1])] = '\0';
				}	//단어장의 마지막 인덱스부터 목표 인덱스까지 한 칸씩 뒤로 밀어냄

				for (int i = 0; i < target_length; i++) {
					words[insertion_idx][i] = target[i];
				}	//입력단어를 목표 인덱스에 복제
				words[insertion_idx][target_length] = '\0';	//단어의 끝 입력
			}

			for (int i = 0; i < cnt; i++) {
				cout << i << "." << words[i] << "\n";
			}	//중복 여부에 관계 없이 단어장 전체 출력

			delete[] target;	//지역변수 할당 해제
		}

		if (my_strcmp(command, "FIND") == 0) {	//command로 FIND가 입력된 경우
			char* target = new char[100];
			cin >> target;	//두 번째 입력으로 target을 받음.
			int found = 0;	//found flag를 false로 초기화
			for (int i = 0; i < cnt; i++) {	//cnt보다 작은 모든 인덱스를 순회하면서 검사
				if (my_strcmp(words[i], target) == 0) {	//i번째 단어가 타겟과 같으면
					cout << i << "." << words[i] << "\n";	//단어 출력
					found = 1;	//found flag를 true로 바꾸고
					break;	//반복문 탈출
				}
			}
			if (!found) {	//found flag가 false이면
				cout << "Not Found\n";	//Not Found 출력
			}
			delete[] target;	//지역변수 할당 해제
		}

	}

	for (int i = 0; i < cnt; i++) {	//cnt보다 작은 모든 인덱스를 순회하면서 할당 해제
		delete[] words[i];
	}
	delete[] words;	//단어장 할당 해제
	return 0;
}

int my_strlen(char* str) {	//문자열 복제를 위한 문자열 길이 반환 함수
	for (int i = 0; i < 100; i++) {
		if (str[i] == NULL) {
			return i;
		}
	}
	return 99;
}

int my_strcmp(const char* str1, const char* str2) {	//command 유효성 검사를 위한 문자열대조 함수
	int i = 0;
	while (str1[i] != '\0' || str2[i] != '\0') {
		if (str1[i] != str2[i]) {
			return str1[i] - str2[i];
		}
		i++;
	}
	return 0;
}

int my_strcmp_nocase(const char* str1, const char* str2) {	//insert를 위한 대소문자 구분하지 않는 strcmp
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