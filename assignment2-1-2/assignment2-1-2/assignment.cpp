#include <iostream>
using namespace std;

int main() {
	char str1[100], str2[100];	//입력받는 문자열은 동적할당하지 않아도 됨.
	cout << "String 1 : ";
	cin.getline(str1, 100);
	cout << "String 2 : ";
	cin.getline(str2, 100);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	//입력받은 두 문자열의 길이를 저장

	char* str3 = new char[len1+len2+1];	//입력받은 두 문자열 길이의 합과, "\0"문자를 저장할 한 칸만큼의 주소를 동적할당의 최대범위로 지정.

	for (int i = 0; i < len1; i++) {
		*(str3 + i) = str1[i];
	}//첫번째 문자열의 첫번째 문자부터 순회하며 동적할당된 배열에 순차적으로 저장
	for (int i = 0; i < len2; i++) {
		*(str3 + len1 + i) = str2[i];
	}//두번째 문자열의 첫번째 문자부터 순회하며 동적할당된 배열의 첫번째문자열길이 번째 인덱스부터 순차적으로 저장

	cout << "Result : ";
	for (int i = 0; i < len1 + len2 ; i++) {
		cout << *(str3 + i);
	}

	delete[] str3;
	return 0;
}

int strlen(char* string) {
	for (int i = 100; i > 0; i--) {
		if (string[i] != '\0') {
			return i+1;
		}
	}	// 입력최대길이가 100이므로 100부터 왼쪽으로 한 칸씩 줄여가며 문자열의 "\0"문자 위치를 탐색하고 반환함.
	return 100;
}