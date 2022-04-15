#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

void bubble_sort(int Array[]);

int main() {
	int INPUT[20]{};
	int tmp;

	ifstream inobj("Assignment.txt"); // input file ����
	if (!inobj) {
		cout << "Assignment.txt cannot open." << "\n";
		assert(false);
	}
	for (int i = 0; i < 20; i++) { // input file���� input �޾ƿͼ� �迭�� ����
		inobj >> tmp;
		INPUT[i] = int(tmp);
	}
	inobj.close(); // input file ����

	cout << "Input array :";
	for (int i = 0; i < 20; i++) {
		cout << " " << INPUT[i];
	}
	cout << "\n"; // ���� ���� �迭 ���

	bubble_sort(INPUT); // ����(��������)

	cout << "Sorted array :";
	for (int i = 0; i < 20; i++) {
		cout << " " << INPUT[i];
	}
	cout << "\n"; // ���� ���� �迭 ���

	return 0;
}

void bubble_sort(int Array[]) { // ���� ���� �Լ�
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