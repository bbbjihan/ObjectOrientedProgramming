#include <iostream>
using namespace std;

int main() {
	char str1[100]{}, str2[100]{};
	cout << "Array 1 :";
	cin >> str1;
	cout << "Array 2 :";
	cin >> str2;
	//두 개의 영어 문자열 입력받기

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
	} // 입력 문자열 길이 확인 및 두 문자열 길이 다를 시 종료(예외처리)

	char tmp1, tmp2;
	int code1, code2;

	for (int i = 0; i < size_str; i++) {
		tmp1 = str1[i];
		tmp2 = str2[i];
		code1 = int(tmp1);
		code2 = int(tmp2);
		if (code1 > 96) { code1 -= 32; }
		if (code2 > 96) { code2 -= 32; }
		// 대소문자 구분을 없애기 위해 대문자의 경우 (소문자-대문자) 값인 32를 빼줌
		if (code1 < code2) {
			str2[i] = tmp1;
			str1[i] = tmp2;
		} // code1이 code2보다 작은 경우 문제의 출력조건과 반대 경우이므로 swap해줌
	}

	cout << "Exchanged Array 1 :" << str1 << "\n";
	cout << "Exchanged Array 2 :" << str2 << "\n";
	return 0;
}