#include <iostream>
#include <cmath>
using namespace std;

int triangle_area(int a, int b, int c) {	//헤론공식
	int p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

class Polygon {
private:
	int Area;
	int Perimeter;
public:
	Polygon() { ; }	//생성자
	Polygon(int Area, int Perimeter) {	//생성자 오버로딩
		this->Area = Area;
		this->Perimeter = Perimeter;
	}
	~Polygon() { ; }	//소멸자
	void print_Area() {	//멤버변수 Area 출력
		cout << "Area is " << Area << "\n";
	};
	void print_Perimeter(){	//멤버변수 Perimeter 출력
		cout << "Perimeter is " << Perimeter << "\n";
	};
};

class Triangle: public Polygon {	//Polygon 클래스를 상속받는 Triangle 클래스 선언
private:
	int A;
	int B;
	int C;
public:
	Triangle(int A, int B, int C) : Polygon(triangle_area(A,B,C), A + B + C) {
		this->A = A;
		this->B = B;
		this->C = C;
	}	//생성자, Area가 triange_area(A,B,C):헤론공식 결과값, Perimeter가 A+B+C이도록 멤버변수 상속
	~Triangle() { ; }
};

class Square: public Polygon {	//Polygon 클래스를 상속받는 Square 클래스 선언
private:
	int A;
	int B;
public:
	Square(int A, int B) : Polygon(A*B,(A+B)*2) {
		this->A = A;
		this->B = B;
	}	//생성자, Area가 A*B이고, Perimeter가 (A+B)*2가 되도록 멤버변수 상속
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