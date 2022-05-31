#include <iostream>
#include <cmath>
using namespace std;

int triangle_area(int a, int b, int c) {	//��а���
	int p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

class Polygon {
private:
	int Area;
	int Perimeter;
public:
	Polygon() { ; }	//������
	Polygon(int Area, int Perimeter) {	//������ �����ε�
		this->Area = Area;
		this->Perimeter = Perimeter;
	}
	~Polygon() { ; }	//�Ҹ���
	void print_Area() {	//������� Area ���
		cout << "Area is " << Area << "\n";
	};
	void print_Perimeter(){	//������� Perimeter ���
		cout << "Perimeter is " << Perimeter << "\n";
	};
};

class Triangle: public Polygon {	//Polygon Ŭ������ ��ӹ޴� Triangle Ŭ���� ����
private:
	int A;
	int B;
	int C;
public:
	Triangle(int A, int B, int C) : Polygon(triangle_area(A,B,C), A + B + C) {
		this->A = A;
		this->B = B;
		this->C = C;
	}	//������, Area�� triange_area(A,B,C):��а��� �����, Perimeter�� A+B+C�̵��� ������� ���
	~Triangle() { ; }
};

class Square: public Polygon {	//Polygon Ŭ������ ��ӹ޴� Square Ŭ���� ����
private:
	int A;
	int B;
public:
	Square(int A, int B) : Polygon(A*B,(A+B)*2) {
		this->A = A;
		this->B = B;
	}	//������, Area�� A*B�̰�, Perimeter�� (A+B)*2�� �ǵ��� ������� ���
	~Square() { ; }
};

int main() {
	class Square A(5, 4);
	class Triangle B(13, 14, 15);

	cout << "-------Square-------" << endl;
	A.print_Area();
	A.print_Perimeter();
	cout << "--------------------" << endl;
	cout << "------Triangle------" << endl;
	B.print_Area();
	B.print_Perimeter();
	cout << "--------------------" << endl;
	return 0;
}