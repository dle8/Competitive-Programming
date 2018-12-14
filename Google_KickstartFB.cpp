#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define oo 1000000000
using namespace std;

long n, m;

long long prim() {
	long long msp;
	d[1] = 0;
	FOR(v, 2, n) d[v] = oo;
	memset(check, true, sizeof(check));
	
	FOR(k, 1, n) {
		u = 0;
		minDistance = oo;
		
		FOR(i, 1, n) {
			if (check[i] && d[i]<minDistance) {
				minDistance = d[i];
				u = i;
			}
		}
		
		if (u==0) break;
		check[u] = false;
		FOR(v, 1, n) {
			if (check[v] && d[v]>c[u][v]) {//tinh lai khoang cach tu v den cay khung
				d[v] = c[u][v];
			}
				
		}		
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); 	
	long u, v, c, test_cases;
	cin >> test_cases;
	FOR(current_test, 1, test_cases) {
		cin >> n >> m;
		
		FOR(i, 1, n)
		FOR(j, 1, n) {
			if (i==j) c[i][j] = 0;
			else c[i][j] = oo;
		}		
		FOR(i, 1, m) {
			cin >> u >> v >> c;
			c[u][v] = c;
			c[v][u] = c;
		}
		
		res = prim();
		
		cout << "Case #" << current_test << ": " << res << "\n";
	}
	return 0;
}
