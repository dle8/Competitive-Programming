#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	if (a==b) a=0;
	else a = (a-b)/abs(a-b);
	cout << a;
	return 0;
}
