#include <iostream>
using namespace std;

long long addition(long long a, long long b);

int main() {
	long long a,b;
	cout << "Enter Two Numbers :";
	cin >> a >> b;
	cout << addition(a, b);
	return 0;
}

long long addition(long long a, long long b) {
	return a + b;
}