#include <iostream>
using namespace std;

void print_board(int node_x, int node_y);

int main() {
	char Command;
	int Node[2]{};

	print_board(Node[0], Node[1]);

	while (1) {
		cout << "Enter Move Command(a: Left, d: Right, w: Up, s: Down, q: Finish) :";
		cin >> Command;
		if (Command == 'a') {
			if (Node[0] > 0) {
				Node[0]--;
			}
		}
		else if (Command == 'd') {
			if (Node[0] < 2) {
				Node[0]++;
			}
		}
		else if (Command == 'w') {
			if (Node[1] > 0) {
				Node[1]--;
			}
		}
		else if (Command == 's') {
			if (Node[1] < 2) {
				Node[1]++;
			}
		}
		else if (Command == 'q') {
			break;
		}
		else {
			cout << "잘못된 입력입니다." << endl;
		}
		print_board(Node[0], Node[1]);
	}
	return 0;
}

void print_board(int node_x, int node_y) {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			if (y == node_y && x == node_x) {
				cout << "x\t";
			}
			else {
				cout << "0\t";
			}
		}
		cout << endl;
	}
};