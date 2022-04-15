#include <iostream>
#pragma warning(disable : 4996)
using namespace std;

class animal {
private:
	char name[10];
	int year = 0;
	char species[100];
public:
	animal() { ; }
	~animal() { ; }
	void set_animal(char* name, int year, char* species) {
		strcpy(this->name, name);
		this->year = year;
		strcpy(this->species,species);
	}
	void print() {
		cout << "Name :" << name << "\n";
		cout << "Year :" << year << "\n";
		cout << "Species :" << species << "\n";
	}
};

class zoo {
private:
	class animal* animal_list[100];
	int size = 0;
public:
	zoo() { ; }
	~zoo() { ; }
	void new_animal(char* name, int year, char* species) {
		animal_list[size]->set_animal(name, year, species);
		size++;
	}
	void print_all() {
		cout << "------print_all------\n";
		for (int i = 0; i < size; i++) {
			cout << "----------" << i << "---------\n";
			animal_list[i]->print();
			cout << "---------------------\n";
		}
		cout << "---------------------\n";
	}
};

int main() {
	class zoo* zoo = new class zoo();

	while (1) {
		char* command = new char[100];
		cout << "Please Enter Any Command(new_animal, print_all,print_species,exit) :";
		cin >> command;

		if (!strcmp(command, "new_animal")) {
			char* name = new char[10];
			int year = 0;
			char* species = new char[100];
			cin >> name >> year >> species;
			zoo->new_animal(name, year, species);
			delete[] name, species;
		}
		else if (!strcmp(command, "print_all")) {
			zoo->print_all();
		}
		else if (!strcmp(command, "print_species")) {
			char* species = new char[100];

			delete[] species;
		}
		else if (!strcmp(command, "exit")) {
			delete[] command;
			break;
		}
	}

	delete zoo;
	return 0;
}