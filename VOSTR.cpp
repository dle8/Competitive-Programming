#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
using namespace std;

string a, b;
long lengtha, lengthb, q;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long l, r, u, v;
	cin >> lengtha >> lengthb;
	
	cin >> a;
	cin >> b;
	
	cin >> q;
	FOR(i, 1, q) {
		cin >> l >> r >> u >> v;
		l--; r--; u--; v--;
		string slr = a.substr(l, r-l+1);
		string suv = b.substr(u, v-u+1);
		
		if (slr==suv) cout << "=";
		else if (slr<suv) cout << "<";
		else cout << ">";
	} 
	return 0;
}
