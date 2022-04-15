#include <iostream>
using namespace std;

int main() {
	int a, b;
	cout << "Enter Two Numbers :";
	cin >> a >> b;
	cout << a << " + " << b << ": " << a + b << endl;
	cout << a << " - " << b << ": " << a - b << endl;
	cout << a << " * " << b << ": " << a * b << endl;
	cout << a << " / " << b << ": " << float(a) / float(b) << endl;
	cout << a << " % " << b << ": " << a % b << endl;
	return 0;
}