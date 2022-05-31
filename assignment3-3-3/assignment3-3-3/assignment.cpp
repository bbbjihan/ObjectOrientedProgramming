#include <iostream>
#include <fstream>
#include <windows.h>
#include <math.h>
#pragma warning(disable : 4996)
using namespace std;

class Node {
public:
	char cuisine[20];
	Node* next;
	Node* prev;
	Node() { 
		strcpy(this->cuisine, "\0");
		this->next = NULL;
		this->prev = NULL;
	}
	Node(char* cuisine) {
		strcpy(this->cuisine, cuisine);
		this->next = NULL;
		this->prev = NULL;
	}
	~Node() { ; }
};

class Queue {
public:
	Node* front;
	Node* rear;
	Queue() {
		this->front = NULL;
		this->rear = NULL;
	}
	~Queue() { ; }
	void push(char* order) {
		Node* node = new Node(order);
		if (this->front == NULL) {
			this->front = node;
			this->rear = node;
			return;
		}
		node->prev = this->rear;
		this->rear->next = node;
		this->rear = node;
		return;
	}
	Node* pop() {
		if (this->front == NULL) return NULL;
		Node* tmp = this->front;
		if (tmp != this->rear) {
			this->front = tmp->next;
			this->front->prev = NULL;
		}
		else {
			this->front = NULL;
		}
		return tmp;
	}
	bool isEmpty() {
		if (this->front == NULL) return true;
		return false;
	}
};

class recipe {
public:
	char cuisine[20];
	int time;
	recipe() {
		strcpy(this->cuisine, "\0");
		this->time = 0;
	}
	recipe(char* cuisine, int time) {
		strcpy(this->cuisine, cuisine);
		this->time = time;
	}
};

void print_cooking(char* cuisine, int remain, int need) {
	int len = strlen(cuisine);
	len += (int)log10(remain);
	len += (int)log10(need);
	len += 12;
	int space = 20 - (len / 2);
	if (len % 2 == 0) {
		for (int i = 0; i < space; i++) cout << " ";
		cout << "Cooking(" << cuisine << remain << "/" << need << ")";
		for (int i = 0; i < space; i++) cout << " ";
	}
	else {
		for (int i = 0; i < space; i++) cout << " ";
		cout << "Cooking(" << cuisine << remain << "/" << need << ")";
		for (int i = 1; i < space; i++) cout << " ";
	}
}

void print_done(char* cuisine) {
	int len = strlen(cuisine) + 7;
	int space = 20 - (len / 2);
	if (len % 2 == 0) {
		for (int i = 0; i < space; i++) cout << " ";
		cout << "Done!(" << cuisine << ")";
		for (int i = 0; i < space; i++) cout << " ";
	}
	else {
		for (int i = 0; i < space; i++) cout << " ";
		cout << "Done!(" << cuisine << ")";
		for (int i = 1; i < space; i++) cout << " ";
	}

}

