#include <iostream>
using namespace std;

int main() {
	char str1[100]{}, str2[100]{};
	cout << "Array 1 :";
	cin >> str1;
	cout << "Array 2 :";
	cin >> str2;
	//�� ���� ���� ���ڿ� �Է¹ޱ�

	int size_str = 0;
	for (int i = 0; i < 100; i++) {
		if (str1[i] == 0 && str2[i] == 0) {
			break;
		}
		else if (str1[i] == 0 || str2[i] == 0) {
			cout << "Input lengths are different.";
			return 0;
		}
		else {
			size_str++;
		}
	} // �Է� ���ڿ� ���� Ȯ�� �� �� ���ڿ� ���� �ٸ� �� ����(����ó��)

	char tmp1, tmp2;

	for (int i = 0; i < size_str; i++) {
		tmp1 = str1[i];
		tmp2 = str2[i];
		if (tmp1 > 96) { tmp1 -= 32; }
		if (tmp2 > 96) { tmp2 -= 32; }
		// ��ҹ��� ������ ���ֱ� ���� �빮���� ��� (�ҹ���-�빮��) ���� 32�� ����
		if (tmp1 < tmp2) {
			str2[i] = tmp1;
			str1[i] = tmp2;
		} // tmp1�� tmp2���� ���� ��� ������ ������ǰ� �ݴ� ����̹Ƿ� swap����
	}

	cout << "Exchanged Array 1 :" << str1 << "\n";
	cout << "Exchanged Array 2 :" << str2 << "\n";
	return 0;
}