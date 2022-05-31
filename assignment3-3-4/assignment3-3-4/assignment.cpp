#include <iostream>
#include <fstream>
#include <windows.h>
#pragma warning(disable : 4996)
using namespace std;

class Student {	//Node of BST
public:
	char name[20];
	Student* left;
	Student* right;
	Student() { strcpy(this->name, "\0"); this->left = NULL; this->right = NULL; }
	Student(char* name) { strcpy(this->name, name); this->left = NULL; this->right = NULL; }
	~Student() { ; }
};

class Year {	//BST and Node of Linked List
public:
	int year;
	Student* root;
	Year* next;
	Year() { this->year = 0; this->root = NULL; this->next = NULL; }
	Year(int year) { this->year = year; this->root = NULL; this->next = NULL; }
	~Year() { delete_preorder(this->root); }

	void delete_preorder(Student* now) {
		if (now != NULL) {
			Student* left = now->left;
			Student* right = now->right;
			delete now;
			delete_preorder(left);
			delete_preorder(right);
		}
	}

	bool insert(char* name) {
		class Student* newNode = new Student(name);
		if (this->root == NULL) {
			this->root = newNode;
			return 1;
		}
		Student* now = this->root;
		while (1) {
			if (strcmp(now->name, name) > 0) {
				if (now->left != NULL) {
					now = now->left;
				}
				else {
					now->left = newNode;
					return 1;
				}
			}
			else if (strcmp(now->name, name) < 0) {
				if (now->right != NULL) {
					now = now->right;
				}
				else {
					now->right = newNode;
					return 1;
				}
			}
			else {
				delete newNode;
				return 0;
			}
		}
	}

	bool Delete(char* name) {
		Student* parent = NULL;
		Student* now = this->root;
		while (1) {
			if (strcmp(now->name, name) > 0) {
				if (now->left == NULL) return 0;
				parent = now;
				now = now->left;
			}
			else if (strcmp(now->name, name) < 0) {
				if (now->right == NULL) return 0;
				parent = now;
				now = now->right;
			}
			else {
				cout << "Delete_Name : " << now->name << "\n";
				if (now->left == NULL && now->right == NULL) {
					if (parent == NULL) this->root = NULL;
					else if (strcmp(parent->name, now->name) > 0)parent->left = NULL;
					else parent->right = NULL;
					delete now;
				}
				else if (now->left == NULL) {
					if (parent == NULL) this->root = now->right;
					else if (strcmp(parent->name, now->name) > 0)parent->left = now->right;
					else parent->right = now->right;
					delete now;
				}
				else if (now->right == NULL) {
					if (parent == NULL) this->root = now->left;
					else if (strcmp(parent->name, now->name) > 0)parent->left = now->left;
					else parent->right = now->left;
					delete now;
				}
				else {
					Student* parent_target = now;
					Student* target = now->right;
					for (; target->left != NULL; target = target->left) parent_target = target;
					strcpy(now->name, target->name);
					if (target->right == NULL) {
						if (parent_target == now) {
							now->right = NULL;
						}
						else {
							parent_target->left = NULL;
						}
					}
					else {
						if (parent_target == now) {
							now->right = target->right;
						}
						else {
							parent_target->left = target->right;
						}
					}
					delete target;
				}
				return 1;
			}
		}
		return 0;
	}

	void print_preorder(Student* now, char* subject, int year) {
		if (now != NULL) {
			cout << subject << " " << year << " " << now->name << "\n";
			print_preorder(now->left, subject, year);
			print_preorder(now->right, subject, year);
		}
	}
};

class Subject {	//Linked List and Node of Linked List
public:
	char name[50];
	Year* head;
	Subject* next;
	Subject() { strcpy(this->name, "\0"); this->head = NULL; this->next = NULL; }
	Subject(char* name) { strcpy(this->name, name); this->head = NULL; this->next = NULL; }
	~Subject() { 
		Year* prev = NULL;
		Year* now = this->head;
		for (; now != NULL; now = now->next) {
			delete prev;
			prev = now;
		}
		delete prev;
	}
	bool insert(int year, char* name) {
		class Year* newYear = new Year(year);
		if (this->head == NULL) {
			this->head = newYear;
			newYear->insert(name);
			return 1;
		}
		Year* prev = NULL;
		Year* now = this->head;
		while (now != NULL) {
			if (now->year > year) {
				if (prev == NULL) {
					newYear->next = this->head;
					this->head = newYear;
					newYear->insert(name);
					return 1;
				}
				prev->next = newYear;
				newYear->next = now;
				newYear->insert(name);
				return 1;
			}
			else if (now->year == year) {
				delete newYear;
				if (now->insert(name)) return 1;
				else return 0;
			}
			prev = now;
			now = now->next;
		}
		prev->next = newYear;
		newYear->insert(name);
		return 1;
	}

	bool Delete(int year, char* name) {
		Year* prev = NULL;
		for (Year* now = this->head; now != NULL; now = now->next) {
			if (now->year == year) {
				if (now->Delete(name)) {
					if (now->root == NULL) {
						cout << "Delete_Year : " << now->year << "\n";
						if (prev == NULL)this->head = now->next;
						else prev->next = now->next;
						delete now;
						return 1;
					}
				}
				else return 0;
			}
			prev = now;
		}
		return 0;
	}

