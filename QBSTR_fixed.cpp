#include <iostream>

using namespace std;

int d[1000][1000];

int bigger(int a, int b) {
	if (a>=b) return a;
	else return b;
}

int main() {
	string a, b;
	cin >> a >> b;
	int bien = 0;//
	for (int i=0; i<a.length(); i++) {
		if (a[i] == b[0]) bien = 1; //
		d[i][0] = bien;	//
	}
	
	bien = 0; //
	for (int j=0; j<b.length(); j++) {
		if (a.at(0) == b.at(j)) bien=1; //
		d[0][j]=bien; //
	}
	
	for (int i=1; i<a.length(); i++) {
		for (int j=1; j<b.length(); j++) {
			if (a.at(i) == b.at(j)) d[i][j] = d[i-1][j-1] + 1;
			else d[i][j] = d[i-1][j-1];
			if (d[i][j] < bigger(d[i-1][j], d[i][j-1])) d[i][j] = bigger(d[i-1][j], d[i][j-1]); 
		}
	}
	
	cout << d[a.length()-1][b.length()-1] ;
	return 0;
}
