#include <iostream>
#pragma warning(disable:4996)
using namespace std;

class 대학 {
private:
	char U_Name[20];
	int year;
	char U_StuID[20];
public:
	대학(char* U_Name, int year, char* U_StuID) {	//대학 클래스 생성자
		strcpy(this->U_Name, U_Name);
		this->year = year;
		strcpy(this->U_StuID, U_StuID);
	}
	~대학() { ; }	//대학 클래스 소멸자
	char* get_U_StuID() {	//대학 클래스 멤버변수인 대학이름 반환함수
		return this->U_StuID;
	}
	char* get_U_Name() {	//대학 클래스 멤버변수인 학생이름 반환함수
		return this->U_Name;
	}
	int get_year() {	//대학 클래스 멤버변수인 학년 반환함수
		return this->year;
	}
};

class 컴퓨터정보공학 : public 대학 {	//대학 클래스를 상속받는 컴퓨터정보공학 클래스 선언
private:
	char Object_Oriented_Programing;
	char Digital_Logic_Circuit;
public:
	컴퓨터정보공학(char* U_Name, int year, char* U_StuID, char OOP, char DLC) : 대학(U_Name	, year, U_StuID) {
		this->Object_Oriented_Programing = OOP;
		this->Digital_Logic_Circuit = DLC;
	}	//컴퓨터정보공학 클래스 생성자(대학 클래스의 멤버변수도 함께 초기화해주기 위한 대학클래스 생성자도 함께 호출함)
	char get_OOP() {	//컴퓨터정보공학 클래스 멤버변수인 OOP학점 반환함수
		return this->Object_Oriented_Programing;
	}
	char get_DLC() {	//컴퓨터정보공학 클래스 멤버변수인 DLC학점 반환함수
		return this->Digital_Logic_Circuit;
	}
};

class 학생정보 : public 컴퓨터정보공학 {	//컴퓨터정보공학 클래스를 상속받는 학생정보 클래스 선언
private:
	char Name[10];
	int age;
public:
	학생정보() : 컴퓨터정보공학(NULL, 0, NULL, NULL, NULL) {
		*this->Name = NULL;
		age = 0;
	}	//학생정보 클래스 생성자
	학생정보(char* U_Name, int year, char* U_StuID, char OOP, char DLC, char* Name, int age) : 컴퓨터정보공학(U_Name, year, U_StuID, OOP, DLC) {
		strcpy(this->Name, Name);
		this->age = age;
	}	//학생정보 클래스 생성자 overloading(컴퓨터정보공학 클래스의 멤버변수도 함께 초기화해주기 위한 컴퓨터정보공학 클래스 생성자도 함께 호출함)
	char* get_Name() {	//학생정보 클래스 멤버변수인 학생이름 반환함수
		return this->Name;
	}
};

int main() {
	class 학생정보** students = new class 학생정보*[100];	//최대 100명의 학생정보를 저장할 수 있는 학생정보 클래스 배열 포인터 변수 선언 및 동적할당
	int cnt = 0;	//students 배열 접근 index를 위한 학생수 저장 변수 선언 및 초기화
	while (1) {
		char command[100];
		cin >> command;
		if (!strcmp(command, "INSERT")) {	//입력이 INSERT인 경우
			if (cnt == 100) {	//학생수가 이미 100인 경우
				continue;	//명령 생략
			}
			char U_Name[20];
			int year;
			char U_StuID[20];
			char OOP;
			char DLC;
			char Name[10];
			int age;

			cout << "학교 :";
			cin >> U_Name;	//두 번째 입력으로 학교 이름 입력받음
			cout << "학번 :";
			cin >> U_StuID;	//세 번째 입력으로 학번 입력받음
			cout << "학년 :";
			cin >> year;	//네 번째 입력으로 학년 입력받음
			cout << "객체지향프로그래밍 학점 :";
			cin >> OOP;	//다섯 번째 입력으로 OOP학점 입력받음
			cout << "디지털논리회로 학점 :";
			cin >> DLC;	//여섯 번째 입력으로 DLC학점 입력받음
			cout << "이름 :";
			cin >> Name;	//일곱 번째 입력으로 이름 입력받음
			cout << "나이 :";
			cin >> age;	//여덟 번째 입력으로 나이 입력받음
			students[cnt] = new class 학생정보(U_Name, year, U_StuID, OOP, DLC, Name, age);
				//입력받은 값들로 새로운 학생정보 클래스 선언 및 students 배열의 마지막 원소로 동적할당
			cnt++;	//학생수 증가
		}
		else if (!strcmp(command, "FIND")) {	//입력이 FIND인 경우
			char Name[10];
			char U_StuID[20];
			cin >> Name >> U_StuID;	//두 번째 입력으로 이름, 세 번째 입력으로 학번 입력받음
			for (int i = 0; i < cnt; i++) {	//students에 저장된 모든 학생정보 클래스를 순회
				if (!strcmp((*students[i]).get_Name(), Name) && !strcmp((*students[i]).get_U_StuID(), U_StuID)) {	//입력된 이름과 학번이 일치하는 학생정보를 발견한 경우
					cout << "학교:" << (*students[i]).get_U_Name() << "\n";
					cout << "학번:" << (*students[i]).get_U_StuID() << "\n";
					cout << "학년:" << (*students[i]).get_year() << "\n";
					cout << "객체지향프로그래밍 학점:" << (*students[i]).get_OOP() << "\n";
					cout << "디지털논리회로 학점:" << (*students[i]).get_DLC() << "\n";
					break;	//학생정보 출력 및 반복문 종료
				}
			}
		}
		else if (!strcmp(command, "EXIT")) {	//입력이 EXIT인 경우
			break;	//반복문 종료
		}
	}
	for (int i = 0; i < cnt; i++) {	//students 내 선언된 학생정보 클래스들의 동적할당 해제
		delete students[i];
	}
	delete[] students;	//students 배열 동적할당 해제
	return 0;
}