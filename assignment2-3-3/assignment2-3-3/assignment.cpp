#include <iostream>
#pragma warning(disable : 4996)

using namespace std;
class Student_info {
private:
	char name[10];
	int age = 0;
	char university[100];
	char major[100];
public:
	Student_info(char* name, int age, char* univ, char* major) {	//������. �Ķ���ͷ� ���� ���� �ش� Ŭ������ ��� ������ ��������.
		strcpy(this->name, name);
		this->age = age;
		strcpy(this->university, univ);
		strcpy(this->major, major);
	}
	bool find(char* name) {
		if (!strcmp(this->name, name)) {	//�Ķ���ͷ� ���� name�� �ش� Ŭ������ ������� name�� ��
			return 1;	//������ true ��ȯ
		}
		return 0;	//�ٸ��� false ��ȯ
	};
	void print() {	//�ش� Ŭ���� ���� ������� ���� ���
		cout << "Name : " << name << "\n";
		cout << "Age : " << age << "\n";
		cout << "University : " << university << "\n";
		cout << "Major : " << major << "\n";
		cout << "------------------------\n";
	};
	void change(char* name, int age, char* univ, char* major) {	//set�Լ�. �Ķ���ͷ� ���� ���� �ش� Ŭ������ ��� ������ ��������.
		strcpy(this->name, name);
		this->age = age;
		strcpy(this->university, univ);
		strcpy(this->major, major);	
	}
	~Student_info() { ; }	//�Ҹ���.
};

int main() {
	class Student_info** students = new class Student_info*[10];	//���� Ŭ���� ������ �����Ҵ�(Ŭ���� ������ �迭 ����)
	int cnt = 0;	//�л����� ī��Ʈ�ϱ� ���� ���� �ʱ�ȭ

	while (1) {
		char* command = new char[100];
		cout << "Please Enter Command(insert, find, change, print, exit) :";
		cin >> command;

		if (!strcmp(command, "insert")) {	//insert�� �ԷµǾ��� ���
			char* input_name = new char[10];
			int input_age = 0;
			char* input_university = new char[100];
			char* input_major = new char[100];	//�Է°� �����Ҵ�
			cin >> input_name >> input_age >> input_university >> input_major;
			//2,3,4��° �Է����� name,age,univ,major ���� ������.

			students[cnt] = new class Student_info(input_name, input_age, input_university, input_major);	//�Է¹��� ���� �Ķ���ͷ� �Ͽ� Ŭ���� ������ �迭�� ������ ���ҿ� ���ο� Ŭ���� ����
			cnt++;	//�л��� ���� 1 ����
			delete[] input_name, input_university, input_major;	//�Է°� �Ҵ�����
		}
		else if (!strcmp(command, "find")) {	//find�� �ԷµǾ��� ���
			char* input_name = new char[10];	//�Է°� �����Ҵ�
			cin >> input_name;	//2��° �Է����� name ���� ������
			for (int i = 0; i < cnt; i++) {	//��� �ο��� ���Ͽ� ��ȸ
				if (students[i]->find(input_name)) {	//�ش� �ε����� Ŭ���� �� ������� name�� �Է°��� �����ϴٸ�
					cout << "----------find---------\n";
					students[i]->print();	//print �Լ� ȣ��
				}
			}
			delete[] input_name;	//�Է°� �Ҵ�����
		}
		else if (!strcmp(command, "change")) {	//change�� �ԷµǾ��� ���
			char* input_name1 = new char[10];
			char* input_name2 = new char[10];
			int input_age = 0;
			char* input_university = new char[100];
			char* input_major = new char[100];	//�Է°� �����Ҵ�
			cin >> input_name1 >> input_name2 >> input_age >> input_university >> input_major;
			//2,3,4,5 ��° �Է����� name1, name2, age, univ, major ���� ������.
			int target_idx = -1;	//��ǥ �ε����� -1�� �ʱ�ȭ
			for (int i = 0; i < cnt; i++) {
				if (students[i]->find(input_name1)) {	//�ش� �ε����� Ŭ���� �� ������� name�� �Է°� name1�� �����ϴٸ�,
					target_idx = i;	//�ش� �ε����� target index�� �����ϰ�,
					break;	//�ݺ��� ����
				}
			}
			if (target_idx != -1) {	//��ǥ �ε����� -1�� �ƴ϶��(name1�� ���� �̸��� ã���� ���)
				students[target_idx]->change(input_name2, input_age, input_university, input_major);	//��ǥ �ε����� ��ġ�� Ŭ������ ������ �Է°����� ��������.
			}
			delete[] input_name1, input_name2, input_university, input_major;	//�Ҵ� ����
		}
		else if (!strcmp(command, "print")) {	//print�� �ԷµǾ��� ���
			cout << "----------print---------\n";
			for (int i = 0; i < cnt; i++) {
				students[i]->print();	//Ŭ���� �� ����Լ� print ȣ��
			}
		}
		else if (!strcmp(command, "exit")) {	//exit�� �ԷµǾ��� ���
			delete[] command;	//��ɹ� �Ҵ�����
			break;	//�ݺ��� Ż��
		}
	}

	for (int i = 0; i < cnt; i++) {
		delete students[i];
	}
	delete[] students;	//�����Ҵ� ����
	return 0;
}