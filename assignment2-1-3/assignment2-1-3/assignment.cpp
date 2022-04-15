#include <iostream>
using namespace std;

int main() {
	int sizeA[2], sizeB[2];
	//각 사이즈배열의 0번째 원소는 행의 갯수, 1번째 원소는 열의 갯수.
	srand(time(NULL));
	cout << "Matrix A :";
	cin >> sizeA[0] >> sizeA[1];
	cout << "Matrix B :";
	cin >> sizeB[0] >> sizeB[1];
	//각 행렬의 행의 갯수와 열의 갯수 입력받음.

	int** mat_A = new int*[sizeA[0]];	//입력된 행의 갯수만큼의 길이를 가진 포인터배열 동적할당
	for (int i = 0; i < sizeA[0]; i++) {
		mat_A[i] = new int[sizeA[1]];	//위에서 초기화된 포인터배열의 위치에 각 입력된 열의 갯수만큼의 길이를 가진 정수형 배열 동적할당
		for (int j = 0; j < sizeA[1]; j++) {
			*(mat_A[i] + j) = rand() % 10 + 1;
		}	//행렬의 모든 원소에 랜덤값 저장
	}

	int** mat_B = new int* [sizeB[0]];	//입력된 행의 갯수만큼의 길이를 가진 포인터배열 동적할당
	for (int i = 0; i < sizeB[0]; i++) {
		mat_B[i] = new int[sizeB[1]];	//위에서 초기화된 포인터배열의 위치에 각 입력된 열의 갯수만큼의 길이를 가진 정수형 배열 동적할당
		for (int j = 0; j < sizeB[1]; j++) {
			*(mat_B[i] + j) = rand() % 10 + 1;
		}	//행렬의 모든 원소에 랜덤값 저장
	}

	cout << "\nA Matrix :\n";
	for (int i = 0; i < sizeA[0]; i++) {
		for (int j = 0; j < sizeA[1]; j++) {
			cout << *(mat_A[i] + j) << "\t";
		}
		cout << "\n";
	}	//matrix A 출력
	
	cout << "\nB Matrix :\n";
	for (int i = 0; i < sizeB[0]; i++) {
		for (int j = 0; j < sizeB[1]; j++) {
			cout << *(mat_B[i] + j) << "\t";
		}
		cout << "\n";
	}	//matrix B 출력

	int temp = 0; // temp int value for matrix multiplication
	if (sizeA[1] == sizeB[0]) {	//(i*n)행렬 * (n*j)행렬 = (i*j)행렬이므로 첫 번째 행렬의 열의 개수와 두 번째 행렬의 행의 개수가 같은 경우만 행렬곱연산 작동
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
	delete[] mat_B;	//할당해제
	return 0;
}