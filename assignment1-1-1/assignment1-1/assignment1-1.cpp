#include <iostream>
using namespace std;

int main() {
	char name[10], major[10];
	int ID;
	cout << "�̸� : ";
	cin >> name ;
	cout << "�й� : ";
	cin >> ID ;
	cout << "���� : ";
	cin >> major;
	cout << major<<" "<< ID <<" "<< name << endl;
	return 0;
}