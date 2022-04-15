#include<iostream>
#include<stdlib.h>

using namespace std;

int main() {
	srand(time(NULL));
	int* valuep = new int[10];
	int* Max = valuep;
	int* Min = valuep;
	for (int i = 0; i < 10; i++) {
		*(valuep + i) = rand()%10;
		cout << "Memory Address is " << valuep+i << "\n";
		cout << "Value is " << *(valuep+i) << "\n";
		if (*(valuep + i) > *Max) {
			Max = (valuep + i);
		}
		if (*(valuep + i) < *Min) {
			Min = (valuep + i);
		}
	}
	cout << "Max data is " << *Max << "(" << Max << ")\n";
	cout << "Min data is " << *Min << "(" << Min << ")\n";

	delete[] valuep;

	return 0;
}