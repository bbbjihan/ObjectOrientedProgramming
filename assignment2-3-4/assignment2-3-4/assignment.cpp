#include <iostream>
#pragma warning(disable : 4996)
using namespace std;

class animal {
private:
	char name[10];
	int year = 0;
	char species[100];
public:
	animal() { ; }	//������
	~animal() { ; }	//�Ҹ���
	void set_animal(char* name, int year, char* species) {	//��������� set�ϴ� set�Լ�
		strcpy(this->name, name);
		this->year = year;
		strcpy(this->species,species);
	}
	void print() {	//��������� ����Լ�
		cout << "Name :" << name << "\n";
		cout << "Year :" << year << "\n";
		cout << "Species :" << species << "\n";
	}
	char* get_species() {	//������� species�� ��ȯ�ϴ� get�Լ�
		return species;
	}
};

class zoo {
private:
	class animal* animal_list[100];	//animal Ŭ���� ������ �迭 �������
	int size = 0;	//animal_list�� �ʱ�ȭ�� Ŭ���� ������ ī��Ʈ�ϱ� ���� ����
public:
	zoo() { ; }	//������
	~zoo() { ; }	//�Ҹ���
	void new_animal(char* name, int year, char* species) {	//animal_list�� ���ο� Ŭ������ �����ϴ� �Լ�
		animal_list[size] = new animal();	//animal_list�� size index ���ҿ� ���ο� animal Ŭ���� ����
		animal_list[size]->set_animal(name,year,species);	//����� animal Ŭ������ ��������� �Ķ���� ���� ���� �ʱ�ȭ
		size++;	//size�� ����
	}
	void print_all() {	//animal_list�� ��� ���ҵ��� ������ ����ϴ� �Լ�
		cout << "------print_all------\n";
		for (int i = 0; i < size; i++) {	//size�� ���� ��� �ε����� ��ȸ
			cout << "----------" << i << "---------\n";
			animal_list[i]->print();	//animal_list�� i��° ������ Ŭ���� �� ����Լ� print ȣ��
			cout << "---------------------\n";
		}
		cout << "---------------------\n";
	}
	void print_species(char* species){	//animal_list�� ���� �� �Ķ���ͷ� �Էµ� species�� species�� ��ġ�ϴ� Ŭ������ �����鸸 ����ϴ� �Լ�
		int cnt = 0;	//���� ���� ������ ����� ���� ī����
		cout << "------print_species------\n";
		for (int i = 0; i < size; i++) {	//size�� ���� ��� �ε����� ��ȸ
			if (!strcmp(animal_list[i]->get_species(), species)) {	//animal_list�� i��° ������ Ŭ������ ������� species���� get_species�� ���� ��ȯ�ް�, �̸� �Ķ���ͷ� ���� species ���ڿ��� ���Ͽ� ���� ���,
				cout << "----------" << i << "---------\n";
				animal_list[i]->print();	//�ش� animal Ŭ���� �� ����Լ� print ȣ��
				cout << "---------------------\n";
				cnt++;	//ī���� 1 ����
			}
		}
		cout << "Number of Species is :" << cnt;	//ī���Ͱ� ���
		cout << "\n---------------------\n";
	}
};

int main() {
	class zoo* Zoo = new class zoo();	//zoo Ŭ���������� Zoo �����Ҵ�, ���� �� �ʱ�ȭ

	while (1) {	//�����ǹݺ�
		char* command = new char[100];	//��ɹ� �����Ҵ�
		cout << "Please Enter Any Command(new_animal, print_all,print_species,exit) :";
		cin >> command;	//��ɹ� �Է¹���

		if (!strcmp(command, "new_animal")) {	//new_animal�� �Էµ� ���
			char* name = new char[10];
			int year = 0;
			char* species = new char[100];	//�Է°� ������ ���� �޸� �����Ҵ�
			cin >> name >> year >> species;	//2,3,4��° �Է����� name,year,species���� ������.
			Zoo->new_animal(name, year, species);	//�Է°��� �Ķ���ͷ� �Ͽ� Zoo Ŭ���� �� ����Լ� new_animal ȣ��
			delete[] name, species;	//�Է°� �Ҵ�����
		}
		else if (!strcmp(command, "print_all")) {	//print_all�� �Էµ� ���
			Zoo->print_all();	//Zoo Ŭ���� �� ����Լ� print_all ȣ��
		}
		else if (!strcmp(command, "print_species")) {	//print_species�� �Էµ� ���
			char* species = new char[100];	//�Է°� ������ ���� �޸� �����Ҵ�
			cin >> species;	//2��° �Է����� species ���� ������.
			Zoo->print_species(species);	//�Է°��� �Ķ���ͷ� Zoo Ŭ���� �� ����Լ� print_species ȣ��
			delete[] species;	//�Է°� �Ҵ�����
		}
		else if (!strcmp(command, "exit")) {	//exit�� �Էµ� ���
			delete[] command;	//��ɹ� �Ҵ�����
			break;	//�ݺ��� ����
		}
	}

	delete Zoo;	//Ŭ���� �Ҵ�����
	return 0;
}