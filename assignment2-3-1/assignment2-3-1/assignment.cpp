#include <iostream>
using namespace std;

class A {
private:
	int value;	//�������
public:
	A(int constructor) {	//������
		this->value = constructor;	//������� �ʱ�ȭ
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
	class A* A = new class A(input);	//�� Ŭ���� �����Ҵ�(������ ȣ��)
	delete A;	//�����Ҵ� ����(�Ҹ��� ȣ��)
	return 0;
}