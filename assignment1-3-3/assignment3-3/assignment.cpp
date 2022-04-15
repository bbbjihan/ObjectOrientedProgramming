#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int length(char str[]);
void sort(char array[][20], int length);

int main() {
	ifstream inobj("Assignment.txt");
	char words[100][20];
	int words_count = 0;

	if (!inobj) {
		cout << "Assignment.txt cannot open";
		return 0;
	}	//오류 예외처리

	while (!inobj.eof()) {
		inobj >> words[words_count];
		words_count++;
	}//입력받은 단어 메모리에 할당

	inobj.close();
	sort(words, words_count);

	int nowlen = strlen(words[0]);
	cout << "Length " << nowlen << " :";
	for (int i = 0; i < words_count; i++) {
		if (strlen(words[i]) > nowlen){
			nowlen++;
			cout << "\nLength " << nowlen << " :";
		}
		cout << words[i] << " ";
	}

	return 0;
}

void sort(char array[][20], int length) {
	char tmp[20];
	int length_1, length_2;
	for (int i = length; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (strlen(array[j]) > strlen(array[j + 1])){
				strcpy_s(tmp,array[j]);
				strcpy_s(array[j], array[j + 1]);
				strcpy_s(array[j + 1], tmp);
			}
		}
	}
}