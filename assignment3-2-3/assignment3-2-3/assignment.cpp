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

class Pen :public item{	//item 객체를 상속받는 Pen 객체 선언
public:
	Pen(int price, int stock) : item(price, stock) { ; }	//Pen 객체 생성자
	~Pen() { ; }	//Pen 객체 소멸자
};
class Pencil :public item {	//item 객체를 상속받는 Pencil 객체 선언
public:
	Pencil(int price, int stock) : item(price, stock) { ; }	//Pencil 객체 생성자
	~Pencil() { ; }	//Pencil 객체 소멸자
};
class Eraser :public item {	//item 객체를 상속받는 Eraser 객체 선언
public:
	Eraser(int price, int stock) : item(price, stock) { ; }	//Eraser 객체 생성자
	~Eraser() { ; }	//Eraser 객체 소멸자
};

int main() {
	class Pen pen = Pen(600, 100);
	class Pencil pencil = Pencil(1200, 100);
	class Eraser eraser = Eraser(500, 100);	//각각의 클래스에 대해 고정된 가격과 수량으로 생성
	int command = -1;
	int sales = 0;
	do {
		cout << "Enter Any Command(0 : Sell, 1 : AddStock, 2 : Discount, 3 : Print, 4 : Quit) :";
		cin >> command;
		if (command == 0) {	//0이 입력된 경우
			char name[10];
			int stock;
			cin >> name >> stock;	//두 번째 입력으로 상품명, 세 번째 입력으로 개수를 입력받음
			if (!strcmp(name, "Pen")) {	//두 번째 입력이 Pen인 경우
				if (pen.getstock() >= stock * 3) {	//Pen의 재고가 구매하려는 양보다 크거나 같은 경우
					pen.sell_item(stock * 3);	//item 객체의 sell_item 함수를 구매하려는 양을 파라미터로 하여 호출
					sales += stock * (pen.getprice()) * (100-pen.getdiscount()) / (100);	//매출을 물품가격*판매단위*개수*할인율만큼 더해줌
				}
			}
			else if (!strcmp(name, "Pencil")) {	//두 번째 입력이 Pencil인 경우
				if (pencil.getstock() >= stock * 12) {	//Pencil의 재고가 구매하려는 양보다 크거나 같은 경우
					pencil.sell_item(stock * 12);	//item 객체의 sell_item 함수를 구매하려는 양을 파라미터로 하여 호출
					sales += stock * (pencil.getprice()) * (100 - pencil.getdiscount()) / (100);	//매출을 물품가격*판매단위*개수*할인율만큼 더해줌
				}
			}
			else if (!strcmp(name, "Eraser")) {	//두 번째 입력이 Eraser인 경우
				if (eraser.getstock() >= stock) {	//Eraser의 재고가 구매하려는 양보다 크거나 같은 경우
					eraser.sell_item(stock);		//item 객체의 sell_item 함수를 구매하려는 양을 파라미터로 하여 호출
					sales += stock * (eraser.getprice()) * (100 - eraser.getdiscount()) / (100);	//매출을 물품가격*판매단위*개수*할인율만큼 더해줌
				}
			}
		}
		else if (command == 1) {	//1이 입력된 경우
			char name[10];
			int stock;
			cin >> name >> stock;	//두 번째 입력으로 상품명, 세 번째 입력으로 개수를 입력받음
			if (!strcmp(name, "Pen")) {	//두 번째 입력이 Pen인 경우
				pen.addstock(stock);	//입력값을 파라미터로 하여 pen의 재고를 증가시켜줌(item의 addstock함수 호출)
			}
			else if (!strcmp(name, "Pencil")) {	//두 번째 입력이 Pencil인 경우
				pencil.addstock(stock);	//입력값을 파라미터로 하여 pencil의 재고를 증가시켜줌(item의 addstock함수 호출)
			}
			else if (!strcmp(name, "Eraser")) {	//두 번째 입력이 Eraser인 경우
				eraser.addstock(stock);	//입력값을 파라미터로 하여 eraser의 재고를 증가시켜줌(item의 addstock함수 호출)
			}
		}
		else if (command == 2) {	///2가 입력된 경우
			char name[10];
			int discount;
			cin >> name >> discount;	//두 번째 입력으로 상품명, 세 번째 입력으로 할인율을 입력받음
			if (!strcmp(name, "Pen")) {	//두 번째 입력이 Pen인 경우
				pen.setdiscount(discount);	//입력값을 파라미터로 하여 pen의 할인율을 조정시켜줌(item의 setdiscount함수 호출)
			}
			else if (!strcmp(name, "Pencil")) {	//두 번째 입력이 Pencil인 경우
				pencil.setdiscount(discount);	//입력값을 파라미터로 하여 pencil의 할인율을 조정시켜줌(item의 setdiscount함수 호출)
			}
			else if (!strcmp(name, "Eraser")) {	//두 번째 입력이 Eraser인 경우
				eraser.setdiscount(discount);	//입력값을 파라미터로 하여 eraser의 할인율을 조정시켜줌(item의 setdiscount함수 호출)
			}
		}
		else if (command == 3) {	//입력값이 3인 경우
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
			//상품들의 정보를 parent class인 item에 선언된 get함수를 통한 반환값으로 출력해줌
		}
		cout << "===============================\nSales : " << sales << "\n===============================\n";
		//매 반복마다 매출을 출력해줌
	} while (command != 4);	//입력값이 4인 경우 반복문 종료

	return 0;
}