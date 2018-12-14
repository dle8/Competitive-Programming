#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, temp;
	char c;
	cin >> s;
	for (int i=0; i<s.length(); i++) {
		for (int j=0; j<s.length(); j++) {
			temp = s;
			if (i!=j) {
				char c = temp[i];
				temp[i] = temp[j];
				temp[j] = c;
			}
			cout << temp << "\n";
		}
	}
}
