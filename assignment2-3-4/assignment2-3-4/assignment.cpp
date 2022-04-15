#include <iostream>
#pragma warning(disable : 4996)
using namespace std;

class animal {
private:
	char name[10];
	int year = 0;
	char species[100];
public:
	animal() { ; }	//생성자
	~animal() { ; }	//소멸자
	void set_animal(char* name, int year, char* species) {	//멤버변수를 set하는 set함수
		strcpy(this->name, name);
		this->year = year;
		strcpy(this->species,species);
	}
	void print() {	//멤버변수값 출력함수
		cout << "Name :" << name << "\n";
		cout << "Year :" << year << "\n";
		cout << "Species :" << species << "\n";
	}
	char* get_species() {	//멤버변수 species를 반환하는 get함수
		return species;
	}
};

class zoo {
private:
	class animal* animal_list[100];	//animal 클래스 포인터 배열 멤버변수
	int size = 0;	//animal_list의 초기화된 클래스 개수를 카운트하기 위한 변수
public:
	zoo() { ; }	//생성자
	~zoo() { ; }	//소멸자
	void new_animal(char* name, int year, char* species) {	//animal_list에 새로운 클래스를 생성하는 함수
		animal_list[size] = new animal();	//animal_list의 size index 원소에 새로운 animal 클래스 생성
		animal_list[size]->set_animal(name,year,species);	//선언된 animal 클래스의 멤버변수를 파라미터 값을 통해 초기화
		size++;	//size값 증가
	}
	void print_all() {	//animal_list의 모든 원소들의 정보를 출력하는 함수
		cout << "------print_all------\n";
		for (int i = 0; i < size; i++) {	//size값 내의 모든 인덱스를 순회
			cout << "----------" << i << "---------\n";
			animal_list[i]->print();	//animal_list의 i번째 원소인 클래스 내 멤버함수 print 호출
			cout << "---------------------\n";
		}
		cout << "---------------------\n";
	}
	void print_species(char* species){	//animal_list의 원소 중 파라미터로 입력된 species와 species가 일치하는 클래스의 정보들만 출력하는 함수
		int cnt = 0;	//같은 종의 마릿수 출력을 위한 카운터
		cout << "------print_species------\n";
		for (int i = 0; i < size; i++) {	//size값 내의 모든 인덱스를 순회
			if (!strcmp(animal_list[i]->get_species(), species)) {	//animal_list의 i번째 원소인 클래스의 멤버변수 species값을 get_species를 통해 반환받고, 이를 파라미터로 받은 species 문자열과 비교하여 같은 경우,
				cout << "----------" << i << "---------\n";
				animal_list[i]->print();	//해당 animal 클래스 내 멤버함수 print 호출
				cout << "---------------------\n";
				cnt++;	//카운터 1 증가
			}
		}
		cout << "Number of Species is :" << cnt;	//카운터값 출력
		cout << "\n---------------------\n";
	}
};

int main() {
	class zoo* Zoo = new class zoo();	//zoo 클래스포인터 Zoo 동적할당, 선언 및 초기화

	while (1) {	//무조건반복
		char* command = new char[100];	//명령문 동적할당
		cout << "Please Enter Any Command(new_animal, print_all,print_species,exit) :";
		cin >> command;	//명령문 입력받음

		if (!strcmp(command, "new_animal")) {	//new_animal이 입력된 경우
			char* name = new char[10];
			int year = 0;
			char* species = new char[100];	//입력값 저장을 위한 메모리 동적할당
			cin >> name >> year >> species;	//2,3,4번째 입력으로 name,year,species값을 저장함.
			Zoo->new_animal(name, year, species);	//입력값을 파라미터로 하여 Zoo 클래스 내 멤버함수 new_animal 호출
			delete[] name, species;	//입력값 할당해제
		}
		else if (!strcmp(command, "print_all")) {	//print_all이 입력된 경우
			Zoo->print_all();	//Zoo 클래스 내 멤버함수 print_all 호출
		}
		else if (!strcmp(command, "print_species")) {	//print_species가 입력된 경우
			char* species = new char[100];	//입력값 저장을 위한 메모리 동적할당
			cin >> species;	//2번째 입력으로 species 값을 저장함.
			Zoo->print_species(species);	//입력값을 파라미터로 Zoo 클래스 내 멤버함수 print_species 호출
			delete[] species;	//입력값 할당해제
		}
		else if (!strcmp(command, "exit")) {	//exit가 입력된 경우
			delete[] command;	//명령문 할당해제
			break;	//반복문 종료
		}
	}

	delete Zoo;	//클래스 할당해제
	return 0;
}