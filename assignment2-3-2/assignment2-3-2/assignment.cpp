#include <iostream>
using namespace std;

int mystrcmp(const char* str1, const char* str2);
int mystrlen(const char* str);

class My_string {
private:
	char* str;
public:
	My_string(char* constructor) { this->str = constructor; }		//생성자
	~My_string() { ; }	//소멸자

	int my_strlen() {	//get string length function
		int i = 0;
		while (this->str[++i] != '\0');
		return i;
	}

	void my_strcpy(char* input) {	
		int length = mystrlen(input);
		for (int i = 0; i < length; i++) {
			this->str[i] = input[i];	//멤버변수 위에 파라미터로 전달된 문자열을 복제한다.
		}
		this->str[length] = '\0';	//문자열의 끝을 지정하여 넘치는 부분을 무시하도록 만든다.
	}

	void my_strcat(char* input) { //파라미터로 전달된 문자열을 클래스의 멤버함수 뒤에 이어붙이는 함수이다.
		int length = my_strlen();
		int length_input = mystrlen(input);
		for (int i = 0; i < length; i++) {
			this->str[i + length] = input[i];	//멤버변수 문자열의 끝으로 저장된 '\0' 문자부터 덮어씌우면서 복제한다.
		}
		this->str[length + length_input] = '\0';	//문자열의 끝 지정
	}

	void print() {	//print string
		cout << "Current String : " << this->str << "\n";
	}
};

int main() {
	char* input = new char[100];
	cout << "First String : ";
	cin >> input;
	class My_string *my_string = new class My_string(input);
	//입력받은 문자열을 통해 새로운 클래스 동적할당
	while (1) {	//무조건반복
		char* command = new char[100];	//입력문 동적할당
		cout << "Please Enter Command(strlen, strcpy, strcat, print, quit) :";
		cin >> command;

		if (!mystrcmp(command, "strlen")) {	//strlen이 입력된 경우
			cout << "String Length :" << my_string->my_strlen() << "\n";	//strlen을 통해 반환받은 값을 출력
		}
		else if (!mystrcmp(command, "strcpy")) {	//strcpy가 첫 번째 입력으로 들어온 경우
			char* cpy_string = new char[100];	//두 번째 입력 동적할당
			cin >> cpy_string;	//두 번째 입력 문자열 받아서
			my_string->my_strcpy(cpy_string);	//멤버함수 my_strcpy의 파라미터로 호출
			cout << "strcpy is done\n";	//안내문자열 출력
			delete[] cpy_string;	//동적할당 해제

		}
		else if (!mystrcmp(command, "strcat")) {	//strcat이 첫 번째 입력으로 들어온 경우
			char* cat_string = new char[100];	//두 번째 입력 동적할당
			cin >> cat_string;	//두 번째 입력 문자열 받아서
			my_string->my_strcat(cat_string);	//멤버함수 my_strcat의 파라미터로 호출
			cout << "strcat is done\n";	//안내문자열 출력
			delete[] cat_string;	//동적할당 해제
		}
		else if (!mystrcmp(command, "print")) {	//print가 입력된 경우
			my_string->print();	//클래스 내 멤버함수 'print'호출
		}
		else if (!mystrcmp(command, "quit")) {	//quit가 입력된 경우
			delete[] command;	//동적할당 해제
			break;	//반복문 탈출
		}
	}

	delete my_string;	//클래스 동적할당 해제
	delete[] input;
	return 0;
}

int mystrcmp(const char* str1, const char* str2) {	//명령문 유효성 검사를 위한 strcmp함수
	int i = 0;
	while (str1[i] != '\0' || str2[i] != '\0') {
		if (str1[i] != str2[i]) {
			return str1[i] - str2[i];
		}
		i++;
	}
	return 0;
};

int mystrlen(const char* str) {	//멤버변수 내 for문의 이터레이터 조작을 위한 strlen함수
	int i = 0;
	while (str[i] != '\0') {
		i++;
	}
	return i;
};