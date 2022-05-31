#include <iostream>
using namespace std;

class Person {
private:
	char Name[20];
	int Age;
	char Address[20];
public:
	Person() { ; }	//생성자
	friend std::istream& operator>>(std::istream &in, Person& A);	//입력연산자 오버로딩 함수 friend 선언
	friend std::ostream& operator<<(std::ostream &out, Person& A);	//출력연산자 오버로딩 함수 friend 선언
};

std::istream& operator>>(std::istream &in, Person& A) {
	in >> A.Name >> A.Age >> A.Address;	//입력 양식에 맞게 in stream으로 입력받음
	return in;	//in stream 반환
}

std::ostream& operator<<(std::ostream &out, Person& A) {
	out << "이름 :" << A.Name << "\n" << "나이 :" << A.Age << "\n" << "거주지 :" << A.Address;	//출력 양식에 맞게 가공된 문자열을 out stream으로 출력
	return out;	//out stream 반환
}

int main() {
	Person P;
	cin >> P;
	cout << P;
	return 0;
}