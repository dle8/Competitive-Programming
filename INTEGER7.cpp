#include <iostream>

using namespace std;

int ucln(int a, int b) {
	if (a<b) {
		int c = a;
		a = b;
		b = c;
	}
	
	if (a%b==0) return b;
	else return (a%b, b);
}

int bcnn(int a, int b) {
	return ((a*b)/ucln(a,b));
}

int main() {
	int a1, b1, a2, b2;
	cin >> a1 >> b1 >> a2 >> b2;
	if (a1==0 && a2!=0) {
		int x2;
		if (b1>b2) {
			if ((b1-b2)%a2 == 0) x2 = (b1-b2)/a2;
			else x2 = (b1-b2)/a2 + 1;
		}
		else x2 = 0;
		cout << 0 << " " << x2;
	}
	
	if (a1!=0 && a2 == 0) {
		int x1;
		if (b2>b1) {
			x1 = bcnn(b2-b1, a1);
			if ((b2-b1)%a1 == 0) x1 = (b2-b1)/a1;
			else x1 = (b2-b1)/a1 + 1;
		}
		else x1 = 0;
		cout << x1 << " " < 0;
	}
	
	if (a1 !=0 && a2 !=0) {
		int x1, x2;
		if (b1>=b2) x2 = bcnn(b1-b2, a2);
		else x2 = bcnn(b2-b1, a2);
		x1 =  (a2*x2+b2-b1)/a1;
		cout << x1 << " " << x2;
	}
}
