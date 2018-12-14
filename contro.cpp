#include <iostream>
#include <string.h>
using namespace std;

struct ngaythangnam {
	int ngay, thang, nam;
};

int main() {
	int n, *p1, *p2;
	p1 = &n;
	*p1 = 77;
	cout << n << endl;
	p2 = new int;//cap phat bo nho dong
	*p2 = 173;
	cout <<"*p2=" << *p2 << endl;
	p1 = new int;
	p1 = p2;
	cout <<"*p1=" << *p1 << endl;
	*p1 = 999;
	cout  << "*p1=, *p2="<< *p1 << endl;
	delete p1;
	delete p2;
	/*thao tac tren cau truc*/
	ngaythangnam *p;
	p = new ngaythangnam;
	p->ngay = 20;
	p->thang = 11;
	p->nam = 2018;
	cout << p->ngay << " " <<p->thang << " " <<p->nam <<endl;
	delete p;
	return 0;
}
