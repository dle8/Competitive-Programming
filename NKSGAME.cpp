#include <bits/stdc++.h>
#define maxn 100000+10
#define oo 1e15
#define FOR(i, l, r) for(int i=l; i<=r; i++)
using namespace std;

long b[maxn], c[maxn], n;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	FOR(i, 1, n) cin >> b[i];
	FOR(i, 1, n) cin >> c[i];
	
	sort(b+1, b+1+n);
	sort(c+1, c+1+n, greater<int>());
	
	long neo = 0;
	long long res = oo;
	FOR(i, 1, n) {
		long long min = oo;
		FOR(j, neo, n) {
			if (abs(b[i]+c[j])<=min) {
				min = abs(b[i]+c[j]);
				neo = j;
			}
			else break;
		}
		if (min<res) res = min;
	}
	return cout << res, 0;
}
