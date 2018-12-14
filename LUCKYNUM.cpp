#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxl 10000+10
using namespace std;
using namespace __gnu_pbds;

typedef tree<long, null_type, less<long>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

long x, f[10][maxl];

long min(long a, long b) {
	if (a<=b) return a;
	else return b;
}

string find(long digit) {
	long temp = digit;
	string res = to_string(digit);
	f[digit][1] = temp%x;
	if (digit%x==0) return res;
	FOR(i, 2, x+1) {
		res+=to_string(digit);
		temp = ((temp*10)+digit)%x;
		f[digit][i] = temp;
		if (temp==0) break;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long test_cases, maxtwo, lo, lt, slength;
	string ans, temp, str, seight, ssix;
	cin >> test_cases;
	FOR(current_test, 1, test_cases) {
		cin >> x;
		if (x%5==0 || x%16==0) {
			cout << -1 << "\n";
			continue;
		}
		string seight = find(8);
		if (x%4==0) {
			slength = seight.length();
			cout << ((slength<=200)? seight : "-1") << "\n";
			continue;
		}
		
		find(2);
		ssix = find(6);
		FOR(i, 2, min(x, 200)) {
			maxtwo = 0;
			FOR(j, 1, i-1) {
				if (f[8][i]==f[2][j]) maxtwo = j;	
			}
			if (maxtwo==0) continue;
			str = "";
			FOR(j, 1, i-maxtwo) str+="8";
			FOR(j, 1, maxtwo) str+="6";
			break;
		}
		
		lo = str.length();
		lt = ssix.length();
		if (lo<=lt) cout << str << "\n";
		else cout << ssix << "\n";		
	}
	return 0;
}
