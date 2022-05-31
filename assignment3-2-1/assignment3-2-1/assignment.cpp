#include <iostream>
using namespace std;

class TwoPoint {
public:
	int x1, y1, x2, y2;
	TwoPoint() {	//TwoPoint ��ü ������
		this->x1 = 0;
		this->x2 = 0;
		this->y1 = 0;
		this->y2 = 0;
	}
	TwoPoint(int x1, int y1, int x2, int y2) {	//TwoPoint ��ü ������ overloading
		this->x1 = x1;
		this->x2 = x2;
		this->y1 = y1;
		this->y2 = y2;
	}
	virtual void print() {	//TwoPoint print virtual function.
		cout << "Point 1 : " << x1 << "," << y1 << "\n";
		cout << "Point 2 : " << x2 << "," << y2 << "\n";
	}
};

class Equation : public TwoPoint {	//TwoPoint ��ü�� ��ӹ޴� Equation ��ü ����
public:
	Equation(int x1, int y1, int x2, int y2) : TwoPoint(x1, y1, x2, y2) { ; }	//Equation��ü ������
	void print() {	//Equation print function.
		float a = (float(this->y2) - float(this->y1)) / (float(this->x2) - float(this->x1));	//����
		float b = float(this->y1) - (a * float(this->x1));	//y����
		cout << "Equation : y = " << a << "x + " << b << "\n";
	}
};

int main() {
	class TwoPoint* A = new TwoPoint(2, 4, 7, 8);
	class TwoPoint* B = new Equation(2, 4, 7, 8);
	A->print();	//A�� TwoPoint��ü�̹Ƿ� TwoPoint ��ü �� ����� Virtual Function Print�� ȣ���
	B->print();	//B�� Equation��ü�̹Ƿ� Equation ��ü �� ����� Print Function�� ȣ���
	delete A;
	delete B;
	return 0;
}