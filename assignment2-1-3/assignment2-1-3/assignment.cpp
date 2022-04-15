#include <iostream>
using namespace std;

int main() {
	int sizeA[2], sizeB[2];
	//�� ������迭�� 0��° ���Ҵ� ���� ����, 1��° ���Ҵ� ���� ����.
	srand(time(NULL));
	cout << "Matrix A :";
	cin >> sizeA[0] >> sizeA[1];
	cout << "Matrix B :";
	cin >> sizeB[0] >> sizeB[1];
	//�� ����� ���� ������ ���� ���� �Է¹���.

	int** mat_A = new int*[sizeA[0]];	//�Էµ� ���� ������ŭ�� ���̸� ���� �����͹迭 �����Ҵ�
	for (int i = 0; i < sizeA[0]; i++) {
		mat_A[i] = new int[sizeA[1]];	//������ �ʱ�ȭ�� �����͹迭�� ��ġ�� �� �Էµ� ���� ������ŭ�� ���̸� ���� ������ �迭 �����Ҵ�
		for (int j = 0; j < sizeA[1]; j++) {
			*(mat_A[i] + j) = rand() % 10 + 1;
		}	//����� ��� ���ҿ� ������ ����
	}

	int** mat_B = new int* [sizeB[0]];	//�Էµ� ���� ������ŭ�� ���̸� ���� �����͹迭 �����Ҵ�
	for (int i = 0; i < sizeB[0]; i++) {
		mat_B[i] = new int[sizeB[1]];	//������ �ʱ�ȭ�� �����͹迭�� ��ġ�� �� �Էµ� ���� ������ŭ�� ���̸� ���� ������ �迭 �����Ҵ�
		for (int j = 0; j < sizeB[1]; j++) {
			*(mat_B[i] + j) = rand() % 10 + 1;
		}	//����� ��� ���ҿ� ������ ����
	}

	cout << "\nA Matrix :\n";
	for (int i = 0; i < sizeA[0]; i++) {
		for (int j = 0; j < sizeA[1]; j++) {
			cout << *(mat_A[i] + j) << "\t";
		}
		cout << "\n";
	}	//matrix A ���
	
	cout << "\nB Matrix :\n";
	for (int i = 0; i < sizeB[0]; i++) {
		for (int j = 0; j < sizeB[1]; j++) {
			cout << *(mat_B[i] + j) << "\t";
		}
		cout << "\n";
	}	//matrix B ���

	int temp = 0; // temp int value for matrix multiplication
	if (sizeA[1] == sizeB[0]) {	//(i*n)��� * (n*j)��� = (i*j)����̹Ƿ� ù ��° ����� ���� ������ �� ��° ����� ���� ������ ���� ��츸 ��İ����� �۵�
		cout << "\nA*B Result :\n";
		for (int i = 0; i < sizeA[0]; i++) {
			for (int j = 0; j < sizeB[1]; j++) {
				temp = 0;
				for (int n = 0; n < sizeA[1]; n++) {
					temp += ((*(mat_A[i] + n)) * (*(mat_B[n] + j)));
				}
				cout << temp << "\t";
			}
			cout << "\n";
		}
	}
	else {
		cout << "\n\nCan't Operate Matrix Multiplication("<<sizeA[1] << "!="<<sizeB[0] << ")";
	}	//Matrix Multiplication

	for (int i = 0; i < sizeA[0]; i++) {
		delete[] mat_A[i];
	}
	for (int i = 0; i < sizeB[0]; i++) {
		delete[] mat_B[i];
	}
	delete[] mat_A;
	delete[] mat_B;	//�Ҵ�����
	return 0;
}