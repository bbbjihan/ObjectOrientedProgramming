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
	//0��°���� �ֱ� ����� �̵����� �����ϱ� ���� array ���� �� �ʱ�ȭ
	int move_count = 0;
	//������ ���� ������ ����ϱ� ���� ������ Ƚ�� ī��Ʈ
	char command[100];
	while (1) {
		for (int i = 0; i < 5; i++) {	//5x5 ���� ��¿� 2�� for��
			for (int j = 0; j < 5; j++) {
				if (node_list[0].x == j && node_list[0].y == i) {
					cout << "H";
				}	//���� ����� ��ġ�� H ���
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
				}	//���� ����� ��ġ�鿡 X ���
				else { cout << "0"; } // ��尡 ��ġ���� ���� ��� 0 ���
			}
			cout << "\n";
		}
		cin >> command;
		if (strlen(command) == 1) {	//�Է��� ��밡���� 2������ ��� �� ���� Ŀ�ǵ尡 ���ý���Ǿ� ���ڼ��� �˻��Ͽ� ��ɾ ���͸��ϱ�� ��.
			if (command[0] == 'q') {
				break;
			}
			else if (command[0] == 'w' && node_list[0].y != 0) {
				//Ŀ�ǵ� �Է½� Ŀ�ǵ� �۵��� ������ ��ġ���� Ȯ���� �� Ŀ�ǵ� �۵�.
				if (move_count > 2) { node_list[4] = node_list[3]; }
				//������ 3ȸ �̻� ������ ��� 4��° ������ �ʱ�ȭ ����
				if (move_count > 1) { node_list[3] = node_list[2]; }
				//������ 2ȸ �̻� ������ ��� 3��° ������ �ʱ�ȭ ����
				if (move_count > 0) { node_list[2] = node_list[1]; }
				//������ 1ȸ �̻� ������ ��� 2��° ������ �ʱ�ȭ ����
				node_list[1] = node_list[0]; //1��° ������ �ʱ�ȭ
				node_list[0].y--;	//Ŀ�ǵ� �۵�
				move_count++;	//���� �۵������Ƿ� �۵�Ƚ�� ����
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