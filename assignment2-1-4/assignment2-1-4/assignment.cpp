#include <iostream>

using namespace std;

int main() {
	srand(time(NULL));
	int** matrix = new int* [10];	//10ĭ¥�� �� ���� ������ġ�� ����Ű�� �ִ� �����͹迭�� �����Ҵ��Ѵ�.

	for (int i = 0; i < 10; i++) {
		matrix[i] = new int[11];	//11ĭ¥�� ���� �� ������ ��� �ִ� ������ �迭�� �����Ҵ��Ѵ�.
		*(matrix[i] + 10) = 0; //11��° ���Ҵ� sum����
		for (int j = 0; j < 10; j++) {
			*(matrix[i] + j) = rand()%100;
			*(matrix[i] + 10) += *(matrix[i] + j);	//�� �� �ȿ��� ���� �� ���� �������� �������ָ鼭 �̸� �ش� ���� 11��° ���� ���������ν� sum���� ������Ų��.
		}
	}

	cout << "Original Matrix\n";
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << *(matrix[i] + j) << "\t";
		}
		cout << "\n";
	}	//������ ���� �� ������ ����� ���������� ����Ѵ�.

	int temp; // temp for sort
	for (int i = 0; i < 10; i++) {
		for (int j = 9; j > 0; j--) {
			for (int k = 0; k < j; k++) {
				if (*(matrix[i] + k) > *(matrix[i] + k + 1)) {
					temp = *(matrix[i] + k);
					*(matrix[i] + k) = *(matrix[i] + k + 1);
					*(matrix[i] + k + 1) = temp;
				}
			}
		}
	}	//�� ������ ������ �࿡ ���Ͽ� 10��° ���ұ���(sum�� 11��° ���� ����) ���������� �����Ѵ�.

	cout << "\nSort by row\n";
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << *(matrix[i] + j) << "\t";
		}
		cout << "Sum is " << *(matrix[i] + 10) <<" (" << matrix[i] << ")\n";
	}	//��� �� �������� �������� ����� �ϰ� ���

	int *temp2; // temp2 for sort
	for (int i = 9; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (*(matrix[j] + 10) > *(matrix[j + 1] + 10)) {
				temp2 = matrix[j];
				matrix[j] = matrix[j + 1];
				matrix[j + 1] = temp2;
			}
		}
	}//����� �ձ��� ��������(��Ʈ�� ������ temp2)

	cout << "\nSort by Sum\n";
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << *(matrix[i] + j) << "\t";
		}
		cout << "Sum is " << *(matrix[i] + 10) << " (" << matrix[i] << ")\n";
	}	//��� �࿡ ���� �� �����ձ��� �������� ����� �ϰ� ���

	for (int i = 0; i < 10; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;	//�Ҵ�����

	return 0;
}