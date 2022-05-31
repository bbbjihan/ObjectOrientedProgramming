#include <iostream>
#pragma warning(disable:4996)
using namespace std;

class ���� {
private:
	char U_Name[20];
	int year;
	char U_StuID[20];
public:
	����(char* U_Name, int year, char* U_StuID) {	//���� Ŭ���� ������
		strcpy(this->U_Name, U_Name);
		this->year = year;
		strcpy(this->U_StuID, U_StuID);
	}
	~����() { ; }	//���� Ŭ���� �Ҹ���
	char* get_U_StuID() {	//���� Ŭ���� ��������� �����̸� ��ȯ�Լ�
		return this->U_StuID;
	}
	char* get_U_Name() {	//���� Ŭ���� ��������� �л��̸� ��ȯ�Լ�
		return this->U_Name;
	}
	int get_year() {	//���� Ŭ���� ��������� �г� ��ȯ�Լ�
		return this->year;
	}
};

class ��ǻ���������� : public ���� {	//���� Ŭ������ ��ӹ޴� ��ǻ���������� Ŭ���� ����
private:
	char Object_Oriented_Programing;
	char Digital_Logic_Circuit;
public:
	��ǻ����������(char* U_Name, int year, char* U_StuID, char OOP, char DLC) : ����(U_Name	, year, U_StuID) {
		this->Object_Oriented_Programing = OOP;
		this->Digital_Logic_Circuit = DLC;
	}	//��ǻ���������� Ŭ���� ������(���� Ŭ������ ��������� �Բ� �ʱ�ȭ���ֱ� ���� ����Ŭ���� �����ڵ� �Բ� ȣ����)
	char get_OOP() {	//��ǻ���������� Ŭ���� ��������� OOP���� ��ȯ�Լ�
		return this->Object_Oriented_Programing;
	}
	char get_DLC() {	//��ǻ���������� Ŭ���� ��������� DLC���� ��ȯ�Լ�
		return this->Digital_Logic_Circuit;
	}
};

class �л����� : public ��ǻ���������� {	//��ǻ���������� Ŭ������ ��ӹ޴� �л����� Ŭ���� ����
private:
	char Name[10];
	int age;
public:
	�л�����() : ��ǻ����������(NULL, 0, NULL, NULL, NULL) {
		*this->Name = NULL;
		age = 0;
	}	//�л����� Ŭ���� ������
	�л�����(char* U_Name, int year, char* U_StuID, char OOP, char DLC, char* Name, int age) : ��ǻ����������(U_Name, year, U_StuID, OOP, DLC) {
		strcpy(this->Name, Name);
		this->age = age;
	}	//�л����� Ŭ���� ������ overloading(��ǻ���������� Ŭ������ ��������� �Բ� �ʱ�ȭ���ֱ� ���� ��ǻ���������� Ŭ���� �����ڵ� �Բ� ȣ����)
	char* get_Name() {	//�л����� Ŭ���� ��������� �л��̸� ��ȯ�Լ�
		return this->Name;
	}
};

int main() {
	class �л�����** students = new class �л�����*[100];	//�ִ� 100���� �л������� ������ �� �ִ� �л����� Ŭ���� �迭 ������ ���� ���� �� �����Ҵ�
	int cnt = 0;	//students �迭 ���� index�� ���� �л��� ���� ���� ���� �� �ʱ�ȭ
	while (1) {
		char command[100];
		cin >> command;
		if (!strcmp(command, "INSERT")) {	//�Է��� INSERT�� ���
			if (cnt == 100) {	//�л����� �̹� 100�� ���
				continue;	//��� ����
			}
			char U_Name[20];
			int year;
			char U_StuID[20];
			char OOP;
			char DLC;
			char Name[10];
			int age;

			cout << "�б� :";
			cin >> U_Name;	//�� ��° �Է����� �б� �̸� �Է¹���
			cout << "�й� :";
			cin >> U_StuID;	//�� ��° �Է����� �й� �Է¹���
			cout << "�г� :";
			cin >> year;	//�� ��° �Է����� �г� �Է¹���
			cout << "��ü�������α׷��� ���� :";
			cin >> OOP;	//�ټ� ��° �Է����� OOP���� �Է¹���
			cout << "�����г�ȸ�� ���� :";
			cin >> DLC;	//���� ��° �Է����� DLC���� �Է¹���
			cout << "�̸� :";
			cin >> Name;	//�ϰ� ��° �Է����� �̸� �Է¹���
			cout << "���� :";
			cin >> age;	//���� ��° �Է����� ���� �Է¹���
			students[cnt] = new class �л�����(U_Name, year, U_StuID, OOP, DLC, Name, age);
				//�Է¹��� ����� ���ο� �л����� Ŭ���� ���� �� students �迭�� ������ ���ҷ� �����Ҵ�
			cnt++;	//�л��� ����
		}
		else if (!strcmp(command, "FIND")) {	//�Է��� FIND�� ���
			char Name[10];
			char U_StuID[20];
			cin >> Name >> U_StuID;	//�� ��° �Է����� �̸�, �� ��° �Է����� �й� �Է¹���
			for (int i = 0; i < cnt; i++) {	//students�� ����� ��� �л����� Ŭ������ ��ȸ
				if (!strcmp((*students[i]).get_Name(), Name) && !strcmp((*students[i]).get_U_StuID(), U_StuID)) {	//�Էµ� �̸��� �й��� ��ġ�ϴ� �л������� �߰��� ���
					cout << "�б�:" << (*students[i]).get_U_Name() << "\n";
					cout << "�й�:" << (*students[i]).get_U_StuID() << "\n";
					cout << "�г�:" << (*students[i]).get_year() << "\n";
					cout << "��ü�������α׷��� ����:" << (*students[i]).get_OOP() << "\n";
					cout << "�����г�ȸ�� ����:" << (*students[i]).get_DLC() << "\n";
					break;	//�л����� ��� �� �ݺ��� ����
				}
			}
		}
		else if (!strcmp(command, "EXIT")) {	//�Է��� EXIT�� ���
			break;	//�ݺ��� ����
		}
	}
	for (int i = 0; i < cnt; i++) {	//students �� ����� �л����� Ŭ�������� �����Ҵ� ����
		delete students[i];
	}
	delete[] students;	//students �迭 �����Ҵ� ����
	return 0;
}