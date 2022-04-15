#include <iostream>
using namespace std;

int main() {
	int N;
	cout << "Enter any Number :";
	cin >> N;
	if (N > 0 && N < 21) {
		for (int i = 1; i < 21; i++) {
			cout << i;
			if (i % N == 0) {
				cout << "\n";
			}
			else {
				cout << "\t";
			}
		}
	}
	else {
		cout << "VALUE ERROR" << endl;
	}
	return 0;
}