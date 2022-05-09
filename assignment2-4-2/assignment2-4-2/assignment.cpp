#include <iostream>
#pragma warning(disable : 4996)
using namespace std;

class Student {
private:
	char name[20];
	int Score;
public:
	Student() { ; }	//Student class 생성자
	Student(char *name, int score) {	//Student class 생성자 overloading
		strcpy(this->name,name);
		this->Score = score;
	}
	~Student() { ; }	//Student class 소멸자
	char* get_name() {	//Student class의 name값 return함수
		return this->name;
	}
	int get_score() {	//Student class의 Score값 return함수
		return this->Score;
	}
};

int main() {
	class Student** students = new Student*[50];	//Student class를 모아둘 배열 할당
	int cnt = 0;

	while (1) {	//무조건반복
		int input;
		cout << "Please Enter Command(1:insert,2:sort by name,3:sort by score,4:quit) : ";
		cin >> input;	//입력받기
		if (input == 1) {	//1이 입력된 경우
			char *input_name = new char[10];
			int input_score;

			cout << "Name : ";
			cin >> input_name;	//두 번째 입력으로 이름 문자열 받음
			cout << "Score : ";
			cin >> input_score;	//세 번째 입력으로 int 점수 받음

			students[cnt] = new class Student(input_name, input_score);	//students의 마지막 index에 입력받은 정보의 student class 생성
			cnt++;
			delete[] input_name;	//동적할당 해제
		}
		else if (input == 2) {	//2가 입력된 경우
			class Student* tmp;	//정렬을 위한 temp student class 선언
			for (int i = cnt - 1; i > 0; i--) {
				for (int j = 0; j < i; j++) {
					if (strcmp(students[j]->get_name(), students[j + 1]->get_name()) > 0) {
						tmp = students[j];
						students[j] = students[j + 1];
						students[j + 1] = tmp;
					}
				}	//이름의 ASCII 값을 기준으로 하여 버블정렬
			}
			for (int i = 0; i < cnt; i++) {
				cout << students[i]->get_name() << " " << students[i]->get_score() << "\n";
			}	//정렬된 students 배열의 원소들을 출력
		}
		else if (input == 3) {	//3이 입력된 경우
			class Student* tmp;	//정렬을 위한 temp student class 선언
			for (int i = cnt - 1; i > 0; i--) {
				for (int j = 0; j < i; j++) {
					if (students[j]->get_score() > students[j+1]->get_score()) {
						tmp = students[j];
						students[j] = students[j + 1];
						students[j + 1] = tmp;
					}
				}	//점수 값을 기준으로 하여 버블정렬
			}
			for (int i = 0; i < cnt; i++) {
				cout << students[i]->get_name() << " " << students[i]->get_score() << "\n";
			}	//정렬된 students 배열의 원소들을 출력
		}
		else if (input == 4) {	//4가 입력된 경우
			break;
		}
	}
	delete[] students;
	return 0;
}