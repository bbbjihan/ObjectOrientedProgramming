#include <iostream>
#pragma warning(disable : 4996)

using namespace std;
class Student_info {
private:
	char name[10];
	int age = 0;
	char university[100];
	char major[100];
public:
	Student_info(char* name, int age, char* univ, char* major) {	//생성자. 파라미터로 받은 값을 해당 클래스의 멤버 변수에 복제해줌.
		strcpy(this->name, name);
		this->age = age;
		strcpy(this->university, univ);
		strcpy(this->major, major);
	}
	bool find(char* name) {
		if (!strcmp(this->name, name)) {	//파라미터로 받은 name과 해당 클래스의 멤버변수 name의 비교
			return 1;	//같으면 true 반환
		}
		return 0;	//다르면 false 반환
	};
	void print() {	//해당 클래스 내의 멤버변수 정보 출력
		cout << "Name : " << name << "\n";
		cout << "Age : " << age << "\n";
		cout << "University : " << university << "\n";
		cout << "Major : " << major << "\n";
		cout << "------------------------\n";
	};
	void change(char* name, int age, char* univ, char* major) {	//set함수. 파라미터로 받은 값을 해당 클래스의 멤버 변수에 복제해줌.
		strcpy(this->name, name);
		this->age = age;
		strcpy(this->university, univ);
		strcpy(this->major, major);	
	}
	~Student_info() { ; }	//소멸자.
};

int main() {
	class Student_info** students = new class Student_info*[10];	//이중 클래스 포인터 동적할당(클래스 포인터 배열 생성)
	int cnt = 0;	//학생수를 카운트하기 위한 변수 초기화

	while (1) {
		char* command = new char[100];
		cout << "Please Enter Command(insert, find, change, print, exit) :";
		cin >> command;

		if (!strcmp(command, "insert")) {	//insert가 입력되었을 경우
			char* input_name = new char[10];
			int input_age = 0;
			char* input_university = new char[100];
			char* input_major = new char[100];	//입력값 동적할당
			cin >> input_name >> input_age >> input_university >> input_major;
			//2,3,4번째 입력으로 name,age,univ,major 값을 저장함.

			students[cnt] = new class Student_info(input_name, input_age, input_university, input_major);	//입력받은 값을 파라미터로 하여 클래스 포인터 배열의 마지막 원소에 새로운 클래스 선언
			cnt++;	//학생수 변수 1 증가
			delete[] input_name, input_university, input_major;	//입력값 할당해제
		}
		else if (!strcmp(command, "find")) {	//find가 입력되었을 경우
			char* input_name = new char[10];	//입력값 동적할당
			cin >> input_name;	//2번째 입력으로 name 값을 저장함
			for (int i = 0; i < cnt; i++) {	//모든 인원에 대하여 순회
				if (students[i]->find(input_name)) {	//해당 인덱스의 클래스 내 멤버변수 name이 입력값과 동일하다면
					cout << "----------find---------\n";
					students[i]->print();	//print 함수 호출
				}
			}
			delete[] input_name;	//입력값 할당해제
		}
		else if (!strcmp(command, "change")) {	//change가 입력되었을 경우
			char* input_name1 = new char[10];
			char* input_name2 = new char[10];
			int input_age = 0;
			char* input_university = new char[100];
			char* input_major = new char[100];	//입력값 동적할당
			cin >> input_name1 >> input_name2 >> input_age >> input_university >> input_major;
			//2,3,4,5 번째 입력으로 name1, name2, age, univ, major 값을 저장함.
			int target_idx = -1;	//목표 인덱스를 -1로 초기화
			for (int i = 0; i < cnt; i++) {
				if (students[i]->find(input_name1)) {	//해당 인덱스의 클래스 내 멤버변수 name이 입력값 name1과 동일하다면,
					target_idx = i;	//해당 인덱스를 target index로 설정하고,
					break;	//반복문 종료
				}
			}
			if (target_idx != -1) {	//목표 인덱스가 -1이 아니라면(name1과 같은 이름을 찾았을 경우)
				students[target_idx]->change(input_name2, input_age, input_university, input_major);	//목표 인덱스에 위치한 클래스의 정보를 입력값으로 갱신해줌.
			}
			delete[] input_name1, input_name2, input_university, input_major;	//할당 해제
		}
		else if (!strcmp(command, "print")) {	//print가 입력되었을 경우
			cout << "----------print---------\n";
			for (int i = 0; i < cnt; i++) {
				students[i]->print();	//클래스 내 멤버함수 print 호출
			}
		}
		else if (!strcmp(command, "exit")) {	//exit가 입력되었을 경우
			delete[] command;	//명령문 할당해제
			break;	//반복문 탈출
		}
	}

	for (int i = 0; i < cnt; i++) {
		delete students[i];
	}
	delete[] students;	//동적할당 해제
	return 0;
}