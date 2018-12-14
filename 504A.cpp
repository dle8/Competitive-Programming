#include <bits/stdc++.h>
using namespace std;

int main() {
	long n, m, star;
	string s, t, left, right;
	cin >> n >> m;
	cin >> s;
	cin >> t;
	
	star = s.find("*");
	
	if (star==-1 || (n-1)>m) {
		if (s==t) cout << "YES";
		else cout << "NO";
		return 0;
	}
	
	left = s.substr(0, star);
	right = s.substr(star+1);
	
	long leftPos = t.find(left);
	long rightPos = t.rfind(right);
	
	if (leftPos == -1 || rightPos==-1) {
		cout << "NO";
		return 0;
	}	
	if (leftPos+left.length()<=rightPos && rightPos+right.length()==m) cout << "YES";
	else cout <<"NO";
	return 0;
}
