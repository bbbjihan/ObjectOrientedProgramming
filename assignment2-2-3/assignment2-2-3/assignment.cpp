#include <iostream>
using namespace std;

int main() {
	unsigned int input;
	cout << "Please enter the length of matrix : ";
	cin >> input;

	unsigned int** field = new unsigned int* [input];
	for (unsigned int i = 0; i < input; i++) {
		field[i] = new unsigned int[input];
	}	//input*input 크기만큼의 int형 배열 동적할당

	unsigned int value = 0; //배열에 입력될 값 0으로 초기화
	unsigned int row = 0;	//참조할 열 인덱스 0으로 초기화
	unsigned int col = 0;	//참조할 행 인덱스 0으로 초기화
	int direction = 0; //방향값 0으로 초기화, 0:오른쪽, 1:아래, 2:왼쪽, 3:위
	unsigned int cnt = input;	//value를 입력할 횟수를 input-1로 초기화, cnt_cnt가 2가 되면 1씩 줄어듦.
	unsigned int cnt_left = cnt;	//현재 value의 남은 입력횟수. 0이 되면 cnt_cnt가 1 증가함.
	unsigned int cnt_cnt = 1;	//value를 cnt만큼 몇 회 배열에 입력했는지 저장하는 용도. 2가 되면 0으로 초기화 시켜야 함.

	while (cnt != 0) {	//더이상 움직일 필요가 없을 경우 반복문 종료
		field[row][col] = value;	//value 값을 배열의 목표 위치에 저장
		value++;	//value값 증가
		cnt_left--;	//cnt_left 감소
		if (cnt_left == 0) {	//cnt_left가 0인 경우
			if (direction == 3) {	//방향전환. 위로 향할 경우 오른쪽을 보도록 함.
				direction = 0;
			}
			else {	//위로 향하지 않을 경우 방향값을 1 증가시킴.
				direction++;
			}
			cnt_cnt++;	//cnt만큼 입력한 횟수인 cnt_cnt를 1 증가시킴
			if (cnt_cnt == 2) {	//cnt만큼 배열에 2회 입력한 경우
				cnt--;	//cnt를 1 감소시킴
				cnt_cnt = 0;	//cnt_cnt 초기화
			}
			cnt_left = cnt;	//해당 방향으로 이동할 횟수를 cnt로 다시 초기화
		}
		if (direction == 0) {
			col++;
		}
		else if (direction == 1) {
			row++;
		}
		else if (direction == 2) {
			col--;
		}
		else {
			row--;
		}	//방향에 따라 목표 좌표값 변경
	}

	for (unsigned int i = 0; i < input; i++) {
		for (unsigned int j = 0; j < input; j++) {
			cout << field[i][j] << "\t";
		}
		cout << "\n";
	}	//필드 출력

	for (unsigned int i = 0; i < input; i++) {
		delete[] field[i];
	}
	delete[] field;	//동적할당 해제
	return 0;
}