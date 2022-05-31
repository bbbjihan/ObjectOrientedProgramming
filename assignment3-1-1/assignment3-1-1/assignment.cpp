#include <iostream>
using namespace std;

class Person {
private:
	char Name[20];
	int Age;
	char Address[20];
public:
	Person() { ; }	//������
	friend std::istream& operator>>(std::istream &in, Person& A);	//�Է¿����� �����ε� �Լ� friend ����
	friend std::ostream& operator<<(std::ostream &out, Person& A);	//��¿����� �����ε� �Լ� friend ����
};

std::istream& operator>>(std::istream &in, Person& A) {
	in >> A.Name >> A.Age >> A.Address;	//�Է� ��Ŀ� �°� in stream���� �Է¹���
	return in;	//in stream ��ȯ
}

std::ostream& operator<<(std::ostream &out, Person& A) {
	out << "�̸� :" << A.Name << "\n" << "���� :" << A.Age << "\n" << "������ :" << A.Address;	//��� ��Ŀ� �°� ������ ���ڿ��� out stream���� ���
	return out;	//out stream ��ȯ
}

int main() {
	Person P;
	cin >> P;
	cout << P;
	return 0;
}