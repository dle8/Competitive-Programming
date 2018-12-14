#include <iostream>

using namespace std;

string palin[3000][3000];

string max(string a, string b) {
	if (a.length() >= b.length()) return a;
	else return b;
}

int main(){
	string a, b;
	cin >> a;
	
	b = "";
	
	for (int i= a.length()-1; i>=0; i--) b+=a[i];//create an inverse string
	
	string prefix = "";
	string suffix = "";
	
	int k = 0;
	while (k<a.length() && k <b.length()) {
		if (a[k] == b[k]) prefix +=a[k];
		else break;
		k++;
	}
	
	if (k<a.length() && k<b.length()) {
		a = a.substr(k, a.length()-k);
		b = b.substr(k, b.length()-k);
		
		k = 0;
		while (k<= a.length()-1 && k<=b.length()-1) {
			if (a[a.length()-1-k] == b[b.length()-1-k]) suffix = a[a.length()-1-k] + suffix;
			else break;
			k++;
		}
		
		if (k<a.length() && k<b.length()) {
			
			a = a.substr(0, a.length()-k);
			b = b.substr(0, b.length()-k);
			string bien = "";
			for (int i=0; i<a.length(); i++) {
				if (a[i] == b[0]) bien = a[i];
				palin[i][0] = bien;
			}
			
			bien = "";
			for (int j=0; j<b.length(); j++) {
				if (b[j] == a[0]) bien = b[j];
				palin[0][j] = bien;
			}
			
			for (int i=1; i<a.length(); i++) {
				for (int j=1; j<b.length(); j++) {
					if (a[i] == b[j]) palin[i][j] = palin[i-1][j-1] + a[i];
					else palin[i][j] = palin[i-1][j-1];
					if (palin[i][j].length() < max(palin[i-1][j], palin[i][j-1]).length()) 
						palin[i][j] = max(palin[i-1][j], palin[i][j-1]);
				}
			}
		
			cout << prefix + palin[a.length()-1][b.length()-1]+ suffix;
			
		} else cout << prefix + suffix;
		
	} else cout << prefix;
	return 0;
}


