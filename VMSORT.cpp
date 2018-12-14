#include <bits/stdc++.h>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	set<string> s;
	string tcase;
	int k, n;
	cin >> k;
	for (int i=1; i<=k; i++) {
		cin >> n;
		cin.ignore();
		for (int j=1; j<=n; j++) {
			getline(cin, tcase);
			s.insert(tcase);
		}
	}
	
	cout << s.size();
	
	return 0;
}
