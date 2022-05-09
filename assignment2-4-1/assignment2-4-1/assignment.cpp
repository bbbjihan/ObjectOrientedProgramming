#include <iostream>
using namespace std;

class Overloading {
public:
	Overloading() { ; }
	~Overloading() { ; }
	void add(int a, int b) {	//add ���� ����(�Ķ���Ͱ� int type�� ���)
		cout << "Int type add: "<< a + b << "\n";
	}
	void add(float a, float b) {	//add ���� ������(�Ķ���Ͱ� float type�� ���)
		cout << "Float type add: " << a + b << "\n";
	}
	void add(unsigned int a, unsigned int b) {	//add ���� ������(�Ķ���Ͱ� unsigned int type�� ���)
		cout << "Unsigned int type add: " << a + b << "\n";
	}
};

int main() {
	class Overloading A;
	int int_a = 5, int_b = -10;
	float float_a = 5.1, float_b = 5.3;
	unsigned int unsigned_int_a = 5, unsigned_int_b = 5;

	A.add(int_a, int_b);
	A.add(float_a, float_b);
	A.add(unsigned_int_a, unsigned_int_b);
	return 0;
}