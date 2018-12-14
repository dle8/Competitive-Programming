#include <iostream>
#include <string>
#include <climits>
using namespace std;

class str {
	public: 
		int length = 0;
		int index = 0;
};

str f[1000000];

int main() {
	string str1, str2;
	cin >> str1;
	cin >> str2;	
	
	string a,b;
	
	if (str1.length() <= str2.length()) {
		a = str1;
		b = str2;
	}
	else {
		a= str2;
		b = str1;
	}
	
	f[0].length = 0;
	f[0].index = -1;
	
	for (int i=0; i<b.length(); i++) {
		if (b.at(i) == a.at(0)) {
			f[0].length = 1;
			f[0].index = i;
			break;
		}
	}
	
	for (int i=1; i<a.length(); i++) {
		int max = 0;
		int end = -1;
		for (int j=0; j<i; j++){
			for (int k = f[j].index+1; k<b.length(); k++) {
				if (b.at(k) == a.at(i)) {
					if (f[j].length + 1 >max) {
						max = f[j].length + 1;
						end = k;
					}
					break;
				}
			}
		}
		f[i].length = max;
		f[i].index = end;
	}
	
	int max = INT_MIN;
	
	for (int i=0; i<a.length(); i++) {
		if (f[i].length > max) max = f[i].length;
	}
	cout<< max;
	return 0;
}
