#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define maxn 1000000+10
using namespace std;

long z[maxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long n, l, r;
	string s;
	cin >> s;
	n = s.length();
	
	l = -1;
	r = -1;
	z[0] = n;
	FOR(i, 1, n-1) {
		if (i>r) {
			FOR(j, i, n-1) if (s[j-i]==s[j]) r = j; else break;
			if (r!=-1) {
				l = i;
				z[i] = r-l+1;	
			}
			else z[i] = 0;
		}
		else {
			long k = i-l;
			if (z[k]<r-i+1) z[i] = z[k];
			else {
				l = i;
				FOR(j, r+1, n-1) if (s[j-i]==s[j]) r = j; else break;
				z[i] = r-l+1;
			}
		}
	}
	
//	FOR(i, 0, n-1) cout << i << " " << z[i] << "\n";
	FOR(i, 1, n-1) if (z[i]==n-i) return cout << s.substr(0, i), 0;
	return 0;
}
