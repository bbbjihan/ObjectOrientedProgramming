#include <iostream>
#pragma warning(disable : 4996)
using namespace std;

class Student {
private:
	char name[20];
	int Score;
public:
	Student() { ; }	//Student class ������
	Student(char *name, int score) {	//Student class ������ overloading
		strcpy(this->name,name);
		this->Score = score;
	}
	~Student() { ; }	//Student class �Ҹ���
	char* get_name() {	//Student class�� name�� return�Լ�
		return this->name;
	}
	int get_score() {	//Student class�� Score�� return�Լ�
		return this->Score;
	}
};

int main() {
	class Student** students = new Student*[50];	//Student class�� ��Ƶ� �迭 �Ҵ�
	int cnt = 0;

	while (1) {	//�����ǹݺ�
		int input;
		cout << "Please Enter Command(1:insert,2:sort by name,3:sort by score,4:quit) : ";
		cin >> input;	//�Է¹ޱ�
		if (input == 1) {	//1�� �Էµ� ���
			char *input_name = new char[10];
			int input_score;

			cout << "Name : ";
			cin >> input_name;	//�� ��° �Է����� �̸� ���ڿ� ����
			cout << "Score : ";
			cin >> input_score;	//�� ��° �Է����� int ���� ����

			students[cnt] = new class Student(input_name, input_score);	//students�� ������ index�� �Է¹��� ������ student class ����
			cnt++;
			delete[] input_name;	//�����Ҵ� ����
		}
		else if (input == 2) {	//2�� �Էµ� ���
			class Student* tmp;	//������ ���� temp student class ����
			for (int i = cnt - 1; i > 0; i--) {
				for (int j = 0; j < i; j++) {
					if (strcmp(students[j]->get_name(), students[j + 1]->get_name()) > 0) {
						tmp = students[j];
						students[j] = students[j + 1];
						students[j + 1] = tmp;
					}
				}	//�̸��� ASCII ���� �������� �Ͽ� ��������
			}
			for (int i = 0; i < cnt; i++) {
				cout << students[i]->get_name() << " " << students[i]->get_score() << "\n";
			}	//���ĵ� students �迭�� ���ҵ��� ���
		}
		else if (input == 3) {	//3�� �Էµ� ���
			class Student* tmp;	//������ ���� temp student class ����
			for (int i = cnt - 1; i > 0; i--) {
				for (int j = 0; j < i; j++) {
					if (students[j]->get_score() > students[j+1]->get_score()) {
						tmp = students[j];
						students[j] = students[j + 1];
						students[j + 1] = tmp;
					}
				}	//���� ���� �������� �Ͽ� ��������
			}
			for (int i = 0; i < cnt; i++) {
				cout << students[i]->get_name() << " " << students[i]->get_score() << "\n";
			}	//���ĵ� students �迭�� ���ҵ��� ���
		}
		else if (input == 4) {	//4�� �Էµ� ���
			break;
		}
	}
	delete[] students;
	return 0;
}