int main() {
	system(" mode  con lines=50   cols=120 ");
	char chef[10];
	char cuisine[20];
	int time;
	class recipe** Jack = new recipe*[100];
	int jackCnt = 0;
	class recipe** Bob = new recipe*[100];
	int bobCnt = 0;
	class recipe** John = new recipe*[100];
	int johnCnt = 0;
	ifstream in1("Assignment3-3-3-1.txt");
	if (in1.is_open()) {
		while (!in1.eof()) {
			in1 >> chef >> cuisine >> time;
			recipe* tmp = new recipe(cuisine, time);
			if (!strcmp(chef, "Jack")) {
				Jack[jackCnt] = tmp;
				jackCnt++;
			}
			else if (!strcmp(chef, "Bob")) {
				Bob[bobCnt] = tmp;
				bobCnt++;
			}
			else if (!strcmp(chef, "John")) {
				John[johnCnt] = tmp;
				johnCnt++;
			}
		}
	}
	else {
		cout << "Assignment3-3-3-1.txt cannot open." << endl;
		return 0;
	}
	in1.close();
	class Queue jackQueue = Queue();
	class Queue bobQueue = Queue();
	class Queue johnQueue = Queue();
	char order[100];
	ifstream in2("Assignment3-3-3-2.txt");
	if (in2.is_open()) {
		while (!in2.eof()) {
			in2 >> order;
			char cooker[10];
			int ordered = 0;
			while (!ordered) {
				cout << "New order : " << order << "\nPick Cooker : ";
				cin >> cooker;
				if (!strcmp(cooker, "Jack")) {
					for (int i = 0; i < jackCnt; i++) {
						if (!strcmp(Jack[i]->cuisine, order)) {
							jackQueue.push(order);
							ordered = 1;
							break;
						}
					}
				}
				else if (!strcmp(cooker, "Bob")) {
					for (int i = 0; i < bobCnt; i++) {
						if (!strcmp(Bob[i]->cuisine, order)) {
							bobQueue.push(order);
							ordered = 1;
							break;
						}
					}
				}
				else if (!strcmp(cooker, "John")) {
					for (int i = 0; i < johnCnt; i++) {
						if (!strcmp(John[i]->cuisine, order)) {
							johnQueue.push(order);
							ordered = 1;
							break;
						}
					}
				}
			}
		}
	}
	else {
		cout << "Assignment3-3-3-2.txt cannot open." << endl;
		return 0;
	}
	in2.close();

	class Node* cooking[3] = { NULL, };
	int timeRemain[3] = { 0, };
	int timeNeed[3] = { 0, };
	int totalTime = 0;

	cout << "                  Jack                  ";
	cout << "                  John                  ";
	cout << "                   Bob                  ";
	while (!jackQueue.isEmpty() || !bobQueue.isEmpty() || !johnQueue.isEmpty() || timeRemain[0] != -1 || timeRemain[1] != -1 || timeRemain[2] != -1 ) {
		if (timeRemain[0] == 0 && !jackQueue.isEmpty()) {
			delete cooking[0];
			cooking[0] = jackQueue.pop();
			for (int i = 0; i < jackCnt; i++) {
				if (!strcmp(Jack[i]->cuisine, cooking[0]->cuisine)) {
					timeRemain[0] = Jack[i]->time;
					timeNeed[0] = timeRemain[0];
					break;
				}
			}
		}
		if (timeRemain[2] == 0 && !bobQueue.isEmpty()) {
			delete cooking[2];
			cooking[2] = bobQueue.pop();
			for (int i = 0; i < bobCnt; i++) {
				if (!strcmp(Bob[i]->cuisine, cooking[2]->cuisine)) {
					timeRemain[2] = Bob[i]->time;
					timeNeed[2] = timeRemain[2];
					break;
				}
			}
		}
		if (timeRemain[1] == 0 && !johnQueue.isEmpty()) {
			delete cooking[1];
			cooking[1] = johnQueue.pop();
			for (int i = 0; i < johnCnt; i++) {
				if (!strcmp(John[i]->cuisine, cooking[1]->cuisine)) {
					timeRemain[1] = John[i]->time;
					timeNeed[1] = timeRemain[1];
					break;
				}
			}
		}
		if(timeRemain[0]>-1) timeRemain[0]--;
		if(timeRemain[1]>-1) timeRemain[1]--;
		if(timeRemain[2]>-1) timeRemain[2]--;
		for (int j = 0; j < 3; j++) {
			if (timeRemain[j] > 0) {
				print_cooking(cooking[j]->cuisine, timeRemain[j], timeNeed[j]);
			}
			else if (timeRemain[j] == 0) {
				print_done(cooking[j]->cuisine);
			}
			else {
				for (int i = 0; i < 40; i++)cout << " ";
			}
		}
		totalTime++;
	}
	cout << "Total Time is :" << totalTime - 1;

	for (int i = 0; i < 3; i++)delete cooking[i];
	for (int i = 0; i < jackCnt; i++) delete Jack[i];
	for (int i = 0; i < bobCnt; i++) delete Bob[i];
	for (int i = 0; i < johnCnt; i++) delete John[i];
	return 0;
}