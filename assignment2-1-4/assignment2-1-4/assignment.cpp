#include <iostream>

using namespace std;

int main() {
	srand(time(NULL));
	int** matrix = new int* [10];	//10칸짜리 각 행의 시작위치를 가리키고 있는 포인터배열을 동적할당한다.

	for (int i = 0; i < 10; i++) {
		matrix[i] = new int[11];	//11칸짜리 행의 값 정보를 담고 있는 정수형 배열을 동적할당한다.
		*(matrix[i] + 10) = 0; //11번째 원소는 sum값임
		for (int j = 0; j < 10; j++) {
			*(matrix[i] + j) = rand()%100;
			*(matrix[i] + 10) += *(matrix[i] + j);	//한 행 안에서 값을 한 개씩 랜덤으로 저장해주면서 이를 해당 행의 11번째 값에 더해줌으로써 sum값을 구성시킨다.
		}
	}

	cout << "Original Matrix\n";
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << *(matrix[i] + j) << "\t";
		}
		cout << "\n";
	}	//위에서 선언 및 구성한 행렬을 일차적으로 출력한다.

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
	}	//행 내에서 각각의 행에 대하여 10번째 원소까지(sum인 11번째 원소 제외) 버블정렬을 수행한다.

	cout << "\nSort by row\n";
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << *(matrix[i] + j) << "\t";
		}
		cout << "Sum is " << *(matrix[i] + 10) <<" (" << matrix[i] << ")\n";
	}	//모든 행 내에서의 버블정렬 결과를 일괄 출력

	int *temp2; // temp2 for sort
	for (int i = 9; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (*(matrix[j] + 10) > *(matrix[j + 1] + 10)) {
				temp2 = matrix[j];
				matrix[j] = matrix[j + 1];
				matrix[j + 1] = temp2;
			}
		}
	}//행단위 합기준 버블정렬(인트형 포인터 temp2)

	cout << "\nSort by Sum\n";
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << *(matrix[i] + j) << "\t";
		}
		cout << "Sum is " << *(matrix[i] + 10) << " (" << matrix[i] << ")\n";
	}	//모든 행에 대해 행 누적합기준 버블정렬 결과를 일괄 출력

	for (int i = 0; i < 10; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;	//할당해제

	return 0;
}