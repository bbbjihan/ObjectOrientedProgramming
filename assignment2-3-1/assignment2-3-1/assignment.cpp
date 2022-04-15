#include <iostream>
using namespace std;

class A {
private:
	int value;	//멤버변수
public:
	A(int constructor) {	//생성자
		this->value = constructor;	//멤버변수 초기화
		cout << "Class A is Created with " << value << "\n";
	}
	~A() {
		cout << "Class A is Destroyed with " << value;
	}
};

int main() {
	int input;
	cout << "Enter Any Number :";
	cin >> input;
	class A* A = new class A(input);	//새 클래스 동적할당(생성자 호출)
	delete A;	//동적할당 해제(소멸자 호출)
	return 0;
}