	void print(char* subject) {
		for (Year* now = this->head; now != NULL; now = now->next) {
			now->print_preorder(now->root, subject, now->year);
		}
	}
};

class List {	//Linked List
public:
	Subject* head;
	List() { this->head = NULL; }
	~List() {
		Subject* prev = NULL;
		Subject* now = this->head;
		for (; now != NULL; now = now->next) {
			delete prev;
			prev = now;
		}
		delete prev;
	}
	bool insert(char* subject, int year, char* name) {
		class Subject* newSubject = new Subject(subject);
		if (this->head == NULL) {
			this->head = newSubject;
			newSubject->insert(year, name);
			return 1;
		}
		Subject* prev = NULL;
		Subject* now = this->head;
		while (now != NULL) {
			if (strcmp(now->name, subject) > 0) {
				if (prev == NULL) {
					newSubject->next = this->head;
					this->head = newSubject;
					newSubject->insert(year, name);
					return 1;
				}
				prev->next = newSubject;
				newSubject->next = now;
				newSubject->insert(year, name);
				return 1;
			}
			else if (!strcmp(now->name, subject)) {
				delete newSubject;
				if (now->insert(year, name))return 1;
				else return 0;
			}
			prev = now;
			now = now->next;
		}
		prev->next = newSubject;
		newSubject->insert(year, name);
		return 1;
	}

	void Delete(char* subject, int year, char* name) {
		Subject* prev = NULL;
		for (Subject* now = this->head; now != NULL; now = now->next) {
			if (!strcmp(now->name, subject)) {
				if (now->Delete(year, name)) {
					if (now->head == NULL) {
						cout << "Delete_Major : " << now->name << "\n";
						if (prev == NULL) this->head = now->next;
						else prev->next = now->next;
						delete now;
					}
					return;
				}
			}
			prev = now;
		}
	}

	void print_all() {
		for (Subject* now = this->head; now != NULL; now = now->next) {
			now->print(now->name);
		}
	}

	void print_path(char* subject, int year, char* name) {
		char buff[1024];
		memset(buff, '\0', sizeof(buff));
		for (Subject* now = this->head; now != NULL; now = now->next) {
			strcat(buff, now->name);
			strcat(buff, "->");
			if (!strcmp(now->name, subject)) {
				for (Year* now_year = now->head; now_year != NULL; now_year = now_year->next) {
					char tmp[10];
					sprintf(tmp, "%d", now_year->year);
					strcat(buff, tmp);
					strcat(buff, "->");
					if (now_year->year == year) {
						Student* now_student = now_year->root;
						int finded = 0;
						while (1) {
							if (strcmp(now_student->name, name) > 0) {
								if (now_student->left == NULL) return;
								strcat(buff, now_student->name);
								strcat(buff, "->");
								now_student = now_student->left;
							}
							else if (strcmp(now_student->name, name) < 0) {
								if (now_student->right == NULL) return;
								strcat(buff, now_student->name);
								strcat(buff, "->");
								now_student = now_student->right;
							}
							else {
								strcat(buff, now_student->name);
								cout << buff << "\n";
								return;
							}
						}
					}
				}
				break;
			}
		}
	}
};

int main() {
	class List list = List();
	char subject[50];
	int year;
	char name[20];
	ifstream in1("Assignment3-3-4.txt");
	if (in1.is_open()) {
		while (!in1.eof()) {
			in1 >> subject >> year >> name;
			list.insert(subject, year, name);
		}
	}
	else {
		cout << "Assignment3-3-4.txt cannot open." << "\n";
		return 0;
	}
	in1.close();

	int command = -1;

	do {
		cout << "Enter Any Command(1:Insert, 2:Delete, 3:Print_all, 4:Print_major, 5:Print_id, 6:Print_Name, 7:Exit): ";
		cin >> command;
		if (command == 1) {
			char in_subject[50];
			int in_year;
			char in_name[20];
			cin >> in_subject >> in_year >> in_name;
			if (list.insert(in_subject, in_year, in_name)) {
				list.print_path(in_subject, in_year, in_name);
			}
			else {
				cout << "Already Exists.\n";
			}
		}
		else if (command == 2) {
			char in_subject[50];
			int in_year;
			char in_name[20];
			cin >> in_subject >> in_year >> in_name;
			list.Delete(in_subject, in_year, in_name);
		}
		else if (command == 3) {
			list.print_all();
		}
		else if (command == 4) {
			char in_subject[50];
			cin >> in_subject;
			Subject* now = list.head;
			for (; now != NULL; now = now->next) {
				if (!strcmp(now->name, in_subject)) {
					now->print(now->name);
					break;
				}
			}
		}
		else if (command == 5) {
			int in_year;
			cin >> in_year;
			Subject* now = list.head;
			for (; now != NULL; now = now->next) {
				Year* now_year = now->head;
				for (; now_year != NULL; now_year = now_year->next) {
					if (now_year->year == in_year) {
						now_year->print_preorder(now_year->root, now->name, now_year->year);
						break;
					}
				}
			}
		}
		else if (command == 6) {
			char in_subject[50];
			int in_year;
			char in_name[20];
			cin >> in_subject >> in_year >> in_name;
			list.print_path(in_subject, in_year, in_name);
		}
	} while (command != 7);

	return 0;
}