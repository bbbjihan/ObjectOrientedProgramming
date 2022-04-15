#include <iostream>
using namespace std;

char* my_strtok(char* string);
int strtok_flag = 0;
char* prev_strtok;

int main() {
	char* input = new char [100];	//입력 문자열 동적메모리할당
	char** string = new char* [10];	//tokenized string 동적메모리할당
	cout << "Please Enter Any String :";
	cin >> input;

	int idx = 0;
	string[idx] = my_strtok(input);	//strtok 첫 번째 호출(string[0]이 input[0]과 같은 주소를 가리키게 함)
	while (string[idx] != NULL) {	//string[0]!=NULL이므로 반복문 시작, '/'가 뒤에 없는 부분문자열이 발생하면 함수 내에서 NULL을 반환하므로 그 때 반복문 종료.
		string[++idx] = my_strtok(NULL);	//idx에 1을 더한 뒤 my_strtok(NULL) 호출
	}
	for (int i = 0; i < idx; i++) {	//string[idx] == NULL 이므로 그 이전 값까지 출력
		cout << string[i] << endl;
	}

	delete[] string;
	delete[] input;	//동적할당 해제
	return 0;
}

char* my_strtok(char* string) {
	if (string == NULL) {	//인자로 입력된 문자열이 NULL인 경우
		if (!strtok_flag) {	//strtok_flag가 0인 경우 NULL을 반환함 -> 처음 사용하는데 NULL로 인자가 입력된 경우나 더 이상 문자열에 '/'이 존재하지 않는 경우
			return NULL;
		}
		else {
			char* strtok = prev_strtok + 1;
			char* strtok_rtn = prev_strtok + 1;
			//prev_strtok는 이전에 NULL로 치환한 주소값이므로 이보다 1 큰 값으로 초기화해줌.
			while (*strtok != '/') {	//strtok가 가리키는 문자가 '/'가 될 때까지 포인터값 증가
				if (*strtok == NULL) {	//문자열에 더 이상 '/'가 존재하지 않는 경우 strtok_flag를 감소시켜 다음 호출 때 NULL이 반환되도록 해줌
					strtok_flag--;
					return strtok_rtn;	//이전 호출 때 NULL로 치환해준 메모리주소 + 1을 반환
				}
				strtok++;
			}
			*strtok = NULL;	//strtok가 가리키는 '/'문자를 NULL로 치환
			prev_strtok = strtok;	//return하면 값이 사라지므로 전역변수에 이번 호출로 NULL로 치환된 주소를 저장해줌
			return strtok_rtn;	//이전 호출 때 NULL로 치환해준 메모리주소 + 1을 반환
		}
	}
	else {	//인자로 입력된 문자열이 NULL이 아닌 경우
		char* strtok = string;
		while (*strtok != '/') {	//strtok가 가리키는 문자가 '/'가 될 때까지 포인터값 증가
			if (*strtok == NULL) {	//문자열에 '/'이 포함되지 않은 경우 strtok_flag를 증가시키지 않으므로 다음 함수 호출 때 NULL이 반환되게 해줌
				return string;
			}
			strtok++;
		}
		*strtok = NULL;	//strtok가 가리키는 '/'문자를 NULL로 치환
		prev_strtok = strtok;	//return하면 값이 사라지므로 전역변수에 NULL로 치환한 주소 저장
		strtok_flag++;	//strtok_flag를 증가시켜서 다음 호출 때 NULL이 반환되지 않도록 함
		return string;	//첫 번째'/'를 이미 NULL로 치환했으므로 string이 가리키는 첫 번째 값부터 출력하면 NULL을 만나 문자열이 잘리게 됨
	}
}