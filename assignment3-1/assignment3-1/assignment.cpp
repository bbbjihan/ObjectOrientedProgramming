#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

void bubble_sort(int Array[]);

int main() {
	int INPUT[20]{};
	int tmp;

	ifstream inobj("Assignment.txt"); // input file 실행
	if (!inobj) {
		cout << "Assignment.txt cannot open." << "\n";
		assert(false);
	}
	for (int i = 0; i < 20; i++) { // input file에서 input 받아와서 배열에 저장
		inobj >> tmp;
		INPUT[i] = int(tmp);
	}
	inobj.close(); // input file 종료

	cout << "Input array :";
	for (int i = 0; i < 20; i++) {
		cout << " " << INPUT[i];
	}
	cout << "\n"; // 정렬 이전 배열 출력

	bubble_sort(INPUT); // 정렬(버블정렬)

	cout << "Sorted array :";
	for (int i = 0; i < 20; i++) {
		cout << " " << INPUT[i];
	}
	cout << "\n"; // 정렬 이후 배열 출력

	return 0;
}

void bubble_sort(int Array[]) { // 버블 정렬 함수
	int tmp;
	for (int i = 19; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (Array[j] > Array[j + 1]) {
				tmp = Array[j];
				Array[j] = Array[j + 1];
				Array[j + 1] = tmp;
			}
		}
	}
}