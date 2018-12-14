#include <iostream>
#include <fstream>
using namespace std;

string up, down;
long countb, counto;
ifstream fi;
ofstream fo;

char rep(long i) {
	if (up[i]=='b' || down[i]=='b') return 'b';
	if (up[i]=='o' || down[i]=='o') return 'o';
} 

string khacla() {
	string temp = "";
	for (int i=1; i<=3; i++) temp+=rep(i-1);
	if ((temp=="bbb" && counto>=1) || temp=="bob"||temp=="bbo"||temp=="obb") return "yes";
	return "no";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long test;
	cin >> test;
//	fi.open("input.txt");
//	fo.open("output.txt");
	fi >> test; 
	for (int i=1; i<=test; i++) {
		cin >> up;
		cin >> down;
	//	fi >> up;
	//	fi >> down;
		counto = 0;
		countb = 0;
		
		for (int j=1; j<=3; j++) {
			if (up[j-1]=='b' || down[j-1]=='b') countb++;
			if (up[j-1]=='o' || down[j-1]=='o') counto++;
		}
		
		if (counto==0 || countb<2) {
			cout << "no" << "\n";
			//fo << "no" << "\n";
			continue;
		}
		
		cout << khacla() << "\n";
	}
//	fi.close();
//	fo.close();
	return 0;
}
