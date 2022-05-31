#include <iostream>
#include <cstring>
#include <stdlib.h>
#pragma warning(disable : 4996)
using namespace std;

class mystring {
public:
	char* string;
	mystring() { 
		this->string = (char*)malloc(sizeof(char));
		if (this->string != NULL) {
			this->string[0] = '\0';
		}
	}
	~mystring() {
		free(this->string);
	}
};

void operator+=(mystring& A, char* B) {
	int lenA = strlen(A.string);
	int lenB = strlen(B);
	A.string = (char*)realloc(A.string, sizeof(char) * (lenA + lenB + 1));
	if (A.string != NULL) {
		for (int i = 0; i < lenB; i++) {
			A.string[lenA + i] = B[i];
		}
		A.string[lenA + lenB] = '\0';
	}
}

void operator-=(mystring& A, char B) {
	int len = strlen(A.string);
	int i = 0;
	while (i < len) {
		if (A.string[i] == B) {
			if (i == len - 1) {
				A.string[i] = '\0';
			}
			else {
				for (int j = i; j < len-1; j++) {
					A.string[j] = A.string[j + 1];
				}
				A.string[len - 1] = '\0';
			}
			len--;
		}
		else {
			i++;
		}
	}
}

void operator--(mystring& A, int) {
	int len = strlen(A.string);
	if (len != 0) {
		A.string[len - 1] = '\0';
	}
}

void operator&&(mystring& A, char B) {
	int len = strlen(A.string);
	for (int i = 0; i < len; i++) {
		if (A.string[i] != B) {
			A.string[i] = '0';
		}
	}
}

int main() {
	int command = -1;
	mystring Mystring = mystring();
	
	do {
		cout << "Please Enter command(1 : add, 2 : delete_char, 3 : delete_lastchar, 4 : and_operator, 5 : print, 6 : exit) : ";
		cin >> command;

		if (command == 1) {
			char input[100];
			cin >> input;
			
			Mystring += input;
		}
		else if (command == 2) {
			char input;
			cin >> input;

			Mystring -= input;
		}
		else if (command == 3) {
			Mystring--;
		}
		else if (command == 4) {
			char input;
			cin >> input;

			Mystring && input;
		}
		else if (command == 5) {
			cout << Mystring.string << "\n";
		}

	} while (command != 6);

	return 0;
}