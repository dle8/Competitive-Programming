#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
using namespace std;

multiset<char> ms, cmpms;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	bool found;
	string s1, s2;
	long test_cases, lengths;
	long long res;
	freopen("input11.in", "r", stdin);
	freopen("output10.out", "w", stdout);	
	cin >> test_cases;
	FOR(current_test, 1, test_cases) {
		cin >> lengths;
		cin.ignore();
		getline(cin, s1);
		getline(cin, s2);
		
		cout << "Case #" << current_test << ": ";
		
		res = 0;
		FOR(i1, 0, lengths-1) 
		FOR(j1, i1, lengths-1) {
			ms.clear();
			FOR(k, i1, j1) ms.insert(s1[k]);
			
			found = false;
			FOR(i2, 0, lengths-j1+i1-1) {
				cmpms.clear();
				FOR(j2, i2, i2+j1-i1) cmpms.insert(s2[j2]);
				if (cmpms==ms) found = true;
				if (found) break;
			}
			
			if (found) res++;
		}
		
		cout << res << "\n";
	}
	
	return 0;
}
