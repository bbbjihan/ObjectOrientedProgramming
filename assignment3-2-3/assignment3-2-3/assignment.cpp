#include <iostream>
using namespace std;

class item {
private:
	int price;
	int stock;
	int discount;
public:
	item(int price, int stock) { this->price = price; this->stock = stock; discount = 0; }
	int getprice() { return price; }
	int getstock() { return stock; }
	int getdiscount() { return discount; }
	void addstock(int num) { this->stock += num; }
	void sell_item(int num) { this->stock -= num; }
	void setdiscount(int num) { this->discount = num; }
};

class Pen :public item{	//item ��ü�� ��ӹ޴� Pen ��ü ����
public:
	Pen(int price, int stock) : item(price, stock) { ; }	//Pen ��ü ������
	~Pen() { ; }	//Pen ��ü �Ҹ���
};
class Pencil :public item {	//item ��ü�� ��ӹ޴� Pencil ��ü ����
public:
	Pencil(int price, int stock) : item(price, stock) { ; }	//Pencil ��ü ������
	~Pencil() { ; }	//Pencil ��ü �Ҹ���
};
class Eraser :public item {	//item ��ü�� ��ӹ޴� Eraser ��ü ����
public:
	Eraser(int price, int stock) : item(price, stock) { ; }	//Eraser ��ü ������
	~Eraser() { ; }	//Eraser ��ü �Ҹ���
};

int main() {
	class Pen pen = Pen(600, 100);
	class Pencil pencil = Pencil(1200, 100);
	class Eraser eraser = Eraser(500, 100);	//������ Ŭ������ ���� ������ ���ݰ� �������� ����
	int command = -1;
	int sales = 0;
	do {
		cout << "Enter Any Command(0 : Sell, 1 : AddStock, 2 : Discount, 3 : Print, 4 : Quit) :";
		cin >> command;
		if (command == 0) {	//0�� �Էµ� ���
			char name[10];
			int stock;
			cin >> name >> stock;	//�� ��° �Է����� ��ǰ��, �� ��° �Է����� ������ �Է¹���
			if (!strcmp(name, "Pen")) {	//�� ��° �Է��� Pen�� ���
				if (pen.getstock() >= stock * 3) {	//Pen�� ��� �����Ϸ��� �纸�� ũ�ų� ���� ���
					pen.sell_item(stock * 3);	//item ��ü�� sell_item �Լ��� �����Ϸ��� ���� �Ķ���ͷ� �Ͽ� ȣ��
					sales += stock * (pen.getprice()) * (100-pen.getdiscount()) / (100);	//������ ��ǰ����*�ǸŴ���*����*��������ŭ ������
				}
			}
			else if (!strcmp(name, "Pencil")) {	//�� ��° �Է��� Pencil�� ���
				if (pencil.getstock() >= stock * 12) {	//Pencil�� ��� �����Ϸ��� �纸�� ũ�ų� ���� ���
					pencil.sell_item(stock * 12);	//item ��ü�� sell_item �Լ��� �����Ϸ��� ���� �Ķ���ͷ� �Ͽ� ȣ��
					sales += stock * (pencil.getprice()) * (100 - pencil.getdiscount()) / (100);	//������ ��ǰ����*�ǸŴ���*����*��������ŭ ������
				}
			}
			else if (!strcmp(name, "Eraser")) {	//�� ��° �Է��� Eraser�� ���
				if (eraser.getstock() >= stock) {	//Eraser�� ��� �����Ϸ��� �纸�� ũ�ų� ���� ���
					eraser.sell_item(stock);		//item ��ü�� sell_item �Լ��� �����Ϸ��� ���� �Ķ���ͷ� �Ͽ� ȣ��
					sales += stock * (eraser.getprice()) * (100 - eraser.getdiscount()) / (100);	//������ ��ǰ����*�ǸŴ���*����*��������ŭ ������
				}
			}
		}
		else if (command == 1) {	//1�� �Էµ� ���
			char name[10];
			int stock;
			cin >> name >> stock;	//�� ��° �Է����� ��ǰ��, �� ��° �Է����� ������ �Է¹���
			if (!strcmp(name, "Pen")) {	//�� ��° �Է��� Pen�� ���
				pen.addstock(stock);	//�Է°��� �Ķ���ͷ� �Ͽ� pen�� ��� ����������(item�� addstock�Լ� ȣ��)
			}
			else if (!strcmp(name, "Pencil")) {	//�� ��° �Է��� Pencil�� ���
				pencil.addstock(stock);	//�Է°��� �Ķ���ͷ� �Ͽ� pencil�� ��� ����������(item�� addstock�Լ� ȣ��)
			}
			else if (!strcmp(name, "Eraser")) {	//�� ��° �Է��� Eraser�� ���
				eraser.addstock(stock);	//�Է°��� �Ķ���ͷ� �Ͽ� eraser�� ��� ����������(item�� addstock�Լ� ȣ��)
			}
		}
		else if (command == 2) {	///2�� �Էµ� ���
			char name[10];
			int discount;
			cin >> name >> discount;	//�� ��° �Է����� ��ǰ��, �� ��° �Է����� �������� �Է¹���
			if (!strcmp(name, "Pen")) {	//�� ��° �Է��� Pen�� ���
				pen.setdiscount(discount);	//�Է°��� �Ķ���ͷ� �Ͽ� pen�� �������� ����������(item�� setdiscount�Լ� ȣ��)
			}
			else if (!strcmp(name, "Pencil")) {	//�� ��° �Է��� Pencil�� ���
				pencil.setdiscount(discount);	//�Է°��� �Ķ���ͷ� �Ͽ� pencil�� �������� ����������(item�� setdiscount�Լ� ȣ��)
			}
			else if (!strcmp(name, "Eraser")) {	//�� ��° �Է��� Eraser�� ���
				eraser.setdiscount(discount);	//�Է°��� �Ķ���ͷ� �Ͽ� eraser�� �������� ����������(item�� setdiscount�Լ� ȣ��)
			}
		}
		else if (command == 3) {	//�Է°��� 3�� ���
			cout << "---------------Pen--------------\n";
			cout << "Price : " << pen.getprice() << "\n";
			cout << "Stock : " << pen.getstock() << "\n";
			cout << "Discount : " << pen.getdiscount() << "%\n";
			cout << "--------------------------------\n";
			cout << "--------------Pencil------------\n";
			cout << "Price : " << pencil.getprice() << "\n";
			cout << "Stock : " << pencil.getstock() << "\n";
			cout << "Discount : " << pencil.getdiscount() << "%\n";
			cout << "--------------------------------\n";
			cout << "--------------Eraser------------\n";
			cout << "Price : " << eraser.getprice() << "\n";
			cout << "Stock : " << eraser.getstock() << "\n";
			cout << "Discount : " << eraser.getdiscount() << "%\n";
			cout << "--------------------------------\n";
			//��ǰ���� ������ parent class�� item�� ����� get�Լ��� ���� ��ȯ������ �������
		}
		cout << "===============================\nSales : " << sales << "\n===============================\n";
		//�� �ݺ����� ������ �������
	} while (command != 4);	//�Է°��� 4�� ��� �ݺ��� ����

	return 0;
}