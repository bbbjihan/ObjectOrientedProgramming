#include<iostream>
#include<cstring>
using namespace std;

class node {
public:
	int x;
	int y;
};

int main() {
	node node_list[5] = { { 0, 0 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 } };
	//0번째부터 최근 노드의 이동값을 저장하기 위한 array 선언 및 초기화
	int move_count = 0;
	//조건을 통해 꼬리를 출력하기 위한 움직인 횟수 카운트
	char command[100];
	while (1) {
		for (int i = 0; i < 5; i++) {	//5x5 보드 출력용 2중 for문
			for (int j = 0; j < 5; j++) {
				if (node_list[0].x == j && node_list[0].y == i) {
					cout << "H";
				}	//현재 노드의 위치에 H 출력
				else if (node_list[1].x == j && node_list[1].y == i) {
					cout << "X";
				}
				else if (node_list[2].x == j && node_list[2].y == i) {
					cout << "X";
				}
				else if (node_list[3].x == j && node_list[3].y == i) {
					cout << "X";
				}
				else if (node_list[4].x == j && node_list[4].y == i) {
					cout << "X";
				}	//이전 노드의 위치들에 X 출력
				else { cout << "0"; } // 노드가 위치하지 않을 경우 0 출력
			}
			cout << "\n";
		}
		cin >> command;
		if (strlen(command) == 1) {	//입력이 허용가능한 2글자일 경우 두 개의 커맨드가 동시실행되어 글자수를 검사하여 명령어를 필터링하기로 함.
			if (command[0] == 'q') {
				break;
			}
			else if (command[0] == 'w' && node_list[0].y != 0) {
				//커맨드 입력시 커맨드 작동이 가능한 위치인지 확인한 뒤 커맨드 작동.
				if (move_count > 2) { node_list[4] = node_list[3]; }
				//이전에 3회 이상 움직인 경우 4번째 꼬리값 초기화 시작
				if (move_count > 1) { node_list[3] = node_list[2]; }
				//이전에 2회 이상 움직인 경우 3번째 꼬리값 초기화 시작
				if (move_count > 0) { node_list[2] = node_list[1]; }
				//이전에 1회 이상 움직인 경우 2번째 꼬리값 초기화 시작
				node_list[1] = node_list[0]; //1번째 꼬리값 초기화
				node_list[0].y--;	//커맨드 작동
				move_count++;	//실제 작동했으므로 작동횟수 증가
			}
			else if (command[0] == 'a' && node_list[0].x != 0) {
				if (move_count > 2) { node_list[4] = node_list[3]; }
				if (move_count > 1) { node_list[3] = node_list[2]; }
				if (move_count > 0) { node_list[2] = node_list[1]; }
				node_list[1] = node_list[0];
				node_list[0].x--;
				move_count++;
			}
			else if (command[0] == 's' && node_list[0].y != 4) {
				if (move_count > 2) { node_list[4] = node_list[3]; }
				if (move_count > 1) { node_list[3] = node_list[2]; }
				if (move_count > 0) { node_list[2] = node_list[1]; }
				node_list[1] = node_list[0];
				node_list[0].y++;
				move_count++;
			}
			else if (command[0] == 'd' && node_list[0].x != 4) {
				if (move_count > 2) { node_list[4] = node_list[3]; }
				if (move_count > 1) { node_list[3] = node_list[2]; }
				if (move_count > 0) { node_list[2] = node_list[1]; }
				node_list[1] = node_list[0];
				node_list[0].x++;
				move_count++;
			}
		}
	}
	return 0;
}