#include <iostream>
using namespace std;

void power2(int x, int& ans);
void power3(int x, int& ans);

int main() {
	int Num, ans1, ans2;
	cout << "Number :";
	cin >> Num;
	power2(Num, ans1);
	power3(Num, ans2);
	cout << "Number^2 : " << ans1 << endl;
	cout << "Number^3 : " << ans2 << endl;
	return 0;
}

void power2(int x, int& ans){
	ans = x * x;
}

void power3(int x, int& ans){
	ans = x * x * x;
}