#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxm 30+10
using namespace std;

long m, n;
long p[maxm];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long u, k;
	cin >> m >> n;
	FOR(i, 1, m) cin >> p[i];
	FOR(i, 1, n) {
		cin >> k;
		FOR(j, 1, k) {
			cin >> u;
			u+=n;
			d[i][u] = p[u];
			d[u][i] = -p[u];
			
			 
		}
	}
	
	
	return 0;
}
