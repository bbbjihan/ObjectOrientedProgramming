#include <iostream>
using namespace std;

int main() {
	unsigned int input;
	cout << "Please enter the length of matrix : ";
	cin >> input;

	unsigned int** field = new unsigned int* [input];
	for (unsigned int i = 0; i < input; i++) {
		field[i] = new unsigned int[input];
	}	//input*input ũ�⸸ŭ�� int�� �迭 �����Ҵ�

	unsigned int value = 0; //�迭�� �Էµ� �� 0���� �ʱ�ȭ
	unsigned int row = 0;	//������ �� �ε��� 0���� �ʱ�ȭ
	unsigned int col = 0;	//������ �� �ε��� 0���� �ʱ�ȭ
	int direction = 0; //���Ⱚ 0���� �ʱ�ȭ, 0:������, 1:�Ʒ�, 2:����, 3:��
	unsigned int cnt = input;	//value�� �Է��� Ƚ���� input-1�� �ʱ�ȭ, cnt_cnt�� 2�� �Ǹ� 1�� �پ��.
	unsigned int cnt_left = cnt;	//���� value�� ���� �Է�Ƚ��. 0�� �Ǹ� cnt_cnt�� 1 ������.
	unsigned int cnt_cnt = 1;	//value�� cnt��ŭ �� ȸ �迭�� �Է��ߴ��� �����ϴ� �뵵. 2�� �Ǹ� 0���� �ʱ�ȭ ���Ѿ� ��.

	while (cnt != 0) {	//���̻� ������ �ʿ䰡 ���� ��� �ݺ��� ����
		field[row][col] = value;	//value ���� �迭�� ��ǥ ��ġ�� ����
		value++;	//value�� ����
		cnt_left--;	//cnt_left ����
		if (cnt_left == 0) {	//cnt_left�� 0�� ���
			if (direction == 3) {	//������ȯ. ���� ���� ��� �������� ������ ��.
				direction = 0;
			}
			else {	//���� ������ ���� ��� ���Ⱚ�� 1 ������Ŵ.
				direction++;
			}
			cnt_cnt++;	//cnt��ŭ �Է��� Ƚ���� cnt_cnt�� 1 ������Ŵ
			if (cnt_cnt == 2) {	//cnt��ŭ �迭�� 2ȸ �Է��� ���
				cnt--;	//cnt�� 1 ���ҽ�Ŵ
				cnt_cnt = 0;	//cnt_cnt �ʱ�ȭ
			}
			cnt_left = cnt;	//�ش� �������� �̵��� Ƚ���� cnt�� �ٽ� �ʱ�ȭ
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
		}	//���⿡ ���� ��ǥ ��ǥ�� ����
	}

	for (unsigned int i = 0; i < input; i++) {
		for (unsigned int j = 0; j < input; j++) {
			cout << field[i][j] << "\t";
		}
		cout << "\n";
	}	//�ʵ� ���

	for (unsigned int i = 0; i < input; i++) {
		delete[] field[i];
	}
	delete[] field;	//�����Ҵ� ����
	return 0;
}