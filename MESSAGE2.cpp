#include <bits/stdc++.h>
#define maxn 800+10
#define maxc 1000000000
using namespace std;

long trace[maxn], d[maxn], c[maxn][maxn], n;
bool check[maxn];

void prim() {
	for (int i=0; i<=n; i++) {
		d[i] = maxc;
		trace[i] = -1;
	}
	d[1] = 0;
	memset(check, true, sizeof(check));
	
	for (int i=0; i<=n; i++) {
		long u = 0;
		long min = maxc;
		for (int i=0; i<=n; i++) 
		if (check[i] && d[i]<min) {
			min = d[i];
			u = i;
		}
		if (u==0) break;
		check[u] = false;
		for (int v=0; v<=n; v++)
		if (check[v] && d[v]>c[u][v]) {
			d[v] = c[u][v];
			trace[v] = u;
		}
	}
	
	for (int i=0; i<=n; i++) {
		cout << trace[i] << " " << i << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long m, u, v;
	cin >> n >> m;
	for (int i=0; i<=n; i++)
	for (int j=0; j<=n; j++) c[i][j] = maxc;
	for (int i=1; i<=m; i++) {
		cin >> u >> v;
		c[u][v] = 0;
	}
	
	for (int i=1; i<=n; i++) {
		c[0][i] = 1000;
		c[i][0] = 1000;
	}
	
	prim();
	return 0;
}
