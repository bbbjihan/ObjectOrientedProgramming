#include <iostream>
#include <cmath>
using namespace std;

int recursion(int level, int cnt, int max_level, int now_sum);

int main() {
	int N;
	cout << "Enter Any Positive Number : ";
	cin >> N;
	cout << recursion(0, 1, N, 0) << endl;

	return 0;
}

int recursion(int level, int cnt, int max_level, int now_sum) {
	if (level > max_level) {
		return now_sum;
	}
	if (cnt > pow(2,level)) {
		recursion(level + 1, 1, max_level, now_sum);
	}
	else {
		recursion(level, cnt + 1, max_level, now_sum + level);
	}
}